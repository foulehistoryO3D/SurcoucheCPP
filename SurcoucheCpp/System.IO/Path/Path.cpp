#include "Path.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System.Collections.Generic/List/List.h"

System::String System::IO::Path::GetPath(const String& _path)
{
    const String _result = _path;
    return _result.Replace(DirectorySeparatorChar, '\\');
}

System::String System::IO::Path::Combine(const String& _a, const String& _b)
{
    const String _res = _a + "/" + _b;
    return GetPath(_res);
}

System::String System::IO::Path::Combine(const String& _a, const String& _b, const String& _c)
{
    const String _result = _a + "/" + _b + "/" + _c;
    return GetPath(_result);
}

System::String System::IO::Path::Combine(const String& _a, const String& _b, const String& _c, const String& _d)
{
    const String _result = _a + "/" + _b + "/" + _c + "/" + _d;
    return GetPath(_result);
}

System::String System::IO::Path::Combine(Collections::Generic::List<String> _str)
{
    String _res = _str[0];
    _res.Append(DirectorySeparatorChar);
    const int _length = _str.Count();
    for (int i = 1; i < _length; i++)
    {
        _res.Append(_str[i]);
        _res.Append(DirectorySeparatorChar);
    }
    _res = GetPath(_res);
    return _res;
}

System::String System::IO::Path::GetExtension(const String& _path)
{
    // if (!File::Exist(_path)) throw Exception("path invalid !");
    // const Int& _index = _path.FindLastOf('.');
    // const Int& _length = _path.Length();
    // const String& _result = _path.SubString(_index, _length);
    // return _result;
    return "";
}

System::String System::IO::Path::GetFileNameWithoutExtension(const String& _path)
{
    // if (!File::Exist(_path)) throw std::exception("path invalid !");
    // const Int& _index = _path.FindLastOf('.');
    // const String& _result = _path.SubString(0, _index);
    // return _result;
    return "";
}

System::String System::IO::Path::GetDirectoryPath(const String& _path)
{
    const String& _pathValid = GetPath(_path);
    const Int& _index = _path.LastIndexOf('\\');
    return _pathValid.SubString(0, _index);;
}

System::Boolean System::IO::Path::HasExtension(const String& _path)
{
    const String& _pathValid = GetPath(_path);
    if (_pathValid[_pathValid.Length() - 1] == '\\') return false;
    const Int& _index = _path.LastIndexOf('.');
    if (_index == -1) return false;
    return true;
}
