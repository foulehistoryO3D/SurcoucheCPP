#include "Matrix4x4.h"

#include "../../Vector/Vector3/Vector3.h"
#include "../../Vector/Vector4/Vector4.h"

#pragma region f/p
System::Numerics::Matrix4x4 const System::Numerics::Matrix4x4::Identity(Vector4(1,0,0,0), Vector4(0,1,0,0), Vector4(0,0,1,0), Vector4(0,0,0,1));

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
    this->m11 = a.x; this->m21 = b.x; this->m31 = c.x; this->m41 = d.x;
    this->m12 = a.y; this->m22 = b.y; this->m32 = c.y; this->m42 = d.y;
    this->m13 = a.z; this->m23 = b.z; this->m33 = c.z; this->m43 = d.z;
    this->m14 = a.w; this->m24 = b.w; this->m34 = c.w; this->m44 = d.w;               
}

System::Numerics::Matrix4x4::Matrix4x4(const Matrix4x4& copy)
{
    this->m11 = copy.m11; this->m21 = copy.m21; this->m31 = copy.m31; this->m41 = copy.m41;
    this->m12 = copy.m12; this->m22 = copy.m22; this->m32 = copy.m32; this->m42 = copy.m42;
    this->m13 = copy.m13; this->m23 = copy.m23; this->m33 = copy.m33; this->m43 = copy.m43;
    this->m14 = copy.m14; this->m24 = copy.m24; this->m34 = copy.m34; this->m44 = copy.m44;       
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

System::String System::Numerics::Matrix4x4::ToString() const
{
    return string::Format("({0},{1},{2},{3}), ({4},{5},{6},{7}), ({8},{9},{10},{11}), ({12},{13},{14},{15})",
        this->m11, this->m12, this->m13, this->m14,
        this->m21, this->m22, this->m23, this->m24,
        this->m31, this->m32, this->m33, this->m34,
        this->m41, this->m42, this->m43, this->m44);
}
#pragma endregion custom methods
