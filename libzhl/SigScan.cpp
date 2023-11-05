#include "SigScan.h"
#include <string>
#include <Windows.h>

#include "hde.h"

unsigned char *SigScan::s_pLastStartAddress = 0;
unsigned char *SigScan::s_pLastAddress = 0;
std::list<SigScan::Match> SigScan::s_lastMatches;
std::unordered_map<std::string, SigScan::Module> SigScan::s_modules;

//=====================================================================

SigScan::SigScan(const char* sig, const char* name) : m_pAddress(0)
{
	m_moduleNameStr = (name == NULL) ? "" : std::string(name);

	if (s_modules.find(m_moduleNameStr) == s_modules.end()) {
		InitModule(name);
	}
	
	if (name != NULL) {
		strcpy(m_moduleName, name);
	}

	m_bStartFromLastAddress = false;
	m_bNoReturnSeek = false;
	m_dist = 0;

	// Default signature if nothing was specified
	if(!sig || !sig[0])
	{
		if(s_lastMatches.empty())
		{
			// Look for the first function after the last scanned function
			sig = ".558bec";
		}
		else
		{
			// Get remaining matches from the last scan
			s_lastMatches.pop_front();
			m_matches = s_lastMatches;
			m_iLength = 0;
			m_sig = NULL;
			m_mask = NULL;
			return;
		}
	}

	int len = 0;
	for(const char *p = sig ; *p ; ++p)
	{
		char c = *p;
		len += ((c>='a' && c<='f') || (c>='A' && c<='F') || (c>='0' && c<='9') || c=='?');
	}

	m_iLength = len / 2;
	m_sig = new unsigned char[m_iLength];
	m_mask = new unsigned char[m_iLength];

	unsigned char *ps = m_sig;
	unsigned char *pm = m_mask;

	bool b = false;

	short matchStart = -1;
	int i = 0;

	for(const char *p = sig ; *p ; ++p)
	{
		int c = *p;
		if(c == '.')
		{
			m_bStartFromLastAddress = true;
			continue;
		}

		if(c == '!')
		{
			m_bNoReturnSeek = true;
			continue;
		}

		if(c == '(')
		{
			matchStart = i;
			continue;
		}
		else if(c == ')')
		{
			m_matches.push_back(Match(matchStart, i - matchStart));

			matchStart = -1;
			continue;
		}

		if(c >= '0' && c <= '9') c -= '0';
		else if(c >= 'a' && c <= 'f') c -= ('a' - 10);
		else if(c >= 'A' && c <= 'F') c -= ('A' - 10);
		else c = -1;
		
		++p;

		int d = *p;
		if(!d) break;
		else if(d >= '0' && d <= '9') d -= '0';
		else if(d >= 'a' && d <= 'f') d -= ('a' - 10);
		else if(d >= 'A' && d <= 'F') d -= ('A' - 10);
		else d = -1;

		if(c >= 0 && d >= 0)
		{
			*(ps++) = (c << 4) | d;
			*(pm++) = 1;
		}
		else
		{
			*(ps++) = 0;
			*(pm++) = 0;
		}
		++i;
	}
}

//=====================================================================

SigScan::~SigScan()
{
	if(m_sig)
		delete[] m_sig;
	if(m_mask)
		delete[] m_mask;
}

bool SigScan::Scan(Callback callback)
{
	const unsigned char *usig = m_sig;
	if(!m_iLength)
	{
		m_pAddress = s_pLastStartAddress;
		return true;
	}

	short itn = 0;

	unsigned char *pStart = s_modules[m_moduleNameStr].base;
	unsigned char *pEnd = s_modules[m_moduleNameStr].base + s_modules[m_moduleNameStr].baseLen - m_iLength;

	if(m_bStartFromLastAddress)
		pStart = (unsigned char*)s_pLastAddress;

	for( ; pStart <= pEnd ; ++pStart)
	{
		const unsigned char *p = pStart;
		const unsigned char *s = usig;
		const unsigned char *m = m_mask;
		size_t i;

		for(i=0 ; i<m_iLength ; ++i, ++p, ++s, ++m)
			if(*m && *s != *p) break;

		if(i == m_iLength)
		{
			if(m_bStartFromLastAddress)
				m_dist = pStart-s_pLastAddress;
			else
				m_dist = pStart- s_modules[m_moduleNameStr].base;

			m_pAddress = pStart;

			// Find out where the function ends
			s_pLastStartAddress = pStart;

			s_pLastAddress = pStart;
			
			if(m_bNoReturnSeek)
			{
				s_pLastAddress = pStart + m_iLength;
			}
			else
			{
				T_HDE s = { 0 };
				int n = 0;
				do
				{
					n = HDE_DISASM(s_pLastAddress, &s);
					s_pLastAddress += n;
				} while(n && s.opcode != 0xc2 && s.opcode != 0xc3);

				if(!n)
				{
					// failed to find ret instruction for whatever reason
					s_pLastAddress = pStart + m_iLength;
				}
			}

			for(auto it = m_matches.begin() ; it != m_matches.end() ; ++it)
				it->address = m_pAddress + it->begin;

			s_lastMatches = m_matches;

			if(callback) callback(this);
			return true;
		}
	}

	s_pLastAddress = s_modules[m_moduleNameStr].base;
	return false;
}

//=====================================================================
void SigScan::Init()
{
	InitModule(NULL);
}

void SigScan::InitModule(const char* name)
{
	std::string moduleName = (name == NULL) ? "" : std::string(name);

	HMODULE hModule = GetModuleHandle(name);

	unsigned char* base = (unsigned char*)hModule;
	IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)base;
	IMAGE_NT_HEADERS* pe = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

	if (pe->Signature != IMAGE_NT_SIGNATURE)
	{
		base = 0;
		return;
	}

	size_t len = pe->OptionalHeader.SizeOfImage;

	s_modules.insert(std::pair(moduleName, Module(base, len)));
	s_pLastAddress = base;
}