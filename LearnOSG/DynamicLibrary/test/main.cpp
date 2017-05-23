#include <stdio.h>
#include <Windows.h>

#include "../library1/func.h"
#include "../library2/func.h"
#include "../library3/func.h"

#if 0

#ifdef _DEBUG
#pragma comment(lib, "../library2/debug/library2.lib")
#pragma comment(lib, "../library3/debug/library3.lib")
#else
#pragma comment(lib, "../library2/release/library2.lib")
#pragma comment(lib, "../library3/release/library3.lib")
#endif

int main1(int argc, char* argv[])
{
#if 1
	// 
	printf("library2: test the DllMain!\n");
	int result = add2(1,2);
	printf("the result is :%d\n", result);
#else
	printf("library3: test the DllMain!\n");
	int result = add3(1,2);
	printf("the result is :%d\n", result);
#endif

	return 0;
}
#endif

int main(int argc, char* argv[])
{
	printf("this is the Run-time\n");
	// 1.
	HMODULE hModule = LoadLibraryA("../library3/debug/library3.dll");
	if (hModule == NULL)
	{
		printf("the LoadLibrary error, %d\n", GetLastError());
		return 0;
	}

	// 2.
	typedef int (*pFunc)(int, int);
	pFunc func = (pFunc)GetProcAddress(hModule, "add3");
	if (func == NULL)
	{
		printf("the GetProcAddress error, %d\n", GetLastError());
		return 0;
	}

	// 3.
	int result = func(10,2);
	printf("the result is %d\n", result);

	// 4.
	FreeLibrary(hModule);

	return 0;
}