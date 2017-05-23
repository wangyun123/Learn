// win32_chapter68.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include <Winnt.h>

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	int i=10;
	OutputDebugStringA("hello world!\n");
	OutputDebugStringF("中国 %d\n", i);
	OutputDebugStringW(L"中国\n");

	return 0;
}
