/*
*	*）工程staticLibrary1:  
*
*	与动态库的区别：
*
*	1、编写方式上，不需要想动态链接库一样书写__declspec(dllexport)
*	
*	2、调用方式上，与动态链接库基本一致
*	
*	3、编译加载，修改后需要将调用其程序的代码重新编译
*
*	注：无论在静态库还是调用其的可执行程序都无法再dependency中查看调用函数！
*/


#ifndef LIBRARY_STATIC_H
#define LIBRARY_STATIC_H

int add(int a, int b);

#endif //LIBRARY_STATIC_H