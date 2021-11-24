#pragma once
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"


namespace System
{
    class String;
    class Integer : public Object, public IEquatable<int>
    {
#pragma region f/p
    private:
        int mValue = 0;
    public:
        static constexpr int MaxValue = 2147483647;
        static constexpr int MinValue = -2147483648;
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
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        size_t GetHashCode() const override;
        Boolean Equals(const int& _object)override;
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
        Integer operator++(int);
        Integer operator--(int);
        Integer operator++();
        Integer operator--();
#pragma endregion operator
    };
    typedef Integer Int;
}
