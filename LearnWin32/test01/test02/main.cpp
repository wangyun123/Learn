#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	LPCTSTR lpszClassName = __TEXT("MyWindowClass");
	LPCTSTR lpszWindowName = __TEXT("WindowsTitle");
	// 1. ����WND���ݽṹ
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
	
	// 2. ע�ᴰ��
	RegisterClassEx(&wce);
	
	// 3. ����������
	HWND hWnd = CreateWindowEx(0, lpszClassName, lpszWindowName, 
		WS_OVERLAPPEDWINDOW, 50, 50, 300, 200, NULL, NULL, hInstance, NULL);
	
	// 4. ���Ƽ����´���
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	
	// 5. ��Ϣѭ��
	MSG uMsg = {0};
	while (GetMessage(&uMsg, NULL, NULL, NULL))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	
	return 0;
}