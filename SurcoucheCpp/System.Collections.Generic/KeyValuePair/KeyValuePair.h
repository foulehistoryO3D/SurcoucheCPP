#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
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
                KeyValuePair(const KeyValuePair& _pair);
#pragma endregion constructor
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
            KeyValuePair<TKey, TValue>::KeyValuePair(const KeyValuePair& _pair)
            {
                Key = std::move(_pair.Key);
                Value = std::move(_pair.Value);
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