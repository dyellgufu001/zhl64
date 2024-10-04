#include <cstdio>
#include <utility>
#include "SigScan.h"
#include "ASMPatcher.hpp"

#include "AntiDebug.h"

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
    std::vector<std::pair<const char*, ByteBuffer>> sigs = {
        {
            "e8????????84c00f84????????5081c8ae27fccc58710248b9c7442468b8010000c744247888010000",
            ByteBuffer().AddString("\x31\xC0\x90\x90\x90"),
        },
        {
            "cceb59c7442420340b00008b442420894424208b442420894424208b442420894424208b442420894424208b442420894424208b44242089442420894424188b442420894424208b4c2420",
            ByteBuffer().AddString("\xEB\x01"),
        },
    };
    
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

    SigScan scanner5("84c00f84????????5581cd890276675d730249bfc74424406a090000c744245047040000");
    scanner5.Scan();
    void* addr5 = scanner5.GetAddress();

    SigScan scanner6("0f0beb040fb604244881c4b8000000c3cccccccccccccccc4c8bdc498953104d8943184d894b2053");
    scanner6.Scan();
    void* addr6 = scanner6.GetAddress();

    printf("patching exception fuckery at %p, %p, %p, %p %p\n", addr, addr2, addr3, addr4, addr5);

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
    sASMPatcher.FlatPatch(addr5, &patch3);

    ASMPatch patch4;
    patch4.AddBytes(ByteBuffer().AddByte(0x90, 4));
    sASMPatcher.FlatPatch(addr4, &patch4);
    sASMPatcher.FlatPatch(addr6, &patch4);

    printf("and also here ");

    for (const auto& sig : sigs) {
        SigScan scanner1(sig.first);
        scanner1.Scan();
        void* addr1 = scanner1.GetAddress();
        
        printf("%p ", addr1);
        ASMPatch patch1;
        patch1.AddBytes(sig.second);
        sASMPatcher.FlatPatch(addr1, &patch1);
    }

    printf("\n");
}

void PatchShellcode() {
    const SizedSig sigs[] = {
        { "ff9540010000488d05????????488d8d????????c605????????01", 6, },
        { "ff5510e8????????85c0740bb80100000089", 3, },
        { "ff9550010000e9????????498bdd83c6024883c702413bf00f8c????????4d8b094d3bcb", 6, },
        { "ff9570010000488d8d09010000e8????????488bd8ff15????????4533c94533c0", 6, },
        { "ffd785c0781e488b7d10488d75c8b930000000f3a452", 4, },
        { "ff55208b459889??????????e8????????488d??????????4533c94533c0488bd0", 3, },
        { "ff55174c8bb424b80000004c8bbc24b0000000488b9c24e0000000488bb424c00000004881c4c80000005f5dc3", 3, },
        { "ff55a84c8bbc24100100004c8bb42418010000488bbc2458010000488bb42450010000488b9c24480100004180fc017517833d", 3, },
        { "ff55df448b7567448b7d5f488d0d1367de004d8bc4498bd5e8581e", 3, },
        { NULL, 0, },
    };

    std::vector<std::pair<const char*, ByteBuffer>> sigs2 = {
        // {
        //     "84c00f84????????5081c8ae27fccc58710248b9c7442468b8010000c744247888010000",
        //     ByteBuffer().AddByte(0x90, 4).AddString("\xEB"),
        // },
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

    printf("and also here ");

    for (const auto& sig : sigs2) {
        SigScan scanner1(sig.first);
        scanner1.Scan();
        void* addr1 = scanner1.GetAddress();
        
        printf("%p ", addr1);
        ASMPatch patch1;
        patch1.AddBytes(sig.second);
        // sASMPatcher.FlatPatch(addr1, &patch1);
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
        { "40883ee9????????418bc1410fb70c44418b048f4c8d14184d85d20f84????????5181e1eb581ea7597102", 3, },
        { "0f82????????eb034533e444896500c74508170000005681e62a10ff205e730249bbc745c8b9ffffffc7", 6, },
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

void PerformASMPatches() {
    PatchSSL();
    PatchException1();
    PatchShellcode();
    PatchRtdsc();
    PatchBadFunction();
    PatchStackGarbage();
    PatchCrashLog();
    // PatchConditionalJumps();
}
