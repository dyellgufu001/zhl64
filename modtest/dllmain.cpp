#include <cstdio>
#include "Overwatch2.h"
#include "HookSystem_private.h"
#include "SigScan.h"
#include "ASMPatches.h"

// HOOK_GLOBAL(WS2::send, (SOCKET s, const char* buf, int len, int flags) -> int, __stdcall) {
//     if (buf[0] > 'A' && buf[0] < 'z') {
//         printf("%s\n", buf);
//     }
    
//     return super(s, buf, len, flags);
// }

HOOK_GLOBAL(AntiDebug1, () -> void, __fastcall) {}

HOOK_GLOBAL(_WinMain, (HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) -> int, __fastcall) {
    printf("hi from winmain");
    return super(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}

MOD_EXPORT int ModInit(int argc, char** argv) {
    printf("x64 zhl is real\n");
        
    PatchSSL();
    PatchException1();
    PatchShellcode();
    PatchRtdsc();
    // PatchConditionalJumps();

    return 0;
}
