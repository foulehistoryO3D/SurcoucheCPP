#pragma once
#include "../../Interface/Convertible/IConvertible.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class Byte sealed : public Object, public IEquatable<byte>, public IConvertible
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        byte mValue = 0;
    public:
        static constexpr byte MinValue = 0;
        static constexpr byte MaxValue = 255;
#pragma endregion f/p
#pragma region constructor
    public:
        Byte()=default;
        Byte(const byte& _byte);
        Byte(const Byte& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static Byte Parse(const String& _str);
#pragma endregion custom methods
#pragma region override
    public:
        Boolean Equals(const unsigned char& _object)override;
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
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
        Byte& operator=(const Byte& _other);
        operator byte()const { return mValue;}
        Boolean operator==(const Byte& _other) const;
        Boolean operator!=(const Byte& _other) const;
#pragma endregion operator
    };
}
