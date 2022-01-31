#pragma once
#include "../OutOfRange/OutOfRange.h"

namespace System
{
    class IndexOutOfRangeException : public OutOfRange
    {
        DECLARE_CLASS_INFO(OutOfRange)
#pragma region constructor/destructor
    public:
        IndexOutOfRangeException() : OutOfRange()
        {
        }

        explicit IndexOutOfRangeException(const char* _message) : OutOfRange(_message)
        {
        }

        IndexOutOfRangeException(const char* _message, int _i) : OutOfRange(_message, _i)
        {
        }

        IndexOutOfRangeException(IndexOutOfRangeException const& _other) : OutOfRange(_other)
        {
        }
#pragma endregion constructor/destructor
#pragma region operator
        IndexOutOfRangeException& operator=(IndexOutOfRangeException& _other)
        {
            return *this;
        }
#pragma endregion operator
    };
}
