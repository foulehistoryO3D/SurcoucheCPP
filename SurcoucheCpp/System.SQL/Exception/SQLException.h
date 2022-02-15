#pragma once
#include "../../System/Exception/Exception/Exception.h"

namespace System
{
    namespace SQL
    {
        class SQLException : public Exception
        {
            DECLARE_CLASS_INFO (Exception)
#pragma region constructor/destructor
        public:
            SQLException() : Exception()
            {
            }

            explicit SQLException(const char* _message) : Exception(_message)
            {
            }

            SQLException(const char* _message, int _i) : Exception(_message, _i)
            {
            }

            SQLException(SQLException const& _other) : Exception(_other)
            {
            }
#pragma endregion constructor/destructor
#pragma region operator
            SQLException& operator=(SQLException& _other)
            {
                return *this;
            }
#pragma endregion operator
        };
    }
}
