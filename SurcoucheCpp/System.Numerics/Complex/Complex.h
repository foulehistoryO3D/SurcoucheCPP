#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Double/Double.h"

namespace System
{
    namespace Numerics
    {
        class Complex sealed : public Object, public IEquatable<Complex>
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            static const Double LOG_10_INV;
            Double real = 0.0;
            Double imaginary = 0.0;
        public:
            static const Complex Zero;
            static const Complex One;
            static const Complex ImaginaryOne;
#pragma endregion f/p
#pragma region constructor
        public:
            Complex()=default;
            Complex(const Double& real, const Double& imaginary);
            Complex(const Double& real);
            Complex(const Complex& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            Double Real()const;
            Double Imaginary()const;
            Double Magnitude()const;
            Double Phase()const;
            static Complex FromPolarCoordinates(const Double& magnitude, const Double& phase);
            static Complex Negate(const Complex& value);
            static Complex Add(const Complex& a, const Complex& b);
            static Complex Subtract(const Complex& a, const Complex& b);
            static Complex Multiply(const Complex& a, const Complex& b);
            static Complex Divide(const Complex& a, const Complex& b);
            static Double Abs(const Complex& value);
            static Complex Conjugate(const Complex& value);
            static Complex Reciprocal(const Complex& value);
            static Complex Sin(const Complex& value);
            static Complex Sinh(const Complex& value);
            static Complex Asin(const Complex& value);
            static Complex Cos(const Complex& value);
            static Complex Cosh(const Complex& value);
            static Complex Acos(const Complex& value);
            static Complex Tan(const Complex& value);
            static Complex Tanh(const Complex& value);
            static Complex Atan(const Complex& value);
            static Complex Log(const Complex& value);
            static Complex Log(const Complex& value, const Double& baseValue);
            static Complex Log10(const Complex& value);
            static Complex Exp(const Complex& value);
            static Complex Sqrt(const Complex& value);
            static Complex Pow(const Complex& value, const Complex& power);
            static Complex Pow(const Complex& value, const Double& power);
            static Complex Scale(const Complex& value, const Double& factor);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            Complex& operator=(const Complex& other);
            Complex operator-()const;
            Complex operator+(const Complex& other)const;
            Complex operator-(const Complex& other)const;
            Complex operator*(const Complex& other)const;
            Complex operator/(const Complex& other)const;
            Boolean operator==(const Complex& zero) const;
            Boolean Equals(const Complex& _object) override;
#pragma endregion operator
        };
    }
}
