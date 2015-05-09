////////////////////////////////////////////////////////////////////////////////
// Filename: main.cpp
////////////////////////////////////////////////////////////////////////////////
#include "SystemClass.h"

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	bool result;

	SystemClass& System = SystemClass::GetInstance();

	// Initialize and run the system object.
	result = System.Initialize();
	if (result)
	{
		System.Run();
	}


	//Jag vet vart din brevlåda bor.
	// Jag vet vart DU bor.
	// Spelet vet vart du bor.

	// Shutdown and release the system object.
	System.Shutdown();

	return 0;
}