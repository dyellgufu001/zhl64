#pragma once

#include <unordered_map>
#include <map>
#include <string>
#include <list>

#include "libzhl.h"

class LIBZHL_API SigScan
{
public:
	class Match
	{
	public:
		Match(short b, short n) : address(0), begin(b), length(n) {}
		~Match() {}

		unsigned char *address;
		short begin;
		short length;
	};

	typedef void (*Callback)(SigScan *scan);

	class Module
	{
	public:
		Module() : base(NULL), baseLen(0) {}
		Module(unsigned char* b, size_t l) : base(b), baseLen(l) {}
		~Module() {}

		unsigned char* base;
		size_t baseLen;
	};

private:
	static unsigned char *s_pLastStartAddress;
	static unsigned char *s_pLastAddress;
	static std::list<Match> s_lastMatches;
	static std::unordered_map<std::string, Module> s_modules;

private:
	size_t m_iLength;
	unsigned char *m_sig;
	unsigned char *m_mask;
	std::list<Match> m_matches;

	bool m_bNoReturnSeek;
	bool m_bStartFromLastAddress;

	unsigned char *m_pAddress;
	char m_moduleName[256];
	std::string m_moduleNameStr;
	int m_dist;

public:
	SigScan(const char *sig, const char* moduleNameCstr = NULL);
	~SigScan();

	bool Scan(Callback callback = NULL);

	void *GetAddress() const {return m_pAddress;}
	template <class T> T GetAddress() const
	{
		return reinterpret_cast<T>(m_pAddress);
	}
	int GetDistance() const {return m_dist;}

	int GetMatchCount() const {return m_matches.size();}
	const Match &GetMatch(int i = 0) const
	{
		auto it = m_matches.cbegin();
		for( ; i && it != m_matches.cend() ; ++it, --i);
		return *it;
	}

	static void* GetBaseAddress(const char* name = NULL) {
		return (void*)s_modules[(name == NULL) ? "" : std::string(name)].base;
	}
	static size_t GetBaseLength(const char* name = NULL) {
		return s_modules[(name == NULL) ? "" : std::string(name)].baseLen;
	}

public:
	static void Init();
	static void InitModule(const char* name);
};
