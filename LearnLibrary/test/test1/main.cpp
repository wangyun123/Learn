#include <stdio.h>
#include <windows.h>

// #define STATIC_LINK

#ifdef STATIC_LINK
#include "../DynLibrary1/func1.h"
#pragma comment(lib, "../DynLibrary1/Debug/DynLibrary1.lib")
#endif

int main(int argc, char* argv[])
{
#ifdef STATIC_LINK
	printf("this is the dynamic link library, the call 1!\n");
	printf("Function of add: %d\n", add(1,2));
	printf("Function of sub: %d\n", sub(1,2));
	printf("Function of mul: %d\n", mul(1,2));
	printf("Function of div: %d\n", div(1,2));
#else
	printf("this is the dynamic link library, the call 2!\n");
	HMODULE hModule = LoadLibrary("../DynLibrary1/Debug/DynLibrary1.dll");
	if (hModule == NULL)
	{
		printf("the load library error!\n");
		return 0;
	}

	typedef int (*Func)(int, int);
	Func add = (Func)GetProcAddress(hModule, "?add@@YAHHH@Z");
	if (add == NULL)
	{
		printf("GetProcAddress add function error!\n");
		return 0;
	}
	printf("Function of add: %d\n", add(1,2));

	Func sub = (Func)GetProcAddress(hModule, (LPCTSTR)0x0004);
	if (sub == NULL)
	{
		printf("GetProcAddress sub function error!\n");
		return 0;
	}
	
	printf("Function of sub: %d\n", sub(1,2));

#endif
	return 0;
}