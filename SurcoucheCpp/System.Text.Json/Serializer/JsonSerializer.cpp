#include "JsonSerializer.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System.Text/StringBuilder/StringBuilder.h"


System::String System::Text::Json::JsonSerializer::SerializeClass(std::pair<string, object*> value)
{
    return string::Empty;
}

System::String System::Text::Json::JsonSerializer::SerializePrimaryType(std::pair<string, object*> value)
{
    return string::Format("\"{0}\": \"{1}\",", value.first, *value.second);
}

System::String System::Text::Json::JsonSerializer::Serialize(object* type)
{
    StringBuilder builder = StringBuilder();
    std::map<string, object*> map = std::map<string, object*>();
    std::map<string, object*>::iterator begin = map.begin();
    const std::map<string, object*>::iterator end = map.end();
    for (; begin != end; ++begin)
    {
        if (begin->second->IsArray())
        {
            builder.Append(SerializeArray<decltype(begin->second)>(*begin));
        }
        else if (begin->second->IsClass())
        {
            builder.Append(SerializeClass(*begin));
        }
        else if (begin->second->IsPrimaryType())
        {
            builder.Append(SerializePrimaryType(*begin));
        }
    }
    return builder.ToString();
}

