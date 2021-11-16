#include "Byte.h"

#include <string>
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../Boolean/Boolean.h"
#include "../String/String.h"

#pragma region constructor
System::Byte::Byte(const byte& _byte)
{
    if (_byte == '\0' || _byte == 'ÿ')
        throw OutOfRange("[Byte] error => invalid value");
    mValue =_byte;
}

System::Byte::Byte(const Byte& _copy)
{
    if (_copy.mValue < MinValue || _copy.mValue > MaxValue)
        throw OutOfRange("[Byte] error => invalid value");
    mValue = _copy.mValue;
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

size_t System::Byte::GetHashCode() const
{
    Byte _byte = *this;
    return std::hash<Byte*>{}(&_byte);
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