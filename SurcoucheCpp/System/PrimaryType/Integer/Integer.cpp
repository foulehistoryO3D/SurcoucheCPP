#include "Integer.h"

#include <sstream>
#include <string>

#include "../String/String.h"
#include "../Boolean/Boolean.h"


#pragma region constructor
System::Integer::Integer(const int _value)
{
    mValue = _value;
}

System::Integer::Integer(const Integer& _copy)
{
    mValue = _copy.mValue;
}
#pragma endregion constructor
#pragma region custom methods
System::Integer System::Integer::Parse(const String& _str)
{
    return std::atoi(_str.ToCstr());
}
#pragma endregion custom methods
#pragma region override
System::String System::Integer::ToString() const
{
    return std::to_string(mValue).c_str();
}

System::Bool System::Integer::Equals(const object* _obj)
{
    const Integer* _bool = dynamic_cast<const Integer*>(_obj);
    return Equals(*_bool);
}

System::Bool  System::Integer::Equals(const object& _obj)
{
    const Integer* _bool = dynamic_cast<const Integer*>(&_obj);
    return Equals(*_bool);
}

System::Bool  System::Integer::Equals(const object* _obj, const object* _other)
{
    const Integer& _bool = *dynamic_cast<const Integer*>(_obj);
    const Integer& _bool1 = *dynamic_cast<const Integer*>(_other);
    return _bool == _bool1;
}

System::Bool  System::Integer::Equals(const object& _obj, const object& _other)
{
    const Integer& _bool = *dynamic_cast<const Integer*>(&_obj);
    const Integer& _bool1 = *dynamic_cast<const Integer*>(&_other);
    return _bool == _bool1;
}

size_t System::Integer::GetHashCode() const
{
    Integer _integer = *this;
    return std::hash<Integer*>{}(&_integer);
}

System::Bool  System::Integer::Equals(const int& _object)
{
    return mValue == _object;
}

#pragma endregion override
#pragma region operator
System::Integer& System::Integer::operator=(const Integer& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

System::Integer System::Integer::operator+(const Integer& _other) const
{
    Integer _result = mValue + _other;
    return _result;
}

System::Integer System::Integer::operator+(const int& _other) const
{
    Integer _result = mValue + _other;
    return _result;
}

System::Integer System::Integer::operator+=(const Integer& _other)
{
    mValue += _other;
    return *this;
}

System::Integer System::Integer::operator+=(const int& _other)
{
    mValue += _other;
    return *this;
}

System::Integer System::Integer::operator-(const Integer& _other) const
{
    Integer _result = mValue - _other;
    return _result;
}

System::Integer System::Integer::operator-(const int& _other) const
{
    Integer _result = mValue - _other;
    return _result;
}

System::Integer System::Integer::operator-=(const Integer& _other)
{
    mValue -= _other;
    return *this;
}

System::Integer System::Integer::operator-=(const int& _other)
{
    mValue -= _other;
    return *this;
}

System::Integer System::Integer::operator*(const Integer& _other) const
{
    Integer _result = mValue * _other;
    return _result;
}

System::Integer System::Integer::operator*(const int& _other) const
{
    Integer _result = mValue * _other;
    return _result;
}

System::Integer System::Integer::operator*=(const Integer& _other)
{
    mValue *= _other;
    return *this;
}

System::Integer System::Integer::operator*=(const int& _other)
{
    mValue *= _other;
    return *this;
}

System::Integer System::Integer::operator/(const Integer& _other) const
{
    Integer _result = mValue / _other;
    return _result;
}

System::Integer System::Integer::operator/(const int& _other) const
{
    Integer _result = mValue / _other;
    return _result;
}

System::Integer System::Integer::operator/=(const Integer& _other)
{
    mValue /= _other;
    return *this;
}

System::Integer System::Integer::operator/=(const int& _other)
{
    mValue /= _other;
    return *this;
}

System::Integer System::Integer::operator++(int)
{
    mValue++;
    return *this;
}

System::Integer System::Integer::operator--(int)
{
    mValue--;
    return *this;
}

System::Integer System::Integer::operator++()
{
    ++mValue;
    return *this;
}

System::Integer System::Integer::operator--()
{
    --mValue;
    return *this;
}
#pragma endregion operator
