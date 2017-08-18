/*
* 
* 动态链接库 library2 
*
* 1、采用申明导出的动态库
*
*/

// 该函数没法正常导出
int add2(int a, int b)
{
	return a+b;
}

// 该函数能正常导出, C++编译器将其导出名定义为?sub2@@YAHHH@Z
__declspec(dllexport) int sub2(int a, int b)
{
	return a-b;
}
// 该函数能正常导出, C++编译器将其作为C函数，其导出名为mul2，与定义一致
extern "C" __declspec(dllexport) int mul2(int a, int b)
{
	return a*b;
}

// 测试函数重载
__declspec(dllexport) int overfunc(int a, int b)
{
	return a+b;
}
__declspec(dllexport) float overfunc(float a, float b)
{
	return a+b;
}