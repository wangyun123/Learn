
#include <stdio.h>
#include <windows.h>

BOOL APIENTRY DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved)
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		printf("[1] library3 entry point!\n");
		printf("[1] Initialize once for each new process.\n");
		//printf("Return FALSE to fail DLL load.\n");
		break;
	case DLL_THREAD_ATTACH:
		printf("Do thread-specific initialization.\n");
		break;
	case DLL_PROCESS_DETACH:
		printf("Do thread-specific cleanup.\n");
		break;
	case DLL_THREAD_DETACH:
		printf("Perform any necessary cleanup.\n");
		break;
	}
    return TRUE;
}