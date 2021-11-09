#include "Char.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"

#pragma region constructor
System::Char::Char(const char _c)
{
    mValue = _c;
}

System::Char::Char(const Char& _copy)
{
    mValue = std::move(_copy.mValue);
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

size_t System::Char::GetHashCode() const
{
    Char _char = *this;
    return std::hash<Char*>{}(&_char);
}
#pragma endregion override