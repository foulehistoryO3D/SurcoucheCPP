#pragma once
#include "../../../Object/Object.h"
#include "../Enumerable/Enumerable.h"

namespace System
{
    namespace Collections
    {
        class ICollection : public IEnumerable
        {
            REGISTER_ATTRIBUTE(Interface)
        public:
            virtual int Count()const PURE_VIRTUAL()
        };
    }
}
