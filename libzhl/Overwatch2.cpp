#include "Overwatch2.h"
#include "HookSystem_private.h"
#include "mologie_detours.h"

// namespace _var1 {
//     static VariableDefinition varObj("g_TestString", "ff9424f001000089442460837c2460007d0732c0e9????????4c8d??????????488d??????????b901000000ff15????????89442460837c2460007d0732c0e9????????488b05(????????)", &__ptr_g_TestString, true, true);
// }
//wchar_t* g_TestString;
//
//namespace _func0 {
//	static void* func = 0;
//	static FunctionDefinition funcObj("testFunc", typeid(void(*)(const char*)), "48894c2408574883ec2041b9400000004c8d??????????488b54243033c9ff15????????4883c4205fc3", nullptr, 0, 0, &func);
//}
//
//HRESULT (*internalSuper)(IDXGISwapChain* this_arg, UINT syncInterval, UINT flags);
//void (*internalSuper_testFunc)(const char* str);
//
//void testFunc(const char* str) {
//	typedef void (*custom_arg_funcptr_t)(const char* str);
//	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func0::func;
//	return execfunc(str);
//}

//namespace _func1 {
//	static void* func = 0;
//	static FunctionDefinition funcObj("IDXGISwapChain::Present", typeid(HRESULT (*)(IDXGISwapChain*, UINT, UINT)), "48895c2410488974242055574156488d6c24904881ec70010000488b??????????4833c4488945604533f64489442448", nullptr, 0, 0, &func, "dxgi");
//}
//
//HRESULT IDXGISwapChain::Present(UINT syncInterval, UINT flags) {
//	typedef HRESULT(*custom_arg_funcptr_t)(IDXGISwapChain *this_arg, UINT syncInterval, UINT flags);
//	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func1::func;
//	return execfunc(this, syncInterval, flags);
//}

// namespace _var1 {
// 	static VariableDefinition varObj("gState", "488905(????????)488b0d????????488b15????????488b19488b9b????????4531c04989c14889d8ff15????????488b35????????488d3d????????4889f9ff15????????488b0e488b59??488d15????????4889f14189c04989f94889d8ff15????????488b0d????????488b01488b40??ff15????????488b0d", &__ptr_gState, false, true);
// }
// RenderState gState;

// namespace _var2 {
// 	static VariableDefinition varObj("gHwnd", "488905(????????)4885c00f84", &__ptr_gHwnd, false, true);
// }
// HWND gHwnd;

// namespace _var3 {
// 	static VariableDefinition varObj("gDevice", "4c8d0d(????????)31c9", &__ptr_gDevice, false, true);
// }
// ID3D12Device* gDevice;

// namespace _var4 {
// 	static VariableDefinition varObj("gInputState", "0f1135(????????)0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135????????0f1135", &__ptr_gInputState, false, true);
// }
// InputState gInputState;

// namespace _var5 {
// 	static VariableDefinition varObj("gAssets", "488d15(????????)0f1004", &__ptr_gAssets, false, true);
// }
// AssetEntry gAssets;

// namespace _func2 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("decryptAsset", typeid(AssetEntry* (*)(int, const uint8_t*)), "5657534883ec304863c1", nullptr, 0, 0, &func);
// }

// AssetEntry* decryptAsset(int offset, const uint8_t* key) {
// 	typedef AssetEntry* (*custom_arg_funcptr_t)(int offset, const uint8_t* key);
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func2::func;
// 	return execfunc(offset, key);
// }

// namespace _func3 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("renderGame", typeid(void (*)()), "41565657534881ecf80000000f57c0", nullptr, 0, 0, &func);
// }

// void renderGame() {
// 	typedef void (*custom_arg_funcptr_t)();
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func3::func;
// 	execfunc();
// }

// namespace _func4 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("initD3D", typeid(void* (*)(void*)), "41574156415541545657534881ecb0030000", nullptr, 0, 0, &func);
// }

// void* initD3D(void* ptr) {
// 	typedef void* (*custom_arg_funcptr_t)(void*);
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func4::func;
// 	return execfunc(ptr);
// }

// namespace _func5 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("WndProc", typeid(LRESULT(*)(HWND, UINT, WPARAM, LPARAM)), "56574883ec384c89ce", nullptr, 0, 0, &func);
// }

// LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
// 	typedef LRESULT(*custom_arg_funcptr_t)(HWND, UINT, WPARAM, LPARAM);
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func5::func;
// 	return execfunc(hWnd, msg, wParam, lParam);
// }

// namespace _func6 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("Player::update", typeid(void(Player::*)(void*, void*, void*, float*)), "415741564155415456575553b808720200", nullptr, 0, 0, &func);
// }

// void Player::update(void* param_1, void* param_2, void* param_3, float* param_4) {
// 	typedef void(*custom_arg_funcptr_t)(void*, void*, void*, float*);
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func6::func;
// 	execfunc(param_1, param_2, param_3, param_4);
// }

// namespace _func7 {
// 	static void* func = 0;
// 	static FunctionDefinition funcObj("updateInput", typeid(void(*)()), "56574883ec380f297424", nullptr, 0, 0, &func);
// }

// void updateInput() {
// 	typedef void(*custom_arg_funcptr_t)();
// 	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func7::func;
// 	execfunc();
// }

namespace _func8 {
    static void* func = 0;
    static FunctionDefinition funcObj("TlsCallback_0", typeid(void(*)(void*, DWORD, void*)), "4c8bdc49894b0855498dab", nullptr, 0, 0, &func);
}

void TlsCallback_0(void* hModule, DWORD reason, void* context) {
    typedef void(*custom_arg_funcptr_t)(void*, DWORD, void*);
    custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func8::func;
    execfunc(hModule, reason, context);
}

namespace _func9 {
    static void* func = 0;
    static FunctionDefinition funcObj("AntiDebug1", typeid(void(*)()), "4c8bdc49895b??498973??49897b??4d8963", nullptr, 0, 0, &func);
}

void AntiDebug1() {
    typedef void(*custom_arg_funcptr_t)();
    custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func9::func;
    execfunc();
}

namespace _func10 {
    static void* func = 0;
    static FunctionDefinition funcObj("_WinMain", typeid(int(*)(HINSTANCE, HINSTANCE, PWSTR, int)), "4055535741544155488dac24", nullptr, 0, 0, &func);
}

int WINAPI _WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    typedef int(*custom_arg_funcptr_t)(HINSTANCE, HINSTANCE, PWSTR, int);
    custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func10::func;
    return execfunc(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}

namespace _extFun0 {
    static void* ptr = GetProcAddress(GetModuleHandle("ws2_32.dll"), "send");
    static void* func = 0;
    static FunctionDefinition fn("WS2::send", typeid(int (*)(SOCKET, const char*, int, int)), ptr, nullptr, 0, 0, &func);
}

namespace _extFun1 {
    static void* ptr = GetProcAddress(GetModuleHandle("ntdll.dll"), "NtAllocateVirtualMemory");
    static void* func = 0;
    static FunctionDefinition fn("NTDLL::NtAllocateVirtualMemory", typeid(NTSTATUS (NTAPI*)(HANDLE, void**, ULONG, PULONG, ULONG, ULONG)), ptr, nullptr, 0, 0, &func);
}
