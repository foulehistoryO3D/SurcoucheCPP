#include "Byte.h"

#include <string>

#include "../../Exception/Cast/InvalidCastException.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../Boolean/Boolean.h"
#include "../String/String.h"
#include "../Integer/Integer.h"
#include "../Char/Char.h"
#include "../Float/Float.h"
#include "../Double/Double.h"
#include "../../DateTime/DateTime.h"

#pragma region constructor
System::Byte::Byte(const byte& _byte)
{
    if (_byte == '\0' || _byte == 'ÿ')
        mValue = 0;
    else
        mValue = _byte;
}

System::Byte::Byte(const Byte& copy) : Object(copy)
{
    if (copy.mValue < MinValue || copy.mValue > MaxValue)
        throw OutOfRange("[Byte] error => invalid value");
    mValue = copy.mValue;
}

System::Byte System::Byte::Parse(const String& _str)
{
    byte _b = std::stof(_str.ToCstr());;
    if (_b < MinValue || _b > MaxValue)
        throw new OutOfRange("[Byte] error => invalid value");
    return _b;
}
#pragma endregion constructor
#pragma region override
System::Boolean System::Byte::Equals(const unsigned char& _object)
{
    return mValue == _object;
}

System::String System::Byte::ToString() const
{
    return std::to_string(mValue).c_str();
}

System::Boolean System::Byte::Equals(const object* _obj)
{
    const Byte& _byte = *dynamic_cast<const Byte*>(_obj);
    return Equals(_byte);
}

System::Boolean System::Byte::Equals(const object* _obj, const object* _other)
{
    const Byte& _byte = *dynamic_cast<const Byte*>(_obj);
    const Byte& _byte1 = *dynamic_cast<const Byte*>(_obj);
    return _byte == _byte1;
}

System::Boolean System::Byte::Equals(const object& _obj, const object& _other)
{
    const Byte& _byte = *dynamic_cast<const Byte*>(&_obj);
    const Byte& _byte1 = *dynamic_cast<const Byte*>(&_obj);
    return _byte == _byte1;
}

System::Integer System::Byte::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Byte::ToBoolean()
{
    if (mValue != 0 && mValue != 1)
        throw InvalidCastException("Cannot cast byte value to boolean");
    return mValue;
}

System::Byte System::Byte::ToByte()
{
    return mValue;
}

System::Char System::Byte::ToChar()
{
    return mValue;
}

System::DateTime System::Byte::ToDateTime()
{
    throw InvalidCastException("Cannot cast byte to DateTime");
}

System::Float System::Byte::ToFloat()
{
    return mValue;
}

System::Double System::Byte::ToDouble()
{
    return mValue;
}

System::Integer System::Byte::ToInteger()
{
    return mValue;
}

System::Byte::operator unsigned char()
{
    return mValue;
}

#pragma endregion override
#pragma region operator

System::Byte& System::Byte::operator=(const Byte& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

System::Boolean System::Byte::operator==(const Byte& _other) const
{
    return mValue == _other.mValue;
}

System::Boolean System::Byte::operator!=(const Byte& _other) const
{
    return mValue != _other.mValue;
}
#pragma endregion operator
