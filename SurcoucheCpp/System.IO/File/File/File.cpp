#include "File.h"
#include "../../../System/DateTime/DateTime.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../Stream/StreamWriter/StreamWriter.h"
#include "../../Stream/StreamReader/StreamReader.h"
#include "../../../System.Collections.Generic/List/List.h"
#include "../FileStream/FileStream.h"

#include <direct.h>
#include <fstream>
#include <iostream>

#include "../../Directory/Directory.h"
#include "../../Directory/DirectoryInfo/DirectoryInfo.h"
#include "../../Exception/IOException/IOException.h"
#include "../../Path/Path.h"

#pragma region constructor
System::IO::File::File(const String& _path)
{
    mPath = _path;
}

System::IO::File::File(const File& _copy)
{
    mPath = _copy.mPath;
}

System::DateTime System::IO::File::GetCreationTime(const String& _path)
{
    struct stat _tStat;
    stat(_path, &_tStat);
    return DateTime::Convert(_tStat.st_ctime);
}

System::DateTime System::IO::File::GetLastAccessTime(const String& _path)
{
    struct stat _tStat;
    stat(_path, &_tStat);
    return DateTime::Convert(_tStat.st_atime);
}

System::DateTime System::IO::File::GetLastWriteTime(const String& _path)
{
    struct stat _tStat;
    stat(_path, &_tStat);
    return DateTime::Convert(_tStat.st_mtime);
}

void System::IO::File::Delete(const String& _path)
{
    if (!Exists(_path))return;
    DeleteFileA(_path);
}

System::Boolean System::IO::File::Exists(const String& _path)
{
    const std::ifstream _stream(_path);
    return _stream.good();
}

System::IO::FileStream System::IO::File::Create(const String& _path)
{
    const String& _directoryPath =Path::GetDirectoryName(_path);
    if (!Directory::Exists(_directoryPath))
        Directory::MakeDirectory(_directoryPath);
    
    if (Exists(_path))return FileStream(_path); //TODO return object of file
    std::ofstream _file = std::ofstream(_path);
    WIN32_FIND_DATAA _wfd;
    const HANDLE _hFind = FindFirstFileA(_path, &_wfd);
    if (_hFind != INVALID_HANDLE_VALUE)
        FindClose(_hFind);
    return FileStream(_path);
    
}

System::IO::StreamWriter System::IO::File::CreateText(const String& _path)
{
    if (Exists(_path)) return StreamWriter(_path);
    Create(_path);
    if (Exists(_path)) return StreamWriter(_path);
    return StreamWriter();
}

System::IO::StreamReader System::IO::File::OpenText(const String& _path)
{
    if (Exists(_path)) return StreamReader(_path);
    Create(_path);
    if (Exists(_path)) return StreamReader(_path);
    return StreamReader();
}

System::String System::IO::File::ReadAllText(const String& _path)
{
    StreamReader _reader = OpenText(_path);
    if (!_reader.IsValid()) return "";
    return _reader.ReadToEnd();
}

System::Collections::Generic::List<System::String> System::IO::File::ReadAllLines(const String& _path)
{
    StreamReader _reader = OpenText(_path);
    if (!_reader.IsValid()) return System::Collections::Generic::List<String>();
    Collections::Generic::List<String> _result = Collections::Generic::List<String>();
    String _str = String::Empty();
    while (_reader.ReadLine(_str))
        _result.Add(_str);
    return _result;
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
