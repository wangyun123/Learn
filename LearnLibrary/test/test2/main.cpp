/*
 * 2a那??‘足??a米?米¯車? ﹞?那?2
 */

#include <stdio.h>
#include <windows.h>

#define STATIC_LINK

#ifdef STATIC_LINK
#include "../DynLibrary2/func2.h"
#pragma comment(lib, "../DynLibrary2/Debug/DynLibrary2.lib")
#endif

int main(int argc, char* argv[])
{
#ifdef STATIC_LINK
	printf("this is the dynamic link library, the call 1!\n");
	printf("Function of add: %d\n", add2(1,2));
	printf("Function of sub: %d\n", sub2(1,2));
	printf("Function of mul: %d\n", mul2(1,2));
// 	printf("Function of div: %d\n", alias1(1,2));
// 	printf("Function of div: %d\n", func3(1,2));

#else
	printf("this is the dynamic link library, the call 2!\n");
	HMODULE hModule = LoadLibrary("../dynLibrary2/Debug/dynLibrary2.dll");
	printf("the library address: %x\n", hModule);
	if (hModule == NULL)
	{
		printf("the load library error!\n");
		return 0;
	}
	
	typedef int (*Func)(int, int);
	// [1] 角?車?o‘那y??3???豕??‘足??a米?3?o‘那y米??﹞
	Func add = (Func)GetProcAddress(hModule, "add2");
	printf("Address of add: %x\n", add);
	if (add == NULL)
		printf("GetProcAddress add function error!\n");
	else
		printf("Function of add: %d\n", add(1,2));
	
	// [2] 角?車?o‘那yD辰o???豕??‘足??a米?3?o‘那y米??﹞
	Func sub = (Func)GetProcAddress(hModule, (LPCTSTR)0x000D);
	if (sub == NULL)
		printf("GetProcAddress sub function error!\n");
	else	
		printf("Function of sub: %d\n", sub(1,2));

	// [3] 角?車?o‘那yD辰o???豕??‘足??a米?3?o‘那y米??﹞ ∩?o‘那y?T??3? mul2 @ 16 NONAME
	Func mul = (Func)GetProcAddress(hModule, (LPCTSTR)0x0010);
	if (mul == NULL)
		printf("GetProcAddress mul function error!\n");
	else	
		printf("Function of mul: %d\n", mul(1,2));

	// [4] 角?車?o‘那y??3???豕??‘足??a﹞?米?3?o‘那y米??﹞ 那∫～邦
	Func func3 = (Func)GetProcAddress(hModule, "func3");
	if (func3 == NULL)
		printf("GetProcAddress func3 function error!\n");
	else
		printf("Function of func3: %d\n", func3(1,2));

	
	// [5] 角?車???㊣角?Do‘那yRVA??豕??‘足??a﹞?米?3?o‘那y米??﹞ 3谷1|
	Func func4 = (Func)((DWORD)hModule+0x1023);
	if (func4 == NULL)
		printf("GetProcAddress mul function error!\n");
	else	
		printf("Function of func4: %d\n", func4(1,2));

#endif
	getchar();

	return 0;
}