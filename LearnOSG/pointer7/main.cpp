#include <stdio.h>

void func1()
{
	int arr[18] = {
		1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18
	};

	int (*px)[3];
	//px = (int (*)[3])10;
	px = (int (*)[3])arr;

// 	printf("%d\n", sizeof(px));
// 	printf("%d\n", px);
// 	px++;
// 	printf("%d\n", px);
// 	printf("%d\t%d\n", px, px++);
// 	printf("%d\t%d\n", *px, ((*px)++));
	printf("%d\n", px[1][2]);
	printf("%d\n", (*(px+1))[2]);
}

void func2()
{
	int arr[16] = {
		1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
	};

	int* px[2];
	// error C2440: “=”: 无法从“int”转换为“int *[2]”
	//px = (int *[2])10;
	//px=(int *[2])arr;
	px[0] = (int*)20;
	px[1] = (int*)30;

	printf("%d\n", sizeof(px));
	printf("%d\n", px);
// 	px = px+1;
	printf("%d\n", px+1);

}
struct Student{
	int a;
	char b;
	short c;
	short d;
};

int main(int argc, char* argv[])
{
// 	func1();
// 	func2();
	Student stu;
	stu.a = 11;
	stu.b = 12;
	stu.c = 13;
	stu.d = 14;

	printf("%d\n", sizeof(Student));
	printf("%d\n", sizeof(stu));

	return 0;
}