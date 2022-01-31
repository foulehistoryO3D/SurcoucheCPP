#pragma once
#include "../TextReader/TextReader.h"

namespace System
{
    namespace IO
    {
        class StreamReader : public TextReader
        {
            DECLARE_CLASS_INFO(TextReader)
#pragma region constructor
        public:
            StreamReader();
            StreamReader(const String& _path);
            StreamReader(StreamReader&& _copy) noexcept;
#pragma endregion constructor
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
        };
    }
}