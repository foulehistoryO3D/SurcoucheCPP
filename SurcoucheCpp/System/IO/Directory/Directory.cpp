#include "Directory.h"
#include "DirectoryInfo/DirectoryInfo.h"
#include "../../Exception/Exception/Exception.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/Integer/Integer.h"
#include "../../Collection/Generic/List/List.h"

#include <direct.h>
#include <iostream>
#include <Windows.h>

System::IO::DirectoryInfo System::IO::Directory::MakeDirectory(const String& _path)
{
    DirectoryInfo _directoryInfo = DirectoryInfo(_path);
    if (_directoryInfo.Exists()) return _directoryInfo;
    const int _result = _mkdir(_path.ToCstr());
    if (_result != 0) throw Exception("error when creating the directory");
    return _directoryInfo;
}

void System::IO::Directory::Delete(const String& _path, bool _sub)
{
    const DirectoryInfo _directoryInfo = DirectoryInfo(_path);
    if (!_directoryInfo.Exists())
        throw Exception("[Directory] => doesn't exist can't delete this");
    if (_sub)
    {
        Collections::Generic::List<String> _directories = GetDirectories(_path);
        for (int i = 0; i < _directories.Count();i++)
        {
            const DirectoryInfo _subDirectoryInfo = DirectoryInfo(_directories[i]);
            if (_subDirectoryInfo.Exists())
                _subDirectoryInfo.Delete();
        }
    }
    _rmdir(_path);
}

System::Collections::Generic::List<System::String> System::IO::Directory::GetDirectories(const String& _path)
{
    Collections::Generic::List<String> _result = System::Collections::Generic::List<String>();
    String _currentDirectory = _path;
    _currentDirectory.Append("/*");
    HANDLE _hFind = HANDLE();
    WIN32_FIND_DATAA _findData;
    _hFind = FindFirstFileA(_currentDirectory, &_findData);
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
