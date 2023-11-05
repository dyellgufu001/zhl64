#include <cstdio>
#include <fstream>
#include "Overwatch2.h"
#include "HookSystem_private.h"
#include "SigScan.h"

//void __stdcall hook(const char* str) {
//	printf("hooked: %s\n", str);
//	if (internalSuper_testFunc) {
//		const char* newstr = "pidar";
//		printf("changing %s to %s\n", str, newstr);
//		internalSuper_testFunc(newstr);
//	}
//	printf("after super\n");
//}
//
//bool printed = false;
//
//HRESULT hookPresent(IDXGISwapChain* this_arg, UINT syncInterval, UINT flags) {
//	if (!printed) {
//		BOOL isFullscreen;
//		this_arg->GetFullscreenState(&isFullscreen, NULL);
//		printf("fullscreen mode: %s", (isFullscreen) ? "true" : "false");
//		printed = true;
//	}
//	return internalSuper(this_arg, syncInterval, flags);
//}

MOD_EXPORT int ModInit(int argc, char** argv) {
	Definition::Init();
	ZHL::Init();
	printf("x64 zhl is real\n");

	SigScan winMainScanner("44894c24204c89442418488954241048894c2408574881ec");
	winMainScanner.Scan();

	printf("WinMain(): %p\n", winMainScanner.GetAddress());
	/*printf("g_TestString: %ls\n", g_TestString);

	testFunc("message");*/

	return 0;
}