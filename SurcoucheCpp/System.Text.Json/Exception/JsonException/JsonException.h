#pragma once
#include "../../../System/Exception/Exception/Exception.h"

namespace System
{
    namespace Text
    {
        namespace Json
        {
            class JsonException : public Exception
            {
                DECLARE_CLASS_INFO(Exception)
#pragma region constructor/destructor
            public:
                JsonException() : Exception()
                {
                }

                explicit JsonException(const char* _message) : Exception(_message)
                {
                }

                JsonException(const char* _message, int _i) : Exception(_message, _i)
                {
                }

                JsonException(JsonException const& _other) : Exception(_other)
                {
                }
#pragma endregion constructor/destructor
#pragma region operator
                JsonException& operator=(JsonException& _other)
                {
                    return *this;
                }
#pragma endregion operator
            };
        }
    }
}
