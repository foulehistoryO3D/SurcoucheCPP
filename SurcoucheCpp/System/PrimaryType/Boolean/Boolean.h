#pragma once
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class String;

    class Boolean : public Object, public IEquatable<bool>
    {
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
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        size_t GetHashCode() const override;
        Boolean Equals(const bool& _object)override;

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
