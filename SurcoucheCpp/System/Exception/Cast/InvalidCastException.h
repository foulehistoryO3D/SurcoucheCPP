#pragma once
#include "../Exception/Exception.h"

namespace System
{
    class InvalidCastException : public Exception
    {
        DECLARE_CLASS_INFO(Exception)
#pragma region constructor/destructor
    public:
        InvalidCastException() : Exception()
        {
        }

        explicit InvalidCastException(const char* _message) : Exception(_message)
        {
        }

        InvalidCastException(const char* _message, int _i) : Exception(_message, _i)
        {
        }

        InvalidCastException(InvalidCastException const& _other) : Exception(_other)
        {
        }
#pragma endregion constructor/destructor
#pragma region operator
        InvalidCastException& operator=(InvalidCastException& _other)
        {
            return *this;
        }
#pragma endregion operator
    };
}
