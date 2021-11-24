#pragma once
#include "../../../System/Object/Object.h"

class IEnumerator;

namespace System
{
    namespace Collections
    {
        class IEnumerable
        {
        public:
            virtual ~IEnumerable() = default;
        private:
            virtual IEnumerator* GetEnumerator() PURE_VIRTUAL()
        };
    }
}
