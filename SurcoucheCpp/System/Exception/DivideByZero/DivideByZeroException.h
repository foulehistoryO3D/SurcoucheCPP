#pragma once
#include "../Exception/Exception.h"

namespace System
{
    class DivideByZeroException : public System::Exception
    {
        DECLARE_CLASS_INFO(Exception)
#pragma region constructor/destructor
    public:
        DivideByZeroException() : Exception()
        {
        }

        explicit DivideByZeroException(const char* _message) : Exception(_message)
        {
        }

        DivideByZeroException(const char* _message, int _i) : Exception(_message, _i)
        {
        }

        DivideByZeroException(DivideByZeroException const& _other) : Exception(_other)
        {
        }
#pragma endregion constructor/destructor
#pragma region operator
        DivideByZeroException& operator=(DivideByZeroException& _other)
        {
            return *this;
        }
#pragma endregion operator
    };
}
