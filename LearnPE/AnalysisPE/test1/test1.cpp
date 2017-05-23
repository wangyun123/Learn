// test1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

#define FILEPATH "D:\\code\\PEparse\\test\\Debug\\FeiQ.exe"
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
	PIMAGE_DOS_HEADER		pDosHeader = NULL;
	PIMAGE_NT_HEADERS		pNTHeader = NULL;
	PIMAGE_FILE_HEADER		pPEHeader = NULL;
	PIMAGE_OPTIONAL_HEADER	pOptionHeader = NULL;
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
	// 判断DOS头前两个字符是否为"MZ"
	if ( *((PWORD)pFileBuffer)!= IMAGE_DOS_SIGNATURE)
	{
		printf("this is not a MZ! %x\n", *((PWORD)pFileBuffer));
		free(pFileBuffer);
		return ;
	}
	// 加载DOS头结构 IMAGE_DOS_HEADER
	pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;

}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	PrintNTHeaders();

	return 0;
}



