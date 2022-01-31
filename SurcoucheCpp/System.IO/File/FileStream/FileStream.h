#pragma once
#include "../../../System/Interface/Disposable/IDisposable.h"
#include "../../../System/Object/Object.h"
#include "../File/File.h"

namespace System
{
    namespace IO
    {
        class StreamWriter;
        class StreamReader;

        class FileStream : public Object, public IDisposable
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            const char* mPath = nullptr;
            StreamWriter* mStreamWriter = nullptr;
            StreamReader* mStreamReader = nullptr;
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
            Integer GetHashCode() const override;
            void Dispose();
#pragma endregion override
#pragma region operator
        public:
            FileStream operator=(const FileStream&_other);
#pragma endregion operator
        };
    }
}
