#include "Vector2.h"

#include "../../../System/Mathf/Mathf.h"

#pragma region f/p
System::Numerics::Vector2 const System::Numerics::Vector2::One(0);
System::Numerics::Vector2 const System::Numerics::Vector2::UnitX(1,0);
System::Numerics::Vector2 const System::Numerics::Vector2::UnitY(0,1);
System::Numerics::Vector2 const System::Numerics::Vector2::Zero(0);
#pragma endregion f/p
#pragma region constructor
System::Numerics::Vector2::Vector2(const Span<Float>& values)
{
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
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

System::Numerics::Vector2 System::Numerics::Vector2::Divide(const Vector2& a, const Float& divisor)
{
    return Vector2(a.x / divisor, a.y / divisor);
}

System::Numerics::Vector2 System::Numerics::Vector2::Divide(const Vector2& a, const Vector2& b)
{
    return Vector2(a.x / b.x, a.y / b.y);
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

void System::Numerics::Vector2::CopyTo(Array<Float>& array) const
{
    array = Array<Float>(2);
    array[0] = x;
    array[1] = y;
}

void System::Numerics::Vector2::CopyTo(Span<Float>& destination) const
{
    const Array array = {x,y};
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
    return x.GetHashCode() ^ y.GetHashCode() << 2;
}
#pragma endregion override
#pragma region operator
System::Numerics::Vector2& System::Numerics::Vector2::operator=(const Vector2& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

System::Bool System::Numerics::Vector2::operator==(const Vector2& other) const
{
    return this->x == other.x && this->y == other.y;
}

System::Bool System::Numerics::Vector2::operator!=(const Vector2& other) const
{
    return this->x != other.x && this->y != other.y;
}

System::Bool System::Numerics::Vector2::operator<(const Vector2& other) const
{
    return x < other.x && y < other.y;
}

System::Bool System::Numerics::Vector2::operator<=(const Vector2& other) const
{
    return x <= other.x && y <= other.y;
}

System::Bool System::Numerics::Vector2::operator>(const Vector2& other) const
{
    return x > other.x && y > other.y;
}

System::Bool System::Numerics::Vector2::operator>=(const Vector2& other) const
{
    return x >= other.x && y >= other.y;
}
#pragma endregion operator