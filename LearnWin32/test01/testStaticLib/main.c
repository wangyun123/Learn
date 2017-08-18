/*
 * 实现C语言调用C/C++静态库
 *
 * 
*/

#include <stdio.h>

// 实现对C语言静态库的调用
#pragma comment(lib, "../clib/debug/clib.lib")
// 实现对C++静态库的调用
#pragma comment(lib, "../cpplib/debug/cpplib.lib")

int main(int argc, char* argv[])
{
	// C语言调用库时不需要头文件，其直接在lib文件寻找函数实现
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("c result: %d, %d\n", x, y);

	// 在不修改库文件的情况下，暂时无法实现C调用C++库
// 	x = add2(6,2);
// 	y = sub2(6,2);
// 	printf("c++ result: %d, %d\n", x, y);

	return 0;
}