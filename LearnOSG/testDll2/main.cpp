#include <stdio.h>

#include "../DynamicLibrary1/Func1.h"

#ifdef _DEBUG
#pragma comment(lib, "../debug/DynamicLibrary1.lib")
#else
#pragma comment(lib, "../release/DynamicLibrary1.lib")
#endif

int main(int argc, char* argv[])
{
	printf("this is load-time library!\n");
	int result = div1(1,2);
	printf("the function is div, %d\n", result);
	getchar();
	return 0;
}