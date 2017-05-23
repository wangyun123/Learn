// ProcessInfo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Resource.h"

BOOL CALLBACK MainDlgProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_PROCESSINFO), NULL, MainDlgProc);
	return 0;
}

BOOL CALLBACK MainDlgProc(HWND   hwndDlg, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

