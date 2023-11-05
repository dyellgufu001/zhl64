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

namespace _func1 {
	static void* func = 0;
	static FunctionDefinition funcObj("IDXGISwapChain::Present", typeid(HRESULT (*)(IDXGISwapChain*, UINT, UINT)), "48895c2410488974242055574156488d6c24904881ec70010000488b??????????4833c4488945604533f64489442448", nullptr, 0, 0, &func, "dxgi");
}

HRESULT IDXGISwapChain::Present(UINT syncInterval, UINT flags) {
	typedef HRESULT(*custom_arg_funcptr_t)(IDXGISwapChain *this_arg, UINT syncInterval, UINT flags);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t)_func1::func;
	return execfunc(this, syncInterval, flags);
}