#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class StreamWriter;
        class StreamReader;

        class FileStream : public Object
        {
#pragma region f/p
        private:
            const char* mPath = null;
            StreamWriter* mStreamWriter = null;
            StreamReader* mStreamReader = null;
#pragma endregion f/p
#pragma region constructor
        public:
            FileStream() = default;
            FileStream(const String& _path);
            FileStream(const FileStream& _copy);
            ~FileStream() override;
#pragma endregion constructor
#pragma region custom methods
        public:
            Boolean Exists()const;
            Boolean IsValid()const;
            void Close() const;
            StreamWriter& Writer() const;
            StreamReader& Reader() const;
            String FullPath() const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            size_t GetHashCode() const override;
#pragma endregion override
        };
    }
}
