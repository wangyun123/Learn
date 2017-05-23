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
	// ��ȡ�ļ���С
	fseek(pFile, 0, SEEK_END);
	dwSize = ftell(pFile);
	
	fseek(pFile, 0, SEEK_SET);
	// ���仺������С
	pFileBuffer = malloc(dwSize);
	if (!pFileBuffer)
	{
		printf("can't malloc the space!\n");
		fclose(pFile);
		return NULL;
	}

	// �ļ���ȡ���ڴ滺����
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

	// ��ȡpe�ļ�
	pFileBuffer = ReadPEFile(FILEPATH);
	if (!pFileBuffer)
	{
		printf("the %s file can't open !\n", FILEPATH);
		free(pFileBuffer);
		return ;
	}

	/////////////////////////////[1]��ӡDOSͷ/////////////////////////////////////////////
	// �ж�DOSͷǰ�����ַ��Ƿ�Ϊ"MZ"
	if ( *((PWORD)pFileBuffer)!= IMAGE_DOS_SIGNATURE)
	{
		printf("this is not a MZ! %x\n", *((PWORD)pFileBuffer));
		free(pFileBuffer);
		return ;
	}
	// ����DOSͷ�ṹ IMAGE_DOS_HEADER
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



