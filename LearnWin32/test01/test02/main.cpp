#include <windows.h>
#include "resource.h"

HINSTANCE g_hInstance;

void OnCommand(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK DialogProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		OnCommand(hwnd, uMsg, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	g_hInstance = hInstance;

	LPCTSTR lpszClassName = __TEXT("MyWindowClass");
	LPCTSTR lpszWindowName = __TEXT("WindowsTitle");
	// 1. 创建WND数据结构
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(WNDCLASSEX);
	wce.style = CS_VREDRAW | CS_HREDRAW;
	wce.lpfnWndProc = WindowProc;
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hInstance = hInstance;
	wce.hIcon = NULL;
	wce.hCursor = NULL;
	wce.hbrBackground = HBRUSH(COLOR_WINDOWFRAME);
	wce.lpszMenuName = NULL;
	wce.lpszClassName = lpszClassName;
	wce.hIcon = NULL;
	
	// 2. 注册窗口
	RegisterClassEx(&wce);
	
	// 3. 创建窗口类	
	HMENU hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
	CREATESTRUCT ss={0};
	HWND hWnd = CreateWindowEx(0, lpszClassName, lpszWindowName, 
		WS_OVERLAPPEDWINDOW, 50, 50, 300, 200, NULL, hMenu, hInstance, &ss);
	
	// 4. 绘制及更新窗口
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	
	// 5. 消息循环
	MSG uMsg = {0};
	while (GetMessage(&uMsg, NULL, NULL, NULL))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	
	return 0;
}

void OnCommand(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(LOWORD(wParam))
	{
	case IDM_DIALOG_MODEL:
		// 创建模式对话框
		DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG_MODEL), hwnd, (DLGPROC)DialogProc);
		break;
	case IDM_DIALOG_MODELESS:
		// 创建非模式对话框
		HWND hDlg = CreateDialog(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG_MODEL), hwnd, (DLGPROC)DialogProc2);
		ShowWindow(hDlg, SW_SHOW);
		break;
	}
}

INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE)
			EndDialog(hwnd, 11);
		break;
	}
	return FALSE;
}

INT_PTR CALLBACK DialogProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE)
			DestroyWindow(hwnd);
		break;
	}
	return FALSE;
}
