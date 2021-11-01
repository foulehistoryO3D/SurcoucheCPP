#pragma once
#include "../Enumerator/IEnumerator.h"


namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class IEnumerable : public Object
            {
                REGISTER_ATTRIBUTE(Interface)
            public:
                virtual IEnumerator<T>* GetEnumerator() PURE_VIRTUAL()
            };
        }
    }
}
