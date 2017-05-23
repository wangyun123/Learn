/*
*	学习数组与指针的使用
*	参考： 浅析int*p[ ]与int(*p)[ ]的区别
*	http://www.jb51.net/article/39690.htm
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

// 
// int* p[2];
void func1()
{
	char a[3] = {1,2,3};
	char b[4] = {4,5,6,7};

	char* p[2];
	p[0] = a;
	p[1] = b;

	for (int i=0; i<3; i++)
		printf("%d\t", *p[0]++);
	printf("\n");

	for (int i=0; i<4; i++)
		printf("%d\t", *(p[1]+i));
	printf("\n");
}

//int (*p)[2];
void func2()
{
	char (*p)[2];
	char a[][2] = {{11,12},{21,22},{31,32}};
	p = a;

	for(int i=0; i<3; i++)
	{
		for (int j=0; j<2; j++)
		{
			//printf("%d\t",*(*(p+i)+j));
			//
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	func1();
	func2();
	getchar();
	return 0;
}