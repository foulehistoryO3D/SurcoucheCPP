#pragma once
#include "../../Object/Object.h"

namespace System
{
    class IDisposable : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Interface)
    public:
        virtual void Dispose() PURE_VIRTUAL()
    };
}
