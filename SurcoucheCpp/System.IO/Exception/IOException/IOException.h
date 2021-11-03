#pragma once
#include "../../../System/Exception/Exception/Exception.h"

namespace System
{
    namespace IO
    {
        class IOException : public Exception
        {
        public:
            IOException() : Exception() {  }

            explicit IOException(const char* _message) : Exception(_message)  { }

            IOException(const char* _message, int _i) : Exception(_message, _i) { }

            IOException(IOException const& _other) : Exception(_other)  { }
        };
    }
}
