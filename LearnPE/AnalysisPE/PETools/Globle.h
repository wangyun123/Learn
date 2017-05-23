#ifndef _GLOBLE_H_
#define _GLOBLE_H_

#include <windows.h>

// [1] file -> fileBuffer
// ���ļ���ȡ���ڴ滺���� 
// lpszFile:	�ļ�·��
// pFileBuffer:	�ļ�����
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻�ʵ�ʶ�ȡ��С
DWORD ReadPEFile(IN LPSTR lpszFile, OUT LPVOID* pFileBuffer);

// [2] fileBuffer -> imageBuffer
// ���ļ�����pFileBuffer���Ƶ�pImageBufferӳ�񻺴�
// pFileBuffer:		�ļ�����
// pImageBuffer:	ӳ�񻺴�
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻ظ��ƴ�С
DWORD CopyFileBufferToImageBuffer(IN LPVOID pFileBuffer, OUT LPVOID* pImageBuffer);

// [3] imageBuffer -> new fileBuffer
// ��pImageBufferӳ�񻺴渴�Ƶ�pNewBuffer�ļ�����
// pImageBuffer:	ӳ�񻺴�
// pNewBuffer:		�ļ�����
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻ظ��ƴ�С
DWORD CopyImageBufferToNewBuffer(IN LPVOID pImageBuffer, OUT LPVOID* pNewBuffer);

// [4] fileBuffer -> file
// ��pNewBuffer�ļ����渴�Ƶ��ļ���
// pMemBuffer:	�ļ�����
// size:		���ƴ�С
// lpszFile:	�ļ�·��
// ����ֵ: 0�Ƿ���ʧ��
BOOL MemeryToFile(IN LPVOID pMemBuffer, IN size_t size, OUT LPSTR lpszFile);

// [5] Relation Virtual Address -> File Offset Address
// RvaToFileOffset:���ڴ�ƫ��RVAת����FOA�ļ�ƫ�� 
// pFileBuffer:	�ļ�����
// dwRva:		�ڴ�ƫ��
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻��ļ�ƫ��
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