#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Float/Float.h"
#include "../../../System/Span/Span.h"

namespace System
{
    namespace Numerics
    {
        class Vector2;
        class Vector3 sealed : public Object, public IEquatable<Vector3>
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        public:
            Float x                         = Float::MinValue;
            Float y                         = Float::MinValue;
            Float z                         = Float::MinValue;
            static const Vector3 Zero;
            static const Vector3 One;
            static const Vector3 UnitX;
            static const Vector3 UnitY;
            static const Vector3 UnitZ;
            static const Float kEpsilon;
            static const Float kEpsilonNormalSqrt;
#pragma endregion f/p
#pragma region constructor
        public:
            Vector3() = default;
            Vector3(const Span<Float>& values);
            Vector3(const Float& value);
            Vector3(const Float& x, const Float& y, const Float& z);
            Vector3(const Vector3& other);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Vector3 Abs(const Vector3& a);
            static Vector3 Add(const Vector3& a, const Vector3& b);
            static Vector3 Clamp(const Vector3& value, const Vector3& min, const Vector3& max);
            static Vector3 Divide(const Vector3& a, const Vector3& b);
            static Vector3 Divide(const Vector3& a, const Float& divisor);
            static Vector3 Lerp(const Vector3& a, const Vector3& b, Float t);
            static Vector3 LerpUnclamped(const Vector3& a, const Vector3& b, const Float& t);
            static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
            static Vector3 Min(const Vector3& a, const Vector3& b);
            static Vector3 Max(const Vector3& a, const Vector3& b);
            static Vector3 ClampMagnitude(const Vector3& vector, const Float& maxLength);
            static Float Distance(const Vector3& a, const Vector3& b);
            static Float Magnitude(const Vector3& vector);
            static Float SqrMagnitude(const Vector3& vector);
            static Float Dot(const Vector3& a, const Vector3& b);
            void Set(const Vector3& newValue);
            void Set(const Float& x, const Float& y, const Float& z);
            void CopyTo(Array<Float>& out) const;
            void CopyTo(Span<Float>& out) const;
            void Normalize();
            Vector2 ToVector2()const;
            Float Length()const;
            Float LengthSquared()const;
            Float Magnitude()const;
            Float SqrMagnitude()const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
            Boolean Equals(const object& obj) override;
            Boolean Equals(const object* obj) override;
            Boolean Equals(const Vector3& other) override;
#pragma endregion override
#pragma region operator
        public:
            Vector3& operator=(const Vector3& other);
            Vector3 operator/(const Vector3& b) const;
            Vector3 operator/(const Float& divisor) const;
            Vector3& operator/=(const Vector3& b);
            Vector3& operator/=(const Float& divisor);
            Vector3 operator*(const Vector3& b) const;
            Vector3 operator*(const Float& value) const;
            Vector3& operator*=(const Vector3& b);
            Vector3& operator*=(const Float& value);
            Vector3 operator+(const Vector3& b) const;
            Vector3 operator+(const Float& value) const;
            Vector3& operator+=(const Vector3& b);
            Vector3& operator+=(const Float& value);
            Vector3 operator-(const Vector3& b) const;
            Vector3 operator-(const Float& value) const;
            Vector3& operator-=(const Vector3& b);
            Vector3& operator-=(const Float& value);
            Vector3& operator-();
            Float& operator[](const Int& index);
            Float operator[](const Int& index) const;
            Bool operator==(const Vector3& other)const;
            Bool operator!=(const Vector3& other)const;
            Bool operator <(const Vector3& other) const;
            Bool operator <=(const Vector3& other) const;
            Bool operator >(const Vector3& other) const;
            Bool operator >=(const Vector3& other) const;
#pragma endregion operator
        };
    }
}
