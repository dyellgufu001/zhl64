#include <cstdio>
#include "SigScan.h"
#include "ASMPatcher.hpp"

struct SizedSig {
    const char* sig;
    size_t size;
};

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

void PatchException1() {
    SigScan scanner("0f0beb040fb604244881c498000000");
    scanner.Scan();
    void* addr = scanner.GetAddress();

    SigScan scanner2("cce9e3000000c744242041f5ffff8b44242089");
    scanner2.Scan();
    void* addr2 = scanner2.GetAddress();

    // SigScan scanner3("0f0beb040fb604244881c4e8000000c3cccccccccccccccc488bc148ba5555555555555555");
    SigScan scanner3("84c00f84????????4889b424d00100005081e016d903dc58710248bac745b0300000008b45b0654c8b004d85c0");
    scanner3.Scan();
    void* addr3 = scanner3.GetAddress();

    SigScan scanner4("0f0beb040fb604244881c4e8000000c3cccccccccccccccc488bc148ba5555555555555555");
    scanner4.Scan();
    void* addr4 = scanner4.GetAddress();

    printf("patching exception fuckery at %p, %p, %p, %p\n", addr, addr2, addr3, addr4);

    ASMPatch patch;
    patch.AddBytes(ByteBuffer().AddString("\xEB\x02"));
    sASMPatcher.FlatPatch(addr, &patch);

    ASMPatch patch2;
    patch2.AddBytes(ByteBuffer().AddString("\xEB\x04"));
    sASMPatcher.FlatPatch(addr2, &patch2);
    
    ASMPatch patch3;
    // patch3.AddBytes(ByteBuffer().AddByte(0x90, 4));
    patch3.AddBytes(ByteBuffer().AddByte(0x90, 3).AddByte(0xE9));
    sASMPatcher.FlatPatch(addr3, &patch3);

    ASMPatch patch4;
    patch4.AddBytes(ByteBuffer().AddByte(0x90, 4));
    sASMPatcher.FlatPatch(addr4, &patch4);
}

void PatchShellcode() {
    const SizedSig sigs[] = {
        { "ff9540010000488d05????????488d8d????????c605????????01", 6, },
        { "ff5510e8????????85c0740bb80100000089", 3, },
        { "ff9550010000e9????????498bdd83c6024883c702413bf00f8c????????4d8b094d3bcb", 6, },
        { "ff9570010000488d8d09010000e8????????488bd8ff15????????4533c94533c0", 6, },
        { NULL, 0, },
    };

    printf("patching shellcode execution at ");

    for (const SizedSig* sig = sigs; sig->sig != NULL; sig++) {
        if (sig->sig != sigs[0].sig) {
            printf(", ");
        }
        
        SigScan scanner(sig->sig);
        scanner.Scan();
        void* addr = scanner.GetAddress();

        printf("%p(%zu)", addr, sig->size);

        ASMPatch patch;
        patch.AddBytes(ByteBuffer().AddByte(0x90, sig->size));
        sASMPatcher.FlatPatch(addr, &patch);    
    }

    printf("\n");
}

void PatchConditionalJumps() {
    const char* sigs[] = {
        "0f84????????5781cf0e07601a5f730248be0f31488b7e104c8b460848c1e220480bc24c896e10",
        "0f84????????5781cf1066048a5f710248ba0f314d8b480848c1e220480bc2488bf8488bc6",
        "0f84????????5181e1c2098d5c59730248b90f31498b70104d8b480848c1e220480bc24989581049895808488bf8",
        NULL,
    };

    printf("patching conditional jumps at ");

    for (const char** sig = sigs; *sig != sig[1]; sig++) {
        if (*sig != sigs[0]) {
            printf(", ");
        }

        SigScan scanner(*sig);
        scanner.Scan();
        void* addr = scanner.GetAddress();

        printf("%p", addr);

        ASMPatch patch;
        patch.AddRelativeJump((char*)addr + 6 + *(uint32_t*)((char*)addr + 2));
        // sASMPatcher.FlatPatch(addr, &patch);
    }

    printf("\n");
}

void PatchRtdsc() {
    SizedSig sigs[] = {
        { "881feb084883c6074883c70748ffc648ffc7493bf0728d4c8b65904489ad80010000c7852801000007000000", 2, },
        { "728d4c8b65904489ad80010000c78528010000070000005381e37d88b34b5b7102", 2, },
        { NULL, 0, },
    };

    printf("patching rtdsc crash at ");

    for (const SizedSig* sig = sigs; sig->sig != NULL; sig++) {
        if (sig->sig != sigs[0].sig) {
            printf(", ");
        }
        
        SigScan scanner(sig->sig);
        scanner.Scan();
        void* addr = scanner.GetAddress();

        printf("%p(%zu)", addr, sig->size);

        ASMPatch patch;
        patch.AddBytes(ByteBuffer().AddByte(0x90, sig->size));
        sASMPatcher.FlatPatch(addr, &patch);    
    }

    printf("\n");
}
