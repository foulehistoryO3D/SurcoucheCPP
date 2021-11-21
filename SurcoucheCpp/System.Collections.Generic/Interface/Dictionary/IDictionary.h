#pragma once
#include "../../../System/Object/Object.h"
#include "../../KeyValuePair/KeyValuePair.h"
#include "../Collection/ICollection.h"
#include "../Enumerable/IEnumerable.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename TKey, typename TValue>
            class IDictionary : public ICollection<KeyValuePair<TKey, TValue>>, public IEnumerable<KeyValuePair<TKey, TValue>>
            {
            public:
                virtual void Add(TKey _key, TValue _value) PURE_VIRTUAL()
                virtual Boolean ContainsKey(TKey _key) PURE_VIRTUAL()
                virtual void RemoveItem(TKey _key) PURE_VIRTUAL()
            };
        }
    }
}
