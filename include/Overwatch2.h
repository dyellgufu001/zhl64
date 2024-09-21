/* #pragma once */

/* #include "libzhl.h" */
/* #include "dxgi1_4.h" */
/* #include "d3d12.h" */
/* #include "xinput.h" */

/* #define WIN32_LEAN_AND_MEAN */
/* #include "windows.h" */

/* struct AssetEntry; */
/* struct RenderState; */
/* struct Vec2f; */
/* struct Vec2i; */
/* struct Player; */
/* struct InputState; */

/* extern LIBZHL_API wchar_t** __ptr_g_TestString; */
/* #define g_TestString (*__ptr_g_TestString) */

/* extern LIBZHL_API RenderState* __ptr_gState; */
/* #define gState (*__ptr_gState) */

/* extern LIBZHL_API HWND* __ptr_gHwnd; */
/* #define gHwnd (*__ptr_gHwnd) */

/* extern LIBZHL_API ID3D12Device** __ptr_gDevice; */
/* #define gDevice (*__ptr_gDevice) */

/* extern LIBZHL_API InputState* __ptr_gInputState; */
/* #define gInputState (*__ptr_gInputState) */

/* extern LIBZHL_API AssetEntry* __ptr_gAssets; */
/* #define gAssets (*__ptr_gAssets) */

/* enum class AssetType : uint8_t { */
/*     Text = 0, */
/*     MapData = 1, */
/*     Png = 2, */
/*     Ogg = 3, */
/*     SpriteData = 5, */
/*     Shader = 7, */
/*     Font = 8, */

/*     Normal = 0x3F, */
/*     Encrypted = 0x40, */
/*     Decrypted = 0x80, */
/* }; */

/* struct AssetEntry { */
/*     AssetType type; */
/*     uint8_t unknown1[7]; */

/*     void* ptr; // offset by 0x140001200 */
/*     uint32_t length; */

/*     uint32_t unknown2; */
/*     uint64_t unknown3; */

/*     uint8_t unknown4[16]; */
/* }; */

/* struct RenderState { */
/*     D3D12_CPU_DESCRIPTOR_HANDLE backBufferRenderTargetViews[2]; */
/*     ID3D12Resource* backBufferRenderTargets[2]; */
/*     char pad0[7176]; */
/*     IDXGISwapChain3* swapChain; */
/*     char adapterDesc[256]; */
/*     char pad1[72]; */
/*     ID3D12Resource* vertBuffer; */
/*     ID3D12Resource* quadVertBuffer; */
/*     ID3D12Resource* quadVertUploadBuffer; */
/*     char pad2[40]; */
/*     ID3D12Resource* queryHeap; */
/*     ID3D12Resource* queryBuffer; */
/*     ID3D12Fence* fence; */
/*     char pad3[32]; */
/*     ID3D12DescriptorHeap* srvDescriptorHeap; */
/*     ID3D12DescriptorHeap* rtvDescriptorHeap; */
/*     ID3D12CommandAllocator* commandAllocator; */
/*     ID3D12CommandQueue* commandQueue; */
/*     ID3D12GraphicsCommandList* commandList; */
/* }; */

/* struct Vec2f { */
/*     float x; */
/*     float y; */

/*     Vec2f(float _x, float _y) : x(_x), y(_y) {} */
/* }; */

/* struct Vec2i { */
/*     uint32_t x; */
/*     uint32_t y; */
/* }; */

/* struct Player { */
/*     Vec2f pos; // 0x0 */
/*     Vec2f vel; // 0x8 */
/*     LIBZHL_API void update(void* param_1, void* param_2, void* param_3, float* param_4); */
/* }; */

/* struct InputState { */
/*     char keyboardState[256]; */
/*     XINPUT_STATE joyState; */
/*     XINPUT_STATE prevJoyState; */
/*     DWORD getStateResult; */
/* }; */

/* LIBZHL_API void testFunc(const char* str); */
/* LIBZHL_API void hookTest(void* hook); */
/* LIBZHL_API AssetEntry* decryptAsset(int offset, const uint8_t* key); */
/* LIBZHL_API AssetEntry* getAsset(int id); */
/* LIBZHL_API void renderGame(); */
/* LIBZHL_API void* initD3D(void* ptr); */
/* LIBZHL_API LRESULT WndProc(HWND, UINT, WPARAM, LPARAM); */
/* LIBZHL_API void updateInput(); */
