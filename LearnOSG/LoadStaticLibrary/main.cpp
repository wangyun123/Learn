#include <stdio.h>

#include "../staticLibrary1/lib.h"

#ifdef _DEBUG
#pragma comment(lib, "../debug/staticLibrary1.lib")
#else
#pragma comment(lib, "../release/staticLibrary1.lib")
#endif

int main(int argc, char* argv[])
{
	printf("loading the static library!\n");
	int result;
	result = add(10,20);
	printf("result=%d\n", result);

	getchar();
	return 0;
}