/*
* 
* ��̬���ӿ� library2 
*
* 1���������������Ķ�̬��
*
*/

// �ú���û����������
int add2(int a, int b)
{
	return a+b;
}

// �ú�������������, C++���������䵼��������Ϊ?sub2@@YAHHH@Z
__declspec(dllexport) int sub2(int a, int b)
{
	return a-b;
}
// �ú�������������, C++������������ΪC�������䵼����Ϊmul2���붨��һ��
extern "C" __declspec(dllexport) int mul2(int a, int b)
{
	return a*b;
}

// ���Ժ�������
__declspec(dllexport) int overfunc(int a, int b)
{
	return a+b;
}
__declspec(dllexport) float overfunc(float a, float b)
{
	return a+b;
}