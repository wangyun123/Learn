/*
*	1）工程library03: 源码中函数前添加关键字 __declspec(dllexport)
*
*	注：使用微软专用的_declspec (dllexport)时，cpp文件在编译为OBJ文件时
*	要对函数进行重新命名，C语言会把函数name重新命名为_name,
*	而C++会重新命名为_name@@decoration,
*	调用时采用Func add = (Func)GetProcAddress(hModule, "?add@@YAHHH@Z");
*	
*	extern "C" TEST_LIBRARY_API int add3(int a, int b);
*
*/

#ifndef LIBRARY_03_H
#define LIBRARY_03_H

#define TEST_LIBRARY

#ifdef TEST_LIBRARY
#define TEST_LIBRARY_API __declspec(dllexport)
#else
#define TEST_LIBRARY_API __declspec(dllimport)
#endif

extern "C" TEST_LIBRARY_API int add3(int a, int b);
extern "C" TEST_LIBRARY_API int sub3(int a, int b);
extern "C" TEST_LIBRARY_API int mul3(int a, int b);
extern "C" TEST_LIBRARY_API int div3(int a, int b);
extern "C" int add(int a, int b);

#endif //LIBRARY_03_H