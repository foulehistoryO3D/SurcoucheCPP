#pragma once
#include <string>
#include <windows.h>

#include "../../../System.Collections.Generic/Interface/Enumerable/IEnumerable.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../../Object/Object.h"
#include "../../Interface/Cloneable/ICloneable.h"
#include "../../Interface/Equatable/IEquatable.h"

namespace System
{
    class Integer;
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class List;
        }
    }
}

namespace System
{
    class String sealed : public Object, public IEquatable<String>, public ICloneable<String>, public Collections::Generic::IEnumerable<char>, public Collections::Generic::IEnumerator<char>
    {
#pragma region f/p
    private:
        const char* mValue = "";
        int mLength = 0;
        char mCurrentValue = 0;
        int mCurrentIndex = -1;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        String()=default;
        String(const char* _value);
        String(const String& _copy);
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        void Append(const Object& _object);
        void Append(const Object* _object);
        void Append(const String& _str);
        void Append(const char& _c);
        void Append(const int _i);
        void Append(const Integer& _integer);
        String ToLower() const;
        String ToUpper() const;
        Boolean Contains(const String& _str) const;
        Collections::Generic::List<String> Split(const char& _c) const;
        Collections::Generic::List<String> Split(const String& _value) const;
        String SubString(const Integer& _begin, const Integer& _end)const;
        String SubString(const Integer& _begin)const;
        const char* ToCstr() const;
        String Replace(const char _oldChar, const char _newChar) const;
        String Replace(const String& _old, const String& _new) const;
        static String Empty();
        static bool IsNullOrEmpty(const String& _str);
        Integer LastIndexOf(const char _c) const;
        Integer FirstIndexOf(const char _c)const;
        Integer FirstIndexOf(const String& _str)const;
        Integer Length()const;
        std::wstring* ToWString()const;
        static std::wstring* ToWString(const String& _str);
        static String WStringToString(const std::wstring& _wstring);

#pragma endregion custom methods
#pragma region override
    public:
        String ToString()const override;
        class Boolean Equals(const object* _obj) override;
        Boolean Equals(const String& _object) override;
        size_t GetHashCode() const override;
        String Clone() override;
        char Current() override;
        bool MoveNext() override;
        void Reset() override;
        IEnumerator<char>* GetEnumerator() override;
#pragma endregion override
#pragma region operator
        operator const char*()const;
        String operator+(const CHAR* _str) const;
        String operator+(const Integer& _integer);
        String operator+(const int _i);
        String operator+(const char& _c);
        char operator[](const int _index) const
        {
            if (_index < 0 || _index > mLength) throw OutOfRange("[String] operator [] => index out of range");
            return mValue[_index];
        }
        String operator=(const String& _str)
        {
            mValue = _str.mValue;
            mLength = _str.mLength;
            return *this;
        }
        String& operator+=(char _c);
        String& operator+=(const String& _str);
        bool operator==(const String& _other) const;
        bool operator== (const char* _other) const;
        bool operator!=(const String& _other) const;
        bool operator!= (const char* _other) const;
#pragma endregion operator
    };
}

typedef System::String string;
