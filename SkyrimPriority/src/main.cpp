#include "common/IDebugLog.h"  // IDebugLog
#include "skse64_common/skse_version.h"  // RUNTIME_VERSION
#include "skse64/PluginAPI.h"  // SKSEInterface, PluginInfo
#include <ShlObj.h>  // CSIDL_MYDOCUMENTS
#include "SkyrimPriority/toml.hpp"
#include <fstream> //required for toml::parse_file()
#include <filesystem>
#include "version.h"  // VERSION_VERSTRING, VERSION_MAJOR

bool SKSEPlugin_Load(const SKSEInterface* a_skse)
{
	_MESSAGE("[Info] Parsing config");

	int priority;
	if (std::filesystem::exists("Data/SKSE/Plugins/SkyrimPriority.toml"))
	{
		auto config = toml::parse_file("Data/SKSE/Plugins/SkyrimPriority.toml");
		priority = config["SkyrimPriority"]["priority"].value_or(HIGH_PRIORITY_CLASS);
	}
	else
	{
		_MESSAGE("[Warning] Missing config file: \"Data/SKSE/Plugins/SkyrimPriority.toml\"");
		priority = HIGH_PRIORITY_CLASS;
	}

	_MESSAGE("[Info] Priority set to %d", priority);

	SetPriorityClass(GetCurrentProcess(), priority);

	_MESSAGE("[Info] Completed");
	return true;
}

extern "C" {
	bool SKSEPlugin_Query(const SKSEInterface* a_skse, PluginInfo* a_info)
	{
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\My Games\\Skyrim Special Edition\\SKSE\\SkyrimPriority.log");

		gLog.SetPrintLevel(IDebugLog::kLevel_DebugMessage);
		gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);

		_MESSAGE("SkyrimPriority v%s", MYFP_VERSION_VERSTRING);

		a_info->infoVersion = PluginInfo::kInfoVersion;
		a_info->name = "SkyrimPriority";
		a_info->version = MYFP_VERSION_MAJOR;

		if (a_skse->isEditor) {
			_FATALERROR("[FATAL ERROR] Loaded in editor, marking as incompatible!\n");
			return false;
		}
		/*
		else if (a_skse->runtimeVersion < RUNTIME_VERSION_1_5_97) {
			_FATALERROR("[FATAL ERROR] Unsupported runtime version %08X!\n", a_skse->runtimeVersion);
			return false;
		}
		*/

		return true;
	}
};
