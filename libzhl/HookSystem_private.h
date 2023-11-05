#pragma once

#include <tuple>
#include <variant>
#include <vector>

#include "HookSystem.h"
#include "mologie_detours.h"

// WTF Windows ?
#ifdef VOID
#undef VOID
#endif

namespace HookSystem {

	enum FunctionFlags {
		THISCALL = 1 << 0,
		CLEANUP = 1 << 1,
		VOID = 1 << 2,
		LONGLONG = 1 << 3
	};

	struct NoRegister {};

	enum GPRegisters : uint8_t {
		EAX,
		ECX,
		EDX,
		EBX,
		ESP,
		EBP,
		ESI,
		EDI
	};

	enum XMMRegisters : uint8_t {
		XMM0,
		XMM1,
		XMM2,
		XMM3,
		XMM4,
		XMM5,
		XMM6,
		XMM7,
		XMM8
	};

	typedef std::variant<NoRegister, GPRegisters, XMMRegisters> Register;

	struct ArgData {
		Register _register;
		// Expressed as the division of the real size by 4 (x86 stack aligned on a 32 bits boundary)
		// Example: a structure is 10 bytes wide (2 ints + 1 short)
		// Passing this structure on the stack will push 12 bytes (32 bits alignment).
		// 12 = 3 * 4, so _size would be 3 when passing such a structure.
		size_t _size = 0;

		bool IsRegister() const;
		bool IsGPRegister() const;
		bool IsXMMRegister() const;
	};
}

class LIBZHL_API Definition
{
public:
	static bool Init();
	static const char *GetLastError();
	static Definition *Find(const char *name);
	static const std::vector<std::tuple<bool, const char*>>& GetMissing();

protected:
	static void Add(const char *name, Definition *def);

public:
	virtual int Load() = 0;
	virtual const char* GetName() const = 0;
	virtual bool IsFunction() const = 0;
};

//=================================================================================================

 class LIBZHL_API FunctionDefinition : public Definition
 {
 private:
 	char _shortName[128];
 	char _name[256];

 	const char *_sig;
 	const HookSystem::ArgData *_argdata;
 	int _nArgs;
 	void **_outFunc;
 	void *_address;
	const char* _module;

 	unsigned int _flags;

 private:
 	void SetName(const char *name, const char *type);

 public:
 	FunctionDefinition(const char *name, const type_info &type, const char *sig, const HookSystem::ArgData *argdata, int nArgs, unsigned int flags, void **outfunc, const char* module = NULL);
 	FunctionDefinition(const char* name, const type_info& type, void* addr, const HookSystem::ArgData* argdata, int nArgs, unsigned int flags, void** outfunc, const char* module = NULL);

 	virtual int Load();
 	const char* GetName() const override;
 	bool IsFunction() const override;

 	bool IsThiscall() const {return (_flags & HookSystem::THISCALL) != 0;}
 	bool NeedsCallerCleanup() const {return (_flags & HookSystem::CLEANUP) != 0;}
 	bool IsVoid() const {return (_flags & HookSystem::VOID) != 0;}
 	bool IsLongLong() const {return (_flags & HookSystem::LONGLONG) != 0;}

 	const HookSystem::ArgData *GetArgData() const {return _argdata;}
 	int GetArgCount() const {return _nArgs;}
 	void *GetAddress() const {return _address;}
 };

//=================================================================================================

class LIBZHL_API VariableDefinition : public Definition
{
private:
	void *_outVar;
	const char *_name;
	const char *_sig;
	const bool _useValue;
	const bool _useOffset;

public:
	VariableDefinition::VariableDefinition(const char* name, const char* sig, void* outvar, bool useValue = true, bool useOffset = false) :
		_name(name),
		_sig(sig),
		_outVar(outvar),
		_useValue(useValue),
		_useOffset(useOffset)
	{
		Add(_name, this);
	}

	virtual int Load();
	virtual const char* GetName() const override;
	bool IsFunction() const override;
};

//=================================================================================================

 #define FUNCTIONHOOK_MAXSIZE 128

 class FunctionHook_private
 {
 protected:
 	char _shortName[128];
 	char _name[256];

 	void *_hook;
 	void **_outInternalSuper;

 	unsigned char _internalHook[FUNCTIONHOOK_MAXSIZE];
 	unsigned char _internalSuper[FUNCTIONHOOK_MAXSIZE];
 	unsigned int _hSize;
 	unsigned int _sSize;
 	int _priority;

 	MologieDetours::Detour<void*> *_detour = nullptr;
	
 public:
 	static int Init();
 	static const char *GetLastError();

 private:
 	static void Add(FunctionHook_private *hook);
 	void SetName(const char *name, const char *type);

 	[[nodiscard]] static unsigned char* Push(HookSystem::GPRegisters reg, unsigned char* text);
 	[[nodiscard]] static unsigned char* Mov(HookSystem::GPRegisters dst, HookSystem::GPRegisters src, unsigned char* text);
 	[[nodiscard]] static unsigned char* Pop(HookSystem::GPRegisters reg, unsigned char* text);
 	[[nodiscard]] static unsigned char* Ret(unsigned short n, unsigned char* text);
 	[[nodiscard]] static unsigned char* DecrESP(unsigned char size, unsigned char* text);
 	[[nodiscard]] static unsigned char* IncrESP(unsigned char size, unsigned char* text);

 	[[nodiscard]] unsigned char* EmitPrologue(FunctionDefinition const* def, unsigned char* text);
 	[[nodiscard]] unsigned char* EmitEpilogue(FunctionDefinition const* def, unsigned char stackPos, unsigned char* text);

 protected:
 	virtual int Install();

 public:
 	FunctionHook_private(const char *name, const type_info &type, void *hook, void **outInternalSuper, int priority) :
 		_hook(hook),
 		_outInternalSuper(outInternalSuper),
 		_hSize(0),
 		_sSize(0),
 		_detour(NULL),
 		_priority(priority)
 	{
 		SetName(name, type.raw_name());
 		Add(this);
 	}
 	~FunctionHook_private();
 };

 class FunctionHookCustom_private : public FunctionHook_private {
 public:
 	using FunctionHook_private::FunctionHook_private;
 protected:
 	virtual int Install() override;
 };