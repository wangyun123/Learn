#include <windows.h>
#include <stdio.h>

//1>MSVCRTD.lib(crtexew.obj) : error LNK2019: 无法解析的外部符号 _WinMain@16，该符号在函数 ___tmainCRTStartup 中被引用
// 1>D:\Learn\LearnOSG\LearnWin32\test\Debug\testThread.exe : fatal error LNK1120: 1 个无法解析的外部命令
#include <tchar.h>
#include "resource.h"

/*
*	注：线程的终止有三种：
*	1） ExitThread()
*	    优点：安全的。代码会等待线程结束后，再执行主进程的下一行代码
*		缺点：只能在线程内部使用该函数，（即，在 ThreadProc函数中使用）
*	    
*	2) 线程执行完成，安全的。
*	    优点：安全的。代码会等待线程结束
*		缺点：只能等待线程自己运行完成
*
*	3) TerminateThread(),不安全的。可在其他线程中终止指定线程
*	   特点：CPU不会等待线程结束再执行下一行代码。需要使用WaitForSingleObject()来等待线程结束。
*
*/
DWORD nCount=1000;
HWND hEdit=NULL;		// 编辑框
HANDLE hThread=NULL;	// 线程句柄

// 对话框的消息响应函数
BOOL CALLBACK MainDlgProc(HWND   hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 线程1 函数
DWORD WINAPI ThreadProc1(LPVOID lpParameter);
// 线程2 函数
DWORD WINAPI ThreadProc2(LPVOID lpParameter);
// 线程3 函数
DWORD WINAPI ThreadProc3(LPVOID lpParameter);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	printf("hInstance=\t %x\n", hInstance);
	printf("hPrevInstance=\t %x\n", hPrevInstance);
	printf("lpCmdLine=\t %s\n", lpCmdLine);
	printf("nCmdShow=\t %d\n", nCmdShow);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, MainDlgProc);
	return 0;
}

BOOL CALLBACK MainDlgProc(HWND   hwndDlg,
	UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		{
			hEdit= GetDlgItem(hwndDlg, IDC_EDIT_COUNT);
			LPCTSTR str=L"1000";
			SetWindowText(hEdit, str);
			break;
		}
	case WM_CLOSE:
		{
			::EndDialog(hwndDlg, 0);
			break;
		}
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case IDC_BUTTON_START:
				{
					LPDWORD lpThreadId=NULL;
					hThread = ::CreateThread(NULL, 0, ThreadProc1, NULL, 0,lpThreadId);
					// 获取context
					CONTEXT context;
					context.ContextFlags = CONTEXT_CONTROL;
					::GetThreadContext(hThread, &context);
					break;
				}
			case IDC_BUTTON_SUSPEND:
				{
					::SuspendThread(hThread);
				}
				break;
			case IDC_BUTTON_RESUME:
				{
					::ResumeThread(hThread);
				}
				break;
			case IDC_BUTTON_EXIT:
				{
					// [结束线程方式 3] 在其他线程中结束指定线程
					::TerminateThread(hThread, 2);
					::WaitForSingleObject(hThread, INFINITE);
				}
				break;
			}
			break;
		}
	}
	return 0;
}

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	while(nCount>0)
	{
		if (nCount == 950)
		{
			// [结束线程方式 1] 通过条件判断来结束线程运行
			ExitThread(2);
		}
		TCHAR str[10];
		memset(str, 0, sizeof(TCHAR)*10);
		// sprintf与wprintf的区别
		swprintf(str, L"%d", --nCount);
		Sleep(200);
		SetWindowText(hEdit, str);
	}

	// [结束线程方式 2]正常等待线程运行结束
	return 0;
}

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	int i;
	while(i>10)
	{
// 		printf();
		Sleep(200);
	}

	// [结束线程方式 2]正常等待线程运行结束
	return 0;
}