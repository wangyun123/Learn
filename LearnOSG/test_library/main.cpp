/*
*	学习windows下动态库编程技术
*	参考：http://blog.csdn.net/u010003835/article/details/48348733
*	三种导出函数定义的方法
*
*	1）工程library03: 源码中函数前添加关键字 __declspec(dllexport)
*
*	注：使用微软专用的_declspec (dllexport)时，cpp文件在编译为OBJ文件时
*	要对函数进行重新命名，C语言会把函数name重新命名为_name,
*	而C++会重新命名为_name@@decoration,
*	调用时采用Func add = (Func)GetProcAddress(hModule, "?add@@YAHHH@Z");
*	
*	extern "C" TEST_LIBRARY_API int add3(int a, int b);
*
*	2）工程library02: def文件中的EXPORTS语句 
*
*	添加*.def文件，编译器->输入->模块定义文件中指定该def文件
*	注：使用.def文件从DLL中导出变量时，不需要在变量上指定__declspec(dllexport)
*	但是，在任何使用DLL的文件中，仍必须在数据声明上使用__declspec(dllimport)
*
*	3）还未尝试: LINK命令中的/EXPORT规范  
*
*/
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

#define DYNAMIC_LOADING

// exe文件同样可以导出函数定义
// 参考：http://www.cppblog.com/Streamlet/archive/2012/12/01/195858.html
// 可以像DLL一样，在EXE里导出函数。调用时可以静态链接也可以动态加载。
// EXE只作为一个进程内的模块被加载，不会新起一个进程。加载过程中EXE中的WinMain函数不会被调用。

#ifndef DYNAMIC_LOADING
#include "../library03/library03.h"
#pragma comment(lib, "../release/library03.lib")
#endif

int main(int argc, char* argv[])
{
#ifndef DYNAMIC_LOADING
	//! 静态加载库文件
	printf("[1] static loading the library!\n");
	int result;
	result = add3(10,20);
	printf("static loading the library03, result=%d\n", result);
	getchar();
#else
	//! 动态加载库文件
	printf("[2] dynamic loading the library!\n");
	HMODULE hModule = LoadLibrary(_T("library03.dll"));
	if (hModule == nullptr)
	{
		printf("can't load library03.dll !\n");
		return 0;
	}
	typedef int (*Func)(int a, int b);
	Func add = (Func)GetProcAddress(hModule, "add3");
	if (add == nullptr)
	{
		printf("can't load func add3 !\n");
		return 0;
	}

	int result;
	result = add(10,20);
	printf("dynamic loading the library03, result=%d\n", result);
	getchar();

	FreeLibrary(hModule);
#endif

#if 0
	//! 加载exe可执行文件
	HMODULE hModule = LoadLibrary(_T("library01.exe"));
	if (hModule== nullptr)
	{
		printf("can't load library01\n");
		//getchar();
		return 0;
	}

	typedef int (*Func)(int a, int b);
	Func add = (Func)GetProcAddress(hModule, "?add@@YAHHH@Z");
	if (add == nullptr)
	{
		printf("can't load func\n");
		//getchar();
		return 0;
	}
	int result;
	result = add(10,20);
	printf("synamic library01, this is exe file! result=%d\n", result);

	FreeLibrary(hModule);
#endif

	return 0;
}