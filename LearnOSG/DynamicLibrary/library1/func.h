#ifndef _MY_LIBRARY1_H_
#define _MY_LIBRARY1_H_

int add1(int a, int b);
extern "C" int sub1(int a, int b);
__declspec(dllexport) int mul1(int a, int b);
extern "C" __declspec(dllexport) int div1(int a, int b);

#endif