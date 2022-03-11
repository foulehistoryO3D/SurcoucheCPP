#include "JsonProperty.h"

#include "../../System/PrimaryType/Byte/Byte.h"
#include "../../System/Span/Span.h"
#include "../../System/PrimaryType/Char/Char.h"
#include "../Element/JsonElement.h"

#pragma region f/p
string System::Text::Json::JsonProperty::Name() const
{
    return this->name;
}

System::Text::Json::JsonElement* System::Text::Json::JsonProperty::Value() const
{
    return this->value;
}
#pragma endregion f/p
#pragma region constructor
System::Text::Json::JsonProperty::JsonProperty(const string& name, JsonElement* value)
{
    this->name = name;
    this->value = value;
}

System::Text::Json::JsonProperty::JsonProperty(const JsonProperty& copy) : Object(copy)
{
    this->name = copy.name;
    this->value = copy.value;
}

System::Boolean System::Text::Json::JsonProperty::NameEquals(Span<Byte> utf8Text) const
{
    const int length = utf8Text.Length();
    if (this->name.Length() != length) return false;
    for (int i = 0; i < length; ++i)
        if (utf8Text[i].ToChar() != this->name[i])
            return false;
    return true;
}

System::Boolean System::Text::Json::JsonProperty::NameEquals(Span<Char> text) const
{
    const int length = text.Length();
    if (this->name.Length() != length) return false;

    for (int i = 0; i < length; ++i)
        if (text[i] != this->name[i])
            return false;

    return true;
}

System::Boolean System::Text::Json::JsonProperty::NameEquals(const string& text) const
{
    return this->name == text;
}
#pragma endregion constructor
#pragma region override
System::String System::Text::Json::JsonProperty::ToString() const
{
    return this->name;
}

System::Integer System::Text::Json::JsonProperty::GetHashCode() const
{
    return this->name.GetHashCode() ^ (this->value->GetHashCode() << 2);
}
#pragma endregion override
#pragma region operator
System::Text::Json::JsonProperty& System::Text::Json::JsonProperty::operator=(const JsonProperty& other)
{
    this->name = other.name;
    this->value = other.value;
    return *this;
}
#pragma endregion operator
