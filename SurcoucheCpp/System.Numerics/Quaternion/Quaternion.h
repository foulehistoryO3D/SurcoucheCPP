#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Float/Float.h"
#include "../Vector/Vector3/Vector3.h"

namespace System
{
    namespace Numerics
    {
        class Vector3;
        class Quaternion sealed : public Object, public IEquatable<Quaternion>
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        public:
            Float x = Float::MinValue;
            Float y = Float::MinValue;
            Float z = Float::MinValue;
            Float w = Float::MinValue;
            static const Float kEpsilon;
            static const Quaternion Identity;
            Bool IsIdentity()const;
#pragma endregion f/p
#pragma region constructor
        public:
            Quaternion() = default;
            Quaternion(const Float& x, const Float& y, const Float& z, const Float& w);
            Quaternion(const Vector3& vector, const Float& w);
            Quaternion(const Quaternion& copy);
#pragma endregion constructor
#pragma region custom methods
        private:
            static Boolean IsEqualUsingDot(const Float& dot);
        public:
            static Quaternion Normalize(const Quaternion& value);
            static Quaternion Conjugate(const Quaternion& value);
            static Quaternion Inverse(const Quaternion& value);
            static Quaternion CreateFromAxisAngle(const Vector3& axis, const Float& angle);
            static Quaternion CreateFromYawPitchRoll(const Float& yaw, const Float& pitch, const Float& roll);
            static Quaternion Concatenate(const Quaternion& a, const Quaternion& b);
            static Quaternion Negate(const Quaternion& value);
            static Quaternion Add(const Quaternion& a, const Quaternion& b);
            static Quaternion Subtract(const Quaternion& a, const Quaternion& b);
            static Quaternion Multiply(const Quaternion& a, const Quaternion& b);
            static Quaternion Multiply(const Quaternion& a, const Float& value);
            static Quaternion Divide(const Quaternion& a, const Quaternion& b);
            static Quaternion Lerp(const Quaternion& a, const Quaternion& b, const Float& t);
            static Quaternion Slerp(const Quaternion& a, const Quaternion& b, const Float& t);
            static Float Dot(const Quaternion& a, const Quaternion& b);
            static Float Angle(const Quaternion& a, const Quaternion& b);
            void Set(const Float& x, const Float& y, const Float& z, const Float& w);
            Float Length()const;
            Float LengthSquared()const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
            Boolean Equals(const object& obj) override;
            Boolean Equals(const object* obj) override;
            Boolean Equals(const Quaternion& _object) override;
#pragma endregion override
#pragma region operator
        public:
            Quaternion& operator=(const Quaternion& other);
            Quaternion operator-() const;
            Quaternion operator-(const Quaternion& other) const;
            Quaternion operator+(const Quaternion& other) const;
            Quaternion operator*(const Quaternion& other) const;
            Quaternion operator*(const Float& value) const;
            Quaternion operator/(const Quaternion& other) const;
            Vector3 operator*(const Vector3& other)const;
            Boolean operator==(const Quaternion& other) const;
            Boolean operator!=(const Quaternion& other) const;
#pragma endregion operator
        };
    }
}
