/*
 * ʵ��C++���Ե���C/C++��̬��
 *
 * C++�����ǵ���C��C++��д�ľ�̬�⣬
 * ��������ǰ�����������ƣ�
 * ���������Է��ھ�̬�⹤���У�Ҳ���Է��ڵ����߹�����
*/

#include <stdio.h>

// [1] C++����C���Ծ�̬��
// ע: extern "C" ���߱�������������ΪC���Ա�д�ĺ���
// C++�������Ὣ����ǰ�����һЩ���η������ڽ��������������
extern "C" int add1(int, int);
extern "C" int sub1(int, int);
#pragma comment(lib, "../clib/debug/clib.lib")

// [2] C++����C++��̬��
int add2(int, int);
int sub2(int, int);
#pragma comment(lib, "../cpplib/debug/cpplib.lib")

// [3]  C++����C��̬��
// ע: __declspec(dllimport)���߱�������Ҫ����ʲô����
extern "C" __declspec(dllimport) int cDynLib_add(int, int);
extern "C" __declspec(dllimport) int cDynLib_sub(int, int);
#pragma comment(lib, "../cDynLib/debug/cDynLib.lib")

// [4]  C++����C++��̬��
__declspec(dllimport) int cppDynLib_add(int, int);
#pragma comment(lib, "../cppDynLib/debug/cppDynLib.lib")

int main(int argc, char* argv[])
{
	// [1] ����C���Ծ�̬��
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("c result: %d, %d\n", x, y);
	
	// [2] ����C++��̬��
	x = add2(6,2);
	y = sub2(6,2);
	printf("c++ result: %d, %d\n", x, y);

	// [3] ����C��̬��
	x = cDynLib_add(8,9);
	y = cDynLib_sub(18,9);
	printf("cDynLib_add: %d, %d\n", x, y);

	// [4] ����C++��̬��
	x = cppDynLib_add(18,9);
	printf("cppDynLib_add: %d, %d\n", x, y);

	return 0;
}