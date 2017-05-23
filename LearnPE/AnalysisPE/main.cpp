#include <stdio.h>
#include <malloc.h>
#include <basetsd.h>

// LPVOID ReadPEFile(LPSTR lpszFile)
// {
// 	DWORD dwSize = 0;
// 	LPVOID pFileBuffer = NULL;
// 	FILE* pFile = NULL;
// 	
// 	pFile = fopen(lpszFile, "rb");
// 	if (!pFile)
// 	{
// 		printf("can't open this exe !\n");
// 		return NULL;
// 	}
// 	// 获取文件大小
// 	fseek(pFile, 0, SEEK_END);
// 	dwSize = ftell(pFile);
// 	
// 	fseek(pFile, 0, SEEK_SET);
// 	// 分配缓冲区大小
// 	pFileBuffer = malloc(dwSize);
// 	
// 	return NULL;
// }


int main(int argc, char* argv[])
{
	BOOL a0 = 0x61;
	BYTE a1 = 0x61;
	UINT a2 = 0x61;
	WORD a3 = 0x61;
	DWORD a4 = 0x61;
	
	printf("%x\n", a0);
	printf("%x\n", a1);
	printf("%x\n", a2);
	printf("%x\n", a3);
	printf("%x\n", a4);
	getchar();

	return 0;
}