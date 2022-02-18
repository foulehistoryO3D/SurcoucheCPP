#pragma once
#include "../../Interface/Cloneable/ICloneable.h"
#include "../../Interface/Convertible/IConvertible.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"


namespace System
{
    class String;
    template<typename T>
    class Span;
    class Char;
    class Integer sealed : public Object, public IEquatable<int>, public IConvertible
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        int mValue = -1;
    public:
        static const Integer MaxValue;
        static const Integer MinValue;
#pragma endregion f/p
#pragma region constructor
    public:
        Integer()=default;
        Integer(const int _value);
        Integer(const Integer& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Integer Parse(const String& _str);
        static Boolean TryParse(const String& str, Integer& out);
        static Integer Parse(const Span<Char>& _arrayChar);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        Integer GetHashCode() const override;
        Boolean Equals(const int& _object)override;
        Boolean ToBoolean() override;
        Byte ToByte() override;
        Char ToChar() override;
        DateTime ToDateTime() override;
        Float ToFloat() override;
        Double ToDouble() override;
        Integer ToInteger() override;

#pragma endregion override
#pragma region operator
        operator int()const { return mValue;}
        Integer& operator=(const Integer& _other);
        Integer operator+(const Integer& _other) const;
        Integer operator+(const int& _other) const;
        Integer operator+=(const Integer& _other);
        Integer operator+=(const int& _other);
        Integer operator-(const Integer& _other) const;
        Integer operator-(const int& _other) const;
        Integer operator-=(const Integer& _other);
        Integer operator-=(const int& _other);
        Integer operator*(const Integer& _other) const;
        Integer operator*(const int& _other) const;
        Integer operator*=(const Integer& _other);
        Integer operator*=(const int& _other);
        Integer operator/(const Integer& _other) const;
        Integer operator/(const int& _other) const;
        Integer operator/=(const Integer& _other);
        Integer operator/=(const int& _other);
        Integer operator%(const Integer& other) const;
        Integer operator%=(const Integer& other);
        Integer operator%(const int& other) const;
        Integer operator%=(const int& other);
        Integer operator++(int);
        Integer operator--(int);
        Integer operator++();
        Integer operator--();
        Boolean operator==(const Integer& other) const;
        Boolean operator==(const int other) const;
        
#pragma endregion operator
    };
    typedef Integer Int;
}
