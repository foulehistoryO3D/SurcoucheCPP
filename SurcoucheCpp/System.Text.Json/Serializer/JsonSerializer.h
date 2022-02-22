#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    namespace Text
    {
        namespace Json
        {
            class JsonSerializer sealed : public Object
            {
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
            public:
                static String Serialize(object* type);
                template<typename T>
                static String Serialize(T* type);
                template<typename T>
                static T* Deserialize(const String& json);
            };
        }
    }
}
