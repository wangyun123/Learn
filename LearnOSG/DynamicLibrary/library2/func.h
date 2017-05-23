#ifndef _MY_LIBRARY2_H_
#define _MY_LIBRARY2_H_

#define TEST_LIBRARY

#ifdef TEST_LIBRARY
#define TEST_LIBRARY_API __declspec(dllexport)
#else
#define TEST_LIBRARY_API __declspec(dllimport)
#endif

extern "C" TEST_LIBRARY_API int add2(int a, int b);
extern "C" TEST_LIBRARY_API int sub2(int a, int b);
extern "C" TEST_LIBRARY_API int mul2(int a, int b);
extern "C" TEST_LIBRARY_API int div2(int a, int b);

#endif //_MY_LIBRARY2_H_