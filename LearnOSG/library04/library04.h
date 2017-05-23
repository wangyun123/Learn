/*
*	4）工程library04: def文件中的EXPORTS语句 
*
*	新建文本文件library04.lib，具体内容入下：
*	LIBRARY	"library04"
*	;DESCRIPTION 'library04 windows dynamic link library'
*
*	EXPORTS
*		add4
*		sub4
*	采用vs命令行 lib /out:library04.lib /machine:ix86 /def:library04.def
*
*	注：在dependency中是看不到library04.dll中的函数名的，
*	只有在2）和3）能看到函数定义 
*
*	2017-04-04：测试中无法完成动态库的调用!!
*/

#ifndef LIBRARY_04_H
#define LIBRARY_04_H

int add4(int a, int b);
int sub4(int a, int b);
int mul4(int a, int b);
int div4(int a, int b);

#endif //LIBRARY_04_H