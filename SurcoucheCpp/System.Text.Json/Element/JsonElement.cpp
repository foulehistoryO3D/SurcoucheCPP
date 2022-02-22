#include "JsonElement.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Byte/Byte.h"
#include "../../System/DateTime/DateTime.h"
#include "../../System/Exception/IndexOutOfRange/IndexOutOfRangeException.h"
#include "../../System/PrimaryType/Float/Float.h"
#include "../../System/PrimaryType/Double/Double.h"
#include "../../System/PrimaryType/String/String.h"
#include "../Exception/JsonException/JsonException.h"

#pragma region f/p
System::Text::Json::JsonValueKind System::Text::Json::JsonElement::ValueKind() const
{
    return this->valueKind;
}

System::Boolean System::Text::Json::JsonElement::IsArrayType() const
{
    return this->valueKind == JsonValueKind::Array;
}
#pragma endregion f/p
#pragma region constructor
System::Text::Json::JsonElement::JsonElement(object* object)
{
    this->value = object;
    if (object->IsArray())
    {
        this->array = *dynamic_cast<Array<Object*>*>(object);
        this->valueKind = JsonValueKind::Array;
        return;
    }
}
#pragma endregion constructor
#pragma region custom methods
System::Integer System::Text::Json::JsonElement::GetArrayLength() const
{
    if (!IsArrayType()) throw JsonException("cannot convert value is not an array");
    return this->array.Count();
}

System::Integer System::Text::Json::JsonElement::GetInteger() const
{
    if (IsArrayType()) throw JsonException("cannot convert array to integer");
    Integer* result = dynamic_cast<Integer*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::Boolean System::Text::Json::JsonElement::GetBoolean() const
{
    if (IsArrayType())
        throw JsonException("cannot convert array to boolean");
    Boolean* result = dynamic_cast<Boolean*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::Byte System::Text::Json::JsonElement::GetByte() const
{
    if (IsArrayType())
        throw JsonException("cannot convert array to Byte");
    Byte* result = dynamic_cast<Byte*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::DateTime System::Text::Json::JsonElement::GetDateTime() const
{
    if (IsArrayType()) throw JsonException("cannot convert array to DateTime");
    DateTime* result = dynamic_cast<DateTime*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::Float System::Text::Json::JsonElement::GetFloat() const
{
    if (IsArrayType()) throw JsonException("cannot convert array to Float");
    Float* result = dynamic_cast<Float*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::Double System::Text::Json::JsonElement::GetDouble() const
{
    if (IsArrayType()) throw JsonException("cannot convert array to Double");
    Double* result = dynamic_cast<Double*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::String System::Text::Json::JsonElement::GetString() const
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    String* result = dynamic_cast<String*>(this->value);
    if (!result) throw JsonException("cannot convert value to integer");
    return *result;
}

System::Boolean System::Text::Json::JsonElement::TryGetArrayLength(Integer& out) const
{
    if (!IsArrayType()) return false;
    out = this->array.Count();
    return true;
}

System::Boolean System::Text::Json::JsonElement::TryGetInteger(Integer& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<Integer>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetBoolean(Boolean& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<Boolean>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetByte(Byte& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<Byte>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetDateTime(DateTime& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<DateTime>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetFloat(Float& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<Float>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetDouble(Double& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<Double>(out);
}

System::Boolean System::Text::Json::JsonElement::TryGetString(String& out)
{
    if (IsArrayType()) throw JsonException("cannot convert array to String");
    return TryGetValue<String>(out);
}
#pragma endregion custom methods
#pragma region override
System::String System::Text::Json::JsonElement::ToString() const
{
    return string::Empty;
}

System::Integer System::Text::Json::JsonElement::GetHashCode() const
{
    return this->array.GetHashCode() ^ this->value->GetHashCode() << 2;
}
#pragma endregion override
#pragma region operator
System::object* System::Text::Json::JsonElement::operator[](const Integer& index) const
{
    if (!IsArrayType()) throw JsonException("value is not an array type !");
    if (index < 0 || index > this->array.Count())
        throw IndexOutOfRangeException("invalid index JsonElement !");
    return this->array[index];
}

System::Text::Json::JsonElement& System::Text::Json::JsonElement::operator=(const JsonElement& other)
{
    this->valueKind = other.valueKind;
    this->array = other.array;
    this->value = other.value;
    return *this;
}
#pragma endregion operator
