#pragma once
#include <regex>

#include "../../System/Interface/Equatable/IEquatable.h"
#include "../../System/Object/Object.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class Regex : public Object, public IEquatable<Regex>
            {
#pragma region f/p
            private:
                const char* mPattern = null;
                std::regex mExpression = std::regex();
#pragma endregion f/p
#pragma region constructor
            public:
                Regex() = default;
                Regex(const String& _pattern);
                Regex(const Regex& _copy);
#pragma endregion constructor
#pragma region custom methods
            public:
                Boolean IsMatch(const String& _input)const;
                String Replace(const String& _input, const String& _replacement)const;
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                size_t GetHashCode() const override;
                Boolean Equals(const Regex& _object) override;
#pragma endregion override
            };
        }
    }
}
