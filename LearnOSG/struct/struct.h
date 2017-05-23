/*
*	参考：http://blog.csdn.net/huqinwei987/article/details/23625823
*
*	结构体定义
*
*/

#ifndef _STRUCT_CUSTOM_H_
#define _STRUCT_CUSTOM_H_


// 第一种：只有结构体定义
struct stuff01{  
	char job;//[20];  
	int age;  
	float height;  
}; 

typedef struct {  
	char job;//[20];  
	int age;  
	float height;  
}stuff04;

// 以下两种方式定义，发生编译错误，不知道什么原因？？
// 1>struct.obj : error LNK2005: "struct stuff03 Huqinwei03" (?Huqinwei03@@3Ustuff03@@A) 已经在 main.obj 中定义
// 1>D:\Learn\LearnOSG\Debug\struct.exe : fatal error LNK1169: 找到一个或多个多重定义的符号
#if 0
// 第二种：附加该结构体类型的“结构体变量”的初始化的结构体定义
// 直接带变量名Huqinwei  
struct stuff02{  
	char job;//[20];  
	int age;  
	float height;  
}Huqinwei02;

// 等同于第二种定义方式
struct stuff03{  
	char job;//[20];  
	int age;  
	float height;  
};  
struct stuff03 Huqinwei03;
#endif

// 测试结构体定义
void testDefine();
// 测试结构体赋值
void testAssign();

#endif //_STRUCT_CUSTOM_H_