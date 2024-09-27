#include <windows.h>
#include <filesystem>
#include <string>
#include "ini.h"

namespace fs = std::filesystem;

struct Config {
    mINI::INIStructure ini;
    std::string path = "config.ini";
    std::string exePath;
    std::string cliArgs;
    bool suspend;

    void Init() {
        mINI::INIFile iniFile(path);
        
        if (!fs::exists(path)) {
            ini["config"]["ExePath"] = "GameClientApp.exe";
            ini["config"]["CliArgs"] = "--BNetServer=bnet-emu.fish:1119";
            ini["config"]["Suspend"] = "0";
            
            iniFile.generate(ini, false);
        }

        iniFile.read(ini);

        exePath = std::string(ini["config"]["ExePath"]);
        cliArgs = std::string(ini["config"]["CliArgs"]);
        suspend = std::string(ini["config"]["Suspend"]) == "1";
    }

    bool Write(const char* category, const char* field, const char* value) {
        mINI::INIFile iniFile(path);
        ini[category][field] = value;
        return iniFile.write(ini);
    }

    void Save() {
        Write("config", "ExePath", exePath.c_str());
        Write("config", "CliArgs", cliArgs.c_str());
        Write("config", "Suspend", suspend ? "1" : "0");
    }
};

extern Config config;
