#include "HookSystem.h"
#include "Overwatch2.h"

#include "d3d11.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include <cstring>
#include <cstdio>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND window;
WNDPROC windowProc;
bool menuShown = false;

DXGI_SWAP_CHAIN_DESC swapChainDesc;
ID3D11Device* device;
ID3D11DeviceContext* deviceContext;
ID3D11RenderTargetView* mainRenderTargetView;

int timesToLog = 10;

LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// Toggle the overlay using the delete key
	if (uMsg == WM_KEYDOWN && wParam == VK_DELETE) {
		menuShown = !menuShown;
		return false;
	}

	// If the overlay is shown, direct input to the overlay only
	if (menuShown) {
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}

	// Otherwise call the game's wndProc function
	return CallWindowProc(windowProc, hWnd, uMsg, wParam, lParam);
}

HOOK_GLOBAL(IDXGISwapChain::Present, (IDXGISwapChain* thisPtr, UINT syncInterval, UINT flags) -> HRESULT, __stdcall) {
	if (timesToLog > 0) {
		printf("present(): swapchain at %p\n", thisPtr);
		timesToLog--;
	}

	static bool initialized = false;
	if (!initialized) {
		thisPtr->GetDesc(&swapChainDesc);
		window = swapChainDesc.OutputWindow;

		thisPtr->GetDevice(__uuidof(ID3D11Device), (void**)&device);
		device->GetImmediateContext(&deviceContext);

		windowProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)windowProc_hook);

		ID3D11Texture2D* pBackBuffer;
		thisPtr->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		device->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
		pBackBuffer->Release();

		ImGui::CreateContext();
		ImGui_ImplWin32_Init(window);
		ImGui_ImplDX11_Init(device, deviceContext);

		ImGui::StyleColorsDark();
		ImGui::GetStyle().AntiAliasedFill = false;
		ImGui::GetStyle().AntiAliasedLines = false;
		ImGui::CaptureMouseFromApp();
		ImGui::GetStyle().WindowTitleAlign = ImVec2(0.5f, 0.5f);
		initialized = true;
		printf("Initialized Dear ImGui\n");
	}

	if (menuShown) {
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
		ImGui::Render();

		// Draw the overlay
		deviceContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		printf("frame drawn\n");
	}

	return super(thisPtr, syncInterval, flags);
}

//HOOK_GLOBAL(testFunc, (const char* str) -> void, __stdcall) {
//	char newstr[256] = { 0 };
//	strcat(newstr, str);
//	strcat(newstr, " (hooked)\nanyway, here's a string from the host process: \n");
//	wcstombs(newstr + strlen(newstr), g_TestString, wcslen(g_TestString));
//	super(newstr);
//}