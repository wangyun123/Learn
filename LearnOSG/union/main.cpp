#include <stdio.h>

union Union1
{
	int a;
	char b;
};

union
{
	int a;
	char b;
}Union2;

int main(int argc, char* argv[])
{
	printf("the size of union: %d\n", sizeof(Union1));
	printf("the size of union: %d\n", sizeof(Union2));

	Union1 u1;
	u1.a = 0x12345678;

	Union2.a = 0x12345678;

	printf("the value of union: %x\n", u1);
	printf("the value of union: %x\n", Union2);

	return 0;
}