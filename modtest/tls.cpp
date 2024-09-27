#include "Overwatch2.h"
#include "HookSystem_private.h"
#include "SigScan.h"

bool tlsFinished = false;

// HOOK_GLOBAL(TlsCallback_0, (void* hModule, DWORD reason, void* context) -> void, __stdcall) {
    // if (tlsFinished) {
    //     return;
    // }

    // tlsFinished = true;

    // auto imageBase = GetModuleHandle(NULL);
    // auto kernel32 = GetModuleHandle("kernel32");

    // char path[MAX_PATH * 2] = {0};
    // GetModuleFileName(NULL, )
// }
