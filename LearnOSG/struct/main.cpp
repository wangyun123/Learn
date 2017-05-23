#include <stdio.h>
#include "struct.h"

//////////////////////////////////////[1]////////////////////////////////////
// 1、该定义中Struct1为一个结构体的类型名
// 可用于定义变量，如 Struct1 st;
struct Struct1
{
	int a;
	char b;
};
// 2、该定义中Struct2为一个包含两个数据的结构体变量
// Struct2本身为一个全局的结构体变量
struct
{
	int a;
	char b;
}Struct2;

////////////////////////////////////////[2]//////////////////////////////////
//1、空结构体
struct Student1{

};
//2、带两个变量的结构体
struct Student2{
	int a;
	int b;
};
//3、带一个成员函数的结构体
struct Student3{
	void func()
	{

	}
};
//4、带两个变量，一个成员函数的结构体
struct Student4{
	int a;
	int b;
	void func()
	{
		a=1;
		b=2;
		printf("this: %x\n", this);
	}
};

//////////////////////////////////////////[3]////////////////////////////////
// 第一种：只有结构体定义
struct Stuff1{  
	char job;//[20];  
	int age;  
	float height;  
}; 

// 第二种：附加该结构体类型的“结构体变量”的初始化的结构体定义
// 直接带变量名Huqinwei  
struct Stuff2{  
	char job;//[20];  
	int age;  
	float height;  
}Huqinwei2;

// 第三种：等同于第二种定义方式
struct Stuff3{  
	char job;//[20];  
	int age;  
	float height;  
};  
struct Stuff3 Huqinwei3;

// 第四种：结构体定义别名（同义词），用于其他文件使用该结构体定义
typedef struct {  
	char job;//[20];  
	int age;  
	float height;  
}Stuff4;


// 测试结构体定义
void testStructDefine();
// 测试结构体赋值
void testStructAssign();

int main(int argc, char* argv[])
{
#if 0
	printf("size of student1:%d\n", sizeof(Student1));
	printf("size of student2:%d\n", sizeof(Student2));
	printf("size of student3:%d\n", sizeof(Student3));
	printf("size of student4:%d\n", sizeof(Student4));

	Student1 st1;
	Student2 st2;
	Student2 st3 = {0};
	st2.a=10;
	st2.b=11;
	Student3 st3;
	Student4 st4;
	st4.func();
#endif

#if 0
	printf("the size of struct: %d\n", sizeof(Struct1));
	printf("the size of struct: %d\n", sizeof(Struct2));

	Struct1 s1;
	s1.a = 0x12345678;
	s1.b = 0x11;

	Struct2.a = 0x12345678;
	Struct2.b = 0x11;

	printf("the address of struct: %x\n", &s1);
	printf("the value of struct: %x\n", s1);
	printf("the address of struct: %x\n", &Struct2);
	printf("the value of struct: %x\n", Struct2);
#endif

#if 1
	testStructDefine();
	testStructAssign();
#endif

	return 0;
}

// 测试结构体定义
void testStructDefine()
{
	printf("the size of struct: %d\n", sizeof(Stuff1));
	printf("the size of struct: %d\n", sizeof(Stuff2));

	struct Stuff1 s1;
	s1.job = 0x61;
	s1.age = 21;
	s1.height = 180.0;

	Huqinwei2.job = 0x62;
	Huqinwei2.age = 22;
	Huqinwei2.height = 180.0;

	Stuff4 s4;
	s1.job = 0x64;
	s1.age = 24;
	s1.height = 180.0;

	printf("the address of struct: %x\n", &s1);
	printf("the value of struct: %x\n", s1);
	printf("the address of struct: %x\n", &Huqinwei2);
	printf("the value of struct: %x\n", Huqinwei2);

}
// 测试结构体赋值
void testStructAssign()
{
	struct Stuff1 s1 = {0x61, 30, 180.0};
	// 此处应该是编译器默认的构造函数
	struct Stuff1 s2 = s1; 
	// 此处变量Huqinwei2与全局变量Huqinwei2同名，竟然编译通过了！！
	// 该变量在ss栈中，而全局变量在ds堆中
	// 个人感觉：变量名的访问次序，先找栈中的，如果找不到就找全局变量堆中！！！
	printf("global: [%x] %c, %d, %f\n", &Huqinwei2, Huqinwei2.job, Huqinwei2.age, Huqinwei2.height);
	struct Stuff2 Huqinwei2 = {0x63, 30, 180.0};
	printf("local : [%x] %c, %d, %f\n", &Huqinwei2, Huqinwei2.job, Huqinwei2.age, Huqinwei2.height);
}
