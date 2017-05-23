// 79课 课后作业之抢红包 2017-04-17
// by wangyun 
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include "resource.h"

HWND hEditTotal=NULL;
HWND hEditT1=NULL;
HWND hEditT2=NULL;
HWND hEditT3=NULL;

HANDLE hMainThread;
HANDLE hThread1;
HANDLE hThread2;
HANDLE hThread3;

CRITICAL_SECTION cs;
int nCount=100;

BOOL CALLBACK MainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

// main thread
DWORD WINAPI MainThreadProc(LPVOID lpParameter);
// ??1 ??
DWORD WINAPI ThreadProc1(LPVOID lpParameter);
// ??2 ??
DWORD WINAPI ThreadProc2(LPVOID lpParameter);
// ??3 ??
DWORD WINAPI ThreadProc3(LPVOID lpParameter);

int APIENTRY _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	InitializeCriticalSection(&cs);

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, MainDlgProc);
	return 0;
}

BOOL CALLBACK MainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(LOWORD(uMsg))
	{
	case WM_INITDIALOG:
		{
			hEditTotal = GetDlgItem(hwndDlg, IDC_EDIT_TOTAL);
			hEditT1 = GetDlgItem(hwndDlg, IDC_EDIT_T1);
			hEditT2 = GetDlgItem(hwndDlg, IDC_EDIT_T2);
			hEditT3 = GetDlgItem(hwndDlg, IDC_EDIT_T3);
			LPCTSTR str="100";
			SetWindowText(hEditTotal, str);
			LPCTSTR str1="0";
			SetWindowText(hEditT1, str1);
			SetWindowText(hEditT2, str1);
			SetWindowText(hEditT3, str1);
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
			case IDC_BUTTON1:
				{
					LPDWORD lpThreadId=NULL;
					hMainThread = ::CreateThread(NULL, 0, MainThreadProc, NULL, 0,lpThreadId);

					break;
				}
			}
			break;
		}
	}
	return 0;
}

// main thread
DWORD WINAPI MainThreadProc(LPVOID lpParameter)
{
	hThread1 = ::CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	hThread2 = ::CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
	hThread3 = ::CreateThread(NULL, 0, ThreadProc3, NULL, 0, NULL);

	return 0;
}

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	while (nCount > 0)
	{
		EnterCriticalSection(&cs);
		nCount --;
		LeaveCriticalSection(&cs);

		// thread 1
		DWORD cout;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		GetWindowText(hEditT1, buffer, 10);
		sscanf(buffer, "%d", &cout);
		cout ++;
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", cout);
		SetWindowText(hEditT1, buffer);

		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", nCount);
		SetWindowText(hEditTotal, buffer);

		Sleep(55);

	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	while (nCount > 0)
	{
		EnterCriticalSection(&cs);
		nCount --;
		LeaveCriticalSection(&cs);
		
		// thread 1
		DWORD cout;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		GetWindowText(hEditT2, buffer, 10);
		sscanf(buffer, "%d", &cout);
		cout ++;
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", cout);
		SetWindowText(hEditT2, buffer);

		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", nCount);
		SetWindowText(hEditTotal, buffer);

		Sleep(151);

	}
	return 0;
}

DWORD WINAPI ThreadProc3(LPVOID lpParameter)
{
	while (nCount > 0)
	{
		EnterCriticalSection(&cs);
		nCount --;
		LeaveCriticalSection(&cs);
	
		// thread 1
		DWORD cout;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		GetWindowText(hEditT3, buffer, 10);
		sscanf(buffer, "%d", &cout);
		cout ++;
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", cout);
		SetWindowText(hEditT3, buffer);

		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", nCount);
		SetWindowText(hEditTotal, buffer);

		Sleep(92);

	}
	return 0;
}
/*
DWORD WINAPI ThreadProc3(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	// total
	TCHAR buffer[10];
	memset(buffer, 0, sizeof(TCHAR)*10);
	GetWindowText(hEditTotal, buffer, 10);
	DWORD cout;
	sscanf(buffer, "%d", &cout);
	
	cout --;
	
	memset(buffer, 0, sizeof(TCHAR)*10);
	sprintf(buffer, "%d", cout);
	SetWindowText(hEditTotal, buffer);
	
	// thread 1
	memset(buffer, 0, sizeof(TCHAR)*10);
	GetWindowText(hEditT3, buffer, 10);
	
	sscanf(buffer, "%d", &cout);
	cout ++;
	
	memset(buffer, 0, sizeof(TCHAR)*10);
	sprintf(buffer, "%d", cout);
	SetWindowText(hEditT3, buffer);
	
	
	Sleep(300);
	LeaveCriticalSection(&cs);
	
	return 0;
}*/