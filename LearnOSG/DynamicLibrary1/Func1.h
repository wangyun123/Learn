#ifndef LIBRARY_FUNC1_H
#define LIBRARY_FUNC1_H

int add1(int a, int b);
extern "C" int sub1(int a, int b);
__declspec(dllexport) int mul1(int a, int b);
extern "C" __declspec(dllexport) int div1(int a, int b);

#endif //LIBRARY_FUNC1_H