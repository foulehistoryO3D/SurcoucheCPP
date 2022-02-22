#pragma once
#include "../../System/Console/Console.h"
#include "../../System/Object/Object.h"
#include "../ValueKind/JsonValueKind.h"
#include "../../System/PrimaryType/Array/Array.h"
#include "../Exception/JsonException/JsonException.h"

namespace System
{
    namespace Text
    {
        namespace Json
        {
            class JsonElement sealed : public Object
            {
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                JsonValueKind valueKind = JsonValueKind::Object;
                Array<object*> array = System::Array<object*>();
                object* value = null;
            public:
                JsonValueKind ValueKind() const;
                Boolean IsArrayType()const;
#pragma endregion f/p
#pragma region constructor
            public:
                JsonElement() = default;
                JsonElement(object* object);
#pragma endregion constructor
#pragma region custom methods
            private:
                template<typename T>
                Boolean TryGetValue(T& out)
                {
                    try
                    {
                        T* result = dynamic_cast<T*>(this->value);
                        static_assert(std::is_base_of_v<Type, T>, "T must be bases of Type");
                        if (!result) return false;
                        out = *result;
                        return result;
                    }
                    catch (JsonException e)
                    {
                        Console::WriteLine(e);
                        return false;
                    }
                }
            public:
                Integer GetArrayLength() const;
                Integer GetInteger()const;
                Boolean GetBoolean() const;
                Byte GetByte() const;
                DateTime GetDateTime() const;
                Float GetFloat() const;
                Double GetDouble() const;
                String GetString() const;

                Boolean TryGetArrayLength(Integer& out) const;
                Boolean TryGetInteger(Integer& out);
                Boolean TryGetBoolean(Boolean& out);
                Boolean TryGetByte(Byte& out);
                Boolean TryGetDateTime(DateTime& out);
                Boolean TryGetFloat(Float& out);
                Boolean TryGetDouble(Double& out);
                Boolean TryGetString(String& out);
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
            public:
                object* operator[](const Integer& index) const;
                JsonElement& operator=(const JsonElement& other);
#pragma endregion operator
            };
        }
    }
}
