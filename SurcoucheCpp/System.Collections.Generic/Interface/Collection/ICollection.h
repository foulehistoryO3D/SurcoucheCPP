#pragma once

namespace System
{
    class Integer;
    namespace Collections
    {
        namespace Generic
        {
            template<typename Item>
            class ICollection
            {
            public:
                virtual ~ICollection() = default;
                virtual Integer Count()const PURE_VIRTUAL()
                virtual void Add(Item _item) PURE_VIRTUAL()
                virtual void Clear() PURE_VIRTUAL()
                virtual bool Contains(Item _item) PURE_VIRTUAL()
                virtual void Remove(Item _item) PURE_VIRTUAL()
            };
        }
    }
}
