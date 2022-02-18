#include "Integer.h"

#include <string>

#include "../../Exception/Cast/InvalidCastException.h"
#include "../../Exception/DivideByZero/DivideByZeroException.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../../Span/Span.h"
#include "../Byte/Byte.h"
#include "../Char/Char.h"
#include "../Float/Float.h"
#include "../Double/Double.h"
#include "../../DateTime/DateTime.h"

System::Integer const System::Integer::MaxValue = Integer(2147483647);
System::Integer const System::Integer::MinValue = Integer(-2147483648);

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

System::Boolean System::Integer::TryParse(const String& str, Integer& out)
{
    try
    {
        out = std::atoi(str.ToCstr());
        return true;
    }
    catch (std::exception&)
    {
        out = Integer();
        return false;
    }
}

System::Integer System::Integer::Parse(const Span<Char>& _arrayChar)
{
    string result = _arrayChar.ToString();
    result = result.Trim();
    return Parse(result);
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

System::Bool System::Integer::Equals(const object& _obj)
{
    const Integer* _bool = dynamic_cast<const Integer*>(&_obj);
    return Equals(*_bool);
}

System::Bool System::Integer::Equals(const object* _obj, const object* _other)
{
    const Integer& _bool = *dynamic_cast<const Integer*>(_obj);
    const Integer& _bool1 = *dynamic_cast<const Integer*>(_other);
    return _bool == _bool1;
}

System::Bool System::Integer::Equals(const object& _obj, const object& _other)
{
    const Integer& _bool = *dynamic_cast<const Integer*>(&_obj);
    const Integer& _bool1 = *dynamic_cast<const Integer*>(&_other);
    return _bool == _bool1;
}

System::Integer System::Integer::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Bool System::Integer::Equals(const int& _object)
{
    return mValue == _object;
}

System::Boolean System::Integer::ToBoolean()
{
    if (mValue != 0 && mValue != 1)
        throw InvalidCastException("Cannot convert int value to boolean");
    return mValue;
}

System::Byte System::Integer::ToByte()
{
    if (mValue < 0 || mValue > Byte::MaxValue)
        throw InvalidCastException("Cannot convert int value to byte");
    return mValue;
}

System::Char System::Integer::ToChar()
{
    return static_cast<char>(mValue);
}

System::DateTime System::Integer::ToDateTime()
{
    throw InvalidCastException("Cannot convert int to DateTime");
}

System::Float System::Integer::ToFloat()
{
    return static_cast<float>(mValue);
}

System::Double System::Integer::ToDouble()
{
    return static_cast<double>(mValue);
}

System::Integer System::Integer::ToInteger()
{
    return mValue;
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
    if (_other == 0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    Integer _result = mValue / _other;
    return _result;
}

System::Integer System::Integer::operator/(const int& _other) const
{
    if (_other == 0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    Integer _result = mValue / _other;
    return _result;
}

System::Integer System::Integer::operator/=(const Integer& _other)
{
    if (_other == 0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    mValue /= _other;
    return *this;
}

System::Integer System::Integer::operator/=(const int& _other)
{
    if (_other == 0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    mValue /= _other;
    return *this;
}

System::Integer System::Integer::operator%(const Integer& other) const
{
    return mValue % other;
}

System::Integer System::Integer::operator%=(const Integer& other)
{
    mValue %= other;
    return *this;
}

System::Integer System::Integer::operator%(const int& other) const
{
    return mValue % other;
}

System::Integer System::Integer::operator%=(const int& other)
{
    mValue %= other;
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

System::Boolean System::Integer::operator==(const Integer& other) const
{
    return mValue == other.mValue;
}

System::Boolean System::Integer::operator==(const int other) const
{
    return mValue == other;
}
#pragma endregion operator
