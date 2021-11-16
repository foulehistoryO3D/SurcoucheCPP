#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    class Integer;
    namespace Text
    {
        namespace RegularExpressions
        {
            class Capture : public Object
            {
                DECLARE_CLASS_INFO(Object)
#pragma region f/p
            protected:
                int mIndex = 0;
                int mLength = 0;
                const char* mValue = null;
            public:
                String Value()const;
                Integer Index()const;
                Integer Length()const;
#pragma endregion f/p
#pragma region constructor
            public:
                Capture() = default;
                Capture(const Capture& _copy);
#pragma endregion constructor
#pragma region custom methods
            public:
                void SetIndex(const int _index);
                void SetValue(const String& _value);
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
                Capture operator=(const Capture& _other)
                {
                    mIndex = std::move(_other.mIndex);
                    mValue = std::move(_other.mValue);
                    mLength = std::move(_other.mLength);
                    return *this;
                }
#pragma endregion operator
            };
        }
    }
}
