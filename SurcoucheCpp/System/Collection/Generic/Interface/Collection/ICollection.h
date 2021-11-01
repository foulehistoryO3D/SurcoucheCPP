#pragma once
#include "../../../Object/Object.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename Item>
            class ICollection : public Object
            {
                REGISTER_ATTRIBUTE(Interface)
            public:
                virtual int Count()const PURE_VIRTUAL()
                virtual void Add(Item _item) PURE_VIRTUAL()
                virtual void Clear() PURE_VIRTUAL()
                virtual bool Contains(Item _item) PURE_VIRTUAL()
                virtual void Remove(Item _item) PURE_VIRTUAL()
            };
        }
    }
}
