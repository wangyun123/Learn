#include <stdio.h>
#include <Windows.h>

int main(int argc, char* argv[])
{
	// run-time load the dynamic library
	HMODULE hModule = LoadLibraryA("../debug/DynamicLibrary1.dll");
	if (hModule == NULL)
	{
		printf("the LoadLibrary error! \n");
		printf("error code: %d\n",GetLastError());
		return 0;
	}

	typedef int (*Func)(int a, int b);
	//Func func1 = (Func)GetProcAddress(hModule, "div1");
	Func func1 = (Func)GetProcAddress(hModule, "div1");
	if (func1 == NULL)
	{
		printf("the GetProcAddress error! \n");
		printf("error code: %d\n",GetLastError());
		return 0;
	}

	int result = func1(1,2);
	printf("function add result is :%d\n", result);
#if 0
	Func func2 = (Func)GetProcAddress(hModule,"?mul1@@YAHHH@Z");
	if (func2 == NULL)
	{
		printf("the GetProcAddress error! \n");
		printf("error code: %d\n",GetLastError());
		return 0;
	}

	result = func2(2,3);
	printf("function add result is :%d\n", result);
#endif

	FreeLibrary(hModule);


	return 0;
}