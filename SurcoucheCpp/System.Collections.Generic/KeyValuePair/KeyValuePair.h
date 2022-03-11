#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/String/String.h"
namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename TKey, typename TValue>
            class KeyValuePair : public Object
            {
                DECLARE_CLASS_INFO(Object)
#pragma region f/p
            public:
                TKey Key = TKey();
                TValue Value = TValue();
#pragma endregion f/p
#pragma region constructor
            public:
                KeyValuePair()=default;
                KeyValuePair(const TKey& _key, const TValue& _value);
                KeyValuePair(const KeyValuePair& copy);
#pragma endregion constructor
#pragma region override
            public:
                String ToString() const override;
#pragma endregion override
#pragma region opeator
                KeyValuePair operator=(const KeyValuePair& _other);
                Boolean operator==(const KeyValuePair& other);
                Boolean operator!=(const KeyValuePair& other);
#pragma endregion operator
            };
#pragma region constructor
            template <typename TKey, typename TValue>
            KeyValuePair<TKey, TValue>::KeyValuePair(const TKey& _key, const TValue& _value)
            {
                Key = std::move(_key);
                Value = std::move(_value);
            }

            template <typename TKey, typename TValue>
            KeyValuePair<TKey, TValue>::KeyValuePair(const KeyValuePair& copy) : Object(copy)
            {
                Key = std::move(copy.Key);
                Value = std::move(copy.Value);
            }

            template <typename TKey, typename TValue>
            String KeyValuePair<TKey, TValue>::ToString() const
            {
                TKey tKey = Key;
                TValue tValue = Value;
                const object* key = reinterpret_cast<object*>(&tKey);
                const object* value = reinterpret_cast<object*>(&tValue);
                if (key == null || value == null) return string::Empty;
                return string::Format("{0} => {1}", key->ToString(), value->ToString());
            }
#pragma endregion constructor
#pragma region operator
            template <typename TKey, typename TValue>
            KeyValuePair<TKey, TValue> KeyValuePair<TKey, TValue>::operator=(const KeyValuePair& _other)
            {
                Key = _other.Key; 
                Value = _other.Value;
                return *this;
            }

            template <typename TKey, typename TValue>
            Bool KeyValuePair<TKey, TValue>::operator==(const KeyValuePair& other)
            {
                return Key == other.Key && Value == other.Value;
            }

            template <typename TKey, typename TValue>
            Boolean KeyValuePair<TKey, TValue>::operator!=(const KeyValuePair& other)
            {
                return !this->operator==(other);
            }
#pragma endregion operator
        }
    }
}