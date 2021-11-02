#include "Path.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/Integer/Integer.h"
#include "../../Collection/Generic/List/List.h"

System::String System::IO::Path::GetPath(const String& _path)
{
    const String _result = _path;
    return _result.Replace('/', '\\');
}

System::String System::IO::Path::Combine(const String& _a, const String& _b)
{
    String _res = _a;
    _res.Append("/");
    _res.Append(_b);
    _res = GetPath(_res);
    return _res;
}

System::String System::IO::Path::Combine(Collections::Generic::List<String> _str)
{
    String _res = _str[0];
    _res.Append("/");
    const int _length = _str.Count();
    for (int i = 1; i < _length; i++)
    {
        _res.Append(_str[i]);
        _res.Append("/");
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

System::String System::IO::Path::GetDirectoryName(const String& _path)
{
    const String& _pathValid = GetPath(_path);
    const Int& _index = _path.LastIndexOf('\\');
    const String& _result = _pathValid.SubString(0, _index);
    return _result;
}

System::Boolean System::IO::Path::HasExtension(const String& _path)
{
    const String& _pathValid = GetPath(_path);
    if (_pathValid[_pathValid.Length() - 1] == '\\') return false;
    const Int& _index = _path.LastIndexOf('.');
    if (_index == -1) return false;
    return true;
}
