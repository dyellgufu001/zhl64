#include <Windows.h>
#include <ImageHlp.h>

#include <cstdarg>
#include <cstdio>
#include <ctime>

#include "ConsoleWindow.h"
#include "HookSystem.h"

static void Log(FILE* f, const char* kind, const char* fmt, ...);

void LoadMods() {
    FILE* f = fopen("zhlLoader.log", "w");
    Log(f, "INFO", "Loading mods...\n");

    WIN32_FIND_DATAA data;
    memset(&data, 0, sizeof(data));
    HANDLE files = FindFirstFileA("zhl*.dll", &data);
    BOOL ok = (files != INVALID_HANDLE_VALUE);
    while (ok) {
        if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && strcmp(data.cFileName, "zhlLoader.dll")) {
            HMODULE mod = LoadLibraryA(data.cFileName);
            if (!mod) {
                Log(f, "WARN", "Unable to load mod %s\n", data.cFileName);
            }
            else {
                FARPROC init = GetProcAddress(mod, "ModInit");
                if (!init) {
                    Log(f, "WARN", "No ModInit found in mod %s\n", data.cFileName);
                    FreeLibrary(mod);
                }
                else {
                    if (init()) {
                        Log(f, "WARN", "Errors encountered while initializing mod %s\n", data.cFileName);
                        FreeLibrary(mod);
                    }
                    else {
                        Log(f, "INFO", "Successfully loaded and initialized mod %s at %p\n", data.cFileName, mod);
                        /* env->mods.push_back(mod); */
                    }
                }
            }
        }
        ok = FindNextFileA(files, &data);
    }

    fclose(f);

    ZHL::Init();
}

extern "C" __declspec(dllexport) int Launch() {
    ConsoleWindow::Init();
    LoadMods();

    return 0;
}

void Log(FILE* f, const char* type, const char* fmt, ...) {
	va_list va;
	va_start(va, fmt);
	time_t now = time(nullptr);
	tm* nowTm = localtime(&now);
	char timeBuffer[4096];
	strftime(timeBuffer, 4095, "[%Y-%m-%d %H:%M:%S] ", nowTm);

	fprintf(f, "[%s] ", type);
	vfprintf(f, fmt, va);
	fflush(f);
}
