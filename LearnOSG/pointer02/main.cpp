/*
*	学习函数与指针的使用
*	参考： 浅析int*p()与int(*p)()的区别
*	http://blog.chinaunix.net/uid-22391661-id-1774385.html
*
*	注意：
*	（1）int* p[2];	等效于p[2][];
*
*		为行数确定、列数不确定，即为2*n型的。
*
*	（2）int (*p)[2];	等效于p[][2];
*
*		为n*2型的数组的指针用法，即行数不确定、列数确定。
*
*	2017-03-22
*/

#include <stdio.h>


int main(int argc, char* argv[])
{
	//func2();
	getchar();
	return 0;
}