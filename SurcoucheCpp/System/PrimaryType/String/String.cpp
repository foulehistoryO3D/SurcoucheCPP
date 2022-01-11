#include "String.h"

#include <algorithm>

#include "../../../System.Collections.Generic/List/List.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/Integer/Integer.h"

#include <cstring>
#include <sstream>
#include <string>
#include <windows.h>

#include "../Float/Float.h"

#pragma region f/p
System::String const System::String::Empty = "";
#pragma endregion f/p

#pragma region constructor/destructor
System::String::String(const char* _value)
{
    if (_value == nullptr) _value = "";
    const int _otherLength = strlen(_value);
    const int& _length = mLength;
    const int _newLength = _length + _otherLength;
    char* _char = new char[_newLength + 1];
    // ReSharper disable CppDeprecatedEntity
    strcpy(_char, mValue);
    // ReSharper disable once CppDeprecatedEntity
    strcat(_char, _value);
    mValue = _char;
    mLength = _newLength;
}

System::String::String(const String& _copy)
{
    if (_copy.mValue == null) return;
    const size_t _length = _copy.mLength;
    char* _new = new char[_length + 1];
    memcpy(_new, _copy.mValue, _length + 1);
    mValue = _new;
    mLength = _copy.mLength;
}

System::Boolean System::String::StartWith(const char& _c) const
{
    return mValue[0] == _c;
}

System::Boolean System::String::StartWith(const String& _str) const
{
    for (int i = 0; i < _str.mLength; ++i)
        if (mValue[i] != _str[i])
            return false;
    return true;
}

System::Boolean System::String::EndWith(const char& _c) const
{
    return mValue[mLength - 1] == _c;
}

System::Boolean System::String::EndWith(const String& _str) const
{
    const int _length = _str.mLength;
    const int _count = mLength;
    for (int i = _length; i > 0; i--)
    {
        const char _a = mValue[_count - i];
        const char _b = _str[_length - i];
        if (_a != _b)
            return false;
    }
    return true;
}

System::Boolean System::String::EqualsIgnoreCase(const String& _str) const
{
    if (mLength != _str.mLength) return false;
    const String& _this = this->ToLower();
    const String& _other = _str.ToLower();
    return _this == _other;
}

#pragma endregion constructor/destructor
#pragma region custom methods

void System::String::Append(const Object& _object)
{
    Append(_object.ToString());
}

void System::String::Append(const Object* _object)
{
    Append(_object->ToString());
}

void System::String::Append(const String& _str)
{
    const int& _otherLength = _str.mLength;
    const int& _length = mLength;
    const int _newLength = _length + _otherLength;
    char* _char = new char[_newLength + 1];
    // ReSharper disable CppDeprecatedEntity
    strcpy(_char, mValue);
    // ReSharper disable once CppDeprecatedEntity
    strcat(_char, _str.mValue);
    mValue = _char;
    mLength = _newLength;
}

void System::String::Append(const char& _c)
{
    const int& _length = mLength;
    const size_t _newLength = _length + 2;
    char* _char = new char[_newLength];
    strcpy(_char, mValue);
    _char[_length] = _c;
    _char[_length + 1] = '\0';
    mValue = _char;
    mLength = _length + 1;
}

void System::String::Append(const int _i)
{
    std::ostringstream ss;
    ss << _i;
    const String _result = ss.str().c_str();
    Append(_result);
}

void System::String::Append(const Integer& _integer)
{
    Append(_integer.ToString());
}

System::String System::String::ToLower() const
{
    std::string _str = mValue;
    std::ranges::transform(_str, _str.begin(), [](unsigned char _c)
    {
        return std::tolower(_c);
    });
    return _str.c_str();
}

System::String System::String::ToUpper() const
{
    std::string _str = mValue;
    std::ranges::transform(_str, _str.begin(), [](unsigned char _c)
    {
        return std::toupper(_c);
    });
    return _str.c_str();
}

System::Boolean System::String::Contains(const String& _str) const
{
    std::string _string = mValue;
    return _string.find(_str) != -1;
}


System::Collections::Generic::List<System::String> System::String::Split(const char& _c) const
{
    Collections::Generic::List<String> _result = Collections::Generic::List<String>();
    int _start = 0;
    const int& _length = mLength;
    for (int i = 0; i < _length; ++i)
    {
        if (mValue[i] == _c)
        {
            string _str = string("");
            for (int x = _start; x < i; ++x)
                _str.Append(mValue[x]);
            _result.Add(_str);
            _start = i + 1;
        }
    }
    string _str = string("");

    for (int i = _start; i < _length; ++i)
        _str.Append(mValue[i]);
    _result.Add(_str);
    return _result;
}

System::Collections::Generic::List<System::String> System::String::Split(const String& _value) const
{
    Collections::Generic::List<String> _result = Collections::Generic::List<String>();
    int _start = 0;
    const int& _length = mLength;
    const int& _otherLength = _value.mLength;
    for (int i = 0; i < _length; ++i)
    {
        bool _split = true;
        int _index = 0;
        for (int j = i; j < i + _otherLength; j++)
        {
            if (mValue[j] != _value.mValue[_index])
                _split = false;
            _index++;
        }
        if (_split)
        {
            string _str = "";
            for (int x = _start; x < i; ++x)
                _str.Append(mValue[x]);
            _result.Add(_str);
            string _other = "";
            for (int x = i; x < i + _value.mLength; x++)
                _other += mValue[x];
            _result.Add(_other);
            _start = i + _value.mLength;
        }
    }
    string _str = Empty;

    for (int i = _start; i < _length; ++i)
        _str.Append(mValue[i]);
    _result.Add(_str);
    return _result;
}

System::String System::String::SubString(const Integer& _begin, const Integer& _end) const
{
    String _result = Empty;
    for (int i = _begin; i < _end; i++)
        _result.Append(mValue[i]);

    return _result;
}

System::String System::String::SubString(const Integer& _begin) const
{
    String _result = Empty;
    const Int _length = mLength;
    for (int i = _begin; i < _length; i++)
        _result.Append(mValue[i]);
    return _result;
}

const char* System::String::ToCstr() const
{
    return mValue;
}

System::String System::String::Replace(const char _oldChar, const char _newChar) const
{
    const Int& _length = Length();
    char* _char = new char[_length];
    // ReSharper disable once CppDeprecatedEntity
    strcpy(_char, mValue);
    for (int i = 0; i < _length; i++)
    {
        const char _c = mValue[i];
        if (_c == _oldChar)
            _char[i] = _newChar;
    }
    return _char;
}

System::String System::String::Replace(const String& _old, const String& _new) const
{
    const std::string subStr = _new.ToCstr();
    std::string _str = "";
    Collections::Generic::List<String> _splitedString = Split(_old);
    const int _length = _splitedString.Count();
    for (int i = 0; i < _length; ++i)
        if (_splitedString[i] == _old)
            _splitedString[i] = _new;
    for (int i = 0; i < _length; ++i)
        _str += _splitedString[i];
    return _str.c_str();
}

System::String System::String::operator+(const CHAR* _str) const
{
    String _result = *this;
    _result.Append(_str);
    return _result;
}

System::String System::String::operator+(const Integer& _integer)
{
    Append(_integer.ToString());
    return *this;
}

System::String System::String::operator+(const Float& _float)
{
    Append(_float.ToString());
    return *this;
}

System::String System::String::operator+(const Bool& _bool)
{
    Append(_bool.ToString());
    return *this;
}

System::String System::String::operator+(const int _i)
{
    Append(_i);
    return *this;
}

System::String System::String::operator+(const char& _c)
{
    Append(_c);
    return *this;
}

bool System::String::IsNullOrEmpty(const String& _str)
{
    return _str.mValue == null || _str.mValue == "" || _str.mLength == 0;
}

System::Integer System::String::LastIndexOf(const char _c) const
{
    int _result = -1;
    for (int i = 0; i < mLength; ++i)
        if (mValue[i] == _c)
            _result = i;
    return _result;
}

System::Integer System::String::FirstIndexOf(const char _c) const
{
    for (int i = 0; i < mLength; ++i)
        if (mValue[i] == _c)
            return i;
    return -1;
}

System::Integer System::String::FirstIndexOf(const String& _str) const
{
    std::string _basicString = mValue;
    return _basicString.find(_str.ToCstr());
}

System::Integer System::String::Length() const
{
    return mLength;
}

std::wstring* System::String::ToWString() const
{
    std::string _str = mValue;
    std::wstring* _result = new std::wstring(_str.begin(), _str.end());
    return _result;
}

std::wstring* System::String::ToWString(const String& _str)
{
    std::string _value = _str.ToCstr();
    std::wstring* _result = new std::wstring(_value.begin(), _value.end());
    return _result;
}

System::String System::String::WStringToString(const std::wstring& _wstring)
{
    std::string _str = std::string(_wstring.begin(), _wstring.end());
    return _str.c_str();
}

#pragma endregion custom methods
#pragma region override

System::String System::String::Join(const Collections::Generic::List<String>& _values)
{
    const int32 _count = _values.Count();
    for (int32 i = 0; i < _count; ++i)
    {
        String _add = _values[i];
        if (i < _count - 1)
            _add += " ";
        Append(_add);
    }
    return *this;
}

System::String System::String::ToString() const
{
    return mValue;
}

System::Boolean System::String::Equals(const object* _obj)
{
    const string* _str = dynamic_cast<const string*>(_obj);
    if (!_str) return false;
    return Equals(*_str);
}

System::Boolean System::String::Equals(const String& _object)
{
    return mValue == _object.mValue;
}

size_t System::String::GetHashCode() const
{
    string _object = *this;
    return std::hash<string*>{}(&_object);
}

char System::String::Current()
{
    return mCurrentValue;
}

bool System::String::MoveNext()
{
    if (++mCurrentIndex >= mLength) return false;
    mCurrentValue = mValue[mCurrentIndex];
    return true;
}

void System::String::Reset()
{
    mCurrentIndex = -1;
}

System::Collections::Generic::IEnumerator<char>* System::String::GetEnumerator()
{
    return this;
}
#pragma endregion override
#pragma region operator
System::String::operator const char*() const
{
    return mValue;
}

System::String System::String::operator+(const char* _str)
{
    Append(_str);
    return *this;
}

System::String System::String::operator+(const String* _str)
{
    Append(_str->ToString());
    return *this;
}

System::String& System::String::operator+=(char _c)
{
    Append(_c);
    return *this;
}

System::String& System::String::operator+=(const String& _str)
{
    Append(_str);
    return *this;
}

System::Boolean System::String::operator==(const String& _other) const
{
    const int _length = _other.mLength;
    if (_length != mLength) return false;
    for (int i = 0; i < _length; ++i)
        if (mValue[i] != _other.mValue[i])
            return false;
    return true;
}


System::Boolean System::String::operator==(const char* _other) const
{
    if (_other == null) return mValue == "";
    const int _length = strlen(_other);
    if (_length != mLength) return false;
    for (int i = 0; i < mLength; ++i)
        if (mValue[i] != _other[i])
            return false;
    return true;
}

System::Boolean System::String::operator!=(const String& _other) const
{
    return !this->operator==(_other);
}

System::Boolean System::String::operator!=(const char* _other) const
{
    return !this->operator==(_other);
}
#pragma endregion operator
