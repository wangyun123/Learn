#include <stdio.h>
#include "library01.h"

int add(int a, int b)
{
	return a+b;
}
int sub(int a, int b)
{
	return a-b;
}
int mul(int a, int b)
{
	return a*b;
}

int main(int argc, char* argv[])
{
	printf("library01: this is exe file!");

	return 0;
}
