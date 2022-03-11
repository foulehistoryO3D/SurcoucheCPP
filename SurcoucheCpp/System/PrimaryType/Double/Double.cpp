#include "Double.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../Integer/Integer.h"
#include "../Char/Char.h"
#include "../Float/Float.h"
#include "../../DateTime/DateTime.h"
#include <string>

#include "../../Exception/Cast/InvalidCastException.h"
#include "../../Exception/DivideByZero/DivideByZeroException.h"
#include "../Byte/Byte.h"

#pragma region constructor
System::Double::Double(const double& _value)
{
    mValue = _value;
}

System::Double::Double(const Double& copy) : Object(copy)
{
    mValue = std::move(copy.mValue);
}

System::Double System::Double::Parse(const String& _str)
{
    return std::stod(_str.ToCstr());
}

System::Boolean System::Double::IsNaN(const Double& _double)
{
    return isnan(_double);
}

System::Boolean System::Double::IsInfinity(const Double& _double)
{
    return _double == PositiveInfinity;
}

System::Boolean System::Double::IsNegativeInfinity(const Double& _double)
{
    return _double == NegativeInfinity;
}

System::Boolean System::Double::Equals(const Double& other)
{
    return mValue == other.mValue;
}

System::String System::Double::ToString(const Integer& precision) const
{
    std::ostringstream ostringstream = std::ostringstream();
    ostringstream << std::fixed << std::setprecision(precision) << mValue;
    return ostringstream.str().c_str();
}
#pragma endregion constructor
#pragma region override
System::Boolean System::Double::Equals(const double& _object)
{
    return mValue == _object;
}

System::String System::Double::ToString() const
{
    if (IsInfinity(mValue)) return "Infinity";
    if (IsNegativeInfinity(mValue)) return "Negative Infinity";
    if (IsNaN(mValue)) return "NaN";
    return std::to_string(mValue).c_str();
}

System::Boolean System::Double::Equals(const object* _obj)
{
    const Double& _float = *dynamic_cast<const Double*>(_obj);
    return Equals(_float);
}

System::Boolean System::Double::Equals(const object& _obj)
{
    const Double& _float = *dynamic_cast<const Double*>(&_obj);
    return Equals(_float);
}

System::Boolean System::Double::Equals(const object* _obj, const object* _other)
{
    const Double& _float = *dynamic_cast<const Double*>(_obj);
    const Double& _float1 = *dynamic_cast<const Double*>(_obj);
    return _float == _float1;
}

System::Boolean System::Double::Equals(const object& _obj, const object& _other)
{
    const Double& _float = *dynamic_cast<const Double*>(&_obj);
    const Double& _float1 = *dynamic_cast<const Double*>(&_obj);
    return _float == _float1;
}

System::Integer System::Double::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Double::ToBoolean()
{
    if (mValue != 0 && mValue != 1)
        throw InvalidCastException("Cannot cast double value to boolean");
    return mValue;
}

System::Byte System::Double::ToByte()
{
    if (mValue < 0 || mValue > Byte::MaxValue)
        throw InvalidCastException("Cannot cast double value to byte");
    return mValue;
}

System::Char System::Double::ToChar()
{
    return mValue;
}

System::DateTime System::Double::ToDateTime()
{
    throw InvalidCastException("Cannot cast double to byte");
}

System::Float System::Double::ToFloat()
{
    return mValue;
}

System::Double System::Double::ToDouble()
{
    return mValue;
}

System::Integer System::Double::ToInteger()
{
    return mValue;
}
#pragma endregion override
#pragma region operator

System::Double& System::Double::operator=(const Double& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

double System::Double::operator*() const
{
    return mValue;
}

System::Double System::Double::operator/(const Double& other) const
{
    if (other == 0.0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    return mValue / other;
}

System::Double System::Double::operator/(const double& other) const
{
    if (other == 0.0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    return mValue / other;
}

System::Double System::Double::operator/=(const Double& other)
{
    if (other == 0.0)
        throw DivideByZeroException(string::Format("Division of {0} by zero.", *this));
    mValue /= other;
    return *this;
}

System::Double System::Double::operator*(const Double& other) const
{
    return mValue * other;
}

System::Double System::Double::operator*=(const Double& other)
{
    mValue *= other;
    return *this;
}

System::Double System::Double::operator+(const Double& other) const
{
    return mValue + other;
}

System::Double System::Double::operator+=(const Double& other)
{
    mValue += other;
    return *this;
}

System::Double System::Double::operator-(const Double& other) const
{
    return mValue - other;
}

System::Double System::Double::operator-=(const Double& other)
{
    mValue -= other;
    return *this;
}

System::Boolean System::Double::operator==(const Double& _other) const
{
    return mValue == _other.mValue;
}

System::Boolean System::Double::operator==(const double& _other) const
{
    return mValue == _other;
}

System::Boolean System::Double::operator!=(const Double& _other) const
{
    return mValue != _other.mValue;
}

System::Boolean System::Double::operator!=(const double& _other) const
{
    return mValue != _other;
}
#pragma endregion operator