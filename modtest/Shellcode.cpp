#include <cstdio>
#include "SigScan.h"
#include "HookSystem.h"
#include "Overwatch2.h"

// HOOK_GLOBAL(NTDLL::NtAllocateVirtualMemory, (HANDLE processHandle, PVOID* baseAddress, ULONG zeroBits, PULONG regionSize, ULONG allocationType, ULONG protect) -> NTSTATUS, NTAPI) {
//     if (protect == 0x40) {
//         printf("hi from %p\n", (void**)(&processHandle)[-1]);
//         MessageBoxA(0, NULL, "", MB_ICONINFORMATION);
//     }

//     return super(processHandle, baseAddress, zeroBits, regionSize, allocationType, protect);
// }
