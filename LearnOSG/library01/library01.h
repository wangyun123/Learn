/*
*	*）工程library01: 从EXE里导出函数定义 
*
*/

#ifndef LIBRARY_01_H
#define LIBRARY_01_H

#define EXE_LIBRARY

#ifdef EXE_LIBRARY
#define EXE_LIBRARY_API __declspec(dllexport)
#else
#define EXE_LIBRARY_API __declspec(dllimport)
#endif

EXE_LIBRARY_API int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);


#endif //LIBRARY_01_H