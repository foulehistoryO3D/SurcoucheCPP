#include "DirectoryInfo.h"
#include "../../../PrimaryType/String/String.h"
#include "../../../PrimaryType/Boolean/Boolean.h"
#include <direct.h>
#include <iostream>
#include <ctime>
#include <sys/stat.h>
#include <Windows.h>

#pragma region override
System::String System::IO::DirectoryInfo::FullPath() const
{
    return FileSystemInfo::FullPath();
}


System::String System::IO::DirectoryInfo::Extension() const
{
    return "";
}

System::Boolean System::IO::DirectoryInfo::Exists() const
{
    struct stat _info;
    if (stat(mPath, &_info) != 0) return false;
    if (_info.st_mode & S_IFDIR) return true;
    return false;
}

void System::IO::DirectoryInfo::Delete()const
{
    _rmdir(mPath);
}

System::String System::IO::DirectoryInfo::ToString() const
{
    return FileSystemInfo::ToString();
}

size_t System::IO::DirectoryInfo::GetHashCode() const
{
    DirectoryInfo _directoryInfo = *this;
    return std::hash<DirectoryInfo*>{}(&_directoryInfo);
}
#pragma endregion override
