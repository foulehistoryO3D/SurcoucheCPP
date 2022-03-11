#include "Char.h"

#include "../../Exception/Cast/InvalidCastException.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../Byte/Byte.h"
#include "../Integer/Integer.h"
#include "../Float/Float.h"
#include "../Double/Double.h"
#include "../../DateTime/DateTime.h"

#pragma region constructor
System::Char::Char(const char _c)
{
    mValue = _c;
}

System::Char::Char(const Char& copy) : Object(copy)
{
    mValue = std::move(copy.mValue);
}
#pragma endregion constructor
#pragma region custom methods
System::Boolean System::Char::IsDigit(const char _c)
{
    return isdigit(_c);
}

System::Boolean System::Char::IsLetter(const char _c)
{
    return isalpha(_c);
}

System::Boolean System::Char::IsLower(const char _c)
{
    return islower(_c);
}

System::Boolean System::Char::IsUpper(const char _c)
{
    return isupper(_c);
}

System::Boolean System::Char::IsWhitSpace(const char _c)
{
    return _c == ' ';
}

System::Char System::Char::ToUpper(const char _c)
{
    return std::toupper(_c);
}

System::Char System::Char::ToLower(const char _c)
{
    return std::tolower(_c);
}

System::Char System::Char::ToUpper()
{
    mValue = std::toupper(mValue);
    return *this;
}

System::Char System::Char::ToLower()
{
    mValue = std::tolower(mValue);
    return *this;
}
#pragma endregion custom methods
#pragma region override
System::String System::Char::ToString() const
{
    return string("") + Char(mValue);
}

System::Boolean System::Char::Equals(const char& _object)
{
    return mValue == _object;
}

System::Boolean System::Char::Equals(const object* object)
{
    const Char* _char = dynamic_cast<const Char*>(object);
    return _char == this;
}

System::Boolean System::Char::Equals(const object& object)
{
    const Char* _char = dynamic_cast<const Char*>(&object);
    return _char == this;
}

System::Integer System::Char::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Char::ToBoolean()
{
    if (mValue != '0' && mValue != '1')
        throw InvalidCastException("Cannot cast char value to boolean");
    return mValue;
}

System::Byte System::Char::ToByte()
{
    if (mValue < 0 || mValue > Byte::MaxValue)
        throw InvalidCastException("Cannot cast char value to byte");
    return mValue;
}

System::Char System::Char::ToChar()
{
    return mValue;
}

System::DateTime System::Char::ToDateTime()
{
    throw InvalidCastException("Cannot cast char to DateTime");
}

System::Float System::Char::ToFloat()
{
    return mValue;
}

System::Double System::Char::ToDouble()
{
    return mValue;
}

System::Integer System::Char::ToInteger()
{
    return mValue;
}

System::Char& System::Char::operator=(const Char& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

System::Boolean System::Char::operator==(const Char& other) const
{
    return this->mValue == other.mValue;
}

System::Boolean System::Char::operator==(const char& other) const
{
    return this->mValue == other;
}

System::Boolean System::Char::operator!=(const Char& other) const
{
    return !this->operator==(other);
}

System::Boolean System::Char::operator!=(const char& other) const
{
    return !this->operator==(other);
}
#pragma endregion override
