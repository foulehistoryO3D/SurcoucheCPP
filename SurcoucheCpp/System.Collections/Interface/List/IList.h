#pragma once
#include "../Collection/ICollection.h"

namespace System
{
    namespace Collections
    {
        class IList : public ICollection
        {
        public:
            virtual int Add(object* _object) PURE_VIRTUAL()
            virtual void Clear() PURE_VIRTUAL()
            virtual bool Contains(object* _object) PURE_VIRTUAL()
            virtual int IndexOf(object* _object) PURE_VIRTUAL()
            virtual void Insert(const int32 _index, object* _object) PURE_VIRTUAL()
            virtual void Remove(object* _object) PURE_VIRTUAL()
            virtual void RemoveAt(const int32 _index) PURE_VIRTUAL()
        };
    }
}
