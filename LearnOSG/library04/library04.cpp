#include "library04.h"

int add4(int a, int b)
{
	return a+b;
}
int sub4(int a, int b)
{
	return a-b;
}
int mul4(int a, int b)
{
	return a*b;
}
int div4(int a, int b)
{
	if(b==0)
		return a;
	return a/b;
}