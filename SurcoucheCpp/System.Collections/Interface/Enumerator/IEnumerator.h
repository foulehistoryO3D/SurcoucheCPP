#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace Collections
    {
        class IEnumerator
        {
        public:
            virtual ~IEnumerator() = default;
            virtual object* Current() PURE_VIRTUAL()
            virtual bool MoveNext() PURE_VIRTUAL()
            virtual void Reset() PURE_VIRTUAL()
        };
    }
}
