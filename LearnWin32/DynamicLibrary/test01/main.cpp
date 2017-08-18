#include <stdio.h>

// 1. 模块定义文件导出的动态库 C++
int add1(int, int);
int sub1(int, int);
#pragma comment(lib, "../library1/debug/library1.lib")

// 2. 申明导出的动态库 C++
// 函数前的__declspec(dllimport)定义可以省略，但不推荐这样使用
__declspec(dllimport) int sub2(int a, int b);
// 函数前的extern "C"定义不能省略，因为该函数为C语言类型的函数，C++编译会查找?sub2@@YAHHH@Z类似的函数名
extern "C" __declspec(dllimport) int mul2(int a, int b);
#pragma comment(lib, "../library2/debug/library2.lib")

// 3. 结合申明导出和模块定义文件导出的动态库
// 疑问：这种方式编译器无法正常识别导出函数?? 难道只能用显式链接?
// 模块定义文件导出的动态库
int func(int);
int func(int, int);
int func(int, int, int);
// __declspec(dllimport) int func1(int);
// __declspec(dllimport) int func2(int, int);
// __declspec(dllimport) int func3(int, int, int);
#pragma comment(lib, "../library3/debug/library3.lib")

// 4. 调用C语言动态库
extern "C" int add4(int a, int b);
extern "C" int sub4(int a, int b);
#pragma comment(lib, "../library4/debug/library4.lib")

int main(int argc, char* argv[])
{
	// 1. 模块定义文件导出的动态库
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("library1 : %d, %d\n", x, y);

	// 2. 申明导出的动态库
	int x2 = sub2(1,2);
	int y2 = mul2(1,2);
	printf("library2 : %d, %d\n", x2, y2);

	// 3. 结合申明导出和模块定义文件导出的动态库
	int x3 = func(1);
	int y3 = func(1,2);
	int z3 = func(1,2,3);
	printf("library3 : %d, %d, %d\n", x3, y3, z3);
// 	x3 = func1(1);
// 	y3 = func2(1,2);
// 	z3 = func3(1,2,3);
// 	printf("library3 : %d, %d, %d\n", x3, y3, z3);

	// 4. 调用C语言动态库
	int x4 = add4(1,2);
	int y4 = sub4(1,2);
	printf("library4 : %d, %d\n", x4, y4);

	return 0;
}
