#pragma once
#include "../../System/Object/Object.h"



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
#pragma endregion operator
            };
#pragma region constructor
            template <typename TKey, typename TValue>
            KeyValuePair<TKey, TValue>::KeyValuePair(const TKey& _key, const TValue& _value)
            {
                Key = _key;
                Value = _value;
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
                Key = std::move(_other.Key);
                Value = std::move(_other.Value);
                return *this;
            }
#pragma endregion operator
        }
    }
}