#include "library02.h"

int add2(int a, int b)
{
	return a+b;
}
int sub2(int a, int b)
{
	return a-b;
}
int mul2(int a, int b)
{
	return a*b;
}
int div2(int a, int b)
{
	if(b==0)
		return a;
	return a/b;
}