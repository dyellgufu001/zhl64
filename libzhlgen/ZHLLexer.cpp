
// Generated from .\ZHLLexer.g4 by ANTLR 4.12.0


#include "ZHLLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ZHLLexerStaticData final {
  ZHLLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ZHLLexerStaticData(const ZHLLexerStaticData&) = delete;
  ZHLLexerStaticData(ZHLLexerStaticData&&) = delete;
  ZHLLexerStaticData& operator=(const ZHLLexerStaticData&) = delete;
  ZHLLexerStaticData& operator=(ZHLLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag zhllexerLexerOnceFlag;
ZHLLexerStaticData *zhllexerLexerStaticData = nullptr;

void zhllexerLexerInitialize() {
  assert(zhllexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<ZHLLexerStaticData>(
    std::vector<std::string>{
      "DoubleQuote", "Colon", "Semi", "Qualifier", "Cleanup", "Static", 
      "Virtual", "Declspec", "External", "LeftParen", "RightParen", "Comma", 
      "Star", "Lt", "Gt", "LeftRBracket", "RightRBracket", "LeftBracket", 
      "RightBracket", "Class", "Struct", "Reference", "Depends", "Typedef", 
      "Const", "CppRef", "Unsigned", "Signed", "Long", "Int", "Short", "Char", 
      "Bool", "Float", "Double", "Void", "Type", "Size", "Synonym", "Align", 
      "Vtable", "Skip", "Pure", "Override", "Debug", "Visibility", "Public", 
      "Private", "Protected", "Register", "GeneralPurposeRegister", "Eax", 
      "Ebx", "Ecx", "Edx", "Esi", "Edi", "Esp", "Ebp", "SSERegister", "Xmm0", 
      "Xmm1", "Xmm2", "Xmm3", "Xmm4", "Xmm5", "Xmm6", "Xmm7", "CallingConvention", 
      "Stdcall", "Cdecl", "Fastcall", "Thiscall", "X8664", "X8664_Output", 
      "Signature", "ReferenceSignature", "Operator", "OpSymbol", "Name", 
      "Number", "HexNumber", "DecNumber", "GenericCode", "Whitespace", "Newline", 
      "BlockComment", "LineComment", "Any"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'\"'", "':'", "';'", "", "'cleanup'", "'static'", "'virtual'", 
      "'__declspec'", "'external'", "'('", "')'", "','", "'*'", "'<'", "'>'", 
      "'['", "']'", "'{'", "'}'", "'class'", "'struct'", "'reference'", 
      "'depends'", "'typedef'", "'const'", "'&'", "'unsigned'", "'signed'", 
      "'long'", "'int'", "'short'", "'char'", "'bool'", "'float'", "'double'", 
      "'void'", "'TypeInfo'", "'Size'", "'Synonym'", "'Align'", "'__vtable'", 
      "'skip'", "'pure'", "'override'", "'debug'", "", "'public'", "'private'", 
      "'protected'", "", "", "'eax'", "'ebx'", "'ecx'", "'edx'", "'esi'", 
      "'edi'", "'esp'", "'ebp'", "", "'xmm0'", "'xmm1'", "'xmm2'", "'xmm3'", 
      "'xmm4'", "'xmm5'", "'xmm6'", "'xmm7'", "", "'__stdcall'", "'__cdecl'", 
      "'__fastcall'", "'__thiscall'", "'__x86_64'", "'__x86_64_output'", 
      "", "", "'operator'"
    },
    std::vector<std::string>{
      "", "DoubleQuote", "Colon", "Semi", "Qualifier", "Cleanup", "Static", 
      "Virtual", "Declspec", "External", "LeftParen", "RightParen", "Comma", 
      "Star", "Lt", "Gt", "LeftRBracket", "RightRBracket", "LeftBracket", 
      "RightBracket", "Class", "Struct", "Reference", "Depends", "Typedef", 
      "Const", "CppRef", "Unsigned", "Signed", "Long", "Int", "Short", "Char", 
      "Bool", "Float", "Double", "Void", "Type", "Size", "Synonym", "Align", 
      "Vtable", "Skip", "Pure", "Override", "Debug", "Visibility", "Public", 
      "Private", "Protected", "Register", "GeneralPurposeRegister", "Eax", 
      "Ebx", "Ecx", "Edx", "Esi", "Edi", "Esp", "Ebp", "SSERegister", "Xmm0", 
      "Xmm1", "Xmm2", "Xmm3", "Xmm4", "Xmm5", "Xmm6", "Xmm7", "CallingConvention", 
      "Stdcall", "Cdecl", "Fastcall", "Thiscall", "X8664", "X8664_Output", 
      "Signature", "ReferenceSignature", "Operator", "OpSymbol", "Name", 
      "Number", "HexNumber", "DecNumber", "GenericCode", "Whitespace", "Newline", 
      "BlockComment", "LineComment", "Any"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,89,743,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,2,70,
  	7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,76,2,77,
  	7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,83,2,84,
  	7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,3,3,191,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,
  	9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,
  	16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,
  	20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,
  	22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,26,1,
  	26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,1,28,1,
  	28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,31,1,
  	31,1,31,1,31,1,31,1,32,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,1,33,1,
  	33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,36,1,
  	36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,1,37,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,39,1,39,1,39,1,40,1,
  	40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,42,1,
  	42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,44,1,
  	44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,3,45,427,8,45,1,46,1,46,1,46,1,
  	46,1,46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,1,47,1,47,1,48,1,48,1,
  	48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,49,1,49,3,49,456,8,49,1,50,1,
  	50,1,50,1,50,1,50,1,50,1,50,1,50,3,50,466,8,50,1,51,1,51,1,51,1,51,1,
  	52,1,52,1,52,1,52,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,55,1,55,1,
  	55,1,55,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,58,1,
  	59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,3,59,508,8,59,1,60,1,60,1,60,1,
  	60,1,60,1,61,1,61,1,61,1,61,1,61,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,
  	63,1,63,1,63,1,64,1,64,1,64,1,64,1,64,1,65,1,65,1,65,1,65,1,65,1,66,1,
  	66,1,66,1,66,1,66,1,67,1,67,1,67,1,67,1,67,1,68,1,68,1,68,1,68,1,68,1,
  	68,3,68,556,8,68,1,69,1,69,1,69,1,69,1,69,1,69,1,69,1,69,1,69,1,69,1,
  	70,1,70,1,70,1,70,1,70,1,70,1,70,1,70,1,71,1,71,1,71,1,71,1,71,1,71,1,
  	71,1,71,1,71,1,71,1,71,1,72,1,72,1,72,1,72,1,72,1,72,1,72,1,72,1,72,1,
  	72,1,72,1,73,1,73,1,73,1,73,1,73,1,73,1,73,1,73,1,73,1,74,1,74,1,74,1,
  	74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,74,1,75,1,
  	75,3,75,625,8,75,1,75,4,75,628,8,75,11,75,12,75,629,1,75,1,75,1,75,1,
  	76,1,76,3,76,637,8,76,1,76,4,76,640,8,76,11,76,12,76,641,1,76,1,76,1,
  	76,1,77,1,77,1,77,1,77,1,77,1,77,1,77,1,77,1,77,1,78,1,78,3,78,658,8,
  	78,1,78,1,78,1,78,3,78,663,8,78,1,79,1,79,5,79,667,8,79,10,79,12,79,670,
  	9,79,1,80,1,80,3,80,674,8,80,1,81,1,81,1,81,1,81,4,81,680,8,81,11,81,
  	12,81,681,1,82,4,82,685,8,82,11,82,12,82,686,1,83,1,83,1,83,1,83,5,83,
  	693,8,83,10,83,12,83,696,9,83,1,83,1,83,1,83,1,84,4,84,702,8,84,11,84,
  	12,84,703,1,84,1,84,1,85,1,85,3,85,710,8,85,1,85,3,85,713,8,85,1,85,1,
  	85,1,86,1,86,1,86,1,86,5,86,721,8,86,10,86,12,86,724,9,86,1,86,1,86,1,
  	86,1,86,1,86,1,87,1,87,1,87,1,87,5,87,735,8,87,10,87,12,87,738,9,87,1,
  	87,1,87,1,88,1,88,2,694,722,0,89,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,
  	21,43,22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,
  	65,33,67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,
  	44,89,45,91,46,93,47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,
  	55,111,56,113,57,115,58,117,59,119,60,121,61,123,62,125,63,127,64,129,
  	65,131,66,133,67,135,68,137,69,139,70,141,71,143,72,145,73,147,74,149,
  	75,151,76,153,77,155,78,157,79,159,80,161,81,163,82,165,83,167,84,169,
  	85,171,86,173,87,175,88,177,89,1,0,9,4,0,48,57,63,63,65,70,97,102,5,0,
  	40,41,48,57,63,63,65,70,97,102,3,0,42,43,45,45,47,47,3,0,65,90,95,95,
  	97,122,4,0,48,57,65,90,95,95,97,122,3,0,48,57,65,70,97,102,1,0,48,57,
  	2,0,9,9,32,32,2,0,10,10,13,13,785,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,
  	0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,
  	0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,
  	0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,
  	39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,
  	0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,
  	0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,
  	71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,
  	0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,
  	0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,
  	103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,
  	113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,
  	123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,0,131,1,0,0,0,0,
  	133,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,0,141,1,0,0,0,0,
  	143,1,0,0,0,0,145,1,0,0,0,0,147,1,0,0,0,0,149,1,0,0,0,0,151,1,0,0,0,0,
  	153,1,0,0,0,0,155,1,0,0,0,0,157,1,0,0,0,0,159,1,0,0,0,0,161,1,0,0,0,0,
  	163,1,0,0,0,0,165,1,0,0,0,0,167,1,0,0,0,0,169,1,0,0,0,0,171,1,0,0,0,0,
  	173,1,0,0,0,0,175,1,0,0,0,0,177,1,0,0,0,1,179,1,0,0,0,3,181,1,0,0,0,5,
  	183,1,0,0,0,7,190,1,0,0,0,9,192,1,0,0,0,11,200,1,0,0,0,13,207,1,0,0,0,
  	15,215,1,0,0,0,17,226,1,0,0,0,19,235,1,0,0,0,21,237,1,0,0,0,23,239,1,
  	0,0,0,25,241,1,0,0,0,27,243,1,0,0,0,29,245,1,0,0,0,31,247,1,0,0,0,33,
  	249,1,0,0,0,35,251,1,0,0,0,37,253,1,0,0,0,39,255,1,0,0,0,41,261,1,0,0,
  	0,43,268,1,0,0,0,45,278,1,0,0,0,47,286,1,0,0,0,49,294,1,0,0,0,51,300,
  	1,0,0,0,53,302,1,0,0,0,55,311,1,0,0,0,57,318,1,0,0,0,59,323,1,0,0,0,61,
  	327,1,0,0,0,63,333,1,0,0,0,65,338,1,0,0,0,67,343,1,0,0,0,69,349,1,0,0,
  	0,71,356,1,0,0,0,73,361,1,0,0,0,75,370,1,0,0,0,77,375,1,0,0,0,79,383,
  	1,0,0,0,81,389,1,0,0,0,83,398,1,0,0,0,85,403,1,0,0,0,87,408,1,0,0,0,89,
  	417,1,0,0,0,91,426,1,0,0,0,93,428,1,0,0,0,95,435,1,0,0,0,97,443,1,0,0,
  	0,99,455,1,0,0,0,101,465,1,0,0,0,103,467,1,0,0,0,105,471,1,0,0,0,107,
  	475,1,0,0,0,109,479,1,0,0,0,111,483,1,0,0,0,113,487,1,0,0,0,115,491,1,
  	0,0,0,117,495,1,0,0,0,119,507,1,0,0,0,121,509,1,0,0,0,123,514,1,0,0,0,
  	125,519,1,0,0,0,127,524,1,0,0,0,129,529,1,0,0,0,131,534,1,0,0,0,133,539,
  	1,0,0,0,135,544,1,0,0,0,137,555,1,0,0,0,139,557,1,0,0,0,141,567,1,0,0,
  	0,143,575,1,0,0,0,145,586,1,0,0,0,147,597,1,0,0,0,149,606,1,0,0,0,151,
  	622,1,0,0,0,153,634,1,0,0,0,155,646,1,0,0,0,157,662,1,0,0,0,159,664,1,
  	0,0,0,161,673,1,0,0,0,163,675,1,0,0,0,165,684,1,0,0,0,167,688,1,0,0,0,
  	169,701,1,0,0,0,171,712,1,0,0,0,173,716,1,0,0,0,175,730,1,0,0,0,177,741,
  	1,0,0,0,179,180,5,34,0,0,180,2,1,0,0,0,181,182,5,58,0,0,182,4,1,0,0,0,
  	183,184,5,59,0,0,184,6,1,0,0,0,185,191,3,9,4,0,186,191,3,11,5,0,187,191,
  	3,13,6,0,188,191,3,15,7,0,189,191,3,89,44,0,190,185,1,0,0,0,190,186,1,
  	0,0,0,190,187,1,0,0,0,190,188,1,0,0,0,190,189,1,0,0,0,191,8,1,0,0,0,192,
  	193,5,99,0,0,193,194,5,108,0,0,194,195,5,101,0,0,195,196,5,97,0,0,196,
  	197,5,110,0,0,197,198,5,117,0,0,198,199,5,112,0,0,199,10,1,0,0,0,200,
  	201,5,115,0,0,201,202,5,116,0,0,202,203,5,97,0,0,203,204,5,116,0,0,204,
  	205,5,105,0,0,205,206,5,99,0,0,206,12,1,0,0,0,207,208,5,118,0,0,208,209,
  	5,105,0,0,209,210,5,114,0,0,210,211,5,116,0,0,211,212,5,117,0,0,212,213,
  	5,97,0,0,213,214,5,108,0,0,214,14,1,0,0,0,215,216,5,95,0,0,216,217,5,
  	95,0,0,217,218,5,100,0,0,218,219,5,101,0,0,219,220,5,99,0,0,220,221,5,
  	108,0,0,221,222,5,115,0,0,222,223,5,112,0,0,223,224,5,101,0,0,224,225,
  	5,99,0,0,225,16,1,0,0,0,226,227,5,101,0,0,227,228,5,120,0,0,228,229,5,
  	116,0,0,229,230,5,101,0,0,230,231,5,114,0,0,231,232,5,110,0,0,232,233,
  	5,97,0,0,233,234,5,108,0,0,234,18,1,0,0,0,235,236,5,40,0,0,236,20,1,0,
  	0,0,237,238,5,41,0,0,238,22,1,0,0,0,239,240,5,44,0,0,240,24,1,0,0,0,241,
  	242,5,42,0,0,242,26,1,0,0,0,243,244,5,60,0,0,244,28,1,0,0,0,245,246,5,
  	62,0,0,246,30,1,0,0,0,247,248,5,91,0,0,248,32,1,0,0,0,249,250,5,93,0,
  	0,250,34,1,0,0,0,251,252,5,123,0,0,252,36,1,0,0,0,253,254,5,125,0,0,254,
  	38,1,0,0,0,255,256,5,99,0,0,256,257,5,108,0,0,257,258,5,97,0,0,258,259,
  	5,115,0,0,259,260,5,115,0,0,260,40,1,0,0,0,261,262,5,115,0,0,262,263,
  	5,116,0,0,263,264,5,114,0,0,264,265,5,117,0,0,265,266,5,99,0,0,266,267,
  	5,116,0,0,267,42,1,0,0,0,268,269,5,114,0,0,269,270,5,101,0,0,270,271,
  	5,102,0,0,271,272,5,101,0,0,272,273,5,114,0,0,273,274,5,101,0,0,274,275,
  	5,110,0,0,275,276,5,99,0,0,276,277,5,101,0,0,277,44,1,0,0,0,278,279,5,
  	100,0,0,279,280,5,101,0,0,280,281,5,112,0,0,281,282,5,101,0,0,282,283,
  	5,110,0,0,283,284,5,100,0,0,284,285,5,115,0,0,285,46,1,0,0,0,286,287,
  	5,116,0,0,287,288,5,121,0,0,288,289,5,112,0,0,289,290,5,101,0,0,290,291,
  	5,100,0,0,291,292,5,101,0,0,292,293,5,102,0,0,293,48,1,0,0,0,294,295,
  	5,99,0,0,295,296,5,111,0,0,296,297,5,110,0,0,297,298,5,115,0,0,298,299,
  	5,116,0,0,299,50,1,0,0,0,300,301,5,38,0,0,301,52,1,0,0,0,302,303,5,117,
  	0,0,303,304,5,110,0,0,304,305,5,115,0,0,305,306,5,105,0,0,306,307,5,103,
  	0,0,307,308,5,110,0,0,308,309,5,101,0,0,309,310,5,100,0,0,310,54,1,0,
  	0,0,311,312,5,115,0,0,312,313,5,105,0,0,313,314,5,103,0,0,314,315,5,110,
  	0,0,315,316,5,101,0,0,316,317,5,100,0,0,317,56,1,0,0,0,318,319,5,108,
  	0,0,319,320,5,111,0,0,320,321,5,110,0,0,321,322,5,103,0,0,322,58,1,0,
  	0,0,323,324,5,105,0,0,324,325,5,110,0,0,325,326,5,116,0,0,326,60,1,0,
  	0,0,327,328,5,115,0,0,328,329,5,104,0,0,329,330,5,111,0,0,330,331,5,114,
  	0,0,331,332,5,116,0,0,332,62,1,0,0,0,333,334,5,99,0,0,334,335,5,104,0,
  	0,335,336,5,97,0,0,336,337,5,114,0,0,337,64,1,0,0,0,338,339,5,98,0,0,
  	339,340,5,111,0,0,340,341,5,111,0,0,341,342,5,108,0,0,342,66,1,0,0,0,
  	343,344,5,102,0,0,344,345,5,108,0,0,345,346,5,111,0,0,346,347,5,97,0,
  	0,347,348,5,116,0,0,348,68,1,0,0,0,349,350,5,100,0,0,350,351,5,111,0,
  	0,351,352,5,117,0,0,352,353,5,98,0,0,353,354,5,108,0,0,354,355,5,101,
  	0,0,355,70,1,0,0,0,356,357,5,118,0,0,357,358,5,111,0,0,358,359,5,105,
  	0,0,359,360,5,100,0,0,360,72,1,0,0,0,361,362,5,84,0,0,362,363,5,121,0,
  	0,363,364,5,112,0,0,364,365,5,101,0,0,365,366,5,73,0,0,366,367,5,110,
  	0,0,367,368,5,102,0,0,368,369,5,111,0,0,369,74,1,0,0,0,370,371,5,83,0,
  	0,371,372,5,105,0,0,372,373,5,122,0,0,373,374,5,101,0,0,374,76,1,0,0,
  	0,375,376,5,83,0,0,376,377,5,121,0,0,377,378,5,110,0,0,378,379,5,111,
  	0,0,379,380,5,110,0,0,380,381,5,121,0,0,381,382,5,109,0,0,382,78,1,0,
  	0,0,383,384,5,65,0,0,384,385,5,108,0,0,385,386,5,105,0,0,386,387,5,103,
  	0,0,387,388,5,110,0,0,388,80,1,0,0,0,389,390,5,95,0,0,390,391,5,95,0,
  	0,391,392,5,118,0,0,392,393,5,116,0,0,393,394,5,97,0,0,394,395,5,98,0,
  	0,395,396,5,108,0,0,396,397,5,101,0,0,397,82,1,0,0,0,398,399,5,115,0,
  	0,399,400,5,107,0,0,400,401,5,105,0,0,401,402,5,112,0,0,402,84,1,0,0,
  	0,403,404,5,112,0,0,404,405,5,117,0,0,405,406,5,114,0,0,406,407,5,101,
  	0,0,407,86,1,0,0,0,408,409,5,111,0,0,409,410,5,118,0,0,410,411,5,101,
  	0,0,411,412,5,114,0,0,412,413,5,114,0,0,413,414,5,105,0,0,414,415,5,100,
  	0,0,415,416,5,101,0,0,416,88,1,0,0,0,417,418,5,100,0,0,418,419,5,101,
  	0,0,419,420,5,98,0,0,420,421,5,117,0,0,421,422,5,103,0,0,422,90,1,0,0,
  	0,423,427,3,93,46,0,424,427,3,95,47,0,425,427,3,97,48,0,426,423,1,0,0,
  	0,426,424,1,0,0,0,426,425,1,0,0,0,427,92,1,0,0,0,428,429,5,112,0,0,429,
  	430,5,117,0,0,430,431,5,98,0,0,431,432,5,108,0,0,432,433,5,105,0,0,433,
  	434,5,99,0,0,434,94,1,0,0,0,435,436,5,112,0,0,436,437,5,114,0,0,437,438,
  	5,105,0,0,438,439,5,118,0,0,439,440,5,97,0,0,440,441,5,116,0,0,441,442,
  	5,101,0,0,442,96,1,0,0,0,443,444,5,112,0,0,444,445,5,114,0,0,445,446,
  	5,111,0,0,446,447,5,116,0,0,447,448,5,101,0,0,448,449,5,99,0,0,449,450,
  	5,116,0,0,450,451,5,101,0,0,451,452,5,100,0,0,452,98,1,0,0,0,453,456,
  	3,101,50,0,454,456,3,119,59,0,455,453,1,0,0,0,455,454,1,0,0,0,456,100,
  	1,0,0,0,457,466,3,103,51,0,458,466,3,105,52,0,459,466,3,107,53,0,460,
  	466,3,109,54,0,461,466,3,111,55,0,462,466,3,113,56,0,463,466,3,115,57,
  	0,464,466,3,117,58,0,465,457,1,0,0,0,465,458,1,0,0,0,465,459,1,0,0,0,
  	465,460,1,0,0,0,465,461,1,0,0,0,465,462,1,0,0,0,465,463,1,0,0,0,465,464,
  	1,0,0,0,466,102,1,0,0,0,467,468,5,101,0,0,468,469,5,97,0,0,469,470,5,
  	120,0,0,470,104,1,0,0,0,471,472,5,101,0,0,472,473,5,98,0,0,473,474,5,
  	120,0,0,474,106,1,0,0,0,475,476,5,101,0,0,476,477,5,99,0,0,477,478,5,
  	120,0,0,478,108,1,0,0,0,479,480,5,101,0,0,480,481,5,100,0,0,481,482,5,
  	120,0,0,482,110,1,0,0,0,483,484,5,101,0,0,484,485,5,115,0,0,485,486,5,
  	105,0,0,486,112,1,0,0,0,487,488,5,101,0,0,488,489,5,100,0,0,489,490,5,
  	105,0,0,490,114,1,0,0,0,491,492,5,101,0,0,492,493,5,115,0,0,493,494,5,
  	112,0,0,494,116,1,0,0,0,495,496,5,101,0,0,496,497,5,98,0,0,497,498,5,
  	112,0,0,498,118,1,0,0,0,499,508,3,121,60,0,500,508,3,123,61,0,501,508,
  	3,125,62,0,502,508,3,127,63,0,503,508,3,129,64,0,504,508,3,131,65,0,505,
  	508,3,133,66,0,506,508,3,135,67,0,507,499,1,0,0,0,507,500,1,0,0,0,507,
  	501,1,0,0,0,507,502,1,0,0,0,507,503,1,0,0,0,507,504,1,0,0,0,507,505,1,
  	0,0,0,507,506,1,0,0,0,508,120,1,0,0,0,509,510,5,120,0,0,510,511,5,109,
  	0,0,511,512,5,109,0,0,512,513,5,48,0,0,513,122,1,0,0,0,514,515,5,120,
  	0,0,515,516,5,109,0,0,516,517,5,109,0,0,517,518,5,49,0,0,518,124,1,0,
  	0,0,519,520,5,120,0,0,520,521,5,109,0,0,521,522,5,109,0,0,522,523,5,50,
  	0,0,523,126,1,0,0,0,524,525,5,120,0,0,525,526,5,109,0,0,526,527,5,109,
  	0,0,527,528,5,51,0,0,528,128,1,0,0,0,529,530,5,120,0,0,530,531,5,109,
  	0,0,531,532,5,109,0,0,532,533,5,52,0,0,533,130,1,0,0,0,534,535,5,120,
  	0,0,535,536,5,109,0,0,536,537,5,109,0,0,537,538,5,53,0,0,538,132,1,0,
  	0,0,539,540,5,120,0,0,540,541,5,109,0,0,541,542,5,109,0,0,542,543,5,54,
  	0,0,543,134,1,0,0,0,544,545,5,120,0,0,545,546,5,109,0,0,546,547,5,109,
  	0,0,547,548,5,55,0,0,548,136,1,0,0,0,549,556,3,139,69,0,550,556,3,141,
  	70,0,551,556,3,143,71,0,552,556,3,145,72,0,553,556,3,147,73,0,554,556,
  	3,149,74,0,555,549,1,0,0,0,555,550,1,0,0,0,555,551,1,0,0,0,555,552,1,
  	0,0,0,555,553,1,0,0,0,555,554,1,0,0,0,556,138,1,0,0,0,557,558,5,95,0,
  	0,558,559,5,95,0,0,559,560,5,115,0,0,560,561,5,116,0,0,561,562,5,100,
  	0,0,562,563,5,99,0,0,563,564,5,97,0,0,564,565,5,108,0,0,565,566,5,108,
  	0,0,566,140,1,0,0,0,567,568,5,95,0,0,568,569,5,95,0,0,569,570,5,99,0,
  	0,570,571,5,100,0,0,571,572,5,101,0,0,572,573,5,99,0,0,573,574,5,108,
  	0,0,574,142,1,0,0,0,575,576,5,95,0,0,576,577,5,95,0,0,577,578,5,102,0,
  	0,578,579,5,97,0,0,579,580,5,115,0,0,580,581,5,116,0,0,581,582,5,99,0,
  	0,582,583,5,97,0,0,583,584,5,108,0,0,584,585,5,108,0,0,585,144,1,0,0,
  	0,586,587,5,95,0,0,587,588,5,95,0,0,588,589,5,116,0,0,589,590,5,104,0,
  	0,590,591,5,105,0,0,591,592,5,115,0,0,592,593,5,99,0,0,593,594,5,97,0,
  	0,594,595,5,108,0,0,595,596,5,108,0,0,596,146,1,0,0,0,597,598,5,95,0,
  	0,598,599,5,95,0,0,599,600,5,120,0,0,600,601,5,56,0,0,601,602,5,54,0,
  	0,602,603,5,95,0,0,603,604,5,54,0,0,604,605,5,52,0,0,605,148,1,0,0,0,
  	606,607,5,95,0,0,607,608,5,95,0,0,608,609,5,120,0,0,609,610,5,56,0,0,
  	610,611,5,54,0,0,611,612,5,95,0,0,612,613,5,54,0,0,613,614,5,52,0,0,614,
  	615,5,95,0,0,615,616,5,111,0,0,616,617,5,117,0,0,617,618,5,116,0,0,618,
  	619,5,112,0,0,619,620,5,117,0,0,620,621,5,116,0,0,621,150,1,0,0,0,622,
  	624,3,1,0,0,623,625,5,46,0,0,624,623,1,0,0,0,624,625,1,0,0,0,625,627,
  	1,0,0,0,626,628,7,0,0,0,627,626,1,0,0,0,628,629,1,0,0,0,629,627,1,0,0,
  	0,629,630,1,0,0,0,630,631,1,0,0,0,631,632,3,1,0,0,632,633,3,3,1,0,633,
  	152,1,0,0,0,634,636,3,1,0,0,635,637,5,46,0,0,636,635,1,0,0,0,636,637,
  	1,0,0,0,637,639,1,0,0,0,638,640,7,1,0,0,639,638,1,0,0,0,640,641,1,0,0,
  	0,641,639,1,0,0,0,641,642,1,0,0,0,642,643,1,0,0,0,643,644,3,1,0,0,644,
  	645,3,3,1,0,645,154,1,0,0,0,646,647,5,111,0,0,647,648,5,112,0,0,648,649,
  	5,101,0,0,649,650,5,114,0,0,650,651,5,97,0,0,651,652,5,116,0,0,652,653,
  	5,111,0,0,653,654,5,114,0,0,654,156,1,0,0,0,655,657,7,2,0,0,656,658,5,
  	61,0,0,657,656,1,0,0,0,657,658,1,0,0,0,658,663,1,0,0,0,659,660,5,61,0,
  	0,660,663,5,61,0,0,661,663,5,61,0,0,662,655,1,0,0,0,662,659,1,0,0,0,662,
  	661,1,0,0,0,663,158,1,0,0,0,664,668,7,3,0,0,665,667,7,4,0,0,666,665,1,
  	0,0,0,667,670,1,0,0,0,668,666,1,0,0,0,668,669,1,0,0,0,669,160,1,0,0,0,
  	670,668,1,0,0,0,671,674,3,163,81,0,672,674,3,165,82,0,673,671,1,0,0,0,
  	673,672,1,0,0,0,674,162,1,0,0,0,675,676,5,48,0,0,676,677,5,120,0,0,677,
  	679,1,0,0,0,678,680,7,5,0,0,679,678,1,0,0,0,680,681,1,0,0,0,681,679,1,
  	0,0,0,681,682,1,0,0,0,682,164,1,0,0,0,683,685,7,6,0,0,684,683,1,0,0,0,
  	685,686,1,0,0,0,686,684,1,0,0,0,686,687,1,0,0,0,687,166,1,0,0,0,688,689,
  	5,123,0,0,689,690,5,123,0,0,690,694,1,0,0,0,691,693,9,0,0,0,692,691,1,
  	0,0,0,693,696,1,0,0,0,694,695,1,0,0,0,694,692,1,0,0,0,695,697,1,0,0,0,
  	696,694,1,0,0,0,697,698,5,125,0,0,698,699,5,125,0,0,699,168,1,0,0,0,700,
  	702,7,7,0,0,701,700,1,0,0,0,702,703,1,0,0,0,703,701,1,0,0,0,703,704,1,
  	0,0,0,704,705,1,0,0,0,705,706,6,84,0,0,706,170,1,0,0,0,707,709,5,13,0,
  	0,708,710,5,10,0,0,709,708,1,0,0,0,709,710,1,0,0,0,710,713,1,0,0,0,711,
  	713,5,10,0,0,712,707,1,0,0,0,712,711,1,0,0,0,713,714,1,0,0,0,714,715,
  	6,85,0,0,715,172,1,0,0,0,716,717,5,47,0,0,717,718,5,42,0,0,718,722,1,
  	0,0,0,719,721,9,0,0,0,720,719,1,0,0,0,721,724,1,0,0,0,722,723,1,0,0,0,
  	722,720,1,0,0,0,723,725,1,0,0,0,724,722,1,0,0,0,725,726,5,42,0,0,726,
  	727,5,47,0,0,727,728,1,0,0,0,728,729,6,86,0,0,729,174,1,0,0,0,730,731,
  	5,47,0,0,731,732,5,47,0,0,732,736,1,0,0,0,733,735,8,8,0,0,734,733,1,0,
  	0,0,735,738,1,0,0,0,736,734,1,0,0,0,736,737,1,0,0,0,737,739,1,0,0,0,738,
  	736,1,0,0,0,739,740,6,87,0,0,740,176,1,0,0,0,741,742,9,0,0,0,742,178,
  	1,0,0,0,23,0,190,426,455,465,507,555,624,629,636,641,657,662,668,673,
  	681,686,694,703,709,712,722,736,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  zhllexerLexerStaticData = staticData.release();
}

}

ZHLLexer::ZHLLexer(CharStream *input) : Lexer(input) {
  ZHLLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *zhllexerLexerStaticData->atn, zhllexerLexerStaticData->decisionToDFA, zhllexerLexerStaticData->sharedContextCache);
}

ZHLLexer::~ZHLLexer() {
  delete _interpreter;
}

std::string ZHLLexer::getGrammarFileName() const {
  return "ZHLLexer.g4";
}

const std::vector<std::string>& ZHLLexer::getRuleNames() const {
  return zhllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ZHLLexer::getChannelNames() const {
  return zhllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ZHLLexer::getModeNames() const {
  return zhllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ZHLLexer::getVocabulary() const {
  return zhllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ZHLLexer::getSerializedATN() const {
  return zhllexerLexerStaticData->serializedATN;
}

const atn::ATN& ZHLLexer::getATN() const {
  return *zhllexerLexerStaticData->atn;
}




void ZHLLexer::initialize() {
  ::antlr4::internal::call_once(zhllexerLexerOnceFlag, zhllexerLexerInitialize);
}
