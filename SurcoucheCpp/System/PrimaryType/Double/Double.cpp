﻿#include "Double.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include <string>

#pragma region constructor
System::Double::Double(const double& _value)
{
    mValue = _value;
}

System::Double::Double(const Double& _copy)
{
    mValue = std::move(_copy.mValue);
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

size_t System::Double::GetHashCode() const
{
    Double _value = *this;
    return std::hash<Double*>{}(&_value);
}
#pragma endregion override
#pragma region operator
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