#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class StreamWriter;
        class File : public Object
        {
#pragma region f/p
        private:
            const char* mPath = null;
#pragma endregion f/p
#pragma region constructor
        public:
            File()=default;
            File(const String& _path);
            File(const File& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            static Boolean Exists(const String& _path);
            static void Create(const String& _path);
            static StreamWriter CreateText(const String& _path);
#pragma endregion custom methods
#pragma region override
        public:
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            size_t GetHashCode() const override;
#pragma endregion override
        };
    }
}
