#include "StringBuilder.h"

#include <iostream>

#include "../../System/PrimaryType/Double/Double.h"
#include "../../System/PrimaryType/Float/Float.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Char/Char.h"
#include "../../System.Collections.Generic/List/List.h"

#pragma region f/p
System::Text::StringBuilder const System::Text::StringBuilder::Empty = "";
#pragma endregion f/p
#pragma region constructor
System::Text::StringBuilder::StringBuilder(const Integer& _capacity)
{
    mCapacity = _capacity;
}

System::Text::StringBuilder::StringBuilder(const Integer& _capacity, const Integer& _capacityMax)
{
    mCapacity = _capacity;
    mCapacityMax = _capacityMax;
}

System::Text::StringBuilder::StringBuilder(const String& _str)
{
    Append(_str);
}

System::Text::StringBuilder::StringBuilder(const String& _str, const Integer& _capacity)
{
    mCapacity = _capacity;
    Append(_str);
}

System::Text::StringBuilder::StringBuilder(const char* _str)
{
    Append(_str);
}

System::Text::StringBuilder::StringBuilder(const StringBuilder& _copy)
{
    mValue = std::move(_copy.mValue);
    mLength = std::move(_copy.mLength);
    mCapacity = std::move(_copy.mCapacity);
    mCapacityMax = std::move(_copy.mCapacityMax);
}
#pragma endregion constructor
#pragma region custom methods
System::Text::StringBuilder& System::Text::StringBuilder::Append(const Object& _object)
{
    const String& _str = _object.ToString();
    const int _otherLength = _str.Length();
    const int _newLength = mLength + _otherLength;
    if (_newLength > mCapacity) throw OutOfRange("String builder out of capacity");
    char* _char = new char[_newLength + 1];
    strcpy(_char, mValue);
    strcat(_char, _str.ToCstr());
    mValue = _char;
    mLength = _newLength;
    return *this;
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const Object* _object)
{
    return Append(*_object);
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const char* _str)
{
    mCapacity = mCapacityMax;
    const String& _value = _str;
    const int _otherLength = _value.Length();
    const int _newLength = mLength + _otherLength;
    if (_newLength > mCapacity) throw OutOfRange("String builder out of capacity");
    char* _char = new char[_newLength + 1];
    strcpy(_char, mValue);
    strcat(_char, _value.ToCstr());
    mValue = _char;
    mLength = _newLength;
    return *this;
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(Collections::Generic::List<char> _char)
{
    const int& _length = _char.Count();
    for (int i = 0; i < _length; ++i)
        Append(Char(_char[i]));
    return *this;
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const Char& _char)
{
    return Append(_char.ToString());
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const int& _int)
{
    const Integer& _value = _int;
    return Append(_value.ToString());
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const float& _float)
{
    const Float& _value = _float;
    return Append(_value.ToString());
}

System::Text::StringBuilder& System::Text::StringBuilder::Append(const double& _double)
{
    const Double& _value = _double;
    return Append(_value.ToString());
}

System::Text::StringBuilder& System::Text::StringBuilder::Clear()
{
    mValue = "";
    mCapacity = 0;
    mLength = 0;
    return *this;
}

System::Text::StringBuilder& System::Text::StringBuilder::Replace(const char& _old, const char& _new)
{
    string _str = mValue;
    _str = _str.Replace(_old, _new);
    mValue = _str.ToCstr();
    return *this;
}

System::Boolean System::Text::StringBuilder::Equals(const StringBuilder& _builder)
{
    return ToString() == _builder.ToString() && mCapacity == _builder.mCapacity && mLength == _builder.mLength &&
        mCapacityMax == _builder.mCapacityMax;
}
#pragma endregion custom methods
#pragma region override
System::String System::Text::StringBuilder::ToString() const
{
    return mValue;
}

System::Boolean System::Text::StringBuilder::Equals(const object* object)
{
    const StringBuilder& _builder = static_cast<const StringBuilder&>(*object);
    return Equals(_builder);
}

System::Boolean System::Text::StringBuilder::Equals(const object& object)
{
    const StringBuilder& _builder = static_cast<const StringBuilder&>(object);
    return Equals(_builder);
}

System::Integer System::Text::StringBuilder::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Text::StringBuilder::operator const char*() const
{
    return ToString();
}

System::Text::StringBuilder& System::Text::StringBuilder::operator=(const StringBuilder& other)
{
    mValue = other.mValue;
    mLength = other.mLength;
    mCapacity = other.mCapacity;
    mCapacityMax = other.mCapacityMax;
    return *this;
}
#pragma endregion override
