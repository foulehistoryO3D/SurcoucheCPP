#include "Vector2.h"

#include "../../../System/Mathf/Mathf.h"

#pragma region f/p
System::Numerics::Vector2 const System::Numerics::Vector2::One(0);
System::Numerics::Vector2 const System::Numerics::Vector2::UnitX(1,0);
System::Numerics::Vector2 const System::Numerics::Vector2::UnitY(0,1);
System::Numerics::Vector2 const System::Numerics::Vector2::Zero(0);
System::Float const System::Numerics::Vector2::kEpsilon(0.00001F);
System::Float const System::Numerics::Vector2::kEpsilonNormalSqrt(1e-15f);
#pragma endregion f/p
#pragma region constructor
System::Numerics::Vector2::Vector2(const Span<Float>& values)
{
    if (values.Length() < 2)
        throw Exception("Vector2 values length < 2");
    this->x = values[0];
    this->y = values[1];
}

System::Numerics::Vector2::Vector2(const Float& value)
{
    this->x = this->y = value;
}

System::Numerics::Vector2::Vector2(const Float& x, const Float& y)
{
    this->x = x;
    this->y = y;
}

System::Numerics::Vector2::Vector2(const Vector2& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}
#pragma endregion constructor
#pragma region custom methods
System::Numerics::Vector2 System::Numerics::Vector2::Abs(const Vector2& other)
{
    return Vector2(Mathf::Abs(other.x), Mathf::Abs(other.y));
}

System::Numerics::Vector2 System::Numerics::Vector2::Add(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Clamp(const Vector2& value, const Vector2& min, const Vector2& max)
{
    return value < min ? min : value > max ? max : value;
}

System::Numerics::Vector2 System::Numerics::Vector2::Divide(const Vector2& a, const Float& divisor)
{
    return Vector2(a.x / divisor, a.y / divisor);
}

System::Numerics::Vector2 System::Numerics::Vector2::Divide(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x / b.x, a.y / b.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Multiply(const Vector2& a, const Float& value)
{
    return Vector2(a.x * value, a.y * value);
}

System::Numerics::Vector2 System::Numerics::Vector2::Multiply(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x * b.x, a.y * b.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Subtract(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x - b.x, a.y - b.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Scale(const Vector2& a, const Float& scale)
{
    return Vector2(a.x * scale, a.y * scale);
}

System::Numerics::Vector2 System::Numerics::Vector2::Scale(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x * b.x, a.y * b.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Max(const Vector2& a, const Vector2& b)
{
    return Vector2(Mathf::Max(a.x, b.x), Mathf::Max(a.y, b.y));
}

System::Numerics::Vector2 System::Numerics::Vector2::Min(const Vector2& a, const Vector2& b)
{
    return Vector2(Mathf::Min(a.x, b.x), Mathf::Min(a.y, b.y));
}

System::Numerics::Vector2 System::Numerics::Vector2::Negate(const Vector2& vector)
{
    return Vector2(-vector.x, -vector.y);
}

System::Numerics::Vector2 System::Numerics::Vector2::Lerp(const Vector2& a, const Vector2& b, Float t)
{
    t = Mathf::Clamp01(t);
    return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

System::Numerics::Vector2 System::Numerics::Vector2::LerpUnclamped(const Vector2& a, const Vector2& b, const Float& t)
{
    return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
}

System::Numerics::Vector2 System::Numerics::Vector2::Normalize(const Vector2& a)
{
    const Float& magnitude = a.Magnitude();
    if (magnitude > kEpsilon)
        return a / magnitude;
    return Zero;
}

void System::Numerics::Vector2::Scale(const Vector2& scale)
{
    this->x *= scale.x;
    this->y *= scale.y;
}

void System::Numerics::Vector2::Scale(const Float& scale)
{
    this->x *= scale;
    this->y *= scale;
}

System::Float System::Numerics::Vector2::Distance(const Vector2& a, const Vector2& b)
{
    const float diff_x = a.x - b.x;
    const float diff_y = a.y - b.y;
    return Mathf::Sqrt(diff_x * diff_x + diff_y * diff_y);
}

System::Float System::Numerics::Vector2::DistanceSquared(const Vector2& a, const Vector2& b)
{
    const float diff_x = a.x - b.x;
    const float diff_y = a.y - b.y;
    return diff_x * diff_x + diff_y * diff_y;
}

System::Float System::Numerics::Vector2::Dot(const Vector2& a, const Vector2& b)
{
    return a.x * b.x + a.y * b.y;
}

System::Float System::Numerics::Vector2::Magnitude() const
{
    return Mathf::Sqrt(x * x + y * y);
}

System::Float System::Numerics::Vector2::Length() const
{
    return Mathf::Sqrt(Dot(*this, *this));
}

System::Float System::Numerics::Vector2::LengthSquared() const
{
    return Dot(*this, *this);
}

void System::Numerics::Vector2::Set(const Float& x, const Float& y)
{
    this->x = x;
    this->y = y;
}

void System::Numerics::Vector2::Set(const Vector2& newValue)
{
    this->x = newValue.x;
    this->y = newValue.y;
}

void System::Numerics::Vector2::Normalize()
{
    Set(Normalize(*this));
}

void System::Numerics::Vector2::CopyTo(Array<Float>& array) const
{
    array = {this->x, this->y};
}

void System::Numerics::Vector2::CopyTo(Span<Float>& destination) const
{
    const Array array = {this->x,this->y};
    destination = array;
}
#pragma endregion custom methods
#pragma region override
System::String System::Numerics::Vector2::ToString() const
{
    return string::Format("({0}, {1})", this->x, this->y);
}

System::Integer System::Numerics::Vector2::GetHashCode() const
{
    return this->x.GetHashCode() ^ this->y.GetHashCode() << 2;
}

System::Boolean System::Numerics::Vector2::Equals(const Vector2& other)
{
    return *this == other;
}

System::Boolean System::Numerics::Vector2::Equals(const object& obj)
{
    const Vector2* other = dynamic_cast<const Vector2*>(&obj);
    if (other == null) return false;
    return Equals(*other);
}

System::Boolean System::Numerics::Vector2::Equals(const object* obj)
{
    const Vector2* other = dynamic_cast<const Vector2*>(obj);
    if (other == null) return false;
    return Equals(*other);
}
#pragma endregion override
#pragma region operator
System::Numerics::Vector2& System::Numerics::Vector2::operator=(const Vector2& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

System::Numerics::Vector2 System::Numerics::Vector2::operator/(const Float& divisor) const
{
    return Divide(*this, divisor);
}

System::Numerics::Vector2 System::Numerics::Vector2::operator/(const Vector2& b) const
{
    return Divide(*this, b);
}

System::Numerics::Vector2& System::Numerics::Vector2::operator/=(const Float& divisor)
{
    this->x /= divisor;
    this->y /= divisor;
    return *this;
}

System::Numerics::Vector2& System::Numerics::Vector2::operator/=(const Vector2& divisor)
{
    this->x /= divisor.x;
    this->y /= divisor.y;
    return *this;
}

System::Numerics::Vector2 System::Numerics::Vector2::operator*(const Float& value) const
{
    return Multiply(*this, value);
}

System::Numerics::Vector2 System::Numerics::Vector2::operator*(const Vector2& b) const
{
    return Multiply(*this, b);
}

System::Numerics::Vector2& System::Numerics::Vector2::operator*=(const Float& value)
{
    this->x *= value;
    this->y *= value;
    return *this;
}

System::Numerics::Vector2& System::Numerics::Vector2::operator*=(const Vector2& value)
{
    this->x *= value.x;
    this->y *= value.y;
    return *this;
}

System::Numerics::Vector2 System::Numerics::Vector2::operator-(const Vector2& b) const
{
    return Subtract(*this, b);
}

System::Numerics::Vector2& System::Numerics::Vector2::operator-=(const Vector2& value)
{
    this->x -= value.x;
    this->y -= value.y;
    return *this;
}

System::Numerics::Vector2 System::Numerics::Vector2::operator+(const Vector2& b) const
{
    return Vector2(this->x + b.x, this->y + b.y);
}

System::Numerics::Vector2& System::Numerics::Vector2::operator+=(const Vector2& value)
{
    this->x += value.x;
    this->y += value.y;
    return *this;
}

System::Numerics::Vector2& System::Numerics::Vector2::operator-()
{
    this->x = -this->x;
    this->y = -this->y;
    return *this;
}

System::Float& System::Numerics::Vector2::operator[](const Int& index)
{
    switch (index)
    {
    case 0: return this->x;
    case 1: return this->y;
    default:
        throw IndexOutOfRangeException("Vector invalid index !");
    }
}

System::Float System::Numerics::Vector2::operator[](const Int& index) const
{
    switch (index)
    {
    case 0: return this->x;
    case 1: return this->y;
    default:
        throw IndexOutOfRangeException("Vector invalid index !");
    }
}

System::Bool System::Numerics::Vector2::operator==(const Vector2& other) const
{
    const float diffX = this->x - other.x;
    const float diffY = this->y - other.y;
    const float sqrmag = diffX * diffX + diffY * diffY;
    return sqrmag < kEpsilon * kEpsilon;
}

System::Bool System::Numerics::Vector2::operator!=(const Vector2& other) const
{
    return !(*this == other);
}

System::Bool System::Numerics::Vector2::operator<(const Vector2& other) const
{
    return this->x < other.x && this->y < other.y;
}

System::Bool System::Numerics::Vector2::operator<=(const Vector2& other) const
{
    return this->x <= other.x && this->y <= other.y;
}

System::Bool System::Numerics::Vector2::operator>(const Vector2& other) const
{
    return this->x > other.x && this->y > other.y;
}

System::Bool System::Numerics::Vector2::operator>=(const Vector2& other) const
{
    return this->x >= other.x && this->y >= other.y;
}
#pragma endregion operator