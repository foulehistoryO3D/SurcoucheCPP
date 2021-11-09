#pragma once
#include <fstream>

#include "../../../System/Object/Object.h"


namespace System
{
    class Float;
    class Double;
    class Integer;
    
    namespace IO
    {
        class TextWriter : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        protected:
            const char* mPath = null;
            std::ofstream mStream = {};
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            TextWriter()=default;
            TextWriter(const String& _path);
            TextWriter(TextWriter&& _copy) noexcept;
#pragma endregion constructor/destructor
#pragma region custom methods
        public:
            virtual Boolean IsOpen()const;
            String Path()const;
            Boolean IsValid()const;
            Boolean Exists()const;
            virtual void Close();
            virtual void Write(const Boolean& _value);
            virtual void Write(const char _value);
            virtual void Write(const Float& _value);
            virtual void Write(const Double& _value);
            virtual void Write(const Integer& _value);
            virtual void Write(const object& _value);
            // virtual void Write(const StringBuilder& _value);
            virtual void Write(const String& _value);
#pragma endregion custom methods
#pragma region override
            public:
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
#pragma endregion override
#pragma region operator
        public:
            TextWriter& operator=(TextWriter&& _writer) noexcept
            {
                mPath = std::move(_writer.mPath);
                mStream = std::move(_writer.mStream);
                return *this;
            }
#pragma endregion operator
        };
    }
}
