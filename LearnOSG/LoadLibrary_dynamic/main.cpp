/*
*	学习windows下动态库编程技术
*	参考：
*	动态链接库的两种调用方式： 静态加载和动态加载
*	
*			即：	1）装入时动态链接；load-time dynamic linking
*				2）运行时动态链接；run-time dynamic linking
*
*	1、工程LoadLibrary_static: 静态加载/静态链接
*	   1) 采用#pragma comment(lib, "**.lib")的方式
*	   2) 采用工程属性中 “链接器” -> “输入”填入**.lib
*	
*	2、工程LoadLibrary_dynamic: 动态加载/动态链接
*	   采用LoadLibrary()方式动态加载库文件
*
*/

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main(int argc, char* argv[])
{
	//! 动态加载库文件
	printf("[2] dynamic loading the library!\n");
	HMODULE hModule = LoadLibrary(_T("library04.dll"));
	if (hModule == nullptr)
	{
		printf("can't load library04.dll !\n");
		return 0;
	}
	typedef int (*Func)(int a, int b);
	Func add = (Func)GetProcAddress(hModule, "add4");
	if (add == nullptr)
	{
		printf("can't load func add !\n");
		return 0;
	}

	int result;
	result = add(10,20);
	printf("dynamic loading the library04, result=%d\n", result);
	getchar();

	FreeLibrary(hModule);

	return 0;
}
