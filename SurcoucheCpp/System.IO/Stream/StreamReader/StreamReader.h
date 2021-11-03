#pragma once
#include "../TextReader/TextReader.h"

namespace System
{
    namespace IO
    {
        class StreamReader : public TextReader
        {
#pragma region constructor
        public:
            StreamReader();
            StreamReader(const String& _path);
            StreamReader(StreamReader&& _copy);
#pragma endregion constructor
        };
    }
}