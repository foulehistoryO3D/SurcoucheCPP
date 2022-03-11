#include "Complex.h"

#include "../../System/Mathf/Mathf.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

#pragma region f/p
System::Double const System::Numerics::Complex::LOG_10_INV = 0.43429448190325;
System::Numerics::Complex const System::Numerics::Complex::Zero(0.0, 0.0);
System::Numerics::Complex const System::Numerics::Complex::One(1.0, 0.0);
System::Numerics::Complex const System::Numerics::Complex::ImaginaryOne(0.0, 1.0);
#pragma endregion f/p
#pragma region constructor
System::Numerics::Complex::Complex(const Double& real, const Double& imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

System::Numerics::Complex::Complex(const Double& real)
{
    this->real = real;
    this->imaginary = 0.0;
}

System::Numerics::Complex::Complex(const Complex& copy) : Object(copy)
{
    this->real = copy.real;
    this->imaginary = copy.imaginary;
}
#pragma endregion constructor
#pragma region custom methods
System::Double System::Numerics::Complex::Real() const
{
    return this->real;
}

System::Double System::Numerics::Complex::Imaginary() const
{
    return this->imaginary;
}

System::Double System::Numerics::Complex::Magnitude() const
{
    return Abs(*this);
}

System::Double System::Numerics::Complex::Phase() const
{
    return Mathf::Atan2(this->imaginary, this->real);
}

System::Numerics::Complex System::Numerics::Complex::FromPolarCoordinates(const Double& magnitude, const Double& phase)
{
    return Complex(magnitude * Mathf::Cos(phase), magnitude * Mathf::Sin(phase));
}

System::Numerics::Complex System::Numerics::Complex::Negate(const Complex& value)
{
    return -value;
}

System::Numerics::Complex System::Numerics::Complex::Add(const Complex& a, const Complex& b)
{
    return a + b;
}

System::Numerics::Complex System::Numerics::Complex::Subtract(const Complex& a, const Complex& b)
{
    return a - b;
}

System::Numerics::Complex System::Numerics::Complex::Multiply(const Complex& a, const Complex& b)
{
    return a * b;
}

System::Numerics::Complex System::Numerics::Complex::Divide(const Complex& a, const Complex& b)
{
    return a / b;
}

System::Double System::Numerics::Complex::Abs(const Complex& value)
{
    if (Double::IsInfinity(value.real) || Double::IsInfinity(value.imaginary))
        return Double::PositiveInfinity;
    const double num1 = Mathf::Abs(value.real);
    const double num2 = Mathf::Abs(value.imaginary);
    if (num1 > num2)
    {
        const double num3 = num2 / num1;
        return num1 * Mathf::Sqrt(Double(1.0 + num3 * num3));
    }
    if (num2 == 0.0) return num1;
    const double num4 = num1 / num2;
    return num2 * Mathf::Sqrt(Double(1.0 + num4 * num4));
}

System::Numerics::Complex System::Numerics::Complex::Conjugate(const Complex& value)
{
    return Complex(value.real, -value.imaginary);
}

System::Numerics::Complex System::Numerics::Complex::Reciprocal(const Complex& value)
{
    return value.real == 0.0 && value.imaginary == 0.0 ? Zero : One / value;
}

System::Numerics::Complex System::Numerics::Complex::Sin(const Complex& value)
{
    const Double& re = value.real;
    const Double& imagi = value.imaginary;
    return Complex(Mathf::Sin(re) * Mathf::Cosh(imagi), Mathf::Cos(re) * Mathf::Sinh(imagi));
}

System::Numerics::Complex System::Numerics::Complex::Sinh(const Complex& value)
{
    const Double& re = value.real;
    const Double& imagi = value.imaginary;
    return Complex(Mathf::Sinh(re) * Mathf::Cos(imagi), Mathf::Cosh(re) * Mathf::Sin(imagi));
}

System::Numerics::Complex System::Numerics::Complex::Asin(const Complex& value)
{
    return -ImaginaryOne * Log(ImaginaryOne * value + Sqrt(One - value * value));
}

System::Numerics::Complex System::Numerics::Complex::Cos(const Complex& value)
{
    const Double& re = value.real;
    const Double& imagi = value.imaginary;
    return Complex(Mathf::Cos(re) * Mathf::Cosh(imagi), -(Mathf::Sin(re) * Mathf::Sinh(imagi)));
}

System::Numerics::Complex System::Numerics::Complex::Cosh(const Complex& value)
{
    const Double& re = value.real;
    const Double& imagi = value.imaginary;
    return Complex(Mathf::Cosh(re) * Mathf::Cos(imagi), Mathf::Sinh(re) * Mathf::Sin(imagi));
}

System::Numerics::Complex System::Numerics::Complex::Acos(const Complex& value)
{
    return -ImaginaryOne * Log(value + ImaginaryOne * Sqrt(One - value * value));
}

System::Numerics::Complex System::Numerics::Complex::Tan(const Complex& value)
{
    return Sin(value) / Cos(value);
}

System::Numerics::Complex System::Numerics::Complex::Tanh(const Complex& value)
{
    return Sinh(value) / Cosh(value);
}

System::Numerics::Complex System::Numerics::Complex::Atan(const Complex& value)
{
    Complex complex = Complex(2.0, 0.0);
    return ImaginaryOne / complex * (Log(One - ImaginaryOne * value) - Log(One + ImaginaryOne * value));
}

System::Numerics::Complex System::Numerics::Complex::Log(const Complex& value)
{
    return Complex(Mathf::Log(Abs(value)), Mathf::Atan2(value.imaginary, value.real));
}

System::Numerics::Complex System::Numerics::Complex::Log(const Complex& value, const Double& baseValue)
{
    return Log(value) / Log(baseValue);
}

System::Numerics::Complex System::Numerics::Complex::Log10(const Complex& value)
{
    return Scale(Log(value), 0.43429448190325);
}

System::Numerics::Complex System::Numerics::Complex::Exp(const Complex& value)
{
    const Double& num = Mathf::Exp(value.real);
    return Complex(num * Mathf::Cos(value.imaginary), num * Mathf::Sin(value.imaginary));
}

System::Numerics::Complex System::Numerics::Complex::Sqrt(const Complex& value)
{
    return FromPolarCoordinates(Mathf::Sqrt(value.Magnitude()), value.Phase() / 2.0);
}

System::Numerics::Complex System::Numerics::Complex::Pow(const Complex& value, const Complex& power)
{
    if (power == Zero)
        return One;
    if (value == Zero)
        return Zero;
    const Double& real1 = value.real;
    const Double& imaginary1 = value.imaginary;
    const Double& real2 = power.real;
    const Double& imaginary2 = power.imaginary;
    const Double& num1 = Abs(value);
    const Double& num2 = Mathf::Atan2(imaginary1, real1);
    const Double& num3 = real2 * num2 + imaginary2 * Mathf::Log(num1);
    const double num4 = Mathf::Pow(num1, real2) * Mathf::Pow(Mathf::E, -imaginary2 * num2);
    return Complex(num4 * Mathf::Cos(num3), num4 * Mathf::Sin(num3));
}

System::Numerics::Complex System::Numerics::Complex::Pow(const Complex& value, const Double& power)
{
    return Pow(value, Complex(power, 0.0));
}

System::Numerics::Complex System::Numerics::Complex::Scale(const Complex& value, const Double& factor)
{
    return Complex(factor * value.real, factor * value.imaginary);
}
#pragma endregion custom methods
#pragma region override
System::String System::Numerics::Complex::ToString() const
{
    return string::Format("({0}, {1})", this->real, this->imaginary);
}

System::Integer System::Numerics::Complex::GetHashCode() const
{
    return this->real.GetHashCode() % 99999997 ^ this->imaginary.GetHashCode();
}

System::Boolean System::Numerics::Complex::Equals(const Complex& _object)
{
    return this->real == _object.real && this->imaginary == _object.imaginary;
}
#pragma endregion override
#pragma region operator
System::Numerics::Complex& System::Numerics::Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imaginary = other.imaginary;
    return *this;
}

System::Numerics::Complex System::Numerics::Complex::operator-() const
{
    return Complex(-this->real, -this->imaginary);
}

System::Numerics::Complex System::Numerics::Complex::operator+(const Complex& other) const
{
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

System::Numerics::Complex System::Numerics::Complex::operator-(const Complex& other) const
{
    return Complex(this->real - other.real, this->imaginary - other.imaginary);
}

System::Numerics::Complex System::Numerics::Complex::operator*(const Complex& other) const
{
    return Complex(this->real * other.real, this->imaginary * other.imaginary);
}

System::Numerics::Complex System::Numerics::Complex::operator/(const Complex& other) const
{
    const double real1 = this->real;
    const double imaginary1 = this->imaginary;
    const Double& real2 = other.real;
    const Double& imaginary2 = other.imaginary;
    if (Mathf::Abs(imaginary2) < Mathf::Abs(real2))
    {
        const Double& num = imaginary2 / real2;
        return Complex((real1 + imaginary1 * num) / (real2 + imaginary2 * num),
                       (imaginary1 - real1 * num) / (real2 + imaginary2 * num));
    }
    const Double& num1 = real2 / imaginary2;
    return Complex((imaginary1 + real1 * num1) / (imaginary2 + real2 * num1),
                   (-real1 + imaginary1 * num1) / (imaginary2 + real2 * num1));
}

System::Boolean System::Numerics::Complex::operator==(const Complex& other) const
{
    return this->real == other.real && this->imaginary == other.imaginary;
}

#pragma endregion operator
