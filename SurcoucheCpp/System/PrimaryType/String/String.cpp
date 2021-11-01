#include "String.h"

#include <algorithm>

#include "../../Collection/Generic/List/List.h"
#include "../../PrimaryType/Boolean/Boolean.h"

#include <cstring>
#include <string>
#include <windows.h>


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
    const size_t _length = _copy.mLength;
    char* _new = new char[_length + 1];
    memcpy(_new, _copy.mValue, _length + 1);
    mValue = _new;
    mLength = _copy.mLength;
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

System::String System::String::ToLower() const
{
    std::string _str = mValue;
    std::transform(_str.begin(), _str.end(), _str.begin(), [](unsigned char _c)
    {
        return std::tolower(_c);
    });
    return _str.c_str();
}

System::String System::String::ToUpper() const
{
    std::string _str = mValue;
    std::transform(_str.begin(), _str.end(), _str.begin(), [](unsigned char _c)
    {
        return std::toupper(_c);
    });
    return _str.c_str();
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

const char* System::String::ToCstr() const
{
    return mValue;
}

System::String System::String::Empty()
{
    return "";
}

bool System::String::IsNullOrEmpty(const String& _str)
{
    return _str.mValue == null || _str.mValue == "" || _str.mLength == 0;
}

#pragma endregion custom methods
#pragma region override

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
    return mValue == _object.mValue && mLength == _object.mLength;
}

size_t System::String::GetHashCode() const
{
    string _object = *this;
    return std::hash<string*>{}(&_object);
}

System::String System::String::Clone()
{
    return *this;
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

bool System::String::operator==(const String& _other) const
{
    const int _length = _other.mLength;
    if (_length != mLength) return false;
    for (int i = 0; i < _length; ++i)
        if (mValue[i] != _other.mValue[i])
            return false;
    return true;
}


bool System::String::operator==(const char* _other) const
{
    const int _length = strlen(_other);
    if (_length != mLength) return false;
    for (int i = 0; i < mLength; ++i)
        if (mValue[i] != _other[i])
            return false;
    return true;
}

bool System::String::operator!=(const String& _other) const
{
    return !this->operator==(_other);
}

bool System::String::operator!=(const char* _other) const
{
    return !this->operator==(_other);
}
#pragma endregion operator
