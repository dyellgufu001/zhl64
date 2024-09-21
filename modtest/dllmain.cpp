#include <cstdio>
#include "Overwatch2.h"
#include "HookSystem_private.h"
#include "SigScan.h"

#include "ASMPatches.h"

MOD_EXPORT int ModInit(int argc, char** argv) {
	printf("x64 zhl is real\n");
        PatchSSL();

	return 0;
}
