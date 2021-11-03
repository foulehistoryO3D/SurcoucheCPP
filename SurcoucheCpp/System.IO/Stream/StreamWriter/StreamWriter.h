#pragma once
#include "../TextWriter/TextWriter.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class List;
        }
    }
    namespace IO
    {
        class StreamWriter sealed : public TextWriter
        {
            REGISTER_ATTRIBUTE(Sealed)
#pragma region constructor/destructor
        public:
            StreamWriter();
            StreamWriter(const String& _path);
            StreamWriter(StreamWriter&& _copy) noexcept;
#pragma endregion constructor/destructor
#pragma region custom methods
        public:
            void WriteAllText(const Collections::Generic::List<String> _values);
#pragma endregion custom methods
#pragma region override
        public:
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
#pragma endregion override
        };
    }
}
