// DynLibrary3.cpp : Defines the entry point for the DLL application.
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
		{
			printf("The DLL is being mapped into the process's address space.\n");
			break;
		}
	case DLL_THREAD_ATTACH:
		{
			printf("A thread is being created.\n");
			break;
		}
	case DLL_THREAD_DETACH:
		{
			printf("A thread is existing cleanly.\n");
			break;
		}
	case DLL_PROCESS_DETACH:
		{
			printf("The DLL is being unmapped from the process's address space.\n");
			break;
		}
	}

    return TRUE;
}

