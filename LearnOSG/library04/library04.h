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
* 
* 2017-08-17: lib命令将dll库中可导出函数生成对应的lib文件，提供内编译器作为链接阶段来使用
*		          如果dll库中没有可供导出的函数，则编译器也无法从生成的lib中找到对应的函数
*             所以，在该工程生成dll之后创建def文件，并不能实现对库函数的调用!!
*             建议：先使用dumpbin /EXPORTS *.dll 来查看是否有导出函数
*/

#ifndef LIBRARY_04_H
#define LIBRARY_04_H

int add4(int a, int b);
int sub4(int a, int b);
int mul4(int a, int b);
int div4(int a, int b);

#endif //LIBRARY_04_H