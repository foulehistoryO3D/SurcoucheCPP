#pragma once
#include "../../Interface/Convertible/IConvertible.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class Double sealed : public Object, public IEquatable<double>, public IConvertible
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        double mValue = 0.0;
    public:
        static const constexpr double Epsilon = 4.94065645841247E-324;
        static const constexpr double MaxValue = 1.7976931348623157E+308;
        static const constexpr double MinValue = -1.7976931348623157E+308;
        static const constexpr double PositiveInfinity = 1e+300 * 1e+300;
        static const constexpr double NegativeInfinity = -PositiveInfinity;
        static const constexpr double NaN = PositiveInfinity * 0.0F;
#pragma endregion f/p
#pragma region constructor
    public:
        Double()=default;
        Double(const double& _value);
        Double(const Double& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Double Parse(const String& _str);
        static Boolean IsNaN(const Double& _double);
        static Boolean IsInfinity(const Double& _double);
        static Boolean IsNegativeInfinity(const Double& _double);
        Boolean Equals(const Double& other);
#pragma endregion custom methods
#pragma region override
    public:
        Boolean Equals(const double& _object)override;
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        Integer GetHashCode() const override;
        Boolean ToBoolean() override;
        Byte ToByte() override;
        Char ToChar() override;
        DateTime ToDateTime() override;
        Float ToFloat() override;
        Double ToDouble() override;
        Integer ToInteger() override;
#pragma endregion override
#pragma region operator
    public:
        Double& operator=(const Double& _other);
        operator double() const { return mValue; }
        Double operator/(const Double& other)const;
        Double operator/=(const Double& other);
        Double operator*(const Double& other)const;
        Double operator*=(const Double& other);
        Double operator+(const Double& other)const;
        Double operator+=(const Double& other);
        Double operator-(const Double& other)const;
        Double operator-=(const Double& other);
        Boolean operator==(const Double& _other) const;
        Boolean operator==(const double& _other) const;
        Boolean operator!=(const Double& _other) const;
        Boolean operator!=(const double& _other) const;
#pragma endregion operator
    };
}
