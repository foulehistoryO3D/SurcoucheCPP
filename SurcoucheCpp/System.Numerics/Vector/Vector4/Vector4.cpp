#include "Vector4.h"

#include "../../../System/Mathf/Mathf.h"
#include "../Vector2/Vector2.h"
#include "../Vector3/Vector3.h"

#pragma region f/p
System::Numerics::Vector4 const System::Numerics::Vector4::Zero(0);
System::Numerics::Vector4 const System::Numerics::Vector4::One(1);
System::Numerics::Vector4 const System::Numerics::Vector4::UnitX(1, 0, 0, 0);
System::Numerics::Vector4 const System::Numerics::Vector4::UnitY(0, 1, 0, 0);
System::Numerics::Vector4 const System::Numerics::Vector4::UnitZ(0, 0, 1, 0);
System::Numerics::Vector4 const System::Numerics::Vector4::UnitW(0, 0, 0, 1);
System::Float const System::Numerics::Vector4::kEpsilon(0.00001F);
#pragma endregion f/p
#pragma region constructor
System::Numerics::Vector4::Vector4(const Float& value)
{
    this->x = this->y = this->z = this->w = value;
}

System::Numerics::Vector4::Vector4(const Float& x, const Float& y, const Float& z, const Float& w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

System::Numerics::Vector4::Vector4(const Float& x, const Float& y, const Float& z) : Vector4(x, y, z, 0)
{
}

System::Numerics::Vector4::Vector4(const Float& x, const Float& y) : Vector4(x, y, 0, 0)
{
}

System::Numerics::Vector4::Vector4(const Span<Float>& values)
{
    if (values.Length() < 4)
        throw Exception("Vector4 values length < 4");

    this->x = values[0];
    this->y = values[1];
    this->z = values[2];
    this->w = values[3];
}
#pragma endregion constructor
#pragma region custom methods

System::Numerics::Vector4 System::Numerics::Vector4::Abs(const Vector4& a)
{
    return Vector4(Mathf::Abs(a.x), Mathf::Abs(a.y), Mathf::Abs(a.z), Mathf::Abs(a.w));
}

System::Numerics::Vector4 System::Numerics::Vector4::Add(const Vector4& a, const Vector4& b)
{
    return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

System::Numerics::Vector4 System::Numerics::Vector4::Clamp(const Vector4& value, const Vector4& min, const Vector4& max)
{
    return value < min ? min : value > max ? max : value;
}

System::Numerics::Vector4 System::Numerics::Vector4::Min(const Vector4& a, const Vector4& b)
{
    return Vector4(Mathf::Min(a.x, b.x), Mathf::Min(a.y, b.y), Mathf::Min(a.z, b.z), Mathf::Min(a.w, b.w));
}

System::Numerics::Vector4 System::Numerics::Vector4::Max(const Vector4& a, const Vector4& b)
{
    return Vector4(Mathf::Max(a.x, b.x), Mathf::Max(a.y, b.y), Mathf::Max(a.z, b.z), Mathf::Max(a.w, b.w));
}

System::Numerics::Vector4 System::Numerics::Vector4::Lerp(const Vector4& a, const Vector4& b, Float t)
{
    t = Mathf::Clamp01(t);
    return Vector4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
}

System::Numerics::Vector4 System::Numerics::Vector4::LerpUnclamped(const Vector4& a, const Vector4& b, const Float& t)
{
    return Vector4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
}

System::Float System::Numerics::Vector4::Dot(const Vector4& a, const Vector4& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

System::Float System::Numerics::Vector4::Magnitude(const Vector4& a)
{
    return Mathf::Sqrt(Dot(a, a));
}

System::Float System::Numerics::Vector4::Distance(const Vector4& a, const Vector4& b)
{
    return Magnitude(a - b);
}

void System::Numerics::Vector4::CopyTo(Array<Float>& out) const
{
    out = {this->x, this->y, this->z, this->w};
}

void System::Numerics::Vector4::CopyTo(Span<Float>& out) const
{
    const Array<Float>& array = {this->x, this->y, this->z, this->w};
    out = array;
}

void System::Numerics::Vector4::Normalize()
{
    const float magnitude = Magnitude(*this);
    if (magnitude > kEpsilon)
        *this = *this / magnitude;
    else *this = Zero;
}

void System::Numerics::Vector4::Set(const Float& x, const Float& y, const Float& z, const Float& w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

System::Float System::Numerics::Vector4::Length() const
{
    return Mathf::Sqrt(Dot(*this, *this));
}

System::Float System::Numerics::Vector4::LengthSquared() const
{
    return Dot(*this, *this);
}

System::Numerics::Vector3 System::Numerics::Vector4::ToVector3() const
{
    return Vector3(this->x, this->y, this->z);
}

System::Numerics::Vector2 System::Numerics::Vector4::ToVector2() const
{
    return Vector2(this->x, this->y);
}
#pragma endregion custom methods
#pragma region override
System::String System::Numerics::Vector4::ToString() const
{
    return string::Format("({0},{1},{2},{3})", this->x, this->y, this->z, this->w);
}

System::Integer System::Numerics::Vector4::GetHashCode() const
{
    return this->x.GetHashCode() ^ this->y.GetHashCode() << 2 ^ this->z.GetHashCode() >> 2 ^ this->w.GetHashCode() >> 1;
}

System::Boolean System::Numerics::Vector4::Equals(const Vector4& object)
{
    return *this == object;
}

System::Boolean System::Numerics::Vector4::Equals(const object& obj)
{
    const Vector4* other = dynamic_cast<const Vector4*>(&obj);
    if (!other) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Vector4::Equals(const object* obj)
{
    const Vector4* other = dynamic_cast<const Vector4*>(obj);
    if (!other) return false;
    return Equals(*other);
}
#pragma endregion override
#pragma region operator
System::Numerics::Vector4& System::Numerics::Vector4::operator=(const Vector4& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
}

System::Bool System::Numerics::Vector4::operator==(const Vector4& other) const
{
    const float diffX = this->x - other.x;
    const float diffY = this->y - other.y;
    const float diffZ = this->z - other.z;
    const float diffW = this->w - other.w;
    const float sqrmag = diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW;
    return sqrmag < kEpsilon * kEpsilon;
}

System::Bool System::Numerics::Vector4::operator!=(const Vector4& other) const
{
    return !(*this == other);
}

System::Numerics::Vector4 System::Numerics::Vector4::operator-(const Vector4& other) const
{
    return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

System::Numerics::Vector4 System::Numerics::Vector4::operator-(const Float& value) const
{
    return Vector4(this->x - value, this->y - value, this->z - value, this->w - value);
}

System::Numerics::Vector4& System::Numerics::Vector4::operator-=(const Vector4& value)
{
    this->x -= value.x;
    this->y -= value.y;
    this->z -= value.z;
    this->w -= value.w;
    return *this;
}

System::Numerics::Vector4& System::Numerics::Vector4::operator-=(const Float& value)
{
    this->x -= value;
    this->y -= value;
    this->z -= value;
    this->w -= value;
    return *this;
}

System::Numerics::Vector4 System::Numerics::Vector4::operator+(const Vector4& other) const
{
    return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

System::Numerics::Vector4 System::Numerics::Vector4::operator+(const Float& value) const
{
    return Vector4(this->x + value, this->y + value, this->z + value, this->w + value);
}

System::Numerics::Vector4& System::Numerics::Vector4::operator+=(const Vector4& value)
{
    this->x += value.x;
    this->y += value.y;
    this->z += value.z;
    this->w += value.w;
    return *this;
}

System::Numerics::Vector4& System::Numerics::Vector4::operator+=(const Float& value)
{
    this->x += value;
    this->y += value;
    this->z += value;
    this->w += value;
    return *this;
}

System::Numerics::Vector4 System::Numerics::Vector4::operator*(const Vector4& other) const
{
    return Vector4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

System::Numerics::Vector4 System::Numerics::Vector4::operator*(const Float& value) const
{
    return Vector4(this->x * value, this->y * value, this->z * value, this->w * value);
}

System::Numerics::Vector4& System::Numerics::Vector4::operator*=(const Vector4& value)
{
    this->x *= value.x;
    this->y *= value.y;
    this->z *= value.z;
    this->w *= value.w;
    return *this;
}

System::Numerics::Vector4& System::Numerics::Vector4::operator*=(const Float& value)
{
    this->x *= value;
    this->y *= value;
    this->z *= value;
    this->w *= value;
    return *this;
}

System::Numerics::Vector4 System::Numerics::Vector4::operator/(const Vector4& other) const
{
    return Vector4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

System::Numerics::Vector4 System::Numerics::Vector4::operator/(const Float& value) const
{
    return Vector4(this->x / value, this->y / value, this->z / value, this->w / value);
}

System::Numerics::Vector4& System::Numerics::Vector4::operator/=(const Vector4& value)
{
    this->x /= value.x;
    this->y /= value.y;
    this->z /= value.z;
    this->w /= value.w;
    return *this;
}

System::Numerics::Vector4& System::Numerics::Vector4::operator/=(const Float& value)
{
    this->x /= value;
    this->y /= value;
    this->z /= value;
    this->w /= value;
    return *this;
}

System::Numerics::Vector4& System::Numerics::Vector4::operator-()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    this->w = -this->w;
    return *this;
}

System::Float& System::Numerics::Vector4::operator[](const Int& index)
{
    switch (index)
    {
    case 0: return this->x;
    case 1: return this->y;
    case 2: return this->z;
    case 3: return this->w;
    default:
        throw IndexOutOfRangeException("Vector4 invalid index!");
    }
}

System::Float System::Numerics::Vector4::operator[](const Int& index) const
{
    switch (index)
    {
    case 0: return this->x;
    case 1: return this->y;
    case 2: return this->z;
    case 3: return this->w;
    default:
        throw IndexOutOfRangeException("Vector4 invalid index!");
    }
}

System::Bool System::Numerics::Vector4::operator<(const Vector4& other) const
{
    return this->x < other.x && this->y < other.y && this->z < other.z && this->w < other.w;
}

System::Bool System::Numerics::Vector4::operator<=(const Vector4& other) const
{
    return this->x <= other.x && this->y <= other.y && this->z <= other.z && this->w <= other.w;
}

System::Bool System::Numerics::Vector4::operator>(const Vector4& other) const
{
    return this->x > other.x && this->y > other.y && this->z > other.z && this->w > other.w;
}

System::Bool System::Numerics::Vector4::operator>=(const Vector4& other) const
{
    return this->x >= other.x && this->y >= other.y && this->z >= other.z && this->w >= other.w;
}
#pragma endregion operator
