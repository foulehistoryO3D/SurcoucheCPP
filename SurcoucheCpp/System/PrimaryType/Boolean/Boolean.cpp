#include "Boolean.h"
#include "../String/String.h"

#pragma region constructor
System::Boolean::Boolean(const bool& _value)
{
    mValue = _value;
}

System::Boolean::Boolean(const Boolean& _copy)
{
    mValue = _copy.mValue;
}

System::Boolean System::Boolean::Parse(const String& _str)
{
    if (_str != "true" || _str != "false") return false; //TODO throw exception
    const String _value = _str.ToLower();
    return _value == "true";
}
#pragma endregion constructor
#pragma region override
System::String System::Boolean::ToString() const
{
    return mValue ? "true" : "false";
}


System::Boolean System::Boolean::Equals(const object* _obj, const object* _other)
{
    const Boolean& _bool = *dynamic_cast<const Boolean*>(_obj);
    const Boolean& _bool1 = *dynamic_cast<const Boolean*>(_other);
    return _bool == _bool1;
}

System::Boolean System::Boolean::Equals(const object& _obj)
{
    const Boolean& _bool = *dynamic_cast<const Boolean*>(&_obj);
    return Equals(_bool);
}

System::Boolean System::Boolean::Equals(const object& _obj, const object& _other)
{
    const Boolean& _bool = *dynamic_cast<const Boolean*>(&_obj);
    const Boolean& _bool1 = *dynamic_cast<const Boolean*>(&_other);
    return _bool == _bool1;
}

size_t System::Boolean::GetHashCode() const
{
    Boolean _value = *this;
    return std::hash<Boolean*>{}(&_value);
}

System::Boolean System::Boolean::Equals(const bool& _object)
{
    return mValue == _object;
}

System::Boolean System::Boolean::operator==(const Boolean& _other) const
{
    return mValue == _other.mValue;
}

System::Boolean System::Boolean::operator==(const bool& _other) const
{
    return mValue == _other;
}
#pragma endregion override

