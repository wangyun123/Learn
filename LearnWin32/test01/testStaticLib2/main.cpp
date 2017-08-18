/*
 * 实现C++语言调用C/C++静态库
 *
 * C++无论是调用C或C++编写的静态库，
 * 都必须提前申明函数名称，
 * 该申明可以放在静态库工程中，也可以放在调用者工程中
*/

#include <stdio.h>

// [1] C++调用C语言静态库
// 注: extern "C" 告诉编译器以下申明为C语言编写的函数
// C++编译器会将函数前后添加一些修饰符，用于解决函数重载问题
extern "C" int add1(int, int);
extern "C" int sub1(int, int);
#pragma comment(lib, "../clib/debug/clib.lib")

// [2] C++调用C++静态库
int add2(int, int);
int sub2(int, int);
#pragma comment(lib, "../cpplib/debug/cpplib.lib")

// [3]  C++调用C动态库
// 注: __declspec(dllimport)告诉编译器需要导入什么函数
extern "C" __declspec(dllimport) int cDynLib_add(int, int);
extern "C" __declspec(dllimport) int cDynLib_sub(int, int);
#pragma comment(lib, "../cDynLib/debug/cDynLib.lib")

// [4]  C++调用C++动态库
__declspec(dllimport) int cppDynLib_add(int, int);
#pragma comment(lib, "../cppDynLib/debug/cppDynLib.lib")

int main(int argc, char* argv[])
{
	// [1] 调用C语言静态库
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("c result: %d, %d\n", x, y);
	
	// [2] 调用C++静态库
	x = add2(6,2);
	y = sub2(6,2);
	printf("c++ result: %d, %d\n", x, y);

	// [3] 调用C动态库
	x = cDynLib_add(8,9);
	y = cDynLib_sub(18,9);
	printf("cDynLib_add: %d, %d\n", x, y);

	// [4] 调用C++动态库
	x = cppDynLib_add(18,9);
	printf("cppDynLib_add: %d, %d\n", x, y);

	return 0;
}