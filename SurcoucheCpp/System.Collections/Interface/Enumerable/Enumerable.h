#pragma once

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
            virtual IEnumerator* GetEnumerator() = 0;
        };
    }
}
