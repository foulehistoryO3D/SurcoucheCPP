#pragma once
#include "../Enumerable/Enumerable.h"

namespace System
{
    namespace Collections
    {
        class ICollection : public IEnumerable
        {
        public:
            virtual int Count()const PURE_VIRTUAL()
        };
    }
}
