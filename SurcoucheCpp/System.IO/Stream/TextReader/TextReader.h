#pragma once
#include <fstream>

#include "../../../System/Interface/Disposable/IDisposable.h"
#include "../../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class TextReader : public Object, public IDisposable
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        protected:
            std::ifstream mStream = std::ifstream();
            const char* mPath = nullptr;
#pragma endregion f/p
#pragma region constructor
        public:
            TextReader() = default;
            TextReader(const String& _path);
            TextReader(const TextReader& _copy) noexcept;
#pragma endregion constructor
#pragma region custom methods
        public:
            void Close();
            Boolean IsOpen()const;
            Boolean IsValid()const;
            Boolean ReadLine(String& _out);
            String ReadLine();
            String ReadToEnd();
            String Path()const;
            char Read();
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
            TextReader& operator=(TextReader&& _reader) noexcept
            {
                mPath = std::move(_reader.mPath);
                mStream = std::move(_reader.mStream);
                return *this;
            }
#pragma endregion operator
        };
    }
}