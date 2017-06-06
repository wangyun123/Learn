#include <stdio.h>

// #define STATIC_LINK

#ifdef STATIC_LINK
#include "./DynLibrary1/func1.h"
#pragma comment(lib, "./DynLibrary1/Debug/DynLibrary1.lib")
#else
// #include "./DynLibrary2/func2.h"
#endif

int main(int argc, char* argv[])
{
#ifdef STATIC_LINK
	printf("this is the dynamic link library, the call 1!\n");
	int r1 = add(1,2);
	int r2 = sub(1,2);
	int r3 = mul(1,2);
	int r4 = div(1,2);
#else
	printf("this is the dynamic link library, the call 2!\n");
#endif
	return 0;
}