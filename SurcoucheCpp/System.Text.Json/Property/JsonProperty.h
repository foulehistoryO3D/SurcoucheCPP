#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/String/String.h"

namespace System
{
    namespace Text
    {
        namespace Json
        {
            class JsonElement;

            class JsonProperty sealed : public Object
            {
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                string name             = string::Empty;
                JsonElement* value      = null;
            public:
                string Name()const;
                JsonElement* Value()const;
#pragma endregion f/p
#pragma region constructor
            public:
                JsonProperty() = default;
                JsonProperty(const string& name, JsonElement* value);
                JsonProperty(const JsonProperty& copy);
#pragma endregion constructor
#pragma region custom methods
            public:
                Boolean NameEquals(Span<Byte> utf8Text) const;
                Boolean NameEquals(Span<Char> text) const;
                Boolean NameEquals(const string& text) const;
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
            public:
                JsonProperty& operator=(const JsonProperty& other);
#pragma endregion operator
            };
        }
    }
}
