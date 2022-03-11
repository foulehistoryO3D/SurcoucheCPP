#include "Quaternion.h"

#include "../../System/Mathf/Mathf.h"
#include "../Vector/Vector3/Vector3.h"

#pragma region f/p
System::Numerics::Quaternion const System::Numerics::Quaternion::Identity(0,0,0,1);
System::Float const System::Numerics::Quaternion::kEpsilon = 0.000001F;
System::Bool System::Numerics::Quaternion::IsIdentity() const
{
    return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f && this->w == 1.0f;
}
#pragma endregion f/p
#pragma region constructor
System::Numerics::Quaternion::Quaternion(const Float& x, const Float& y, const Float& z, const Float& w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

System::Numerics::Quaternion::Quaternion(const Vector3& vector, const Float& w)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
    this->w = w;
}

System::Numerics::Quaternion::Quaternion(const Quaternion& copy) : Object(copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

System::Boolean System::Numerics::Quaternion::IsEqualUsingDot(const Float& dot)
{
    return dot > 1.0f - kEpsilon;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Normalize(const Quaternion& value)
{
    const float num = 1.0f / Mathf::Sqrt(value.x * value.x + value.y * value.y + value.z * value.z + value.w * value.w);
    return Quaternion(value.x * num, value.y * num, value.z * num, value.w * num);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Conjugate(const Quaternion& value)
{
    return Quaternion(-value.x, -value.y, -value.z, -value.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Inverse(const Quaternion& value)
{
    const float num = 1.0f / value.x * value.x + value.y * value.y + value.z * value.z + value.w * value.w;
    return Quaternion(-value.x * num, -value.y * num, -value.z * num, -value.w * num);
}

System::Numerics::Quaternion System::Numerics::Quaternion::CreateFromAxisAngle(const Vector3& axis, const Float& angle)
{
    const Double& num1 = angle * 0.5f;
    const float num2 = Mathf::Sin(num1);
    const float num3 = Mathf::Cos(num1);
    return Quaternion(axis.x * num2, axis.y * num2, axis.z * num2, num3);
}

System::Numerics::Quaternion System::Numerics::Quaternion::CreateFromYawPitchRoll(const Float& yaw, const Float& pitch, const Float& roll)
{
    const Double& num1 = roll * 0.5f;
    const float num2 = Mathf::Sin(num1);
    const float num3 = Mathf::Cos(num1);
    const Double& num4 = pitch * 0.5f;
    const float num5 = Mathf::Sin(num4);
    const float num6 = Mathf::Cos(num4);
    const Double& num7 = yaw * 0.5f;
    const float num8 = Mathf::Sin(num7);
    const float num9 = Mathf::Cos(num7);
    Quaternion fromYawPitchRoll = Identity;
    fromYawPitchRoll.x = num9 * num5 * num3 + num8 * num6 * num2;
    fromYawPitchRoll.y = num8 * num6 * num3 - num9 * num5 * num2;
    fromYawPitchRoll.z = num9 * num6 * num2 - num8 * num5 * num3;
    fromYawPitchRoll.w = num9 * num6 * num3 + num8 * num5 * num2;
    return fromYawPitchRoll;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Concatenate(const Quaternion& a, const Quaternion& b)
{
    const float x1 = b.x;
    const float y1 = b.y;
    const float z1 = b.z;
    const float w1 = b.w;
    const float x2 = a.x;
    const float y2 = a.y;
    const float z2 = a.z;
    const float w2 = a.w;
    const float num1 = y1 * z2 - z1 * y2;
    const float num2 = z1 * x2 - x1 * z2;
    const float num3 = x1 * y2 - y1 * x2;
    const float num4 = x1 * x2 + y1 * y2 + z1 * z2;
    Quaternion quaternion = Identity;
    quaternion.x = (x1 * w2 + x2 * w1) + num1;
    quaternion.y = (y1 * w2 + y2 * w1) + num2;
    quaternion.z = (z1 * w2 + z2 * w1) + num3;
    quaternion.w = w1 * w2 - num4;
    return quaternion;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Negate(const Quaternion& value)
{
    return Quaternion(-value.x, -value.y, -value.z, -value.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Add(const Quaternion& a, const Quaternion& b)
{
    return Quaternion(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Subtract(const Quaternion& a, const Quaternion& b)
{
    return Quaternion(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Multiply(const Quaternion& a, const Quaternion& b)
{
    const float x1 = a.x;
    const float y1 = a.y;
    const float z1 = a.z;
    const float w1 = a.w;
    const float x2 = b.x;
    const float y2 = b.y;
    const float z2 = b.z;
    const float w2 = b.w;
    const float num1 = y1 * z2 - z1 * y2;
    const float num2 = z1 * x2 - x1 * z2;
    const float num3 = x1 * y2 - y1 * x2;
    const float num4 = x1 * x2 + y1 * y2 + z1 * z2;
    Quaternion quaternion = Identity;
    quaternion.x = (x1 * w2 + x2 * w1) + num1;
    quaternion.y = (y1 * w2 + y2 * w1) + num2;
    quaternion.z = (z1 * w2 + z2 * w1) + num3;
    quaternion.w = w1 * w2 - num4;
    return quaternion;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Multiply(const Quaternion& a, const Float& value)
{
    return Quaternion(a.x * value, a.y * value, a.z * value, a.w * value);
}

System::Numerics::Quaternion System::Numerics::Quaternion::Divide(const Quaternion& a, const Quaternion& b)
{
    const float x1 = a.x;
    const float y1 = a.y;
    const float z1 = a.z;
    const float w1 = a.w;
    const float num1 = 1.0f / b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w;
    const float num2 = -b.x * num1;
    const float num3 = -b.y * num1;
    const float num4 = -b.z * num1;
    const float num5 = b.w * num1;
    const float num6 = y1 * num4 - z1 * num3;
    const float num7 = z1 * num2 - x1 * num4;
    const float num8 = x1 * num3 - y1 * num2;
    const float num9 = x1 * num2 + y1 * num3 + z1 * num4;
    Quaternion quaternion = Identity;
    quaternion.x = (x1 * num5 + num2 * w1) + num6;
    quaternion.y = (y1 * num5 + num3 * w1) + num7;
    quaternion.z = (z1 * num5 + num4 * w1) + num8;
    quaternion.w = w1 * num5 - num9;
    return quaternion;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Lerp(const Quaternion& a, const Quaternion& b, const Float& t)
{
    const float num1 = t;
    const float num2 = 1.0f - num1;
    Quaternion quaternion = Quaternion();
    if (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w >= 0.0f)
    {
        quaternion.x = num2 * a.x + num1 * b.x;
        quaternion.y = num2 * a.y + num1 * b.y;
        quaternion.z = num2 * a.z + num1 * b.z;
        quaternion.w = num2 * a.w + num1 * b.w;
    }
    else
    {
        quaternion.x = num2 * a.x - num1 * b.x;
        quaternion.y = num2 * a.y - num1 * b.y;
        quaternion.z = num2 * a.z - num1 * b.z;
        quaternion.w = num2 * a.w - num1 * b.w;
    }

    const float num3 = 1.0f / Mathf::Sqrt(quaternion.x * quaternion.x + quaternion.y * quaternion.y + quaternion.z * quaternion.z + quaternion.w * quaternion.w);
    quaternion.x *= num3;
    quaternion.y *= num3;
    quaternion.z *= num3;
    quaternion.w *= num3;
    return quaternion;
}

System::Numerics::Quaternion System::Numerics::Quaternion::Slerp(const Quaternion& a, const Quaternion& b,
    const Float& t)
{
    const Float& num1 = t;
    float d = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    bool flag = false;
    if (d < 0.0f)
    {
        flag = true;
        d = -d;
    }
    float num2, num3;
    if (d > 0.999998986721039)
    {
        num2 = 1.0f - num1;
        num3 = flag ? -num1: num1;
    }
    else
    {
        const Float& a1 = Mathf::Acos(d);
        const Float& num4 = 1.0f / Mathf::Sin(a1);
        num2 = Mathf::Sin(Float((1.0 - num1) * a1)) * num4;
        num3 = flag ? -Mathf::Sin(Float(num1 * a1)) * num4 : Mathf::Sin(Float(num1 * a1)) * num4;
    }
    Quaternion quaternion = Quaternion();
    quaternion.x = num2 * a.x + num3 * b.x;
    quaternion.y = num2 * a.y + num3 * b.y;
    quaternion.z = num2 * a.z + num3 * b.z;
    quaternion.w = num2 * a.w + num3 * b.w;
    return quaternion;
}

System::Float System::Numerics::Quaternion::Dot(const Quaternion& a, const Quaternion& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

System::Float System::Numerics::Quaternion::Angle(const Quaternion& a, const Quaternion& b)
{
    const float dot = Dot(a, b);
    return IsEqualUsingDot(dot) ? 0.0f : Mathf::Acos(Mathf::Min(Mathf::Abs(dot), 1.0f)) * 2.0f * Mathf::Rad2Deg;
}
#pragma endregion constructor
#pragma region custom methods

void System::Numerics::Quaternion::Set(const Float& x, const Float& y, const Float& z, const Float& w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

System::Float System::Numerics::Quaternion::Length() const
{
    return Mathf::Sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
}

System::Float System::Numerics::Quaternion::LengthSquared() const
{
    return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
}
#pragma endregion custom methods
#pragma region override
System::String System::Numerics::Quaternion::ToString() const
{
    return string::Format("({0},{1},{2},{3})", this->x, this->y, this->z, this->w);
}

System::Integer System::Numerics::Quaternion::GetHashCode() const
{
    return this->x.GetHashCode() ^ this->y.GetHashCode() << 2 ^ this->z.GetHashCode() >> 2 ^ this->w.GetHashCode() >> 1;
}

System::Boolean System::Numerics::Quaternion::Equals(const object& obj)
{
    const Quaternion* other = dynamic_cast<const Quaternion*>(&obj);
    if (!other) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Quaternion::Equals(const object* obj)
{
    const Quaternion* other = dynamic_cast<const Quaternion*>(obj);
    if (!other) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Quaternion::Equals(const Quaternion& object)
{
    return *this == object;
}
#pragma endregion override
#pragma region operator
System::Numerics::Quaternion& System::Numerics::Quaternion::operator=(const Quaternion& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator-() const
{
    return Negate(*this);
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator-(const Quaternion& other) const
{
    return Quaternion(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator+(const Quaternion& other) const
{
    return Quaternion(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator*(const Quaternion& other) const
{
    return Multiply(*this, other);
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator*(const Float& value) const
{
    return Multiply(*this, value);
}

System::Numerics::Quaternion System::Numerics::Quaternion::operator/(const Quaternion& other) const
{
    return Divide(*this, other);
}

System::Boolean System::Numerics::Quaternion::operator==(const Quaternion& other) const
{
    return this->x == other.x && this->y == other.y && this->z == other.z && this->w && other.w;
}

System::Boolean System::Numerics::Quaternion::operator!=(const Quaternion& other) const
{
    return !(*this == other);
}

System::Numerics::Vector3 System::Numerics::Quaternion::operator*(const Vector3& other) const
{
    const float mX = this->x * 2.0f;
    const float mY = this->y * 2.0f;
    const float mZ = this->z * 2.0f;
    const float xx = this->x * mX;
    const float yy = this->y * mY;
    const float zz = this->z * mZ;
    const float xy = this->x * mY;
    const float xz = this->x * mZ;
    const float yz = this->y * mZ;
    const float wx = this->w * mX;
    const float wy = this->w * mY;
    const float wz = this->w * mZ;
    const float resX = (1.0f - (yy + zz)) * other.x + (xy - wz) * other.y  +(xz + wy) * other.z;
    const float resY = (xy + wz) * other.x + (1.0f - (xx + zz)) * other.y + (yz - wx) * other.z;
    const float resZ = (xz - wy) * other.x + (yz + wx) * other.y + (1.0f - (xx + yy)) * other.z;
    return Vector3(resX, resY, resZ);
}
#pragma endregion operator
