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
#pragma region f/p
        protected:
            std::ofstream mStream = {};
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            TextWriter()=default;
            TextWriter(const String& _path);
            TextWriter(TextWriter&& _copy) noexcept;
            ~TextWriter()override;
#pragma endregion constructor/destructor
#pragma region custom methods
        public:
            virtual Boolean IsOpen()const;
            Boolean IsValid()const;
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
        };
    }
}
