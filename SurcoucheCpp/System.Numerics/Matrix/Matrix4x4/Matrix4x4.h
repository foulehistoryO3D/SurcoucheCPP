#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Float/Float.h"
#include "../../Vector/Vector3/Vector3.h"

namespace System
{
    namespace Numerics
    {
        class Vector3;
        class Vector4;
        class Quaternion;

        class Matrix4x4 sealed : public Object, public IEquatable<Matrix4x4>
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        public:
            Float m11 = 0.0f;
            Float m12 = 0.0f;
            Float m13 = 0.0f;
            Float m14 = 0.0f;
            Float m21 = 0.0f;
            Float m22 = 0.0f;
            Float m23 = 0.0f;
            Float m24 = 0.0f;
            Float m31 = 0.0f;
            Float m32 = 0.0f;
            Float m33 = 0.0f;
            Float m34 = 0.0f;
            Float m41 = 0.0f;
            Float m42 = 0.0f;
            Float m43 = 0.0f;
            Float m44 = 0.0f;
            static const Matrix4x4 Identity;
            Boolean IsIdentity() const;
            Vector3 Translation() const;
#pragma endregion f/p
#pragma region constructor
        public:
            Matrix4x4() = default;
            Matrix4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);
            Matrix4x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31,
                      float m32, float m33, float m34, float m41, float m42, float m43, float m44);
            Matrix4x4(const Matrix4x4& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Matrix4x4 CreateTranslation(const Vector3& position);
            static Matrix4x4 CreateTranslation(const Float& x, const Float& y, const Float& z);
            static Matrix4x4 CreateScale(const Float& xScale, const Float& yScale, const Float& zScale);
            static Matrix4x4 CreateScale(const Float& xScale, const Float& yScale, const Float& zScale,
                                         const Vector3& center);
            static Matrix4x4 CreateScale(const Vector3& scales);
            static Matrix4x4 CreateScale(const Vector3& scales, const Vector3& center);
            static Matrix4x4 CreateScale(const Float& scale);
            static Matrix4x4 CreateScale(const Float& scale, const Vector3& center);
            static Matrix4x4 CreateRotationX(const Float& radians);
            static Matrix4x4 CreateRotationX(const Float& radians, const Vector3& center);
            static Matrix4x4 CreateRotationY(const Float& radians);
            static Matrix4x4 CreateRotationY(const Float& radians, const Vector3& center);
            static Matrix4x4 CreateRotationZ(const Float& radians);
            static Matrix4x4 CreateRotationZ(const Float& radians, const Vector3& center);
            static Matrix4x4 CreateFromAxisAngle(const Vector3& axis, const Float& angle);
            static Matrix4x4 CreatePerspectiveFieldOfView(const Float& fieldOfView, const Float& aspectRatio,
                                                          const Float& nearPlaneDistance,
                                                          const Float& farPlaneDistance);
            static Matrix4x4 CreatePerspective(const Float& width, const Float& height, const Float& nearPlaneDistance,
                                               const Float& farPlaneDistance);
            static Matrix4x4 CreatePerspectiveOffCenter(const Float& left, const Float& right, const Float& bottom,
                                                        const Float& top, const Float& nearPlaneDistance,
                                                        const Float& farPlaneDistance);
            static Matrix4x4 CreateOrthographic(const Float& width, const Float& height, const Float& zNearPlane,
                                                const Float& zFarPlane);
            static Matrix4x4 CreateOrthographicOffCenter(const Float& left, const Float& right, const Float& bottom,
                                                         const Float& top, const Float& zNearPlane,
                                                         const Float& zFarPlane);
            static Matrix4x4 CreateLookAt(const Vector3& cameraPosition, const Vector3& cameraTarget,
                                          const Vector3& cameraUpVector);
            static Matrix4x4 CreateWorld(const Vector3& position, const Vector3& forward, const Vector3& up);
            static Matrix4x4 CreateFromQuaternion(const Quaternion& quaternion);
            static Matrix4x4 CreateFromYawPitchRoll(const Float& yaw, const Float& pitch, const Float& roll);
            static Matrix4x4 Transpose(const Matrix4x4& matrix);
            static Matrix4x4 Multiply(const Matrix4x4& value1, const Matrix4x4& value2);
            static Matrix4x4 Lerp(const Matrix4x4& a, const Matrix4x4& b, const Float& t);
            Float GetDeterminant() const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
            Boolean Equals(const Matrix4x4& object) override;
            Boolean Equals(const object& _obj) override;
            Boolean Equals(const object* _obj) override;
#pragma endregion override
#pragma region operator
        public:
            Matrix4x4 operator-()const;
            Matrix4x4 operator+(const Matrix4x4& other) const;
            Matrix4x4 operator-(const Matrix4x4& other) const;
            Matrix4x4 operator*(const Float& value) const;
            Matrix4x4 operator*(const Matrix4x4& other) const;
            Matrix4x4& operator=(const Matrix4x4& other);
            Bool operator==(const Matrix4x4& other);
            Bool operator!=(const Matrix4x4& other);
            
#pragma endregion operator
        };
    }
}
