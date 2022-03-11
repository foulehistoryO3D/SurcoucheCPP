#include "Mathf.h"
#include "../PrimaryType/Float/Float.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include <complex>

System::Double const System::Mathf::E = 2.71828182845905;
System::Float const System::Mathf::FloatMinNormal = 1.17549435E-38F;
System::Float const System::Mathf::FloatMinDenormal = 1.401298E-45F;
System::Boolean const System::Mathf::IsFlushToZeroEnabled = FloatMinDenormal == 0.0f;
System::Double const System::Mathf::Pi = 3.1415926535897932384;
System::Float const System::Mathf::Deg2Rad = ((float)Pi) * 2.0f / 360.0f;
System::Float const System::Mathf::Rad2Deg = Float(1.0f) / Deg2Rad;
System::Float const System::Mathf::Epsilon = IsFlushToZeroEnabled ? FloatMinNormal : FloatMinDenormal;

System::Float System::Mathf::Clamp01(const Float& _value)
{
    if (_value < 0.0f) return 0.0f;
    if (_value > 1.0f) return 1.0f;
    return _value;
}

System::Float System::Mathf::Clamp(const Float& _value, const Float& _min, const Float& _max)
{
    if (_value < _min) return _min;
    if (_value > _max) return _max;
    return _value;
}

System::Float System::Mathf::Sqrt(const Float& _value)
{
    return std::sqrt(_value);
}

System::Double System::Mathf::Sqrt(const Double& _value)
{
    return std::sqrt(_value);
}

System::Float System::Mathf::Min(const Float& _a, const Float& _b)
{
    return _a < _b ? _a : _b;
}

System::Integer System::Mathf::Min(const Integer& _a, const Integer& _b)
{
    return _a < _b ? _a : _b;
}

System::Float System::Mathf::Max(const Float& _a, const Float& _b)
{
    return _a > _b ? _a : _b;
}

System::Integer System::Mathf::Max(const Integer& _a, const Integer& _b)
{
    return _a > _b ? _a : _b;
}

System::Float System::Mathf::Sign(const Float& _f)
{
    return _f >= 0.0f ? 1.0f : -1.0f;
}

System::Float System::Mathf::Lerp(const Float& _a, const Float& _b, const Float& _t)
{
    return _a + (_b - _a) * _t;
}

System::Float System::Mathf::Floor(const Float& _f)
{
    return std::floor(_f);
}

System::Float System::Mathf::Repeat(const Float& _t, const Float& _length)
{
    return Clamp(_t - Floor(_t/_length) * _length, 0.0f, _length);
}

System::Float System::Mathf::PingPong(const Float& _t, const Float& _length)
{
    const float _t1 = Repeat(_t, _length*2.0f);
    return _length - Abs(Float(_t1 - _length));
}

System::Float System::Mathf::Abs(const Float& _f)
{
    return std::abs(_f);
}

System::Double System::Mathf::Abs(const Double& _f)
{
    return std::abs(_f);
}

System::Float System::Mathf::Log(const Float& _f)
{
    return std::log(_f);
}

System::Double System::Mathf::Log(const Double& _f)
{
    return std::log(_f);
}

System::Float System::Mathf::InverseLerp(const Float& _a, const Float& _b, const Float& _value)
{
    if (_a != _b)
        return Clamp01((_value - _a) / (_b - _a));
    return 0.0f;
}

System::Float System::Mathf::DeltaAngle(const Float& _current, const Float& _target)
{
    float _delta = Repeat(_target - _current, 360.0f);
    if (_delta > 180.0f) _delta-=360.0f;
    return _delta;
}

System::Float System::Mathf::Gamma(const Float& _value, const Float& _absMax, const Float& _gamma)
{
    const bool _negative = _value < 0.0f;
    const float _absValue = Abs(_value);
    if (_absValue > _absMax)
        return _negative ? -_absValue : _absValue;
    const float _result = Pow(_absValue / _absMax, _gamma) * _absMax;
    return _negative ? -_result : _result;
}

System::Float System::Mathf::Pow(const Float& _a, const Float& _p)
{
    return std::pow(_a, _p);
}

System::Double System::Mathf::Pow(const Double& _a, const Double& _p)
{
    return std::pow(_a, _p);
}

System::Float System::Mathf::Round(const Float& _f)
{
    return std::round(_f);
}

System::Float System::Mathf::Ceil(const Float& _f)
{
    return std::ceil(_f);
}

System::Float System::Mathf::Exp(const Float& _pow)
{
    return std::exp(_pow);
}

System::Double System::Mathf::Exp(const Double& _pow)
{
    return std::exp(_pow);
}

System::Float System::Mathf::Sinh(const Float& _f)
{
    return std::sinh(_f);
}

System::Double System::Mathf::Sinh(const Double& _f)
{
    return std::sinh(_f);
}

System::Float System::Mathf::Sin(const Float& _f)
{
    return std::sin(_f);
}

System::Float System::Mathf::Cos(const Float& _f)
{
    return std::cos(_f);
}

System::Double System::Mathf::Sin(const Double& _f)
{
    return std::sin(_f);
}

System::Double System::Mathf::Cos(const Double& _f)
{
    return std::cos(_f);
}

System::Double System::Mathf::Cosh(const Double& _f)
{
    return std::cosh(_f);
}

System::Float System::Mathf::Cosh(const Float& _f)
{
    return std::cosh(_f);
}

System::Float System::Mathf::Tan(const Float& _f)
{
    return std::tan(_f);
}

System::Float System::Mathf::Asin(const Float& _f)
{
    return std::asin(_f);
}

System::Float System::Mathf::Acos(const Float& _f)
{
    return std::acos(_f);
}

System::Float System::Mathf::Atan(const Float& _f)
{
    return std::atan(_f);
}

System::Float System::Mathf::Atan2(const Float& _y, const Float& _x)
{
    return std::atan2(_y, _x);
}

System::Double System::Mathf::Atan2(const Double& _y, const Double& _x)
{
    return std::atan2(_y, _x);
}

System::Integer System::Mathf::CeilToInt(const Float& _f)
{
    return static_cast<Int>(Ceil(_f));
}
