#pragma once
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class Char : public Object, public IEquatable<char>
    {
#pragma region f/p
    private:
        char mValue = -1;
    public:
        static const constexpr char MinValue = (char)0x00;
        static const constexpr char MaxValue = (char)0xFFFF;
#pragma endregion f/p
#pragma region constructor
    public:
        Char()=default;
        Char(const char _c);
        Char(const Char& _copy);
#pragma endregion consturctor
#pragma region custom methods
    public:
        static Boolean IsDigit(const char _c);
        static Boolean IsLetter(const char _c);
        static Boolean IsLower(const char _c);
        static Boolean IsUpper(const char _c);
        static Char ToUpper(const char _c);
        static Char ToLower(char _c);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const char& _object) override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
    public:
        operator char()const { return mValue; }
#pragma endregion operator
    };
}
