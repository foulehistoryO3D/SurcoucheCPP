#include "FileSystemInfo.h"

#include <fstream>

#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../../System/PrimaryType/Integer/Integer.h"

#pragma region constructor
System::IO::FileSystemInfo::FileSystemInfo(const String& _path)
{
    mPath = _path;
}

System::IO::FileSystemInfo::FileSystemInfo(const FileSystemInfo& _fileSystemInfo)
{
    mPath = _fileSystemInfo.mPath;
}

System::String System::IO::FileSystemInfo::FullPath() const
{
    return mPath;
}

System::String System::IO::FileSystemInfo::Name() const
{
    const String _str = mPath;
    return _str.SubString(_str.LastIndexOf('\\')+1);
}

System::String System::IO::FileSystemInfo::Extension() const
{
    const String _path = FullPath();
    const int _index = _path.LastIndexOf('.');
    if (_index == -1) return string::Empty();
    return _path.SubString(_index, _path.Length());    
}

System::Boolean System::IO::FileSystemInfo::Exists() const
{
    const std::ifstream _stream(mPath);
    return _stream.good();
}
#pragma endregion constructor
#pragma region override
System::String System::IO::FileSystemInfo::ToString() const
{
    return mPath;
}

size_t System::IO::FileSystemInfo::GetHashCode() const
{
    FileSystemInfo _fileSystemInfo = *this;
    return std::hash<FileSystemInfo*>{}(&_fileSystemInfo);
}
#pragma endregion override