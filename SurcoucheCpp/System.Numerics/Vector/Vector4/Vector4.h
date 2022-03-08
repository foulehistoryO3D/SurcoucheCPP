#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Float/Float.h"
#include "../../../System/Span/Span.h"

namespace System
{
    namespace Numerics
    {
        class Vector3;
        class Vector2;
        class Vector4 sealed : public Object, public IEquatable<Vector4>
        {
            DECLARE_CLASS_INFO(Object);
            REGISTER_ATTRIBUTE(Sealed);
#pragma region f/p
        public:
            Float x = Float::MinValue;
            Float y = Float::MinValue;
            Float z = Float::MinValue;
            Float w = Float::MinValue;
            static const Vector4 Zero;
            static const Vector4 One;
            static const Vector4 UnitX;
            static const Vector4 UnitY;
            static const Vector4 UnitZ;
            static const Vector4 UnitW;
            static const Float kEpsilon;
#pragma endregion f/p
#pragma region constructor
        public:
            Vector4() = default;
            Vector4(const Float& value);
            Vector4(const Float& x, const Float& y, const Float& z, const Float& w);
            Vector4(const Float& x, const Float& y, const Float& z);
            Vector4(const Float& x, const Float& y);
            Vector4(const Span<Float>& values);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Vector4 Abs(const Vector4& a);
            static Vector4 Add(const Vector4& a, const Vector4& b);
            static Vector4 Clamp(const Vector4& value, const Vector4& min, const Vector4& max);
            static Vector4 Min(const Vector4& a, const Vector4& b);
            static Vector4 Max(const Vector4& a, const Vector4& b);
            static Vector4 Lerp(const Vector4& a, const Vector4& b, Float t);
            static Vector4 LerpUnclamped(const Vector4& a, const Vector4& b, const Float& t);
            static Float Dot(const Vector4& a, const Vector4& b);
            static Float Magnitude(const Vector4& a);
            static Float Distance(const Vector4& a, const Vector4& b);
            void CopyTo(Array<Float>& out)const;
            void CopyTo(Span<Float>& out)const;
            void Normalize();
            void Set(const Float& x, const Float& y, const Float& z, const Float& w);
            Float Length()const;
            Float LengthSquared()const;
            Vector3 ToVector3()const;
            Vector2 ToVector2()const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
            Boolean Equals(const Vector4& object) override;
            Boolean Equals(const object& obj) override;
            Boolean Equals(const object* obj) override;
#pragma endregion override
#pragma region operator
        public:
            Vector4& operator=(const Vector4& other);
            Vector4 operator-(const Vector4& other) const;
            Vector4 operator-(const Float& value) const;
            Vector4& operator-=(const Vector4& value);
            Vector4& operator-=(const Float& value);
            Vector4 operator+(const Vector4& other) const;
            Vector4 operator+(const Float& value) const;
            Vector4& operator+=(const Vector4& value);
            Vector4& operator+=(const Float& value);
            Vector4 operator*(const Vector4& other) const;
            Vector4 operator*(const Float& value) const;
            Vector4& operator*=(const Vector4& value);
            Vector4& operator*=(const Float& value);
            Vector4 operator/(const Vector4& other) const;
            Vector4 operator/(const Float& value) const;
            Vector4& operator/=(const Vector4& value);
            Vector4& operator/=(const Float& value);
            Vector4& operator-();
            Float& operator[](const Int& index);
            Float operator[](const Int& index)const;
            Bool operator==(const Vector4& other) const;
            Bool operator!=(const Vector4& other) const;
            Bool operator<(const Vector4& other) const;
            Bool operator<=(const Vector4& other) const;
            Bool operator>(const Vector4& other) const;
            Bool operator>=(const Vector4& other) const;
#pragma endregion operator
        };
    }
}
