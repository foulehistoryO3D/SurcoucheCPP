#pragma once
#include "../../Interface/Equatable/IEquatable.h"
#include "../../Object/Object.h"

namespace System
{
    class String;
    class Float : public Object, public IEquatable<float>
    {
#pragma region f/p
    private:
        float mValue = 0.0f;
    public:
        static const constexpr float Epsilon = 1.401298E-45f;
        static const constexpr float MaxValue = 3.40282347E+38f;
        static const constexpr float MinValue = -3.40282347E+38f;
        static const constexpr double PositiveInfinity = 1e+300 * 1e+300;
        static const constexpr double NegativeInfinity = -PositiveInfinity;
        static const constexpr double NaN = PositiveInfinity * 0.0F;
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
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Boolean Equals(const object* _obj, const object* _other) override;
        Boolean Equals(const object& _obj, const object& _other) override;
        Boolean Equals(const float& _object) override;
#pragma endregion override
#pragma region operator
    public:
        Float& operator=(const Float& _other);
        operator float()const { return mValue;}
        Boolean operator==(const Float& _other) const;
        Boolean operator!=(const Float& _other) const;
#pragma endregion operator
    };
}
