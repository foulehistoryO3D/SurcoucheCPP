#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/Double/Double.h"

namespace System
{
    class Float;
    class Integer;

    class Mathf : public Object
    {
#pragma region const
    public:
        static const Float FloatMinNormal;
        static const Float FloatMinDenormal;
        static const Boolean IsFlushToZeroEnabled;
        static const Double Pi;
        static const Double E;
        static const Float Deg2Rad;
        static const Float Rad2Deg;
        static const Float Epsilon;
#pragma endregion const
#pragma region custom methods
    public:
        static Float Clamp01(const Float& _value);
        static Float Clamp(const Float& _value, const Float& _min, const Float& _max);
        static Float Sqrt(const Float& _value);
        static Double Sqrt(const Double& _value);
        static Float Min(const Float& _a, const Float& _b);
        static Integer Min(const Integer& _a, const Integer& _b);
        static Float Max(const Float& _a, const Float& _b);
        static Integer Max(const Integer& _a, const Integer& _b);
        static Float Sign(const Float& _f);
        static Float Lerp(const Float& _a, const Float& _b, const Float& _t);
        static Float Floor(const Float& _f);
        static Float Repeat(const Float& _t, const Float& _length);
        static Float PingPong(const Float& _t, const Float& _length);
        static Float Abs(const Float& _f);
        static Double Abs(const Double& _f);
        static Float Log(const Float& _f);
        static Double Log(const Double& _f);
        static Float InverseLerp(const Float& _a, const Float& _b, const Float& _value);
        static Float DeltaAngle(const Float& _current, const Float& _target);
        static Float Gamma(const Float& _value, const Float& _absMax, const Float& _gamma);
        static Float Pow(const Float& _a, const Float& _p);
        static Double Pow(const Double& _a, const Double& _p);
        static Float Round(const Float& _f);
        static Float Ceil(const Float& _f);
        static Float Exp(const Float& _pow);
        static Double Exp(const Double& _pow);
        static Float Sinh(const Float& _f);
        static Double Sinh(const Double& _f);
        static Float Sin(const Float& _f);
        static Float Cos(const Float& _f);
        static Double Sin(const Double& _f);
        static Double Cos(const Double& _f);
        static Double Cosh(const Double& _f);
        static Float Cosh(const Float& _f);
        static Float Tan(const Float& _f);
        static Float Asin(const Float& _f);
        static Float Acos(const Float& _f);
        static Float Atan(const Float& _f);
        static Float Atan2(const Float& _y, const Float& _x);
        static Double Atan2(const Double& _y, const Double& _x);
        static Integer CeilToInt(const Float& _f);
#pragma endregion custom methods
    };
}
