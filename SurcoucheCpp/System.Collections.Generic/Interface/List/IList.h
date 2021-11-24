#pragma once
#include "../Enumerable/IEnumerable.h"
#include "../Collection/ICollection.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename Item>
            class IList : ICollection<Item>, IEnumerable<Item>
            {
            public:
                virtual int IndexOf(Item _item) PURE_VIRTUAL()
                virtual void Insert(const int32 _index, Item _item) PURE_VIRTUAL()
                virtual void RemoveAt(const int32 _index) PURE_VIRTUAL()
            };
        }
    }
}
