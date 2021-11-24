#include "Version.h"

#include "../../System.Collections.Generic/List/List.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Boolean/Boolean.h"

#pragma region f/p
System::Integer System::Version::Major() const
{
    return mMajor;
}

System::Integer System::Version::Minor() const
{
    return mMinor;
}
#pragma endregion f/p
#pragma region constructor
System::Version::Version(int32 _args0, int32 _args1, int32 _args2, int32 _args3)
{
    m0 = _args0;
    m1 = _args1;
    m2 = _args2;
    m3 = _args3;
    mMajor = m0;
    mMinor = m3 != -1 ? m3 : m2 != -1 ? m2 : m1;
}

System::Version::Version(const String& _str)
{
    const Collections::Generic::List<String> _splitedString = _str.Split('.');
    const int& _count = _splitedString.Count();
    if (_count == 1) throw Exception("error format for version");
    m0 = Integer::Parse(_splitedString[0]);
    m1 = Integer::Parse(_splitedString[1]);
    if (_count > 2)
        m2 = Integer::Parse(_splitedString[2]);
    if (_count > 3)
        m3 = Integer::Parse(_splitedString[3]);
    mMajor = m0;
    mMinor = m3 != -1 ? m3 : m2 != -1 ? m2 : m1;
}

System::Version::Version(const Version& _copy)
{
    m0 = std::move(_copy.m0);
    m1 = std::move(_copy.m1);
    m2 = std::move(_copy.m2);
    m3 = std::move(_copy.m3);
    mMinor = std::move(_copy.mMinor);
    mMajor = std::move(_copy.mMajor);
}
#pragma endregion constructor
#pragma region override

System::String System::Version::ToString() const
{
    String _result = string("v") + m0 + "." + m1;
    if (m2 == -1) return _result;
    _result += string(".") + m2;
    if (m3 == -1) return _result;
    _result += string(".") + m3;
    return _result;
}

System::Boolean System::Version::Equals(const object* object)
{
    const Version* _version = dynamic_cast<const Version*>(object);
    if (!_version) return false;
    return Equals(*_version);
}

System::Boolean System::Version::Equals(const object& object)
{
    const Version* _version = dynamic_cast<const Version*>(&object);
    if (!_version) return false;
    return Equals(*_version);
}

size_t System::Version::GetHashCode() const
{
    Version _version = *this;
    return std::hash<Version*>{}(&_version);
}

System::Boolean System::Version::Equals(const Version& _object)
{
    return m0 == _object.m0 && m1 == _object.m1 && m2 == _object.m2 && m3 == _object.m3;
}
#pragma endregion override
#pragma region operator
System::Version& System::Version::operator=(const Version& _other)
{
    m0 = std::move(_other.m0);
    m1 = std::move(_other.m1);
    m2 = std::move(_other.m2);
    m3 = std::move(_other.m3);
    mMinor = std::move(_other.mMinor);
    mMajor = std::move(_other.mMajor);
    return *this;
}

System::Version& System::Version::operator=(const String& _str)
{
    const Collections::Generic::List<String> _splitedString = _str.Split('.');
    const int& _count = _splitedString.Count();
    if (_count == 1) throw Exception("error format for version");

    m0 = Integer::Parse(_splitedString[0]);
    m1 = Integer::Parse(_splitedString[1]);
    if (_count > 2)
        m2 = Integer::Parse(_splitedString[2]);
    if (_count > 3)
        m3 = Integer::Parse(_splitedString[3]);
    mMajor = m0;
    mMinor = m3 != -1 ? m3 : m2 != -1 ? m2 : m1;
    return *this;
}
#pragma endregion operator
