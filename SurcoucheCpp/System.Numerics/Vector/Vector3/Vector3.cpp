#include "Vector3.h"

#include "../../../System/Mathf/Mathf.h"
#include "../Vector2/Vector2.h"

#pragma region f/p
System::Numerics::Vector3 const System::Numerics::Vector3::Zero(0);
System::Numerics::Vector3 const System::Numerics::Vector3::One(1);
System::Numerics::Vector3 const System::Numerics::Vector3::UnitX(1, 0, 0);
System::Numerics::Vector3 const System::Numerics::Vector3::UnitY(0, 1, 0);
System::Numerics::Vector3 const System::Numerics::Vector3::UnitZ(0, 0, 1);
System::Float const System::Numerics::Vector3::kEpsilon = 0.00001F;
System::Float const System::Numerics::Vector3::kEpsilonNormalSqrt = 1e-15F;
#pragma endregion f/p
#pragma region constructor
System::Numerics::Vector3::Vector3(const Span<Float>& values)
{
    if (values.Length() < 3)
        throw Exception("Vector3 values length < 3");

    this->x = values[0];
    this->y = values[1];
    this->z = values[2];
}

System::Numerics::Vector3::Vector3(const Float& value)
{
    this->x = this->y = this->z = value;
}

System::Numerics::Vector3::Vector3(const Float& x, const Float& y, const Float& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

System::Numerics::Vector3::Vector3(const Vector3& other) : Object(other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}
#pragma endregion constructor
#pragma region custom methods
System::Numerics::Vector3 System::Numerics::Vector3::Normalize(const Vector3& value)
{
    return value / value.Length();
}

System::Numerics::Vector3 System::Numerics::Vector3::Abs(const Vector3& a)
{
    return Vector3(Mathf::Abs(a.x), Mathf::Abs(a.y), Mathf::Abs(a.z));
}

System::Numerics::Vector3 System::Numerics::Vector3::Add(const Vector3& a, const Vector3& b)
{
    return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

System::Numerics::Vector3 System::Numerics::Vector3::Clamp(const Vector3& value, const Vector3& min, const Vector3& max)
{
    return value < min ? min : value > max ? max : value;
}

System::Numerics::Vector3 System::Numerics::Vector3::Divide(const Vector3& a, const Vector3& b)
{
    return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

System::Numerics::Vector3 System::Numerics::Vector3::Divide(const Vector3& a, const Float& divisor)
{
    return Vector3(a.x / divisor, a.y / divisor, a.z / divisor);
}

System::Numerics::Vector3 System::Numerics::Vector3::Lerp(const Vector3& a, const Vector3& b, Float t)
{
    t = Mathf::Clamp01(t);
    return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
}

System::Numerics::Vector3 System::Numerics::Vector3::LerpUnclamped(const Vector3& a, const Vector3& b, const Float& t)
{
    return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
}

System::Numerics::Vector3 System::Numerics::Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

System::Numerics::Vector3 System::Numerics::Vector3::Min(const Vector3& a, const Vector3& b)
{
    return Vector3(Mathf::Min(a.x, b.x), Mathf::Min(a.y, b.y), Mathf::Min(a.z, b.z));
}

System::Numerics::Vector3 System::Numerics::Vector3::Max(const Vector3& a, const Vector3& b)
{
    return Vector3(Mathf::Max(a.x, b.x), Mathf::Max(a.y, b.y), Mathf::Max(a.z, b.z));
}

System::Numerics::Vector3 System::Numerics::Vector3::ClampMagnitude(const Vector3& vector, const Float& maxLength)
{
    const float sqrmag = vector.SqrMagnitude();
    if (sqrmag > maxLength * maxLength)
    {
        const float mag = Mathf::Sqrt(sqrmag);
        const float normalizedX = vector.x / mag;
        const float normalizedY = vector.y / mag;
        const float normalizedZ = vector.z / mag;
        return Vector3(normalizedX, normalizedY, normalizedZ);
    }
    return vector;
}

System::Float System::Numerics::Vector3::Distance(const Vector3& a, const Vector3& b)
{
    const float diffX = a.x - b.x;
    const float diffY = a.y - b.y;
    const float diffZ = a.z - b.z;
    return Mathf::Sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

System::Float System::Numerics::Vector3::Magnitude(const Vector3& vector)
{
    return Mathf::Sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

System::Float System::Numerics::Vector3::SqrMagnitude(const Vector3& vector)
{
    return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

System::Float System::Numerics::Vector3::Dot(const Vector3& a, const Vector3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

void System::Numerics::Vector3::Set(const Vector3& newValue)
{
    *this = newValue;
}

void System::Numerics::Vector3::Set(const Float& x, const Float& y, const Float& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void System::Numerics::Vector3::CopyTo(Array<Float>& out) const
{
    out = {this->x, this->y, this->z};
}

void System::Numerics::Vector3::CopyTo(Span<Float>& out) const
{
    const Array array = {this->x, this->y, this->z};
    out = array;
}

void System::Numerics::Vector3::Normalize()
{
    const float magnitude = Magnitude();
    if (magnitude > kEpsilon)
        Set(*this / magnitude);
    else Set(Zero);
}

System::Numerics::Vector2 System::Numerics::Vector3::ToVector2() const
{
    return Vector2(this->x, this->y);
}

System::Float System::Numerics::Vector3::Length() const
{
    return Mathf::Sqrt(Dot(*this, *this));
}

System::Float System::Numerics::Vector3::LengthSquared() const
{
    return Dot(*this, *this);
}

System::Float System::Numerics::Vector3::Magnitude() const
{
    return Mathf::Sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

System::Float System::Numerics::Vector3::SqrMagnitude() const
{
    return this->x * this->x + this->y * this->y + this->z * this->z;
}
#pragma endregion custom methods
#pragma region override
System::String System::Numerics::Vector3::ToString() const
{
    return string::Format("({0},{1},{2})", this->x, this->y, this->z);
}

System::Integer System::Numerics::Vector3::GetHashCode() const
{
    return this->x.GetHashCode() ^ this->y.GetHashCode() << 2 ^ this->z.GetHashCode() >> 2;
}

System::Boolean System::Numerics::Vector3::Equals(const object& obj)
{
    const Vector3* other = dynamic_cast<const Vector3*>(&obj);
    if (other == null) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Vector3::Equals(const object* obj)
{
    const Vector3* other = dynamic_cast<const Vector3*>(obj);
    if (other == null) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Vector3::Equals(const Vector3& other)
{
    return *this == other;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator=(const Vector3& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}
#pragma endregion override
#pragma region operator

System::Numerics::Vector3 System::Numerics::Vector3::operator/(const Vector3& b) const
{
    return Divide(*this, b);
}

System::Numerics::Vector3 System::Numerics::Vector3::operator/(const Float& divisor) const
{
    return Divide(*this, divisor);
}

System::Numerics::Vector3& System::Numerics::Vector3::operator/=(const Vector3& b)
{
    this->x /= b.x;
    this->y /= b.y;
    this->z /= b.z;
    return *this;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator/=(const Float& divisor)
{
    this->x /= divisor;
    this->y /= divisor;
    this->z /= divisor;
    return *this;
}

System::Numerics::Vector3 System::Numerics::Vector3::operator*(const Vector3& b) const
{
    return Vector3(this->x * b.x, this->y * b.y, this->z * b.z);
}

System::Numerics::Vector3 System::Numerics::Vector3::operator*(const Float& value) const
{
    return Vector3(this->x * value, this->y * value, this->z * value);   
}

System::Numerics::Vector3& System::Numerics::Vector3::operator*=(const Vector3& b)
{
    this->x *= b.x;
    this->y *= b.y;
    this->z *= b.z;
    return *this;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator*=(const Float& value)
{
    this->x *= value;
    this->y *= value;
    this->z *= value;
    return *this;
}

System::Numerics::Vector3 System::Numerics::Vector3::operator+(const Vector3& b) const
{
    return Vector3(this->x + b.x, this->y + b.y, this->z + b.z);
}

System::Numerics::Vector3 System::Numerics::Vector3::operator+(const Float& value) const
{
    return Vector3(this->x + value, this->y + value, this->z + value);
}

System::Numerics::Vector3& System::Numerics::Vector3::operator+=(const Vector3& b)
{
    this->x += b.x;
    this->y += b.y;
    this->z += b.z;
    return *this;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator+=(const Float& value)
{
    this->x += value;
    this->y += value;
    this->z += value;
    return *this;
}

System::Numerics::Vector3 System::Numerics::Vector3::operator-(const Vector3& b) const
{
    return Vector3(this->x - b.x, this->y - b.y, this->z - b.z);
}

System::Numerics::Vector3 System::Numerics::Vector3::operator-(const Float& value) const
{
    return Vector3(this->x - value, this->y - value, this->z - value);
}

System::Numerics::Vector3& System::Numerics::Vector3::operator-=(const Vector3& b)
{
    this->x -= b.x;
    this->y -= b.y;
    this->z -= b.z;
    return *this;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator-=(const Float& value)
{
    this->x -= value;
    this->y -= value;
    this->z -= value;
    return *this;
}

System::Numerics::Vector3& System::Numerics::Vector3::operator-()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    return *this;
}

System::Numerics::Vector3 System::Numerics::Vector3::operator-() const
{
    return Vector3(-this->x, -this->y, -this->z);
}

System::Float& System::Numerics::Vector3::operator[](const Int& index)
{
    switch(index)
    {
        case 0: return this->x;
        case 1: return this->y;
        case 2: return this->z;
        default:
        throw IndexOutOfRangeException("Vector3 invalid index!");
    }
}

System::Float System::Numerics::Vector3::operator[](const Int& index) const
{
    switch(index)
    {
        case 0: return this->x;
        case 1: return this->y;
        case 2: return this->z;
        default:
        throw IndexOutOfRangeException("Vector3 invalid index!");
    }
}

System::Bool System::Numerics::Vector3::operator==(const Vector3& other) const
{
    const float diffX = this->x - other.x;
    const float diffY = this->y - other.y;
    const float diffZ = this->z - other.z;
    const float sqrmag = diffX * diffX + diffY * diffY + diffZ * diffZ;
    return sqrmag < kEpsilon * kEpsilon;
}

System::Bool System::Numerics::Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

System::Bool System::Numerics::Vector3::operator<(const Vector3& other) const
{
    return this->x < other.x && this->y < other.y && this->z < other.z;
}

System::Bool System::Numerics::Vector3::operator<=(const Vector3& other) const
{
    return this->x <= other.x && this->y <= other.y && this->z <= other.z;
}

System::Bool System::Numerics::Vector3::operator>(const Vector3& other) const
{
    return this->x > other.x && this->y > other.y && this->z > other.z;
}

System::Bool System::Numerics::Vector3::operator>=(const Vector3& other) const
{
    return this->x >= other.x && this->y >= other.y && this->z >= other.z;
}
#pragma endregion operator
