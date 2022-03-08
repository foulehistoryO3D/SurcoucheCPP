#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Float/Float.h"

namespace System
{
    namespace Numerics
    {
        class Vector3;
        class Vector4;
        class Matrix4x4 sealed : public Object
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        public:
            Float m11;
            Float m12;
            Float m13;
            Float m14;
            Float m21;
            Float m22;
            Float m23;
            Float m24;
            Float m31;
            Float m32;
            Float m33;
            Float m34;
            Float m41;
            Float m42;
            Float m43;
            Float m44;
            static const Matrix4x4 Identity;
            Boolean IsIdentity()const;
            Vector3 Translation()const;
#pragma endregion f/p
#pragma region constructor
        public:
            Matrix4x4() = default;
            Matrix4x4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);
            Matrix4x4(const Matrix4x4& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Matrix4x4 CreateTranslation(const Vector3& position);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
#pragma endregion override
        };
    }
}
