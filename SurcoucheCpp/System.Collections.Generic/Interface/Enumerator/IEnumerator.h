#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class IEnumerator : public Object
            {
                REGISTER_ATTRIBUTE(Interface)
            public:
                virtual T Current() PURE_VIRTUAL()
                virtual bool MoveNext() PURE_VIRTUAL()
                virtual void Reset() PURE_VIRTUAL()
            };
        }
    }
}
