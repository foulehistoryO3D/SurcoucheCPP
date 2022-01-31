#pragma once
#include "../Exception/Exception.h"

namespace System
{
    class OutOfRange : public Exception
    {
        DECLARE_CLASS_INFO(Exception)
#pragma region constructor/destructor
    public:
        OutOfRange() : Exception() {  }

        explicit OutOfRange(const char* _message) : Exception(_message)  { }

        OutOfRange(const char* _message, int _i) : Exception(_message, _i) { }

        OutOfRange(OutOfRange const& _other) : Exception(_other)  { }
#pragma endregion constructor/destructor
#pragma region operator
        OutOfRange& operator=(const OutOfRange& _other)
        {
            return *this;
        }
#pragma endregion operator
    };
}
