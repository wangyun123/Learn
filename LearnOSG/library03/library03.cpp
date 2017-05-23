#include "library03.h"

int add3(int a, int b)
{
	return a+b;
}
int sub3(int a, int b)
{
	return a-b;
}
int mul3(int a, int b)
{
	return a*b;
}
int div3(int a, int b)
{
	if(b==0)
		return a;
	return a/b;
}

int add(int a, int b)
{
	return a+b;
}