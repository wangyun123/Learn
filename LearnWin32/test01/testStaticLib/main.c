/*
 * ʵ��C���Ե���C/C++��̬��
 *
 * 
*/

#include <stdio.h>

// ʵ�ֶ�C���Ծ�̬��ĵ���
#pragma comment(lib, "../clib/debug/clib.lib")
// ʵ�ֶ�C++��̬��ĵ���
#pragma comment(lib, "../cpplib/debug/cpplib.lib")

int main(int argc, char* argv[])
{
	// C���Ե��ÿ�ʱ����Ҫͷ�ļ�����ֱ����lib�ļ�Ѱ�Һ���ʵ��
	int x = add1(1,2);
	int y = sub1(1,2);
	printf("c result: %d, %d\n", x, y);

	// �ڲ��޸Ŀ��ļ�������£���ʱ�޷�ʵ��C����C++��
// 	x = add2(6,2);
// 	y = sub2(6,2);
// 	printf("c++ result: %d, %d\n", x, y);

	return 0;
}