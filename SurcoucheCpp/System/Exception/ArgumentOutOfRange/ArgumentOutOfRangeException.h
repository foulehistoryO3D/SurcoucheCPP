#pragma once
#include "../Exception/Exception.h"

namespace System
{
    class ArgumentOutOfRangeException : public Exception
    {
        DECLARE_CLASS_INFO(Exception)
#pragma region constructor/destructor
    public:
        ArgumentOutOfRangeException() : Exception()
        {
        }

        explicit ArgumentOutOfRangeException(const char* _message) : Exception(_message)
        {
        }

        ArgumentOutOfRangeException(const char* _message, int _i) : Exception(_message, _i)
        {
        }

        ArgumentOutOfRangeException(ArgumentOutOfRangeException const& _other) : Exception(_other)
        {
        }
#pragma endregion constructor/destructor
#pragma region operator
        ArgumentOutOfRangeException& operator=(ArgumentOutOfRangeException& _other) = delete;
#pragma endregion operator
    };
}
