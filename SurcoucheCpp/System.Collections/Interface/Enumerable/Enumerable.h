#pragma once
#include "../../../System/Object/Object.h"

class IEnumerator;

namespace System
{
    namespace Collections
    {
        class IEnumerable : public Object
        {
            REGISTER_ATTRIBUTE(Interface)
            virtual IEnumerator* GetEnumerator() PURE_VIRTUAL()
        };
    }
}
