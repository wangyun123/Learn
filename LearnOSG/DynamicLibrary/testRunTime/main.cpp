#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[])
{
	printf("this is the Run-time\n");
	// 1.
	HMODULE hModule = LoadLibraryA("../library1/debug/library1.dll");
	if (hModule == NULL)
	{
		printf("the LoadLibrary error, %d\n", GetLastError());
		return 0;
	}

	// 2.
	typedef int (*pFunc)(int, int);
	pFunc func = (pFunc)GetProcAddress(hModule, "div1");
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