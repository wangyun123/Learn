#ifndef _MY_FUNC_3_H_
#define _MY_FUNC_3_H_

#ifdef DYNLIBRARY3_EXPORTS
#define DYN_LIBRARY_API extern "C" __declspec(dllexport)
#else
#define DYN_LIBRARY_API extern "C" __declspec(dllimport)
#endif

DYN_LIBRARY_API int add3(int a, int b);
DYN_LIBRARY_API int sub3(int a, int b);
DYN_LIBRARY_API int mul3(int a, int b);
DYN_LIBRARY_API int div3(int a, int b);

#endif