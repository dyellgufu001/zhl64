#pragma once

#include "libzhl.h"
#include "dxgi.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

extern LIBZHL_API wchar_t** __ptr_g_TestString;
#define g_TestString (*__ptr_g_TestString)

extern LIBZHL_API HRESULT(*internalSuper)(IDXGISwapChain* this_arg, UINT syncInterval, UINT flags);
extern LIBZHL_API void (*internalSuper_testFunc)(const char* str);

LIBZHL_API void testFunc(const char* str);
LIBZHL_API void hookTest(void* hook);