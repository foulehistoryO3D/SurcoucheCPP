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
            public:
                virtual ~IEnumerable() = default;
                virtual IEnumerator<T>* GetEnumerator() PURE_VIRTUAL()
            };
        }
    }
}
