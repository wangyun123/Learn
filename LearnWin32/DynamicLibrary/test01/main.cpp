#include <stdio.h>

// 1. ģ�鶨���ļ������Ķ�̬�� C++
int add1(int, int);
int sub1(int, int);
#pragma comment(lib, "../library1/debug/library1.lib")

// 2. ���������Ķ�̬�� C++
// ����ǰ��__declspec(dllimport)�������ʡ�ԣ������Ƽ�����ʹ��
__declspec(dllimport) int sub2(int a, int b);
// ����ǰ��extern "C"���岻��ʡ�ԣ���Ϊ�ú���ΪC�������͵ĺ�����C++��������?sub2@@YAHHH@Z���Ƶĺ�����
extern "C" __declspec(dllimport) int mul2(int a, int b);
#pragma comment(lib, "../library2/debug/library2.lib")

// 3. �������������ģ�鶨���ļ������Ķ�̬��
// ���ʣ����ַ�ʽ�������޷�����ʶ�𵼳�����?? �ѵ�ֻ������ʽ����?
// ģ�鶨���ļ������Ķ�̬��
int func(int);
int func(int, int);
int func(int, int, int);
// __declspec(dllimport) int func1(int);
// __declspec(dllimport) int func2(int, int);
// __declspec(dllimport) int func3(int, int, int);
#pragma comment(lib, "../library3/debug/library3.lib")

// 4. ����C���Զ�̬��
extern "C" int add4(int a, int b);
extern "C" int sub4(int a, int b);
#pragma comment(lib, "../library4/debug/library4.lib")

int main(int argc, char* argv[])
{
	// 1. ģ�鶨���ļ������Ķ�̬��
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("library1 : %d, %d\n", x, y);

	// 2. ���������Ķ�̬��
	int x2 = sub2(1,2);
	int y2 = mul2(1,2);
	printf("library2 : %d, %d\n", x2, y2);

	// 3. �������������ģ�鶨���ļ������Ķ�̬��
	int x3 = func(1);
	int y3 = func(1,2);
	int z3 = func(1,2,3);
	printf("library3 : %d, %d, %d\n", x3, y3, z3);
// 	x3 = func1(1);
// 	y3 = func2(1,2);
// 	z3 = func3(1,2,3);
// 	printf("library3 : %d, %d, %d\n", x3, y3, z3);

	// 4. ����C���Զ�̬��
	int x4 = add4(1,2);
	int y4 = sub4(1,2);
	printf("library4 : %d, %d\n", x4, y4);

	return 0;
}
