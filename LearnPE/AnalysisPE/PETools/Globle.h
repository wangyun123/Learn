#ifndef _GLOBLE_H_
#define _GLOBLE_H_

#include <windows.h>

// [1] file -> fileBuffer
// 将文件读取到内存缓冲区 
// lpszFile:	文件路径
// pFileBuffer:	文件缓存
// 返回值: 0是返回失败, 否则返回实际读取大小
DWORD ReadPEFile(IN LPSTR lpszFile, OUT LPVOID* pFileBuffer);

// [2] fileBuffer -> imageBuffer
// 将文件缓存pFileBuffer复制到pImageBuffer映像缓存
// pFileBuffer:		文件缓存
// pImageBuffer:	映像缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyFileBufferToImageBuffer(IN LPVOID pFileBuffer, OUT LPVOID* pImageBuffer);

// [3] imageBuffer -> new fileBuffer
// 将pImageBuffer映像缓存复制到pNewBuffer文件缓存
// pImageBuffer:	映像缓存
// pNewBuffer:		文件缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyImageBufferToNewBuffer(IN LPVOID pImageBuffer, OUT LPVOID* pNewBuffer);

// [4] fileBuffer -> file
// 将pNewBuffer文件缓存复制到文件中
// pMemBuffer:	文件缓存
// size:		复制大小
// lpszFile:	文件路径
// 返回值: 0是返回失败
BOOL MemeryToFile(IN LPVOID pMemBuffer, IN size_t size, OUT LPSTR lpszFile);

// [5] Relation Virtual Address -> File Offset Address
// RvaToFileOffset:将内存偏移RVA转换成FOA文件偏移 
// pFileBuffer:	文件缓存
// dwRva:		内存偏移
// 返回值: 0是返回失败, 否则返回文件偏移
DWORD RvaToFileOffset(IN LPVOID pFileBuffer, IN DWORD dwRva);

// print the dos header
void PrintDosHeader(PIMAGE_DOS_HEADER pDosHeader);

// print the nt header
void PrintNTHeader(PIMAGE_NT_HEADERS pNTHeader);

// print the file header
void PrintFileHeader(PIMAGE_FILE_HEADER pPEHeader);

// print the optional header
void PrintOptionalHeader(PIMAGE_OPTIONAL_HEADER pOptionHeader);

//print the section header
void PrintSectionHeader(PIMAGE_SECTION_HEADER pSectionHeader);

#endif