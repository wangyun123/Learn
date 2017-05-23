// library2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("Initialize once for each new process.\n");
		printf("Return FALSE to fail DLL load.\n");
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

