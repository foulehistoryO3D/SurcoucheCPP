#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Float/Float.h"
#include "../../../System/Span/Span.h"

namespace System
{
    namespace Numerics
    {
        class Vector2 : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        public:
            Float x = Float::MinValue;
            Float y = Float::MinValue;
            static const Vector2 One;
            static const Vector2 UnitX;
            static const Vector2 UnitY;
            static const Vector2 Zero;
#pragma endregion f/p
#pragma region constructor
        public:
            Vector2() = default;
            Vector2(const Span<Float>& values);
            Vector2(const Float& value);
            Vector2(const Float& x, const Float& y);
            Vector2(const Vector2& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Vector2 Abs(const Vector2& other);
            static Vector2 Add(const Vector2& a, const Vector2& b);
            static Vector2 Clamp(const Vector2& value, const Vector2& min, const Vector2& max);
            static Vector2 Divide(const Vector2& a, const Float& divisor);
            static Vector2 Divide(const Vector2& a, const Vector2& b);
            static Vector2 Scale(const Vector2& a, const Float& scale);
            static Vector2 Scale(const Vector2& a, const Vector2& b);
            static Vector2 Max(const Vector2& a, const Vector2& b);
            static Vector2 Min(const Vector2& a, const Vector2& b);
            static Vector2 Negate(const Vector2& vector);
            static Float Distance(const Vector2& a, const Vector2& b);
            static Float DistanceSquared(const Vector2& a, const Vector2& b);
            static Float Dot(const Vector2& a, const Vector2& b);
            void Scale(const Vector2& scale);
            void Scale(const Float& scale);
            void CopyTo(Array<Float>& array) const;
            void CopyTo(Span<Float>& destination) const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            Vector2& operator=(const Vector2& other);
            Bool operator==(const Vector2& other) const;
            Bool operator!=(const Vector2& other) const;
            Bool operator<(const Vector2& other) const;
            Bool operator<=(const Vector2& other) const;
            Bool operator>(const Vector2& other) const;
            Bool operator>=(const Vector2& other) const;
#pragma endregion operator
        };
    }
}
