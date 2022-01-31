#include "DirectoryInfo.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
#include "../../../System/DateTime/DateTime.h"
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

System::Integer System::IO::DirectoryInfo::GetHashCode() const
{
    return super::GetHashCode();
}

System::DateTime System::IO::DirectoryInfo::GetCreationTime() const
{
    struct stat _tStat;
    stat(mPath, &_tStat);
    return DateTime::Convert(_tStat.st_ctime);
}

System::DateTime System::IO::DirectoryInfo::GetLastAccessTime() const
{
    struct stat _tStat;
    stat(mPath, &_tStat);
    return DateTime::Convert(_tStat.st_atime);
}

System::DateTime System::IO::DirectoryInfo::GetLastWriteTime() const
{
    struct stat _tStat;
    stat(mPath, &_tStat);
    return DateTime::Convert(_tStat.st_mtime);
}
#pragma endregion override
