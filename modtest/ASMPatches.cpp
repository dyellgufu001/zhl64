#include <cstdio>
#include "SigScan.h"
#include "ASMPatcher.hpp"

void PatchSSL() {
    SigScan scanner("ff50??8bf885c00f85");
    scanner.Scan();
    void* addr = scanner.GetAddress();

    SigScan scanner2("0f85????????4c896424??4c896424");
    scanner2.Scan();
    void* addr2 = scanner2.GetAddress();

    printf("patching ssl at %p and %p\n", addr, addr2);

    ASMPatch patch;
    patch.AddBytes(ByteBuffer().AddByte(0x90, 3));
    sASMPatcher.FlatPatch(addr, &patch);

    ASMPatch patch2;
    patch2.AddBytes(ByteBuffer().AddByte(0x90, 6));
    sASMPatcher.FlatPatch(addr2, &patch2);
}
