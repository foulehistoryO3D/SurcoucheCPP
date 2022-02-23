#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Array/Array.h"

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
            private:
                template<typename T>
                static String SerializeArray(std::pair<string, object*> value);
                static String SerializeClass(std::pair<string, object*> value);
                static String SerializePrimaryType(std::pair<string, object*> value);
            public:
                static String Serialize(object* type);
                template<typename T>
                static String Serialize(T* type);
                template<typename T>
                static T* Deserialize(const String& json);
            };

            template <typename T>
            String JsonSerializer::SerializeArray(std::pair<string, object*> value)
            {
                Array<T>* array = dynamic_cast<Array<T>*>(value.second);
                if (!array) return string::Empty;
                const int length = array->Count();
                for (int i = 0; i < length; ++i)
                {
                    
                }
                return string::Empty;
            }

            template <typename T>
            String System::Text::Json::JsonSerializer::Serialize(T* type)
            {
                static_assert(std::is_base_of_v<Object, T>, "T must be bases of object");
                return string::Empty;
            }

            template <typename T>
            T* System::Text::Json::JsonSerializer::Deserialize(const String& json)
            {
                return new T();
            }

        }
    }
}
