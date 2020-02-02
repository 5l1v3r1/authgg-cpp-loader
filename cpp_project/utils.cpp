#include "utils.hpp"

bool utils::is_dll_valid;

void utils::check_dlls()
{ //borrowed code
	System::String^ trinityMD5 = "40182c14facac046a2d4e9141e615c80"; // AuthGG.dll hash goes here
	System::String^ NewtonMD5 = "a907da945d77abd7d7ad83bbcbd67b68"; // NewtonJson.dll hash goes here
	Handler::Handler hashcheck;
	System::String^ trinityDLLResult = (System::String^)hashcheck.CalculateMD5("AuthGG.dll");
	System::String^ NewtonDLLResult = (System::String^)hashcheck.CalculateMD5("Newtonsoft.Json.dll");
	if (trinityDLLResult != trinityMD5 || NewtonDLLResult != NewtonMD5)
	{
		MessageBox(0, "Hashcheck has failed!", "", MB_OK);
		utils::is_dll_valid = false;
		exit(0);
	}
	else
	{
		utils::is_dll_valid = true;
	}

}

std::string utils::wstring_to_string(const std::wstring& ws) {
	const std::string s(ws.begin(), ws.end());
	return s;
}

std::wstring utils::string_to_wstring(const std::string& s) {
	const std::wstring ws(s.begin(), s.end());
	return ws;
}
