#include "Globle.h"
#include <stdio.h>

// [1] file -> fileBuffer
// 将文件读取到内存缓冲区 
// lpszFile:	文件路径
// pFileBuffer:	文件缓存
// 返回值: 0是返回失败, 否则返回实际读取大小
// ? 疑问 为什么用LPVOID*类型?
DWORD ReadPEFile(IN LPSTR lpszFile, OUT LPVOID* pFileBuffer)
{
	printf("**************ReadPEFile****************\n");
	printf("*****the file path: %s\n", lpszFile);
	FILE* pFile = NULL;
	pFile = fopen(lpszFile, "rb");
	if (pFile == NULL)
	{
		perror("can't open the file!\n");
		fclose(pFile);
		return 0;
	}

	// 文件大小
	DWORD dwFileSize;
	fseek(pFile, 0, SEEK_END);
	dwFileSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	// 分配空间
	char* pBuffer = (char*)malloc(dwFileSize);
	if (pBuffer == NULL)
	{
		perror("can't malloc the memory of the FileBuffer!\n");
		return 0;
	}

	// 内存赋初值
	memset(pBuffer, 0, dwFileSize);

	// 疑问：fread函数的第二和三个参数的含义?
	size_t nSize = fread(pBuffer, 1, dwFileSize, pFile);
	if (nSize == 0)
	{
		perror("read the file error!\n");
		fclose(pFile);
		return 0;
	}

	*pFileBuffer = pBuffer;
	pBuffer = NULL;
	fclose(pFile);

 	return nSize;
}

// 解析文件缓存
void ParseFileBuffer(IN LPVOID pFileBuffer)
{
	PIMAGE_DOS_HEADER		pDosHeader = NULL;
	PIMAGE_NT_HEADERS		pNTHeader = NULL;
	PIMAGE_FILE_HEADER		pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER  pOptionalHeader = NULL;
	PIMAGE_DATA_DIRECTORY	pDataDirectory = NULL;
	PIMAGE_SECTION_HEADER   pSectionHeader = NULL;
	
	if (pFileBuffer == NULL)
	{
		perror("the file buffer error!\n");
		return ;
	}
	
	// 解析PE文件
	// dos header
	pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;
// 	PrintDosHeader(pDosHeader);
	
	// nt header
	pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pFileBuffer+pDosHeader->e_lfanew);
// 	PrintNTHeader(pNTHeader);
	
	// file header
	pPEHeader = (PIMAGE_FILE_HEADER)(&pNTHeader->FileHeader);
// 	PrintFileHeader(pPEHeader);
	
	// optional header
	pOptionalHeader = (PIMAGE_OPTIONAL_HEADER)(&pNTHeader->OptionalHeader);
// 	PrintOptionalHeader(pOptionalHeader);
	
	// image data directory
	pDataDirectory = (PIMAGE_DATA_DIRECTORY)pOptionalHeader->DataDirectory;
	PIMAGE_DATA_DIRECTORY pTmpDataDirectory = pDataDirectory;
	printf("**************IMAGE_DATA_DIRECTORY****************\n");
	for (int i=0; i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++,pTmpDataDirectory++)
	{
		printf("Data Directory [%d]\n", i);
		PrintImageDataDirectory(pTmpDataDirectory);
	}
	// export table
	pTmpDataDirectory = pDataDirectory;
	printf("**************PIMAGE_EXPORT_DIRECTORY****************\n");
	DWORD dwRVA = (DWORD)pTmpDataDirectory->VirtualAddress;
	DWORD dwFOA = RvaToFileOffset(pFileBuffer, dwRVA);
	printf("*****RVA :\t\t%x \n", dwRVA);
	PIMAGE_EXPORT_DIRECTORY pExportTable = (PIMAGE_EXPORT_DIRECTORY)(dwFOA+(DWORD)pFileBuffer);
	PrintDirectoryOfExportTable(pExportTable);

#if 1
	// [1]
	DWORD dwFoaName = RvaToFileOffset(pFileBuffer, (DWORD)pExportTable->Name);
	char* pName = (char*)(dwFoaName+(DWORD)pFileBuffer);
	printf("[*] The Name of DynLibrary2.dll: %s\n", pName);
	// [2]
	DWORD dwFoaAddressOfFunc = RvaToFileOffset(pFileBuffer, (DWORD)pExportTable->AddressOfFunctions);
	DWORD* pAddressOfFunc = (DWORD*)(dwFoaAddressOfFunc+(DWORD)pFileBuffer);
	printf("[*] AddressOfFunctions: \n");
	for (DWORD j=0; j < pExportTable->NumberOfFunctions; j++, pAddressOfFunc++)
		printf("\t[%d] : %x\n", j, *pAddressOfFunc);
	// [3]
	DWORD dwFoaAddressOfName = RvaToFileOffset(pFileBuffer, (DWORD)pExportTable->AddressOfNames);
	DWORD* pAddressOfName = (DWORD*)(dwFoaAddressOfName+(DWORD)pFileBuffer);
	printf("[*] AddressOfNames: \n");
	for ( j=0; j < pExportTable->NumberOfNames; j++, pAddressOfName++)
		printf("\t[%d] : %x , %s\n", j, *pAddressOfName, (char*)(RvaToFileOffset(pFileBuffer,(DWORD)(*pAddressOfName))+(DWORD)pFileBuffer));
	// [4]
	DWORD dwFoaAddressOfOrdinal = RvaToFileOffset(pFileBuffer, (DWORD)pExportTable->AddressOfNameOrdinals);
	WORD* pAddressOfOrdinal = (WORD*)(dwFoaAddressOfOrdinal+(DWORD)pFileBuffer);
	printf("[*] AddressOfNameOrdinals: \n");
	for ( j=0; j < pExportTable->NumberOfNames; j++, pAddressOfOrdinal++)
		printf("\t[%d] : %x\n", j, *pAddressOfOrdinal);
#endif
	// section table
// 	pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD)pNTHeader+sizeof(IMAGE_NT_HEADERS));
// 	PIMAGE_SECTION_HEADER pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;
// 	for (i=0; i< pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
// 	{
// 		printf("Section Table [%d]\n", i);
// 		PrintSectionHeader(pTmpSectionHeader);
// 	}
}

// [2] fileBuffer -> imageBuffer
// 将文件缓存pFileBuffer复制到pImageBuffer映像缓存
// pFileBuffer:		文件缓存
// pImageBuffer:	映像缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyFileBufferToImageBuffer(IN LPVOID pFileBuffer, OUT LPVOID* pImageBuffer)
{
	printf("**************CopyFileBufferToImageBuffer****************\n");

	PIMAGE_DOS_HEADER		pDosHeader = NULL;
	PIMAGE_NT_HEADERS		pNTHeader = NULL;
	PIMAGE_FILE_HEADER		pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER  pOptionalHeader = NULL;
	PIMAGE_DATA_DIRECTORY	pDataDirectory = NULL;
	PIMAGE_SECTION_HEADER   pSectionHeader = NULL;

	LPVOID pTmpImageBuffer = NULL;

	if (pFileBuffer == NULL)
	{
		perror("the file buffer error!\n");
		return 0;
	}

	// 解析PE文件
	// dos header
	pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;
	PrintDosHeader(pDosHeader);

	// nt header
	pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pFileBuffer+pDosHeader->e_lfanew);
	PrintNTHeader(pNTHeader);

	// file header
	pPEHeader = (PIMAGE_FILE_HEADER)(&pNTHeader->FileHeader);
	PrintFileHeader(pPEHeader);

	// optional header
	pOptionalHeader = (PIMAGE_OPTIONAL_HEADER)(&pNTHeader->OptionalHeader);
	PrintOptionalHeader(pOptionalHeader);

	// image data directory
	pDataDirectory = (PIMAGE_DATA_DIRECTORY)pOptionalHeader->DataDirectory;
	PIMAGE_DATA_DIRECTORY pTmpDataDirectory = pDataDirectory;
	for (int i=0; i<IMAGE_NUMBEROF_DIRECTORY_ENTRIES; i++,pTmpDataDirectory++)
	{
		printf("Data Directory [%d]\n", i);
		PrintImageDataDirectory(pTmpDataDirectory);
	}
	// export table
	pTmpDataDirectory = pDataDirectory;
	printf("********RVA of PIMAGE_EXPORT_DIRECTORY:\t\t%x \n",    pTmpDataDirectory->VirtualAddress);
	PIMAGE_EXPORT_DIRECTORY pExportTable = (PIMAGE_EXPORT_DIRECTORY)((DWORD)pTmpDataDirectory->VirtualAddress+(DWORD)pFileBuffer);
	PrintDirectoryOfExportTable(pExportTable);

	// section table
	pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD)pNTHeader+sizeof(IMAGE_NT_HEADERS));
	PIMAGE_SECTION_HEADER pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;
	for (i=0; i< pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
	{
		printf("Section Table [%d]\n", i);
		PrintSectionHeader(pTmpSectionHeader);
	}

	// imageBuffer分配多大空间?
	DWORD dwSizeImageBuffer = pOptionalHeader->SizeOfImage;
	pTmpImageBuffer = malloc(dwSizeImageBuffer);
	if (pTmpImageBuffer == NULL)
	{
		printf("can't malloc the memory!\n");
		return 0;
	}
	memset(pTmpImageBuffer, 0, dwSizeImageBuffer*sizeof(char));

	// copy the SizeOfHeaders
	memcpy(pTmpImageBuffer, pFileBuffer, pOptionalHeader->SizeOfHeaders*sizeof(char));

	// copy the section table
	pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;
	for (i=0; i < pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
	{
		// fileImage position: PointerToRawData
		// fileImage size: SizeOfRawData
		memcpy(LPVOID((DWORD)pTmpImageBuffer+pTmpSectionHeader->VirtualAddress), 
			LPVOID((DWORD)pFileBuffer+pTmpSectionHeader->PointerToRawData),
			pTmpSectionHeader->SizeOfRawData);
	}

	*pImageBuffer = pTmpImageBuffer;
	pTmpImageBuffer = NULL;
	return dwSizeImageBuffer;
}

// [3] imageBuffer -> new fileBuffer
// 将pImageBuffer映像缓存复制到pNewBuffer文件缓存
// pImageBuffer:	映像缓存
// pNewBuffer:		文件缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyImageBufferToNewBuffer(IN LPVOID pImageBuffer, OUT LPVOID* pNewBuffer)
{
	printf("**************CopyImageBufferToNewBuffer****************\n");

	PIMAGE_DOS_HEADER		pDosHeader = NULL;
	PIMAGE_NT_HEADERS		pNTHeader = NULL;
	PIMAGE_FILE_HEADER		pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER  pOptionalHeader = NULL;
	PIMAGE_SECTION_HEADER   pSectionHeader = NULL;

	if (pImageBuffer == NULL)
	{
		perror("the image buffer error!\n");
		return 0;
	}
	
	// 解析PE文件
	// dos header
	pDosHeader = (PIMAGE_DOS_HEADER)pImageBuffer;
	PrintDosHeader(pDosHeader);
	
	// nt header
	pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pImageBuffer+pDosHeader->e_lfanew);
	PrintNTHeader(pNTHeader);
	
	// file header
	pPEHeader = (PIMAGE_FILE_HEADER)(&pNTHeader->FileHeader);
	PrintFileHeader(pPEHeader);
	
	// optional header
	pOptionalHeader = (PIMAGE_OPTIONAL_HEADER)(&pNTHeader->OptionalHeader);
	PrintOptionalHeader(pOptionalHeader);
	
	// section table
	pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD)pNTHeader+sizeof(IMAGE_NT_HEADERS));
	PIMAGE_SECTION_HEADER pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;
	for (int i=0; i< pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
	{
		printf("Section Table [%d]\n", i);
		PrintSectionHeader(pTmpSectionHeader);
	}

	LPVOID pTmpFileBuffer = NULL;
	pTmpSectionHeader --;
	DWORD dwSizeFileBuffer = pTmpSectionHeader->PointerToRawData + pTmpSectionHeader->SizeOfRawData;
	pTmpFileBuffer = malloc(dwSizeFileBuffer);
	if (pTmpFileBuffer == NULL)
	{
		printf("can't malloc the memory!\n");
		return 0;
	}

	memset(pTmpFileBuffer, 0, dwSizeFileBuffer*sizeof(char));

	// copy the headers
	memcpy(pTmpFileBuffer, pImageBuffer, pOptionalHeader->SizeOfHeaders);

	// copy the section table
	pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;
	for (i=0; i < pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
	{
		memcpy(LPVOID((DWORD)pTmpFileBuffer+pTmpSectionHeader->PointerToRawData), 
			LPVOID((DWORD)pImageBuffer+pTmpSectionHeader->VirtualAddress),
			pTmpSectionHeader->SizeOfRawData);
	}

	*pNewBuffer = pTmpFileBuffer;
	pTmpFileBuffer = NULL;
	return dwSizeFileBuffer;
}

// [4] fileBuffer -> file
// 将pNewBuffer文件缓存复制到文件中
// pMemBuffer:	文件缓存
// size:		复制大小
// lpszFile:	文件路径
// 返回值: 0是返回失败
BOOL MemeryToFile(IN LPVOID pMemBuffer, IN size_t size, OUT LPSTR lpszFile)
{
	FILE* pFile = NULL;
	pFile = fopen(lpszFile, "wb");

	if (pFile == NULL)
	{
		printf("can't write the file %s\n", lpszFile);
		return FALSE;
	}

	fwrite(pMemBuffer, sizeof(char), size, pFile);

	fclose(pFile);

	return TRUE;
}

// [5] Relation Virtual Address -> File Offset Address
// RvaToFileOffset:将内存偏移RVA转换成FOA文件偏移 
// pFileBuffer:	文件缓存
// dwRva:		内存偏移
// 返回值: 0是返回失败, 否则返回文件偏移
DWORD RvaToFileOffset(IN LPVOID pFileBuffer, IN DWORD dwRva)
{
	PIMAGE_DOS_HEADER		pDosHeader = NULL;
	PIMAGE_NT_HEADERS		pNTHeader = NULL;
	PIMAGE_FILE_HEADER		pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER  pOptionalHeader = NULL;
	PIMAGE_SECTION_HEADER   pSectionHeader = NULL;
	
	if (pFileBuffer == NULL)
	{
		perror("the file buffer error!\n");
		return 0;
	}
	
	// 解析PE文件
	// dos header
	pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;
	
	// nt header
	pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pFileBuffer+pDosHeader->e_lfanew);
	
	// file header
	pPEHeader = (PIMAGE_FILE_HEADER)(&pNTHeader->FileHeader);
	
	// optional header
	pOptionalHeader = (PIMAGE_OPTIONAL_HEADER)(&pNTHeader->OptionalHeader);
	
	// section table
	pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD)pNTHeader+sizeof(IMAGE_NT_HEADERS));
	PIMAGE_SECTION_HEADER pTmpSectionHeader = (PIMAGE_SECTION_HEADER)pSectionHeader;

	//
	if (dwRva > pOptionalHeader->SizeOfImage)
	{
		printf("virtual address large than the SizeofImage!\n");
		return 0;
	}

	if (dwRva < pOptionalHeader->SizeOfHeaders)
	{
		printf("location is the sizeofheaders\n");
		return dwRva;
	}

	for (int i=0; i< pPEHeader->NumberOfSections; i++, pTmpSectionHeader++)
	{
		DWORD begin = pTmpSectionHeader->VirtualAddress;
		DWORD end = pTmpSectionHeader->VirtualAddress+pTmpSectionHeader->Misc.VirtualSize;
		if (dwRva >= begin && dwRva < end)
		{
// 			printf("RVA: %x\t", dwRva);
// 			printf("section %d:\t [%x-%x]\n", i, begin, end);
			return pTmpSectionHeader->PointerToRawData+dwRva-begin;
		}
	}

	return 0;
}

void PrintDosHeader(PIMAGE_DOS_HEADER pDosHeader)
{
	/////////////////////////////[1]打印DOS头/////////////////////////////////////////////
	printf("             [1]打印DOS头\n");
	// 判断DOS头前两个字符是否为"MZ"
	if ( *((PWORD)pDosHeader)!= IMAGE_DOS_SIGNATURE)
	{
		printf("this is not a MZ! %x\n", *((PWORD)pDosHeader));
		return ;
	}
	// 加载DOS头结构 IMAGE_DOS_HEADER
	printf("**************[1. DOS Header - IMAGE_DOS_HEADER]********************\n");
	printf("   e_magic:\t%x h\n",		pDosHeader->e_magic);                     // Magic number
    printf("   e_cblp:\t%x h\n",		pDosHeader->e_cblp);                      // Bytes on last page of file
    printf("   e_cp:\t%x h\n",			pDosHeader->e_cp);                        // Pages in file
    printf("   e_crlc:\t%x h\n",		pDosHeader->e_crlc);                      // Relocations
    printf("   e_cparhdr:\t%x h\n",		pDosHeader->e_cparhdr);                   // Size of header in paragraphs
    printf("   e_minalloc:\t%x h\n",	pDosHeader->e_minalloc);                  // Minimum extra paragraphs needed
    printf("   e_maxalloc:\t%x h\n",	pDosHeader->e_maxalloc);                  // Maximum extra paragraphs needed
    printf("   e_ss:\t%x h\n",			pDosHeader->e_ss);                        // Initial (relative) SS value
    printf("   e_sp:\t%x h\n",			pDosHeader->e_sp);                        // Initial SP value
    printf("   e_csum:\t%x h\n",		pDosHeader->e_csum);                      // Checksum
    printf("   e_ip:\t%x h\n",			pDosHeader->e_ip);                        // Initial IP value
    printf("   e_cs:\t%x h\n",			pDosHeader->e_cs);                        // Initial (relative) CS value
    printf("   e_lfarlc:\t%x h\n",		pDosHeader->e_lfarlc);                    // File address of relocation table
    printf("   e_ovno:\t%x h\n",		pDosHeader->e_ovno);                      // Overlay number
    printf("   e_res[4]:\t%x h\n",		pDosHeader->e_res);						  // Reserved words
    printf("   e_oemid:\t%x h\n",		pDosHeader->e_oemid);                     // OEM identifier (for e_oeminfo)
    printf("   e_oeminfo:\t%x h\n",		pDosHeader->e_oeminfo);                   // OEM information; e_oemid specific
    printf("   e_res2[10]:\t%x\n",		pDosHeader->e_res2);					  // Reserved words
    printf("   e_lfanew:\t%x h\n",		pDosHeader->e_lfanew);                    // File address of new exe header
	printf("the size of IMAGE_DOS_HEADER is : %x h\n", sizeof(IMAGE_DOS_HEADER));
}

// print the nt header
void PrintNTHeader(PIMAGE_NT_HEADERS pNTHeader)
{
	/////////////////////////////[2]打印NT头/////////////////////////////////////////////
	if ( *(PWORD)(pNTHeader) != IMAGE_NT_SIGNATURE )
	{
		printf("this is not PE");
		return ;
	}
	// 加载PE标准头结构体
	printf("**************[2. NT Header - IMAGE_NT_HEADERS]********************\n");
	printf("    Signature:\t%x h\n", pNTHeader->Signature);
	printf("    FileHeader:\t%x h\n", pNTHeader->FileHeader);
	printf("    OptionalHeader:\t%x h\n", pNTHeader->OptionalHeader);
	printf("the size of IMAGE_NT_HEADERS is : %x h\n", sizeof(IMAGE_NT_HEADERS));
}

void PrintFileHeader(PIMAGE_FILE_HEADER pPEHeader)
{
	/////////////////////////////[2.1]打印PE标准头/////////////////////////////////////////////
	printf("              [2.1]打印PE标准头\n");
	printf("**************[2.1 NT Header - IMAGE_FILE_HEADER]********************\n");
	printf("    Machine:\t\t\t%x h\n",				pPEHeader->Machine);
    printf("    NumberOfSections:\t\t%x h\n",		pPEHeader->NumberOfSections);
    printf("    TimeDateStamp:\t\t%x h\n",		pPEHeader->TimeDateStamp);
    printf("    PointerToSymbolTable:\t%x h\n", pPEHeader->PointerToSymbolTable);
    printf("    NumberOfSymbols:\t\t%x h\n",		pPEHeader->NumberOfSymbols);
    printf("    SizeOfOptionalHeader:\t%x h\n", pPEHeader->SizeOfOptionalHeader);
    printf("    Characteristics:\t\t%x h\n",		pPEHeader->Characteristics);
	printf("the size of IMAGE_FILE_HEADER is : %x h\n", sizeof(IMAGE_FILE_HEADER));
}

void PrintOptionalHeader(PIMAGE_OPTIONAL_HEADER pOptionHeader)
{
	printf("              [2.2]打印可选PE头\n");
	printf("**************[2.2 NT Header - IMAGE_OPTIONAL_HEADER]********************\n");
	//printf("%x\t, %x\n", ((DWORD)pNTHeader+4), ((DWORD)(pNTHeader+4))); //两种写法的区别 
	//pOptionHeader = &pNTHeader->OptionalHeader;
// 	pOptionHeader = (PIMAGE_OPTIONAL_HEADER) ((DWORD)pPEHeader + IMAGE_SIZEOF_FILE_HEADER);
	printf("    Magic:\t\t\t\t%x h\n",						pOptionHeader->Magic);
    printf("    MajorLinkerVersion:\t\t\t%x h\n",			pOptionHeader->MajorLinkerVersion);
    printf("    MinorLinkerVersion:\t\t\t%x h\n",			pOptionHeader->MinorLinkerVersion);
    printf("    SizeOfCode:\t\t\t\t%x h\n",					pOptionHeader->SizeOfCode);
    printf("    SizeOfInitializedData:\t\t%x h\n",			pOptionHeader->SizeOfInitializedData);
    printf("    SizeOfUninitializedData:\t\t%x h\n",		pOptionHeader->SizeOfUninitializedData);
    printf("    AddressOfEntryPoint:\t\t%x h\n",			pOptionHeader->AddressOfEntryPoint);
    printf("    BaseOfCode:\t\t\t\t%x h\n",					pOptionHeader->BaseOfCode);
    printf("    BaseOfData:\t\t\t\t%x h\n",					pOptionHeader->BaseOfData);
    printf("    ImageBase:\t\t\t\t%x h\n",					pOptionHeader->ImageBase);
    printf("    SectionAlignment:\t\t\t%x h\n",				pOptionHeader->SectionAlignment);
    printf("    FileAlignment:\t\t\t%x h\n",				pOptionHeader->FileAlignment);
    printf("    MajorOperatingSystemVersion:\t%x h\n",		pOptionHeader->MajorOperatingSystemVersion);
    printf("    MinorOperatingSystemVersion:\t%x h\n",		pOptionHeader->MinorOperatingSystemVersion);
    printf("    MajorImageVersion:\t\t\t%x h\n",			pOptionHeader->MajorImageVersion);
    printf("    MinorImageVersion:\t\t\t%x h\n",			pOptionHeader->MinorImageVersion);
    printf("    MajorSubsystemVersion:\t\t%x h\n",			pOptionHeader->MajorSubsystemVersion);
    printf("    MinorSubsystemVersion:\t\t%x h\n",			pOptionHeader->MinorSubsystemVersion);
    printf("    Win32VersionValue:\t\t\t%x h\n",			pOptionHeader->Win32VersionValue);
    printf("    SizeOfImage:\t\t\t%x h\n",					pOptionHeader->SizeOfImage);
    printf("    SizeOfHeaders:\t\t\t%x h\n",				pOptionHeader->SizeOfHeaders);
    printf("    CheckSum:\t\t\t\t%x h\n",					pOptionHeader->CheckSum);
    printf("    Subsystem:\t\t\t\t%x h\n",					pOptionHeader->Subsystem);
    printf("    DllCharacteristics:\t\t\t%x h\n",			pOptionHeader->DllCharacteristics);
    printf("    SizeOfStackReserve:\t\t\t%x h\n",			pOptionHeader->SizeOfStackReserve);
    printf("    SizeOfStackCommit:\t\t\t%x h\n",			pOptionHeader->SizeOfStackCommit);
    printf("    SizeOfHeapReserve:\t\t\t%x h\n",			pOptionHeader->SizeOfHeapReserve);
    printf("    SizeOfHeapCommit:\t\t\t%x h\n",				pOptionHeader->SizeOfHeapCommit);
    printf("    LoaderFlags:\t\t\t%x h\n",					pOptionHeader->LoaderFlags);
    printf("    NumberOfRvaAndSizes:\t\t%x h\n",			pOptionHeader->NumberOfRvaAndSizes);
	//     printf(" DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
	
	printf("the size of PIMAGE_OPTIONAL_HEADER is : %x h\n", sizeof(IMAGE_OPTIONAL_HEADER));

}

// print the image data directory
void PrintImageDataDirectory(PIMAGE_DATA_DIRECTORY pDataDirectory)
{
	printf("    VirtualAddress:\t\t%x \n", pDataDirectory->VirtualAddress);
	printf("    Size:\t\t\t\t%d \n", pDataDirectory->Size);
}

// printf the export table [0]
void PrintDirectoryOfExportTable(PIMAGE_EXPORT_DIRECTORY pExportTable)
{
// 	printf("********RVA of PIMAGE_EXPORT_DIRECTORY:\t\t%x \n",    pExportTable);
	printf("    Characteristics:\t\t%x \n",    pExportTable->Characteristics);
    printf("    TimeDateStamp:\t\t%x \n",    pExportTable->TimeDateStamp);
    printf("    MajorVersion:\t\t%x \n",    pExportTable->MajorVersion);
    printf("    MinorVersion:\t\t%x \n",    pExportTable->MinorVersion);
    printf("    Name:\t\t%x \n",    pExportTable->Name);
    printf("    Base:\t\t%x \n",    pExportTable->Base);
    printf("    NumberOfFunctions:\t\t%x \n",    pExportTable->NumberOfFunctions);
    printf("    NumberOfNames:\t\t%x \n",    pExportTable->NumberOfNames);
    printf("    AddressOfFunctions:\t\t%x \n",    pExportTable->AddressOfFunctions);     // RVA from base of image
    printf("    AddressOfNames:\t\t%x \n",    pExportTable->AddressOfNames);         // RVA from base of image
    printf("    AddressOfNameOrdinals:\t\t%x \n",    pExportTable->AddressOfNameOrdinals);  // RVA from base of image
}

void PrintSectionHeader(PIMAGE_SECTION_HEADER pSectionHeader)
{
	printf("              [3]打印界标\n");
	printf("**************[3 Section Header - IMAGE_SECTION_HEADER]********************\n");
	printf("    Name:\t\t\t\t%s \n",					(char*)pSectionHeader->Name);
    printf("    Misc:\t\t\t\t%x h\n",					pSectionHeader->Misc);
	printf("    VirtualAddress:\t\t\t%x h\n",			pSectionHeader->VirtualAddress);
    printf("    SizeOfRawData:\t\t\t%x h\n",			pSectionHeader->SizeOfRawData);
	printf("    PointerToRawData:\t\t\t%x h\n",			pSectionHeader->PointerToRawData);
    printf("    PointerToRelocations:\t\t%x h\n",		pSectionHeader->PointerToRelocations);
	printf("    PointerToLinenumbers:\t\t%x h\n",		pSectionHeader->PointerToLinenumbers);
    printf("    NumberOfRelocations:\t\t%x h\n",		pSectionHeader->NumberOfRelocations);
	printf("    NumberOfLinenumbers:\t\t%x h\n",		pSectionHeader->NumberOfLinenumbers);
    printf("    Characteristics:\t\t\t%x h\n",			pSectionHeader->Characteristics);

	printf("the size of PIMAGE_SECTION_HEADER is : %x h\n", sizeof(IMAGE_SECTION_HEADER));

}