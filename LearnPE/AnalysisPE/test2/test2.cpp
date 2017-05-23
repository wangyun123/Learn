// test2.cpp : Defines the entry point for the console application.
// 解析pe文件 2017-04-11
// 学习第四章
//

#include "stdafx.h"
#include "test2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

#define FILEPATH "D:\\code\\PEparse\\test\\Debug\\FeiQ.exe"
VOID PrintNTHeaders();
LPVOID ReadPEFile(LPSTR lpszFile);

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}

	//////////////////////////////////////////////////////////////////////////
// 	BOOL a0 = 0x12345678;
// 	BYTE a1 = 0x12345678;
// 	UINT a2 = 0x12345678;
// 	WORD a3 = 0x12345678;
// 	DWORD a4 = 0x12345678;
// 	
// 	printf("%x\n", a0);
// 	printf("%x\n", a1);
// 	printf("%x\n", a2);
// 	printf("%x\n", a3);
// 	printf("%x\n", a4);

	PrintNTHeaders();

	return nRetCode;
}

LPVOID ReadPEFile(LPSTR lpszFile)
{
	DWORD dwSize = 0;
	LPVOID pFileBuffer = NULL;
	FILE* pFile = NULL;
	
	pFile = fopen(lpszFile, "rb");
	if (!pFile)
	{
		printf("can't open this exe !\n");
		return NULL;
	}
	// 获取文件大小
	fseek(pFile, 0, SEEK_END);
	dwSize = ftell(pFile);
	
	fseek(pFile, 0, SEEK_SET);
	// 分配缓冲区大小
	pFileBuffer = malloc(dwSize);
	if (!pFileBuffer)
	{
		printf("can't malloc the space!\n");
		fclose(pFile);
		return NULL;
	}
	
	// 文件读取到内存缓冲区
	size_t n = fread(pFileBuffer, sizeof(char), dwSize, pFile);
	if (!n)
	{
		printf("fread the file error!\n");
		free(pFileBuffer);
		fclose(pFile);
		return NULL;
	}
	fclose(pFile);
	
	return pFileBuffer;
}

VOID PrintNTHeaders()
{
	LPVOID pFileBuffer = NULL;
	PIMAGE_DOS_HEADER		pDosHeader = NULL;		// DOS Header
	PIMAGE_NT_HEADERS		pNTHeader = NULL;		// NT Header 包括标准头和可选头
	PIMAGE_FILE_HEADER		pPEHeader = NULL;		// File Header 标准头
	PIMAGE_OPTIONAL_HEADER	pOptionHeader = NULL;	// Optional Header 可选头
	PIMAGE_SECTION_HEADER	pSectionHeader = NULL;
	
	// 读取pe文件
	pFileBuffer = ReadPEFile(FILEPATH);
	if (!pFileBuffer)
	{
		printf("the %s file can't open !\n", FILEPATH);
		free(pFileBuffer);
		return ;
	}
	
	/////////////////////////////[1]打印DOS头/////////////////////////////////////////////
	printf("[1]打印DOS头\n");
	// 判断DOS头前两个字符是否为"MZ"
	if ( *((PWORD)pFileBuffer)!= IMAGE_DOS_SIGNATURE)
	{
		printf("this is not a MZ! %x\n", *((PWORD)pFileBuffer));
		free(pFileBuffer);
		return ;
	}
	// 加载DOS头结构 IMAGE_DOS_HEADER
	pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;
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
//     printf("   e_res2[10]:\t%x\n", pDosHeader->e_res2);						  // Reserved words
    printf("   e_lfanew:\t%x h\n",		pDosHeader->e_lfanew);                    // File address of new exe header
	printf("the size of IMAGE_DOS_HEADER is : %x h\n", sizeof(IMAGE_DOS_HEADER));

	/////////////////////////////[2]打印NT头/////////////////////////////////////////////
	if ( *(PWORD)((DWORD)pFileBuffer+pDosHeader->e_lfanew) != IMAGE_NT_SIGNATURE )
	{
		printf("this is not PE");
		free(pFileBuffer);
		return ;
	}
	// 加载PE标准头结构体
	pNTHeader = (PIMAGE_NT_HEADERS) ((DWORD)pFileBuffer+pDosHeader->e_lfanew);
	printf("**************[2. NT Header - IMAGE_NT_HEADERS]********************\n");
	printf("    Signature:\t%x h\n", pNTHeader->Signature);
	printf("the size of IMAGE_NT_HEADERS is : %x h\n", sizeof(IMAGE_NT_HEADERS));

	/////////////////////////////[2.1]打印PE标准头/////////////////////////////////////////////
	printf("[2.1]打印PE标准头\n");
	//pPEHeader = &pNTHeader->FileHeader;
	pPEHeader = (PIMAGE_FILE_HEADER) ((DWORD)pNTHeader+4);
	printf("**************[2.1 NT Header - IMAGE_FILE_HEADER]********************\n");
	printf("    Machine:\t\t\t%x h\n",				pPEHeader->Machine);
    printf("    NumberOfSections:\t\t%x h\n",		pPEHeader->NumberOfSections);
    printf("    TimeDateStamp:\t\t%x h\n",		pPEHeader->TimeDateStamp);
    printf("    PointerToSymbolTable:\t%x h\n", pPEHeader->PointerToSymbolTable);
    printf("    NumberOfSymbols:\t\t%x h\n",		pPEHeader->NumberOfSymbols);
    printf("    SizeOfOptionalHeader:\t%x h\n", pPEHeader->SizeOfOptionalHeader);
    printf("    Characteristics:\t\t%x h\n",		pPEHeader->Characteristics);
	printf("the size of IMAGE_FILE_HEADER is : %x h\n", sizeof(IMAGE_FILE_HEADER));

	printf("[2.2]打印可选PE头\n");
	printf("**************[2.2 NT Header - IMAGE_OPTIONAL_HEADER]********************\n");
	//printf("%x\t, %x\n", ((DWORD)pNTHeader+4), ((DWORD)(pNTHeader+4))); //两种写法的区别 
	//pOptionHeader = &pNTHeader->OptionalHeader;
	pOptionHeader = (PIMAGE_OPTIONAL_HEADER) ((DWORD)pPEHeader + IMAGE_SIZEOF_FILE_HEADER);
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

	/////////////////////////////[3]打印节表头/////////////////////////////////////////////
	printf("[3]打印节表头\n");

	pSectionHeader = (PIMAGE_SECTION_HEADER) ((DWORD)pOptionHeader + IMAGE_SIZEOF_NT_OPTIONAL_HEADER);
	printf("**************[3 SECTION TABLE - IMAGE_SECTION_HEADER]********************\n");

	for (int n=0; n<pPEHeader->NumberOfSections; n++)
	{
		printf("第[%d]个节表头信息\n", n+1);
		printf("    Name:\t\t\t");
		for (int i=0; i<8; i++)
			printf("%c", pSectionHeader->Name[i]);
		printf("\n");
		printf("    Misc:\t\t\t%xh\n",				pSectionHeader->Misc);
		printf("    VirtualAddress:\t\t%xh\n",		pSectionHeader->VirtualAddress);
		printf("    SizeOfRawData:\t\t%xh\n",		pSectionHeader->SizeOfRawData);
		printf("    PointerToRawData:\t\t%xh\n",	pSectionHeader->PointerToRawData);
		printf("    PointerToRelocations:\t%xh\n",	pSectionHeader->PointerToRelocations);
		printf("    PointerToLinenumbers:\t%xh\n",	pSectionHeader->PointerToLinenumbers);
		printf("    NumberOfRelocations:\t%xh\n",	pSectionHeader->NumberOfRelocations);
		printf("    NumberOfLinenumbers:\t%xh\n",	pSectionHeader->NumberOfLinenumbers);
		printf("    Characteristics:\t\t%xh\n",		pSectionHeader->Characteristics);
		pSectionHeader++  ;
	}

	free(pFileBuffer);
}
