#pragma once
#include "../../Collection/Generic/Interface/Enumerable/IEnumerable.h"
#include "../../Object/Object.h"
#include "../../Interface/Cloneable/ICloneable.h"
#include "../../Interface/Equatable/IEquatable.h"

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
        // String(String&& _copy) noexcept;
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        void Append(const Object& _object);
        void Append(const Object* _object);
        void Append(const String& _str);
        void Append(const char& _c);
        String ToLower() const;
        String ToUpper() const;
        Collections::Generic::List<String> Split(const char& _c) const;
        const char* ToCstr() const;
        static String Empty();
        static bool IsNullOrEmpty(const String& _str);
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
        String operator=(const String& _str)
        {
            mValue = _str.mValue;
            mLength = _str.mLength;
            return *this;
        }
        bool operator==(const String& _other) const;
        bool operator== (const char* _other) const;
        bool operator!=(const String& _other) const;
        bool operator!= (const char* _other) const;
#pragma endregion operator
    };
}

typedef System::String string;
