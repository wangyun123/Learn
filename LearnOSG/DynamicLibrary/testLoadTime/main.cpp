#include <stdio.h>
#include "../library1/func.h"

#ifdef _DEBUG
#pragma comment(lib, "../library1/debug/library1.lib")
#else
#pragma comment(lib, "../library1/release/library1.lib")
#endif

int main(int argc, char* argv[])
{
	printf("this is the Load-time!\n");
	int result = div1(1,2);
	printf("the result is :%d\n", result);

	return 0;
}