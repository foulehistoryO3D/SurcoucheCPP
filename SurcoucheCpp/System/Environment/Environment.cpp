#include "Environment.h"
#include "../PrimaryType/String/String.h"
#include "../Collection/Generic/List/List.h"
#include <Windows.h>
#include <ShlObj_core.h>
#include <sstream>

#pragma warning(disable: 4996)

System::String System::Environment::CurrentDirectory()
{
    TCHAR buffer[MAX_PATH];
    GetCurrentDirectory(  MAX_PATH , buffer);
    std::wstring _arrW = buffer;
    std::wstring::size_type _pos = std::wstring(buffer).find_last_of(L"\\/");
    _arrW = _arrW.substr(0, _pos);
    const std::string _result(_arrW.begin(), _arrW.end());
    return _result.c_str();
}

System::String System::Environment::SpecialFolder(const System::SpecialFolder& _specialFolder)
{
    TCHAR buffer[MAX_PATH];
    SHGetSpecialFolderPath(0,buffer, (int)_specialFolder, FALSE);
    std::wstring _arrW = buffer;
    const std::string _result(_arrW.begin(), _arrW.end());
    return _result.c_str();
}

System::Collections::Generic::List<System::String> System::Environment::GetLogicalDrives()
{
    System::Collections::Generic::List<String> _result = System::Collections::Generic::List<String>();
    char* _szDrives = new char[MAX_PATH]();
    if (GetLogicalDriveStringsA(MAX_PATH, _szDrives))
        for (int i = 0; i < 100; i+=4)
            if (_szDrives[i] != (char)0)
                _result.Add(std::string{_szDrives[i],_szDrives[i+1],_szDrives[i+2]}.c_str());
    return _result;
}

System::String System::Environment::GetOsVersion()
{
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((LPOSVERSIONINFO)&info);
    String _result = GetOsName();
    char procID[10];
    sprintf(procID, "%d.%d", info.dwMajorVersion, info.dwMinorVersion);
    _result.Append(" v" );
    _result.Append(procID);
    return _result;
}

System::String System::Environment::GetOsName()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}

bool System::Environment::Is64BitProcess()
{
#ifdef _WIN32
    return false;
#else _WIN64
    return true;
#endif
}
