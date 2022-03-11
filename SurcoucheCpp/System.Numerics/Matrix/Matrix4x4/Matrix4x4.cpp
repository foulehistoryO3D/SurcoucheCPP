#include "Matrix4x4.h"

#include "../../../System/Exception/ArgumentOutOfRange/ArgumentOutOfRangeException.h"
#include "../../../System/Mathf/Mathf.h"
#include "../../Vector/Vector3/Vector3.h"
#include "../../Vector/Vector4/Vector4.h"
#include "../../Quaternion/Quaternion.h"

#pragma region f/p
System::Numerics::Matrix4x4 const System::Numerics::Matrix4x4::Identity(Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0),
                                                                        Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1));

System::Bool System::Numerics::Matrix4x4::IsIdentity() const
{
    return this->m11 == 1.0f && this->m22 == 1.0f && this->m33 == 1.0f && this->m44 == 1.0f;
}

System::Numerics::Vector3 System::Numerics::Matrix4x4::Translation() const
{
    return Vector3(this->m41, this->m42, this->m43);
}
#pragma endregion f/p
#pragma region constructor
System::Numerics::Matrix4x4::Matrix4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
{
    this->m11 = a.x;
    this->m21 = b.x;
    this->m31 = c.x;
    this->m41 = d.x;
    this->m12 = a.y;
    this->m22 = b.y;
    this->m32 = c.y;
    this->m42 = d.y;
    this->m13 = a.z;
    this->m23 = b.z;
    this->m33 = c.z;
    this->m43 = d.z;
    this->m14 = a.w;
    this->m24 = b.w;
    this->m34 = c.w;
    this->m44 = d.w;
}

System::Numerics::Matrix4x4::Matrix4x4(const float m11, const float m12, const float m13, const float m14,
                                       const float m21, const float m22, const float m23,
                                       const float m24, const float m31, const float m32, const float m33,
                                       const float m34, const float m41, const float m42, const float m43,
                                       const float m44)
{
    this->m11 = m11;
    this->m21 = m21;
    this->m31 = m31;
    this->m41 = m41;
    this->m12 = m12;
    this->m22 = m22;
    this->m32 = m32;
    this->m42 = m42;
    this->m13 = m13;
    this->m23 = m23;
    this->m33 = m33;
    this->m43 = m43;
    this->m14 = m14;
    this->m24 = m24;
    this->m34 = m34;
    this->m44 = m44;
}

System::Numerics::Matrix4x4::Matrix4x4(const Matrix4x4& copy) : Object(copy)
{
    this->m11 = copy.m11;
    this->m21 = copy.m21;
    this->m31 = copy.m31;
    this->m41 = copy.m41;
    this->m12 = copy.m12;
    this->m22 = copy.m22;
    this->m32 = copy.m32;
    this->m42 = copy.m42;
    this->m13 = copy.m13;
    this->m23 = copy.m23;
    this->m33 = copy.m33;
    this->m43 = copy.m43;
    this->m14 = copy.m14;
    this->m24 = copy.m24;
    this->m34 = copy.m34;
    this->m44 = copy.m44;
}
#pragma endregion f/p
#pragma region custom methods
System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateTranslation(const Vector3& position)
{
    Matrix4x4 translation = Identity;
    translation.m41 = position.x;
    translation.m42 = position.y;
    translation.m43 = position.z;
    return translation;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateTranslation(const Float& x, const Float& y,
                                                                           const Float& z)
{
    Matrix4x4 translation = Identity;
    translation.m41 = x;
    translation.m42 = y;
    translation.m43 = z;
    return translation;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Float& xScale, const Float& yScale,
                                                                     const Float& zScale)
{
    Matrix4x4 scale = Matrix4x4();
    scale.m11 = xScale;
    scale.m12 = 0.0f;
    scale.m12 = 0.0f;
    scale.m14 = 0.0f;
    scale.m21 = 0.0f;
    scale.m22 = yScale;
    scale.m23 = 0.0f;
    scale.m24 = 0.0f;
    scale.m31 = 0.0f;
    scale.m32 = 0.0f;
    scale.m33 = zScale;
    scale.m34 = 0.0f;
    scale.m41 = 0.0f;
    scale.m42 = 0.0f;
    scale.m43 = 0.0f;
    scale.m44 = 1.0f;
    return scale;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Float& xScale, const Float& yScale,
                                                                     const Float& zScale, const Vector3& center)
{
    const float num1 = center.x * (1.0f - xScale);
    const float num2 = center.y * (1.0f - yScale);
    const float num3 = center.z * (1.0f - zScale);
    Matrix4x4 scale = Matrix4x4();
    scale.m11 = xScale;
    scale.m12 = 0.0f;
    scale.m12 = 0.0f;
    scale.m14 = 0.0f;
    scale.m21 = 0.0f;
    scale.m22 = yScale;
    scale.m23 = 0.0f;
    scale.m24 = 0.0f;
    scale.m31 = 0.0f;
    scale.m32 = 0.0f;
    scale.m33 = zScale;
    scale.m34 = 0.0f;
    scale.m41 = num1;
    scale.m42 = num2;
    scale.m43 = num3;
    scale.m44 = 1.0f;
    return scale;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Vector3& scales)
{
    Matrix4x4 scale = Matrix4x4();
    scale.m11 = scales.x;
    scale.m12 = 0.0f;
    scale.m12 = 0.0f;
    scale.m14 = 0.0f;
    scale.m21 = 0.0f;
    scale.m22 = scales.y;
    scale.m23 = 0.0f;
    scale.m24 = 0.0f;
    scale.m31 = 0.0f;
    scale.m32 = 0.0f;
    scale.m33 = scales.z;
    scale.m34 = 0.0f;
    scale.m41 = 0.0f;
    scale.m42 = 0.0f;
    scale.m43 = 0.0f;
    scale.m44 = 1.0f;
    return scale;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Vector3& scales, const Vector3& center)
{
    const float num1 = center.x * (1.0f - scales.x);
    const float num2 = center.y * (1.0f - scales.y);
    const float num3 = center.z * (1.0f - scales.z);
    Matrix4x4 scale = Matrix4x4();
    scale.m11 = scales.x;
    scale.m12 = 0.0f;
    scale.m12 = 0.0f;
    scale.m14 = 0.0f;
    scale.m21 = 0.0f;
    scale.m22 = scales.y;
    scale.m23 = 0.0f;
    scale.m24 = 0.0f;
    scale.m31 = 0.0f;
    scale.m32 = 0.0f;
    scale.m33 = scales.z;
    scale.m34 = 0.0f;
    scale.m41 = num1;
    scale.m42 = num2;
    scale.m43 = num3;
    scale.m44 = 1.0f;
    return scale;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Float& scale)
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = scale;
    result.m12 = 0.0f;
    result.m12 = 0.0f;
    result.m14 = 0.0f;
    result.m21 = 0.0f;
    result.m22 = scale;
    result.m23 = 0.0f;
    result.m24 = 0.0f;
    result.m31 = 0.0f;
    result.m32 = 0.0f;
    result.m33 = scale;
    result.m34 = 0.0f;
    result.m41 = 0.0f;
    result.m42 = 0.0f;
    result.m43 = 0.0f;
    result.m44 = 1.0f;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateScale(const Float& scale, const Vector3& center)
{
    const float num1 = center.x * (1.0f - scale);
    const float num2 = center.y * (1.0f - scale);
    const float num3 = center.z * (1.0f - scale);
    Matrix4x4 result = Matrix4x4();
    result.m11 = scale;
    result.m12 = 0.0f;
    result.m12 = 0.0f;
    result.m14 = 0.0f;
    result.m21 = 0.0f;
    result.m22 = scale;
    result.m23 = 0.0f;
    result.m24 = 0.0f;
    result.m31 = 0.0f;
    result.m32 = 0.0f;
    result.m33 = scale;
    result.m34 = 0.0f;
    result.m41 = num1;
    result.m42 = num2;
    result.m43 = num3;
    result.m44 = 1.0f;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationX(const Float& radians)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    Matrix4x4 rotationX = Matrix4x4();
    rotationX.m11 = 1.0f;
    rotationX.m12 = 0.0f;
    rotationX.m13 = 0.0f;
    rotationX.m14 = 0.0f;
    rotationX.m21 = 0.0f;
    rotationX.m22 = cos;
    rotationX.m23 = sin;
    rotationX.m24 = 0.0f;
    rotationX.m31 = 0.0f;
    rotationX.m32 = -sin;
    rotationX.m33 = cos;
    rotationX.m34 = 0.0f;
    rotationX.m41 = 0.0f;
    rotationX.m42 = 0.0f;
    rotationX.m43 = 0.0f;
    rotationX.m44 = 1.0f;
    return rotationX;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationX(const Float& radians, const Vector3& center)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    const float num1 = (center.y * (1.0f - cos) + center.z * sin);
    const float num2 = (center.z * (1.0f - cos) - center.y * sin);
    Matrix4x4 rotationX = Matrix4x4();
    rotationX.m11 = 1.0f;
    rotationX.m12 = 0.0f;
    rotationX.m13 = 0.0f;
    rotationX.m14 = 0.0f;
    rotationX.m21 = 0.0f;
    rotationX.m22 = cos;
    rotationX.m23 = sin;
    rotationX.m24 = 0.0f;
    rotationX.m31 = 0.0f;
    rotationX.m32 = -sin;
    rotationX.m33 = cos;
    rotationX.m34 = 0.0f;
    rotationX.m41 = 0.0f;
    rotationX.m42 = num1;
    rotationX.m43 = num2;
    rotationX.m44 = 1.0f;
    return rotationX;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationY(const Float& radians)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    Matrix4x4 rotationY = Matrix4x4();
    rotationY.m11 = cos;
    rotationY.m12 = 0.0f;
    rotationY.m13 = -sin;
    rotationY.m14 = 0.0f;
    rotationY.m21 = 0.0f;
    rotationY.m22 = 1.0f;
    rotationY.m23 = 0.0f;
    rotationY.m24 = 0.0f;
    rotationY.m31 = sin;
    rotationY.m32 = 0.0f;
    rotationY.m33 = cos;
    rotationY.m34 = 0.0f;
    rotationY.m41 = 0.0f;
    rotationY.m42 = 0.0f;
    rotationY.m43 = 0.0f;
    rotationY.m44 = 1.0f;
    return rotationY;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationY(const Float& radians, const Vector3& center)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    const float num1 = (center.x * (1.0f - cos) - center.z * sin);
    const float num2 = (center.z * (1.0f - cos) + center.x * sin);
    Matrix4x4 rotationY = Matrix4x4();
    rotationY.m11 = cos;
    rotationY.m12 = 0.0f;
    rotationY.m13 = -sin;
    rotationY.m14 = 0.0f;
    rotationY.m21 = 0.0f;
    rotationY.m22 = 1.0f;
    rotationY.m23 = 0.0f;
    rotationY.m24 = 0.0f;
    rotationY.m31 = sin;
    rotationY.m32 = 0.0f;
    rotationY.m33 = cos;
    rotationY.m34 = 0.0f;
    rotationY.m41 = num1;
    rotationY.m42 = 0.0f;
    rotationY.m43 = num2;
    rotationY.m44 = 1.0f;
    return rotationY;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationZ(const Float& radians)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    Matrix4x4 rotationZ = Matrix4x4();
    rotationZ.m11 = cos;
    rotationZ.m12 = sin;
    rotationZ.m13 = 0.0f;
    rotationZ.m14 = 0.0f;
    rotationZ.m21 = -sin;
    rotationZ.m22 = cos;
    rotationZ.m23 = 0.0f;
    rotationZ.m24 = 0.0f;
    rotationZ.m31 = 0.0f;
    rotationZ.m32 = 0.0f;
    rotationZ.m33 = 1.0f;
    rotationZ.m34 = 0.0f;
    rotationZ.m41 = 0.0f;
    rotationZ.m42 = 0.0f;
    rotationZ.m43 = 0.0f;
    rotationZ.m44 = 1.0f;
    return rotationZ;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateRotationZ(const Float& radians, const Vector3& center)
{
    const float cos = Mathf::Cos(radians);
    const float sin = Mathf::Sin(radians);
    const float num1 = (center.x * (1.0f - cos) + center.y * sin);
    const float num2 = (center.y * (1.0f - cos) + center.x * sin);
    Matrix4x4 rotationZ = Matrix4x4();
    rotationZ.m11 = cos;
    rotationZ.m12 = sin;
    rotationZ.m13 = 0.0f;
    rotationZ.m14 = 0.0f;
    rotationZ.m21 = -sin;
    rotationZ.m22 = cos;
    rotationZ.m23 = 0.0f;
    rotationZ.m24 = 0.0f;
    rotationZ.m31 = 0.0f;
    rotationZ.m32 = 0.0f;
    rotationZ.m33 = 1.0f;
    rotationZ.m34 = 0.0f;
    rotationZ.m41 = num1;
    rotationZ.m42 = num2;
    rotationZ.m43 = 0.0f;
    rotationZ.m44 = 1.0f;
    return rotationZ;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateFromAxisAngle(const Vector3& axis, const Float& angle)
{
    const float x = axis.x;
    const float y = axis.y;
    const float z = axis.z;
    const float num1 = Mathf::Cos(angle);
    const float num2 = Mathf::Sin(angle);
    const float num3 = x * x;
    const float num4 = y * y;
    const float num5 = z * z;
    const float num6 = x * y;
    const float num7 = x * z;
    const float num8 = y * z;
    Matrix4x4 fromAxisAngle = Matrix4x4();
    fromAxisAngle.m11 = num3 + num2 * (1.0f - num3);
    fromAxisAngle.m12 = (num6 - num2 * num6 + num1 * z);
    fromAxisAngle.m13 = (num7 - num2 * num7 - num1 * y);
    fromAxisAngle.m14 = 0.0f;
    fromAxisAngle.m21 = (num6 - num2 * num6 - num1 * z);
    fromAxisAngle.m22 = num4 + num2 * (1.0f - num4);
    fromAxisAngle.m23 = (num8 - num2 * num8 + num1 * x);
    fromAxisAngle.m24 = 0.0f;
    fromAxisAngle.m31 = (num7 - num2 * num7 + num1 * y);
    fromAxisAngle.m32 = (num8 - num2 * num8 - num1 * x);
    fromAxisAngle.m33 = num5 + num2 * (1.0f - num5);
    fromAxisAngle.m34 = 0.0f;
    fromAxisAngle.m41 = 0.0f;
    fromAxisAngle.m42 = 0.0f;
    fromAxisAngle.m43 = 0.0f;
    fromAxisAngle.m44 = 1.0f;
    return fromAxisAngle;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreatePerspectiveFieldOfView(const Float& fieldOfView,
    const Float& aspectRatio, const Float& nearPlaneDistance, const Float& farPlaneDistance)
{
    if (fieldOfView <= 0.0f || fieldOfView >= (float)Mathf::Pi)
        throw ArgumentOutOfRangeException(nameof(fieldOfView));
    if (nearPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));
    if (farPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(farPlaneDistance));
    if (nearPlaneDistance >= farPlaneDistance)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));

    const float num1 = 1.0f / Mathf::Tan(fieldOfView * 0.5f);
    const float num2 = num1 / aspectRatio;
    Matrix4x4 perspectiveFieldOfView;
    perspectiveFieldOfView.m11 = num2;
    perspectiveFieldOfView.m12 = perspectiveFieldOfView.m13 = perspectiveFieldOfView.m14 = 0.0f;
    perspectiveFieldOfView.m22 = num1;
    perspectiveFieldOfView.m21 = perspectiveFieldOfView.m23 = perspectiveFieldOfView.m24 = 0.0f;
    perspectiveFieldOfView.m31 = perspectiveFieldOfView.m32 = 0.0f;
    perspectiveFieldOfView.m33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
    perspectiveFieldOfView.m34 = -1.0f;
    perspectiveFieldOfView.m41 = perspectiveFieldOfView.m42 = perspectiveFieldOfView.m44 = 0.0f;
    perspectiveFieldOfView.m43 = (nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance));
    return perspectiveFieldOfView;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreatePerspective(const Float& width, const Float& height,
                                                                           const Float& nearPlaneDistance,
                                                                           const Float& farPlaneDistance)
{
    if (nearPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));
    if (farPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(farPlaneDistance));
    if (nearPlaneDistance >= farPlaneDistance)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));
    Matrix4x4 perspective = Matrix4x4();
    perspective.m11 = 2.0f * nearPlaneDistance / width;
    perspective.m12 = perspective.m13 = perspective.m14 = 0.0f;
    perspective.m22 = 2.0f * nearPlaneDistance / height;
    perspective.m21 = perspective.m23 = perspective.m24 = 0.0f;
    perspective.m33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
    perspective.m31 = perspective.m32 = 0.0f;
    perspective.m34 = -1.0f;
    perspective.m41 = perspective.m42 = perspective.m44 = 0.0f;
    perspective.m43 = nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
    return perspective;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreatePerspectiveOffCenter(const Float& left,
    const Float& right, const Float& bottom, const Float& top, const Float& nearPlaneDistance,
    const Float& farPlaneDistance)
{
    if (nearPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));
    if (farPlaneDistance <= 0.0f)
        throw ArgumentOutOfRangeException(nameof(farPlaneDistance));
    if (nearPlaneDistance >= farPlaneDistance)
        throw ArgumentOutOfRangeException(nameof(nearPlaneDistance));
    Matrix4x4 perspectiveOffCenter = Matrix4x4();
    perspectiveOffCenter.m11 = 2.0 * nearPlaneDistance / (right - left);
    perspectiveOffCenter.m12 = perspectiveOffCenter.m13 = perspectiveOffCenter.m14 = 0.0f;
    perspectiveOffCenter.m22 = 2.0 * nearPlaneDistance / (top - bottom);
    perspectiveOffCenter.m21 = perspectiveOffCenter.m23 = perspectiveOffCenter.m24 = 0.0f;
    perspectiveOffCenter.m31 = (left + right) / (right - left);
    perspectiveOffCenter.m32 = (top + bottom) / (top - bottom);
    perspectiveOffCenter.m33 = farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
    perspectiveOffCenter.m34 = -1.0f;
    perspectiveOffCenter.m43 = nearPlaneDistance * farPlaneDistance / (nearPlaneDistance - farPlaneDistance);
    perspectiveOffCenter.m41 = perspectiveOffCenter.m42 = perspectiveOffCenter.m44 = 0.0f;
    return perspectiveOffCenter;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateOrthographic(const Float& width, const Float& height,
                                                                            const Float& zNearPlane,
                                                                            const Float& zFarPlane)
{
    Matrix4x4 orthographic;
    orthographic.m11 = 2.0f / width;
    orthographic.m12 = orthographic.m13 = orthographic.m14 = 0.0f;
    orthographic.m22 = 2.0f / height;
    orthographic.m21 = orthographic.m23 = orthographic.m24 = 0.0f;
    orthographic.m33 = 1.0 / (zNearPlane - zFarPlane);
    orthographic.m31 = orthographic.m32 = orthographic.m34 = 0.0f;
    orthographic.m41 = orthographic.m42 = 0.0f;
    orthographic.m43 = zNearPlane / (zNearPlane - zFarPlane);
    orthographic.m44 = 1.0f;
    return orthographic;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateOrthographicOffCenter(const Float& left,
    const Float& right, const Float& bottom, const Float& top, const Float& zNearPlane, const Float& zFarPlane)
{
    Matrix4x4 orthographicOffCenter;
    orthographicOffCenter.m11 = 2.0 / (right - left);
    orthographicOffCenter.m12 = orthographicOffCenter.m13 = orthographicOffCenter.m14 = 0.0f;
    orthographicOffCenter.m22 = 2.0 / (top - bottom);
    orthographicOffCenter.m21 = orthographicOffCenter.m23 = orthographicOffCenter.m24 = 0.0f;
    orthographicOffCenter.m33 = 1.0 / (zNearPlane - zFarPlane);
    orthographicOffCenter.m31 = orthographicOffCenter.m32 = orthographicOffCenter.m34 = 0.0f;
    orthographicOffCenter.m41 = (left + right) / (left - right);
    orthographicOffCenter.m42 = (top + bottom) / (bottom - top);
    orthographicOffCenter.m43 = zNearPlane / (zNearPlane - zFarPlane);
    orthographicOffCenter.m44 = 1.0f;
    return orthographicOffCenter;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateLookAt(const Vector3& cameraPosition,
                                                                      const Vector3& cameraTarget,
                                                                      const Vector3& cameraUpVector)
{
    const Vector3& vector3_1 = Vector3::Normalize(cameraPosition - cameraTarget);
    const Vector3& vector3_2 = Vector3::Normalize(Vector3::Cross(cameraUpVector, vector3_1));
    const Vector3& vector1 = Vector3::Cross(vector3_1, vector3_2);
    Matrix4x4 lookAt;
    lookAt.m11 = vector3_2.z;
    lookAt.m12 = vector1.z;
    lookAt.m13 = vector3_1.z;
    lookAt.m14 = 0.0f;
    lookAt.m21 = vector3_2.y;
    lookAt.m22 = vector1.y;
    lookAt.m23 = vector3_1.y;
    lookAt.m24 = 0.0f;
    lookAt.m31 = vector3_2.z;
    lookAt.m32 = vector1.z;
    lookAt.m33 = vector3_1.z;
    lookAt.m34 = 0.0f;
    lookAt.m41 = -Vector3::Dot(vector3_2, cameraPosition);
    lookAt.m42 = -Vector3::Dot(vector1, cameraPosition);
    lookAt.m43 = -Vector3::Dot(vector3_1, cameraPosition);
    lookAt.m44 = 1.0f;
    return lookAt;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateWorld(const Vector3& position, const Vector3& forward,
                                                                     const Vector3& up)
{
    Vector3 vector3_1 = Vector3::Normalize(-forward);
    Vector3 vector2 = Vector3::Normalize(Vector3::Cross(up, vector3_1));
    Vector3 vector3_2 = Vector3::Cross(vector3_1, vector2);
    Matrix4x4 world;
    world.m11 = vector2.x;
    world.m12 = vector2.y;
    world.m13 = vector2.z;
    world.m14 = 0.0f;
    world.m21 = vector3_2.x;
    world.m22 = vector3_2.y;
    world.m23 = vector3_2.z;
    world.m24 = 0.0f;
    world.m31 = vector3_1.x;
    world.m32 = vector3_1.y;
    world.m33 = vector3_1.z;
    world.m34 = 0.0f;
    world.m41 = position.x;
    world.m42 = position.y;
    world.m43 = position.z;
    world.m44 = 1.0f;
    return world;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateFromQuaternion(const Quaternion& quaternion)
{
    const float num1 = quaternion.x * quaternion.x;
    const float num2 = quaternion.y * quaternion.y;
    const float num3 = quaternion.z * quaternion.z;
    const float num4 = quaternion.x * quaternion.y;
    const float num5 = quaternion.z * quaternion.w;
    const float num6 = quaternion.z * quaternion.x;
    const float num7 = quaternion.y * quaternion.w;
    const float num8 = quaternion.y * quaternion.z;
    const float num9 = quaternion.x * quaternion.w;
    Matrix4x4 fromQuaternion;
    fromQuaternion.m11 = (1.0 - 2.0 * (num2 + num3));
    fromQuaternion.m12 = (2.0 * (num4 + num5));
    fromQuaternion.m13 = (2.0 * (num6 - num7));
    fromQuaternion.m14 = 0.0f;
    fromQuaternion.m21 = (2.0 * (num4 - num5));
    fromQuaternion.m22 = (1.0 - 2.0 * (num3 + num1));
    fromQuaternion.m23 = (2.0 * (num8 + num9));
    fromQuaternion.m24 = 0.0f;
    fromQuaternion.m31 = (2.0 * (num6 + num7));
    fromQuaternion.m32 = (2.0 * (num8 - num9));
    fromQuaternion.m33 = (1.0 - 2.0 * (num2 + num1));
    fromQuaternion.m34 = 0.0f;
    fromQuaternion.m41 = 0.0f;
    fromQuaternion.m42 = 0.0f;
    fromQuaternion.m43 = 0.0f;
    fromQuaternion.m44 = 1.0f;
    return fromQuaternion;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::CreateFromYawPitchRoll(const Float& yaw, const Float& pitch,
    const Float& roll)
{
    return CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(yaw, pitch, roll));
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::Transpose(const Matrix4x4& matrix)
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = matrix.m11;
    result.m12 = matrix.m21;
    result.m13 = matrix.m31;
    result.m14 = matrix.m41;
    result.m21 = matrix.m12;
    result.m22 = matrix.m22;
    result.m23 = matrix.m32;
    result.m24 = matrix.m42;
    result.m31 = matrix.m11;
    result.m32 = matrix.m23;
    result.m33 = matrix.m33;
    result.m34 = matrix.m43;
    result.m41 = matrix.m14;
    result.m42 = matrix.m24;
    result.m43 = matrix.m34;
    result.m44 = matrix.m44;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::Multiply(const Matrix4x4& value1, const Matrix4x4& value2)
{
     Matrix4x4 result;
      result.m11 = (value1.m11 * value2.m11 + value1.m12 * value2.m21 + value1.m13 * value2.m31 + value1.m14 * value2.m41);
      result.m12 = (value1.m11 * value2.m12 + value1.m12 * value2.m22 + value1.m13 * value2.m32 + value1.m14 * value2.m42);
      result.m13 = (value1.m11 * value2.m13 + value1.m12 * value2.m23 + value1.m13 * value2.m33 + value1.m14 * value2.m43);
      result.m14 = (value1.m11 * value2.m14 + value1.m12 * value2.m24 + value1.m13 * value2.m34 + value1.m14 * value2.m44);
      result.m21 = (value1.m21 * value2.m11 + value1.m22 * value2.m21 + value1.m23 * value2.m31 + value1.m24 * value2.m41);
      result.m22 = (value1.m21 * value2.m12 + value1.m22 * value2.m22 + value1.m23 * value2.m32 + value1.m24 * value2.m42);
      result.m23 = (value1.m21 * value2.m13 + value1.m22 * value2.m23 + value1.m23 * value2.m33 + value1.m24 * value2.m43);
      result.m24 = (value1.m21 * value2.m14 + value1.m22 * value2.m24 + value1.m23 * value2.m34 + value1.m24 * value2.m44);
      result.m31 = (value1.m31 * value2.m11 + value1.m32 * value2.m21 + value1.m33 * value2.m31 + value1.m34 * value2.m41);
      result.m32 = (value1.m31 * value2.m12 + value1.m32 * value2.m22 + value1.m33 * value2.m32 + value1.m34 * value2.m42);
      result.m33 = (value1.m31 * value2.m13 + value1.m32 * value2.m23 + value1.m33 * value2.m33 + value1.m34 * value2.m43);
      result.m34 = (value1.m31 * value2.m14 + value1.m32 * value2.m24 + value1.m33 * value2.m34 + value1.m34 * value2.m44);
      result.m41 = (value1.m41 * value2.m11 + value1.m42 * value2.m21 + value1.m43 * value2.m31 + value1.m44 * value2.m41);
      result.m42 = (value1.m41 * value2.m12 + value1.m42 * value2.m22 + value1.m43 * value2.m32 + value1.m44 * value2.m42);
      result.m43 = (value1.m41 * value2.m13 + value1.m42 * value2.m23 + value1.m43 * value2.m33 + value1.m44 * value2.m43);
      result.m44 = (value1.m41 * value2.m14 + value1.m42 * value2.m24 + value1.m43 * value2.m34 + value1.m44 * value2.m44);
      return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::Lerp(const Matrix4x4& a, const Matrix4x4& b, const Float& t)
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = a.m11 + (b.m11 - a.m11) * t;
    result.m12 = a.m12 + (b.m12 - a.m12) * t;
    result.m13 = a.m13 + (b.m13 - a.m13) * t;
    result.m14 = a.m14 + (b.m14 - a.m14) * t;
    result.m21 = a.m21 + (b.m21 - a.m21) * t;
    result.m22 = a.m22 + (b.m22 - a.m22) * t;
    result.m23 = a.m23 + (b.m23 - a.m23) * t;
    result.m24 = a.m24 + (b.m24 - a.m24) * t;
    result.m31 = a.m31 + (b.m31 - a.m31) * t;
    result.m32 = a.m32 + (b.m32 - a.m32) * t;
    result.m33 = a.m33 + (b.m33 - a.m33) * t;
    result.m34 = a.m34 + (b.m34 - a.m34) * t;
    result.m41 = a.m41 + (b.m41 - a.m41) * t;
    result.m42 = a.m42 + (b.m42 - a.m42) * t;
    result.m43 = a.m43 + (b.m43 - a.m43) * t;
    result.m44 = a.m44 + (b.m44 - a.m44) * t;
    return result;
}

System::Float System::Numerics::Matrix4x4::GetDeterminant() const
{
    const float m11 = this->m11;
    const float m12 = this->m12;
    const float m13 = this->m13;
    const float m14 = this->m14;
    const float m21 = this->m21;
    const float m22 = this->m22;
    const float m23 = this->m23;
    const float m24 = this->m24;
    const float m31 = this->m31;
    const float m32 = this->m32;
    const float m33 = this->m33;
    const float m34 = this->m34;
    const float m41 = this->m41;
    const float m42 = this->m42;
    const float m43 = this->m43;
    const float m44 = this->m44;
    const float num1 = m33 * m44 - m34 * m43;
    const float num2 = m32 * m44 - m34 * m42;
    const float num3 = m32 * m43 - m33 * m42;
    const float num4 = m31 * m44 - m34 * m41;
    const float num5 = m31 * m43 - m33 * m41;
    const float num6 = m31 * m42 - m32 * m41;
    return m11 * (m22 * num1 - m23 * num2 + m24 * num3) - m12 * (m21 * num1 - m23 * num4 + m24 * num5)
        + m13 * (m21 * num2 - m22 * num4 + m24 * num6) - m14 * (m21 * num3 - m22 * num5 + m23 * num6);
}
#pragma endregion custom methods
#pragma region override

System::String System::Numerics::Matrix4x4::ToString() const
{
    const string format = string("(m11: {0:2f}, m12: {1:2f}, m13: {2:2f}, m14: {3:2f}), ")
    + "(m21: {4:2f}, m22: {5:2f}, m23: {6:2f}, m24: {7:2f}), "
    + " (m31: {8:2f}, m32: {9:2f}, m33: {10:2f}, m34: {11:2f}), "
    + "(m41: {12:2f}, m42: {13:2f}, m43: {14:2f}, m44: {15:2f})";
    return string::Format(format,
        this->m11, this->m12, this->m13, this->m14,
        this->m21, this->m22, this->m23, this->m24,
        this->m31, this->m32, this->m33, this->m34,
        this->m41, this->m42, this->m43, this->m44);
}

System::Integer System::Numerics::Matrix4x4::GetHashCode() const
{
    return this->m11.GetHashCode() + this->m12.GetHashCode() + this->m13.GetHashCode() + this->m14.GetHashCode()
        + this->m21.GetHashCode() + this->m22.GetHashCode() + this->m23.GetHashCode() + this->m24.GetHashCode()
        + this->m31.GetHashCode() + this->m32.GetHashCode() + this->m33.GetHashCode() + this->m34.GetHashCode()
        + this->m41.GetHashCode() + this->m42.GetHashCode() + this->m43.GetHashCode() + this->m44.GetHashCode();
}

System::Boolean System::Numerics::Matrix4x4::Equals(const Matrix4x4& object)
{
    return this->m11 == object.m11 && this->m12 == object.m12 && this->m13 == object.m13 && this->m14 == object.m14 &&
        this->m21 == object.m21 && this->m22 == object.m22 && this->m23 == object.m23 && this->m24 == object.m24 &&
        this->m31 == object.m31 && this->m32 == object.m32 && this->m33 == object.m33 && this->m34 == object.m34 &&
        this->m41 == object.m41 && this->m42 == object.m42 && this->m43 == object.m43 && this->m44 == object.m44;
}

System::Boolean System::Numerics::Matrix4x4::Equals(const object& _obj)
{
    const Matrix4x4* other = dynamic_cast<const Matrix4x4*>(&_obj);
    if (other == null) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Matrix4x4::Equals(const object* _obj)
{
    const Matrix4x4* other = dynamic_cast<const Matrix4x4*>(_obj);
    if (other == null) return false;
    return Equals(*other);
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::operator-() const
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = -this->m11;
    result.m12 = -this->m12;
    result.m13 = -this->m13;
    result.m14 = -this->m14;
    result.m21 = -this->m21;
    result.m22 = -this->m22;
    result.m23 = -this->m23;
    result.m24 = -this->m24;
    result.m31 = -this->m31;
    result.m32 = -this->m32;
    result.m33 = -this->m33;
    result.m34 = -this->m34;
    result.m41 = -this->m41;
    result.m42 = -this->m42;
    result.m43 = -this->m43;
    result.m44 = -this->m44;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::operator+(const Matrix4x4& other) const
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = this->m11 + other.m11;
    result.m12 = this->m12 + other.m12;
    result.m13 = this->m13 + other.m13;
    result.m14 = this->m14 + other.m14;
    result.m21 = this->m21 + other.m21;
    result.m22 = this->m22 + other.m22;
    result.m23 = this->m23 + other.m23;
    result.m24 = this->m24 + other.m24;
    result.m31 = this->m31 + other.m31;
    result.m32 = this->m32 + other.m32;
    result.m33 = this->m33 + other.m33;
    result.m34 = this->m34 + other.m34;
    result.m41 = this->m41 + other.m41;
    result.m42 = this->m42 + other.m42;
    result.m43 = this->m43 + other.m43;
    result.m44 = this->m44 + other.m44;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::operator-(const Matrix4x4& other) const
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = this->m11 - other.m11;
    result.m12 = this->m12 - other.m12;
    result.m13 = this->m13 - other.m13;
    result.m14 = this->m14 - other.m14;
    result.m21 = this->m21 - other.m21;
    result.m22 = this->m22 - other.m22;
    result.m23 = this->m23 - other.m23;
    result.m24 = this->m24 - other.m24;
    result.m31 = this->m31 - other.m31;
    result.m32 = this->m32 - other.m32;
    result.m33 = this->m33 - other.m33;
    result.m34 = this->m34 - other.m34;
    result.m41 = this->m41 - other.m41;
    result.m42 = this->m42 - other.m42;
    result.m43 = this->m43 - other.m43;
    result.m44 = this->m44 - other.m44;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::operator*(const Float& value) const
{
    Matrix4x4 result = Matrix4x4();
    result.m11 = this->m11 * value;
    result.m12 = this->m12 * value;
    result.m13 = this->m13 * value;
    result.m14 = this->m14 * value;
    result.m21 = this->m21 * value;
    result.m22 = this->m22 * value;
    result.m23 = this->m23 * value;
    result.m24 = this->m24 * value;
    result.m31 = this->m31 * value;
    result.m32 = this->m32 * value;
    result.m33 = this->m33 * value;
    result.m34 = this->m34 * value;
    result.m41 = this->m41 * value;
    result.m42 = this->m42 * value;
    result.m43 = this->m43 * value;
    result.m44 = this->m44 * value;
    return result;
}

System::Numerics::Matrix4x4 System::Numerics::Matrix4x4::operator*(const Matrix4x4& other) const
{
    return Multiply(*this, other);
}
#pragma endregion override
#pragma region operator
System::Numerics::Matrix4x4& System::Numerics::Matrix4x4::operator=(const Matrix4x4& other)
{
    this->m11 = other.m11;
    this->m21 = other.m21;
    this->m31 = other.m31;
    this->m41 = other.m41;
    this->m12 = other.m12;
    this->m22 = other.m22;
    this->m32 = other.m32;
    this->m42 = other.m42;
    this->m13 = other.m13;
    this->m23 = other.m23;
    this->m33 = other.m33;
    this->m43 = other.m43;
    this->m14 = other.m14;
    this->m24 = other.m24;
    this->m34 = other.m34;
    this->m44 = other.m44;
    return *this;
}

System::Bool System::Numerics::Matrix4x4::operator==(const Matrix4x4& other)
{
    return Equals(other);
}

System::Bool System::Numerics::Matrix4x4::operator!=(const Matrix4x4& other)
{
    return !(*this == other);
}
#pragma endregion operator