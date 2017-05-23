#include <stdio.h>

void func()
{
	char* a;
	short* b;
	int* c;

	a = (char*)101;
	b = (short*)102;
	c = (int*)103;

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
}
void func_1()
{
	int* a1 = (int*)100;
	int* a2 = (int*)203;
	printf("%d\n", a2-a1);
}

void func1()
{

}
void func2(int a, int b)
{

}
int func3(int a, int b)
{
	return a+b;
}

struct S1
{
	char a;
	short b;
	int c;
};

struct S2
{
	int a;
	__int64 b;
	char c;
};

struct S3
{
	int a;
	__int64 b;
	char c;
	char d;
};

struct S4
{
	int a;
	__int64 b;
	char c;
	int d;
};

int main(int argc, char* argv[])
{
	//printf("hello world!\n");
	//func();
// 	S2 s2;
// 	s2.a=1;
// 	s2.b=2;
// 	s2.c=3;
// 	S3 s3;
// 	s3.a=1;
// 	s3.b=2;
// 	s3.c=3;
// 	s3.d=4;
// 	S4 s4;
// 	s4.a=1;
// 	s4.b=2;
// 	s4.c=3;
// 	s4.d=4;
// 	printf("%d\n", sizeof(S2));
// 	printf("%d\n", sizeof(S3));
// 	printf("%d\n", sizeof(S4));

	func1();
	func2(1,2);
	func3(3,4);
	return 0;
}