// stdafx.cpp : 只包括标准包含文件的源文件
// win32_chapter68.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"
#include <stdio.h>

// TODO: 在 STDAFX.H 中
// 引用任何所需的附加头文件，而不是在此文件中引用

void __cdecl OutputDebugStringF(const char* format, ...)
{
	va_list vlArgs;
	char *strBuffer = (char*)GlobalAlloc(GPTR, 4096);

	va_start(vlArgs, format);
	_vsnprintf(strBuffer, 4096-1, format, vlArgs);
	va_end(vlArgs);

	strcat(strBuffer, "\n");
	OutputDebugStringA(strBuffer);
	GlobalFree(strBuffer);
	return ;
}