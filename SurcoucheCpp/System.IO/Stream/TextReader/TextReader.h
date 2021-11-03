#pragma once
#include <fstream>

#include "../../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class TextReader : public Object
        {
#pragma region f/p
        protected:
            std::ifstream mStream = std::ifstream();
#pragma endregion f/p
#pragma region constructor
        public:
            TextReader() = default;
            TextReader(const String& _path);
            TextReader(TextReader&& _copy) noexcept;
#pragma endregion constructor
#pragma region custom methods
        public:
            void Close();
            Boolean IsOpen()const;
            Boolean IsValid()const;
            Boolean ReadLine(String& _out);
            String ReadLine();
            String ReadToEnd();
            char Read();
#pragma endregion custom methods
        };
    }
}