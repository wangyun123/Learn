#include <stdio.h>
#include "Globle.h"

// #define FILEPATH "c:\\FeiQ.exe"
// #define FILEPATH "d:\\Code\\LearnLibrary\\test\\DynLibrary2\\Debug\\DynLibrary2.dll"
// #define FILEPATH "d:\\Code\\LearnLibrary\\test\\DynLibrary2\\Debug\\OllyICE.exe"
#define FILEPATH "C:\\Code\\Learn\\LearnPE\\AnalysisPE\\PETools\\Debug\\OllyICE.exe"
#define FILEPATHNEW "c:\\FeiQ_new.exe"

int main(int argc, char* argv[])
{

	LPVOID pFileBuffer = NULL;
	ReadPEFile(FILEPATH, &pFileBuffer);
	ParseFileBuffer(pFileBuffer);
	free(pFileBuffer);

// 	LPVOID pImageBuffer = NULL;
// 	CopyFileBufferToImageBuffer(pFileBuffer, &pImageBuffer);

// 	LPVOID pNewBuffer = NULL;
// 	DWORD dwSizeFile = CopyImageBufferToNewBuffer(pImageBuffer, &pNewBuffer);
// 
// 	MemeryToFile(pNewBuffer, dwSizeFile, FILEPATHNEW);

// 	LPVOID pNewBuffer = NULL;
	
// 	char* p = "asdf";
// 	char p2[] = {0x2e, 0x74, 0x65, 0x78, 0x74, 0, 0, 0};
// 	char* p3 = p2;
// 	printf("1: %s\n", p2);
// 	printf("2: %s\n", p3);

	return 0;
}