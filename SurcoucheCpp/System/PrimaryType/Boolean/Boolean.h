#pragma once
#include "../../Interface/Convertible/IConvertible.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class String;

    class Boolean sealed : public Object, public IEquatable<bool>, public IConvertible
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        bool mValue = false;
#pragma endregion f/p
#pragma region constructor
    public:
        Boolean()=default;
        Boolean(const bool& _value);
        Boolean(const Boolean& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Boolean Parse(const String& _str);
        Boolean Equals(const Boolean& other);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        Integer GetHashCode() const override;
        Boolean Equals(const bool& _object)override;
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
        Boolean& operator=(const Boolean& _other);
        operator bool()const{ return mValue; }
        Boolean operator!() const
        {
            return !mValue;
        }
        Boolean operator!=(const Boolean& _other)const;
        Boolean operator!=(const bool& _other)const;
        Boolean operator==(const Boolean& _other) const;
        Boolean operator==(const bool& _other)const;
#pragma endregion operator
    };
    typedef Boolean Bool;
}
