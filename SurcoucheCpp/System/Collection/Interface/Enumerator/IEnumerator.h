﻿#pragma once
#include "../../../Object/Object.h"

namespace System
{
    namespace Collections
    {
        class IEnumerator : public Object
        {
            REGISTER_ATTRIBUTE(Interface)
        public:
            virtual object* Current() PURE_VIRTUAL()
            virtual bool MoveNext() PURE_VIRTUAL()
            virtual void Reset() PURE_VIRTUAL()
        };
    }
}
