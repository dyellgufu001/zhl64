#include <windows.h>
#include <imagehlp.h>
#include <stdio.h>
#include "config.h"
#include "loader.h"

Config config;

DWORD StartGame(PROCESS_INFORMATION* procInfo) {
    STARTUPINFOA startupInfo = {0};
    char cli[256] = {0};
    strncpy(cli, config.cliArgs.c_str(), strlen(config.cliArgs.c_str()));
    
    DWORD result = CreateProcessA(config.exePath.c_str(), cli, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startupInfo, procInfo);
    if (result == 0) {
        fprintf(stderr, "failed to create process: %d\n", result);
        return -1;
    }

    printf("started %s suspended: %d\n", config.exePath.c_str(), procInfo->dwProcessId);
    return result;
}

int UpdateMemory(HANDLE process, PROCESS_INFORMATION const* procInfo, void** page, size_t* codeOffset, size_t* argOffset) {
    HMODULE self = GetModuleHandle(NULL);
    PIMAGE_NT_HEADERS ntHeaders = ImageNtHeader(self);
    char* base = (char*)&(ntHeaders->OptionalHeader);
    base += ntHeaders->FileHeader.SizeOfOptionalHeader;
    IMAGE_SECTION_HEADER* headers = (IMAGE_SECTION_HEADER*)base;
    bool found = false;

    for (int i = 0; i < ntHeaders->FileHeader.NumberOfSections; i++) {
        if (!strcmp((char*)headers->Name, ".trampo")) {
            found = true;
            break;
        }
        ++headers;
    }

    if (!found) {
        fprintf(stderr, "failed to find .trampo\n");
        return -1;
    }

    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (!kernel32) {
        fprintf(stderr, "failed to load kernel32.dll\n");
        return -1;
    }

    LoaderData data;
#define LOAD_CAST(NAME) (decltype(NAME)*)GetProcAddress(kernel32, #NAME)
    data.freeLibrary = LOAD_CAST(FreeLibrary);
    data.getProcAddress = LOAD_CAST(GetProcAddress);
    data.loadLibraryA = LOAD_CAST(LoadLibraryA);
#undef LOAD_CAST
    data.InitializeStringTable();

    void* remotePage = VirtualAllocEx(process, NULL, headers->Misc.VirtualSize + sizeof(LoaderData), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (!remotePage) {
        fprintf(stderr, "failed to allocate executable memory\n");
        return -1;
    }

    size_t bytesWritten = 0;
    BOOL ok = WriteProcessMemory(process, remotePage, (char*)self + headers->VirtualAddress, headers->Misc.VirtualSize, &bytesWritten);
    ok = ok && WriteProcessMemory(process, (char*)remotePage + headers->Misc.VirtualSize, &data, sizeof(data), &bytesWritten);
    if (!ok) {
        fprintf(stderr, "failed to write content of .trampo at %p\n", remotePage);
        return -1;
    }

    DWORD dummy;
    ok = VirtualProtectEx(process, remotePage, headers->Misc.VirtualSize, PAGE_EXECUTE_READ, &dummy);
    if (!ok) {
        fprintf(stderr, "failed to change protection from rwx to rx at %p\n", remotePage);
        return -1;
    }

    printf("allocated code at %p\n", remotePage);

    *page = remotePage;
    *codeOffset = (size_t)GetLoadDLLsAddress() - ((size_t)self + headers->VirtualAddress);
    *argOffset = headers->Misc.VirtualSize;
    return 0;
}

DWORD FirstStageInit(HANDLE* outProcess, void** page, 
                     size_t* functionOffset, size_t* paramOffset, PROCESS_INFORMATION* procInfo) {
    DWORD pid = StartGame(procInfo);
    HANDLE process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
                                 FALSE, procInfo->dwProcessId);

    if (!process) {
        fprintf(stderr, "failed to open process %d\n", procInfo->dwProcessId);
        return -1;
    }

    if (UpdateMemory(process, procInfo, page, functionOffset, paramOffset)) {
        fprintf(stderr, "failed to inject trampoline\n");
        return -1;
    }

    *outProcess = process;
    return 0;
}

DWORD CreateAndWait(HANDLE process, void* remotePage, size_t functionOffset, size_t paramOffset) {
    DWORD threadId;
    HANDLE remoteThread = CreateRemoteThread(process, NULL, 0, 
                                             (LPTHREAD_START_ROUTINE)((char*)remotePage + functionOffset), 
                                             (char*)remotePage + paramOffset, 0, &threadId);
    if (!remoteThread) {
        fprintf(stderr, "Error while creating remote thread: %d\n", GetLastError());
        return -1;
    }

    printf("Waiting for remote thread %d to complete\n", threadId);
    DWORD result = WaitForSingleObject(remoteThread, 60 * 1000);

    switch (result) {
    case WAIT_OBJECT_0:
        printf("RemoteThread completed\n");
        break;

    case WAIT_ABANDONED:
        printf("This shouldn't happened: RemoteThread returned WAIT_ABANDONNED\n");
        return -1;

    case WAIT_TIMEOUT:
        fprintf(stderr, "RemoteThread timed out\n");
        return -1;

    case WAIT_FAILED:
        fprintf(stderr, "WaitForSingleObject on RemoteThread failed: %d\n", GetLastError());
        return -1;
    }

    GetExitCodeThread(remoteThread, &result);
    printf("%d\n", result);

    return 0;
}

int main() {
    config.Init();

    HANDLE process;
    void* remotePage;
    size_t functionOffset;
    size_t paramOffset;
    PROCESS_INFORMATION procInfo;

    if (FirstStageInit(&process, &remotePage, &functionOffset, &paramOffset, &procInfo)) {
        fprintf(stderr, "could not start %s\n", config.exePath.c_str());
        return -1;
    }

    if (CreateAndWait(process, remotePage, functionOffset, paramOffset)) {
        fprintf(stderr, "failed to create remoet thread\n");
        return -1;
    }

    if (!config.suspend) {
        printf("resuming\n");
        DWORD result = ResumeThread(procInfo.hThread);
        if (result == -1) {
            printf("sorry fucky ou\n");
            return -1;
        }

        printf("resumed\n");
    } else {
        printf("not resuming\n");
    }
    
    return 0;
}
