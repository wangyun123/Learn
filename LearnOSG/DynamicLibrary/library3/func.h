#ifndef _MY_LIBRARY3_H_
#define _MY_LIBRARY3_H_

#define TEST_LIBRARY3

#ifdef TEST_LIBRARY3
#define TEST_LIBRARY_API __declspec(dllexport)
#else
#define TEST_LIBRARY_API __declspec(dllimport)
#endif

extern "C" TEST_LIBRARY_API int add3(int a, int b);
extern "C" TEST_LIBRARY_API int sub3(int a, int b);
extern "C" TEST_LIBRARY_API int mul3(int a, int b);
extern "C" TEST_LIBRARY_API int div3(int a, int b);

#endif //_MY_LIBRARY3_H_