﻿#include "File.h"
#include "../../../System/DateTime/DateTime.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
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

System::IO::File::File(const File& copy) : Object(copy)
{
    mPath = copy.mPath;
}

System::DateTime System::IO::File::GetCreationTime() const
{
    return GetCreationTime(this->mPath);
}

System::DateTime System::IO::File::GetLastAccessTime() const
{
    return GetLastAccessTime(this->mPath);
}

System::DateTime System::IO::File::GetLastWriteTime() const
{
    return GetLastWriteTime(this->mPath);
}

void System::IO::File::Delete() const
{
    Delete(this->mPath);
}

System::IO::StreamReader System::IO::File::OpenReader() const
{
    return OpenText(this->mPath);
}

System::IO::StreamWriter System::IO::File::OpenWriter() const
{
    return CreateText(this->mPath);
}

System::String System::IO::File::ReadAllText() const
{
    return ReadAllText(this->mPath);
}

System::Collections::Generic::List<System::String> System::IO::File::ReadAllLines() const
{
    return ReadAllLines(this->mPath);
}

System::String System::IO::File::Path() const
{
    return this->mPath;
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

    const bool _value = DeleteFileA(_path);
    if (!_value)
        throw IOException("[File] error on delete file or the file instance is open !");
}

System::Boolean System::IO::File::Exists(const String& _path)
{
    const std::ifstream _stream = std::ifstream(_path);
    return _stream.good();
}

System::IO::FileStream System::IO::File::Create(const String& _path)
{
    const String& _directoryPath = Path::GetDirectoryPath(_path);
    if (!Directory::Exists(_directoryPath))
        Directory::MakeDirectory(_directoryPath);

    if (Exists(_path))return FileStream(_path);
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
    return StreamWriter(_path);
}

System::IO::StreamReader System::IO::File::OpenText(const String& _path)
{
    if (Exists(_path)) return StreamReader(_path);
    Create(_path);
    return StreamReader(_path);
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
    if (!_reader.IsValid())
        throw IOException("[File] error => path is not valid !");
    Collections::Generic::List<String> _result = Collections::Generic::List<String>();
    String _str = String::Empty;
    while (_reader.ReadLine(_str))
        _result.Add(_str);
    return _result;
}
#pragma endregion constructor
#pragma region override
System::Boolean System::IO::File::Equals(const object* object)
{
    const File& _file = *dynamic_cast<const File*>(object);
    return mPath == _file.mPath;
}

System::Boolean System::IO::File::Equals(const object& object)
{
    const File& _file = *dynamic_cast<const File*>(&object);
    return mPath == _file.mPath;
}

System::Integer System::IO::File::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::String System::IO::File::ToString() const
{
    return mPath;
}
#pragma endregion override
#pragma region operator

System::IO::File& System::IO::File::operator=(const File& other)
{
    this->mPath = other.mPath;
    return *this;
}
#pragma endregion operator
