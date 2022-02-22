#include "JsonSerializer.h"
#include "../../System/PrimaryType/String/String.h"

System::String System::Text::Json::JsonSerializer::Serialize(object* type)
{
    return string::Empty;
}

template <typename T>
System::String System::Text::Json::JsonSerializer::Serialize(T* type)
{
    static_assert(Instanceof<Type>(type), "T must be bases of Type");
    return string::Empty;
}

template <typename T>
T* System::Text::Json::JsonSerializer::Deserialize(const String& json)
{
    return new T();
}
