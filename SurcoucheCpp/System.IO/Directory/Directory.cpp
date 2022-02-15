#include "Directory.h"
#include "DirectoryInfo/DirectoryInfo.h"
#include "../../System/Exception/Exception/Exception.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System.Collections.Generic/List/List.h"

#include <direct.h>
#include <iostream>
#include <Windows.h>

#include "../Exception/IOException/IOException.h"
#include "../File/File/File.h"
#include "../Path/Path.h"

System::IO::DirectoryInfo System::IO::Directory::MakeDirectory(const String& _path)
{
    DirectoryInfo _directoryInfo = DirectoryInfo(_path);
    if (_directoryInfo.Exists()) return _directoryInfo;
    const int _result = _mkdir(_path.ToCstr());
    if (_result != 0) throw Exception("error when creating the directory");
    return _directoryInfo;
}

System::IO::DirectoryInfo System::IO::Directory::GetDirectory(const String& _path)
{
    const DirectoryInfo _directoryInfo = DirectoryInfo(_path);
    if (!_directoryInfo.Exists())
        throw IOException("[Directory] => doesn't exist");
    return _directoryInfo;
}

void System::IO::Directory::Delete(const String& _path, bool _sub)
{
    const DirectoryInfo _directoryInfo = DirectoryInfo(_path);
    if (!_directoryInfo.Exists())
        throw IOException(string("[Directory]") + _path + " => doesn't exist can't delete this");
    if (_sub)
    {
        Collections::Generic::List<String> _directories = GetDirectories(_path);
        for (int i = 0; i < _directories.Count(); i++)
        {
            const DirectoryInfo _subDirectoryInfo = DirectoryInfo(_directories[i]);
            if (_subDirectoryInfo.Exists())
                _subDirectoryInfo.Delete();
        }
    }
    _directoryInfo.Delete();
}

System::Collections::Generic::List<System::String> System::IO::Directory::GetDirectories(const String& _path)
{
    Collections::Generic::List<String> _result = System::Collections::Generic::List<String>();
    String _currentDirectory = _path;
    _currentDirectory.Append("/*");
    WIN32_FIND_DATAA _findData;
    const HANDLE _hFind = FindFirstFileA(_currentDirectory, &_findData);
    if (_hFind == INVALID_HANDLE_VALUE)return _result;
    do
    {
        if (_findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            const String& _str = _path + "\\" + _findData.cFileName;
            _result.Add(_str);
        }
    }
    while (FindNextFileA(_hFind, &_findData));
    FindClose(_hFind);
    return _result;
}

System::Collections::Generic::List<System::IO::File> System::IO::Directory::GetFiles(
    const String& _path, const String& ext)
{
    Collections::Generic::List<File> _result = System::Collections::Generic::List<File>();
    String _currentDirectory = _path;
    _currentDirectory.Append("/*");
    WIN32_FIND_DATAA _findData;
    const HANDLE _hFind = FindFirstFileA(_currentDirectory, &_findData);
    if (_hFind == INVALID_HANDLE_VALUE)return _result;
    do
    {
        if (_findData.dwFileAttributes & 32)
        {
            const String& _str = _path + "\\" + _findData.cFileName;
            if (!string::IsNullOrEmpty(ext) && Path::GetExtension(_str) == ext)
                _result.Add(File(_str));
        }
    }
    while (FindNextFileA(_hFind, &_findData));
    FindClose(_hFind);
    return _result;
}

void System::IO::Directory::Move(const String& _path, const String& _newLocation)
{
    const String _newLocationFullPath = _newLocation + _path.SubString(_path.LastIndexOf('\\'), _path.Length());
    if (string::IsNullOrEmpty(_path) || string::IsNullOrEmpty(_newLocation))
        throw Exception("[Directory] => Move => path or new location is null");
    if (!MoveFileEx(_path.ToWString()->c_str(), _newLocationFullPath.ToWString()->c_str(), MOVEFILE_WRITE_THROUGH))
        throw Exception("[Directory] error on moving directory");
}

System::IO::DirectoryInfo System::IO::Directory::GetParent(const String& _path)
{
    return DirectoryInfo(_path.SubString(0, _path.LastIndexOf('\\')));
}

System::Boolean System::IO::Directory::Exists(const String& _path)
{
    struct stat _info;
    if (stat(_path.ToCstr(), &_info) != 0) return false;
    if (_info.st_mode & S_IFDIR) return true;
    return false;
}
