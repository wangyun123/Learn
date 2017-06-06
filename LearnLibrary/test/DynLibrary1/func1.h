#ifndef _MY_FUNC_1_H_
#define _MY_FUNC_1_H_

#ifdef DYNLIBRARY1_EXPORTS
#define DYN_LIBRARY_API __declspec(dllexport)
#else
#define DYN_LIBRARY_API __declspec(dllimport)
#endif

int DYN_LIBRARY_API add(int a, int b);
int DYN_LIBRARY_API sub(int a, int b);
int DYN_LIBRARY_API mul(int a, int b);
int DYN_LIBRARY_API div(int a, int b);

#endif