#pragma once
#include "../../Interface/Convertible/IConvertible.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class String;
    class Float sealed : public Object, public IEquatable<float>, public IConvertible
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        float mValue = 0.0f;
    public:
        static const Float Epsilon;
        static const Float MaxValue;
        static const Float MinValue;
        static const Double PositiveInfinity;
        static const Double NegativeInfinity;
        static const Double NaN;
#pragma endregion f/p
#pragma region constructor
    public:
        Float()=default;
        Float(const float& _value);
        Float(const Float&_other);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Float Parse(const String& _str);
        Boolean Equals(const Float& other);
        String ToString(const Integer& precision) const;
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        Boolean Equals(const float& _object)override;
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
        Float& operator=(const Float& _other);
        Float& operator*=(const Float& _other);
        Float& operator/=(const Float& other);
        Float& operator+=(const Float& other);
        Float& operator-=(const Float& other);
        Float operator+(const Float& other)const;
        Float operator+(const float& other)const;
        Float operator-(const Float& other)const;
        Float operator-(const float& other)const;
        Float operator/(const Float& other) const;
        Float operator/(const float& other) const;
        Boolean operator<(const Float& other) const;
        Boolean operator>(const Float& other) const;
        Boolean operator<=(const Float& other) const;
        Boolean operator>=(const Float& other) const;
        Boolean operator<(const float& other) const;
        Boolean operator>(const float& other) const;
        Boolean operator<=(const float& other) const;
        Boolean operator>=(const float& other) const;
        operator float()const { return mValue;}
        float operator*() const;
        Boolean operator==(const Float& _other) const;
        Boolean operator!=(const Float& _other) const;
        Boolean operator==(const float _other) const;
        Boolean operator!=(const float _other) const;
#pragma endregion operator
    };
}
