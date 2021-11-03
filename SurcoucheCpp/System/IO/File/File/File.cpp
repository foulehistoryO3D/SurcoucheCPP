#include "File.h"
#include "../../../PrimaryType/String/String.h"
#include "../../../PrimaryType/Boolean/Boolean.h"
#include "../../Stream/StreamWriter/StreamWriter.h"
#include <fstream>

#pragma region constructor
System::IO::File::File(const String& _path)
{
    mPath = _path;
}

System::IO::File::File(const File& _copy)
{
    mPath = _copy.mPath;
}

System::Boolean System::IO::File::Exists(const String& _path)
{
    const std::ifstream _stream(_path);
    return _stream.good();
}

void System::IO::File::Create(const String& _path)
{
    if (Exists(_path))return; //TODO return object of file
    std::ofstream _file = std::ofstream(_path);
    WIN32_FIND_DATAA _wfd;
    const HANDLE _hFind = FindFirstFileA(_path, &_wfd);
    if (_hFind != INVALID_HANDLE_VALUE)
        FindClose(_hFind);
}

System::IO::StreamWriter System::IO::File::CreateText(const String& _path)
{
    if (Exists(_path)) return StreamWriter(_path);
    Create(_path);
    if (Exists(_path)) return StreamWriter(_path);
    return StreamWriter();
}
#pragma endregion constructor
#pragma region override
System::Boolean System::IO::File::Equals(const object* object)
{
    return this == object;
}

System::Boolean System::IO::File::Equals(const object& object)
{
    return this == &object;
}

size_t System::IO::File::GetHashCode() const
{
    File _file = *this;
    return std::hash<File*>{}(&_file);
}
#pragma endregion override
