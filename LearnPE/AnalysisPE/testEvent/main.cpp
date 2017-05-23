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
DWORD WINAPI ThreadProcWrite(LPVOID lpParameter);
// ??1 ??
DWORD WINAPI ThreadProcRead1(LPVOID lpParameter);
// ??2 ??
DWORD WINAPI ThreadProcRead2(LPVOID lpParameter);
// ??3 ??
DWORD WINAPI ThreadProcRead3(LPVOID lpParameter);

int APIENTRY _tWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, MainDlgProc);
	return 0;
}

// main thread
DWORD WINAPI ThreadProcWrite(LPVOID lpParameter)
{
	int i=0;
	while(i<100)
	{
// 		i ++;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", ++i);
		SetWindowText(hEditTotal, buffer);
		Sleep(500);
	}
	return 0;
}
DWORD WINAPI ThreadProcRead1(LPVOID lpParameter)
{
	int i=0;
	while(i<100)
	{
		// 		i ++;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", ++i);
		SetWindowText(hEditT1, buffer);
		Sleep(500);
	}
	
	return 0;
}
DWORD WINAPI ThreadProcRead2(LPVOID lpParameter)
{
	int i=0;
	while(i<100)
	{
		// 		i ++;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", ++i);
		SetWindowText(hEditT2, buffer);
		Sleep(500);
	}

	return 0;
}
DWORD WINAPI ThreadProcRead3(LPVOID lpParameter)
{
	int i=0;
	while(i<100)
	{
		// 		i ++;
		TCHAR buffer[10];
		memset(buffer, 0, sizeof(TCHAR)*10);
		sprintf(buffer, "%d", ++i);
		SetWindowText(hEditT3, buffer);
		Sleep(500);
	}

	return 0;
}

BOOL CALLBACK MainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(LOWORD(uMsg))
	{
	case WM_INITDIALOG:
		{
			hEditTotal = GetDlgItem(hwndDlg, IDC_EDIT_WRITE);
			hEditT1 = GetDlgItem(hwndDlg, IDC_EDIT_READ_1);
			hEditT2 = GetDlgItem(hwndDlg, IDC_EDIT_READ_2);
			hEditT3 = GetDlgItem(hwndDlg, IDC_EDIT_READ_3);
			LPCTSTR str="0";
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
			case IDC_BUTTON_START:
				{
// 					LPDWORD lpThreadId=NULL;
					hMainThread = ::CreateThread(NULL, 0, ThreadProcWrite, NULL, 0, NULL);
					WaitForSingleObject(hMainThread, INFINITE);

					hThread1 = ::CreateThread(NULL, 0, ThreadProcRead1, NULL, 0, NULL);
					hThread2 = ::CreateThread(NULL, 0, ThreadProcRead2, NULL, 0, NULL);
					hThread3 = ::CreateThread(NULL, 0, ThreadProcRead3, NULL, 0, NULL);

					CloseHandle(hMainThread);
					CloseHandle(hThread1);
					CloseHandle(hThread2);
					CloseHandle(hThread3);
					break;
				}
			}
			break;
		}
	}
	return 0;
}
