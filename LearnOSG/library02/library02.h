/*
*	2）工程library02: def文件中的EXPORTS语句 
*
*	添加*.def文件，链接器->输入->模块定义文件中指定该def文件
*	注：使用.def文件从DLL中导出变量时，不需要在变量上指定__declspec(dllexport)
*	但是，在任何使用DLL的文件中，仍必须在数据声明上使用__declspec(dllimport)?? 不知参考何处
*	出处来自于：http://blog.csdn.net/u010003835/article/details/48348733
*
*	测试过程，不论是load-time还是run-time调用，都不需要使用申明__declspec(dllimport)
*
*	可将原有函数重命名后输出，
*	参考：http://www.cppblog.com/FateNo13/archive/2009/08/24/94224.html
*
*	先看看EXPORTS语法规则：
*	entryname[=internalname] [@ordinal [NONAME]] [PRIVATE] [DATA]
*
*	EXPORTS
*	func2=add2	新名=老名
*
*/

#ifndef LIBRARY_02_H
#define LIBRARY_02_H

int add2(int a, int b);
int sub2(int a, int b);
int mul2(int a, int b);
int div2(int a, int b);

#endif //LIBRARY_02_H