#include "Float.h"

#include <string>

#include "../../Exception/Cast/InvalidCastException.h"
#include "../../Exception/DivideByZero/DivideByZeroException.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../Byte/Byte.h"
#include "../Integer/Integer.h"
#include "../Char/Char.h"
#include "../Double/Double.h"
#include "../../DateTime/DateTime.h"


System::Float const System::Float::Epsilon = Float(1.401298E-45f);
System::Float const System::Float::MaxValue = Float(3.40282347E+38f);
System::Float const System::Float::MinValue = Float(-3.40282347E+38f);
System::Double const System::Float::PositiveInfinity = Double(1e+300 * 1e+300);
System::Double const System::Float::NegativeInfinity = -PositiveInfinity;
System::Double const System::Float::NaN = 0.0F * PositiveInfinity;


#pragma region constructor
System::Float::Float(const float& _value)
{
    mValue = _value;
}

System::Float::Float(const Float& _other)
{
    mValue = _other.mValue;
}

System::Float System::Float::Parse(const String& _str)
{
    float _value = std::stof(_str.ToCstr());
    return _value;
}

System::Boolean System::Float::Equals(const Float& other)
{
    return mValue == other.mValue;
}

System::String System::Float::ToString(const Integer& precision) const
{
    std::ostringstream strs = std::ostringstream();
    strs << std::fixed << std::setprecision(precision) << mValue;
    return strs.str().c_str();
}

System::String System::Float::ToString() const
{
    return std::to_string(mValue).c_str();
}

System::Integer System::Float::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Float::Equals(const object* _obj)
{
    const Float& _float = *dynamic_cast<const Float*>(_obj);
    return Equals(_float);
}

System::Boolean System::Float::Equals(const object& _obj)
{
    const Float& _float = *dynamic_cast<const Float*>(&_obj);
    return Equals(_float);
}

System::Boolean System::Float::Equals(const object* _obj, const object* _other)
{
    const Float& _float = *dynamic_cast<const Float*>(_obj);
    const Float& _float1 = *dynamic_cast<const Float*>(_obj);
    return _float == _float1;
}

System::Boolean System::Float::Equals(const object& _obj, const object& _other)
{
    const Float& _float = *dynamic_cast<const Float*>(&_obj);
    const Float& _float1 = *dynamic_cast<const Float*>(&_obj);
    return _float == _float1;
}

System::Boolean System::Float::Equals(const float& _object)
{
    return mValue == _object;
}

System::Boolean System::Float::ToBoolean()
{
    if (mValue != 0 && mValue != 1)
        throw InvalidCastException("Cannot cast float value to boolean");
    return mValue;
}

System::Byte System::Float::ToByte()
{
    if (mValue < 0 || mValue > Byte::MaxValue)
        throw InvalidCastException("Cannot cast float value to byte");
    return mValue;
}

System::Char System::Float::ToChar()
{
    return mValue;
}

System::DateTime System::Float::ToDateTime()
{
    throw InvalidCastException("Cannot convert float to datetime");
}

System::Float System::Float::ToFloat()
{
    return mValue;
}

System::Double System::Float::ToDouble()
{
    return mValue;
}

System::Integer System::Float::ToInteger()
{
    return mValue;
}

System::Float& System::Float::operator=(const Float& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

System::Float& System::Float::operator*=(const Float& _other)
{
    mValue *= _other.mValue;
    return *this;
}

System::Float& System::Float::operator/=(const Float& other)
{
    if (other == 0.0f)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    mValue /= other;
    return *this;
}

System::Float& System::Float::operator+=(const Float& other)
{
    mValue += other;
    return *this;
}

System::Float& System::Float::operator-=(const Float& other)
{
    mValue -= other;
    return *this;
}

System::Float System::Float::operator+(const Float& other) const
{
    return mValue + other;
}

System::Float System::Float::operator+(const float& other) const
{
    return mValue + other;
}

System::Float System::Float::operator-(const Float& other) const
{
    return mValue - other;
}

System::Float System::Float::operator-(const float& other) const
{
    return mValue - other;
}

System::Boolean System::Float::operator<(const Float& other) const
{
    return mValue < other;
}

System::Boolean System::Float::operator>(const Float& other) const
{
    return mValue > other;
}

System::Boolean System::Float::operator<=(const Float& other) const
{
    return mValue <= other;
}

System::Boolean System::Float::operator>=(const Float& other) const
{
    return mValue >= other;
}

System::Boolean System::Float::operator<(const float& other) const
{
    return mValue < other;
}

System::Boolean System::Float::operator>(const float& other) const
{
    return mValue > other;
}

System::Boolean System::Float::operator<=(const float& other) const
{
    return mValue <= other;
}

System::Boolean System::Float::operator>=(const float& other) const
{
    return mValue >= other;
}

System::Float System::Float::operator/(const Float& other) const
{
    if (other == 0.0f)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    const Float& result = mValue / other;
    return result;
}

System::Float System::Float::operator/(const float& other) const
{
    if (other == 0.0f)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    const Float& result = mValue / other;
    return result;
}

System::Boolean System::Float::operator==(const Float& _other) const
{
    return mValue == _other.mValue;
}

System::Boolean System::Float::operator!=(const Float& _other) const
{
    return !this->operator==(_other);
}

System::Boolean System::Float::operator==(const float _other) const
{
    return mValue == _other;
}

System::Boolean System::Float::operator!=(const float _other) const
{
    return !this->operator==(_other);
}
#pragma endregion constructor
