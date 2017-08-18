/*
* 
* 动态链接库 library1 
*
* 1、采用模块定义文件导出的动态库
*
*/

int add1(int a, int b)
{
	return a+b;
}

int sub1(int a, int b)
{
	return a-b;
}

// 测试函数重载
int overfunc(int a, int b)
{
	return a+b;
}
float overfunc(float a, float b)
{
	return a+b;
}