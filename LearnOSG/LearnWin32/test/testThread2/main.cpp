#include <stdio.h>
#include <Windows.h>

HANDLE hThread1 = NULL;
HANDLE hThread2 = NULL;
HANDLE hThread3 = NULL;
CRITICAL_SECTION cs;

DWORD WINAPI ThreadProc1(LPVOID lpParameter);
DWORD WINAPI ThreadProc2(LPVOID lpParameter);
DWORD WINAPI ThreadProc3(LPVOID lpParameter);

int main(int argc, char* argv[])
{
	InitializeCriticalSection(&cs);

	hThread1 = ::CreateThread(NULL, 0, ThreadProc1, NULL, 0,NULL);
	hThread2 = ::CreateThread(NULL, 0, ThreadProc2, NULL, 0,NULL);
	hThread3 = ::CreateThread(NULL, 0, ThreadProc3, NULL, 0,NULL);

// 	WaitForSingleObject(hThread1, INFINITE);
// 
// 	MessageBox(NULL, L"thread", 0, 0);
	getchar();
	return 0;
}

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	for (int i=0; i<20; i++)
	{
		EnterCriticalSection(&cs);
		printf("thread 1: %x %x %x\n", cs.LockCount, cs.RecursionCount, cs.OwningThread);
		Sleep(800);
		LeaveCriticalSection(&cs);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	for (int i=0; i<20; i++)
	{
		EnterCriticalSection(&cs);
		printf("thread 2: %x %x %x\n", cs.LockCount, cs.RecursionCount, cs.OwningThread);
		Sleep(700);
		LeaveCriticalSection(&cs);
	}
	return 0;
}

DWORD WINAPI ThreadProc3(LPVOID lpParameter)
{
	for (int i=0; i<20; i++)
	{
		EnterCriticalSection(&cs);
		printf("thread 3: %x %x %x\n", cs.LockCount, cs.RecursionCount, cs.OwningThread);
		Sleep(600);
		LeaveCriticalSection(&cs);
	}
	return 0;
}