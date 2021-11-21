#pragma once
#include "../Enumerator/IEnumerator.h"


namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename T>
            class IEnumerable
            {
                // REGISTER_ATTRIBUTE(Interface)
            public:
                virtual IEnumerator<T>* GetEnumerator() { return null; }
            };
        }
    }
}
