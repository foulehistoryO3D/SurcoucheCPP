#include "Float.h"

#include <string>

#include "../String/String.h"
#include "../Boolean/Boolean.h"

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

System::String System::Float::ToString() const
{
    return std::to_string(mValue).c_str();;
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

System::Float& System::Float::operator=(const Float& _other)
{
    mValue = std::move(_other.mValue);
    return *this;
}

System::Boolean System::Float::operator==(const Float& _other) const
{
    return mValue == _other.mValue;
}

System::Boolean System::Float::operator!=(const Float& _other) const
{
    return !this->operator==(_other);
}
#pragma endregion constructor
