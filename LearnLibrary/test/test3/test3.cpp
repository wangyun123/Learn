// test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

#define STATIC_LOAD_LIBRARY

#ifdef STATIC_LOAD_LIBRARY
#include "../DynLibrary3/func3.h"
#pragma comment(lib, "../DynLibrary3/Debug/DynLibrary3.lib")
#endif

int main(int argc, char* argv[])
{
#ifdef STATIC_LOAD_LIBRARY
	printf("this is the static load library3 ...\n");
	int r = add3(1,2);
#else
	printf("this is the dynamic load library3 ...\n");
	printf("1. call function [LoadLibrary]\n");

	HMODULE h1 = GetModuleHandle("Kernel32");
	if (h1!=NULL)
		printf("the Kernel32 already been loaded!\n");

	HMODULE hModule = LoadLibrary("../DynLibrary3/Debug/DynLibrary3.dll");
	if (hModule == NULL)
	{
		printf("the Load Library 3 error!\n");
		return 0;
	}

	printf("2. call function [LoadLibrary]\n");
	typedef int (*pFunc)(int, int);
	pFunc add = (pFunc)GetProcAddress(hModule, "add3");
	if (add == NULL)
	{
		printf("GetProcAddress add function error!\n");
		return 0;
	}

	FreeLibrary(hModule);
#endif

	getchar();

	return 0;
}
