#include <cstdio>
#include "SigScan.h"
#include "ASMPatcher.hpp"
#include "HookSystem.h"
#include "Overwatch2.h"

void __fastcall hi() {
    MessageBoxA(0, "about to crash", "hi", MB_ICONINFORMATION);
    printf("yo\n");
}

void PatchStackGarbage() {
    SigScan scanner("881fe9????????418bc0");
    scanner.Scan();
    void* addr = scanner.GetAddress();

    printf("patching stack garbage at %p\n", addr);

    ASMPatch patch;
    patch.AddBytes(ByteBuffer().AddByte(0x90, 2));
    sASMPatcher.FlatPatch(addr, &patch);
}

void PatchBadFunction() {
    SigScan scanner("405657b878800000");
    scanner.Scan();
    void* addr = scanner.GetAddress();

    printf("hi patching at %p\n", addr);

    using Reg = ASMPatch::SavedRegisters;
    Reg reg(Reg::GP_REGISTERS_X64, true);

    ASMPatch patch;
    patch.PreserveRegisters(reg);
    patch.AddInternalCall(hi);
    patch.RestoreRegisters(reg);
    patch.AddBytes(ByteBuffer().AddAny((char*)addr, 8));
    // printf("%p %x %p\n", (char*)addr + 13, *(uint32_t*)((char*)addr + 9), (char*)addr + 13 + *(uint32_t*)((char*)addr + 9));
    patch.AddInternalCall((char*)addr + 13 + *(uint32_t*)((char*)addr + 9));
    patch.AddBytes(ByteBuffer().AddAny((char*)addr + 13, 3));
    patch.AddRelativeJump((char*)addr + 16);
    sASMPatcher.PatchAt(addr, &patch);

    ASMPatch nop;
    nop.AddBytes(ByteBuffer().AddByte(0x90, 3));
    sASMPatcher.FlatPatch((char*)addr + 13, &nop);
}

// HOOK_GLOBAL(CrashFunction, (void* obj, void* other) -> bool, __fastcall) {
//     bool result = super(obj, other);
//     MessageBoxA(0, "attach now", "hi", MB_ICONINFORMATION);
//     return result;
// }

void CrashLogTrampoline(void* a) {
    printf("hi from trampo %p\n", a);
    __debugbreak();
}

void PatchCrashLog() {
    SigScan scanner("f3a45581e5442145235d710249baff55208b459889052c0e2901e8????????488d??????????4533c9");
    scanner.Scan();
    void* addr = scanner.GetAddress();

    printf("patching in log at %p\n", addr);

    using Reg = ASMPatch::SavedRegisters;
    Reg reg(Reg::GP_REGISTERS_X64, true);

    ASMPatch patch;
    patch.PreserveRegisters(reg);
    patch.AddBytes(ByteBuffer().AddString("\x48\x89\xcf"));
    patch.AddInternalCall(CrashLogTrampoline);
    patch.RestoreRegisters(reg);

    // sASMPatcher.PatchAt(addr, &patch);
}

HOOK_GLOBAL(SomeAntiDebug, () -> void, __fastcall) {}
