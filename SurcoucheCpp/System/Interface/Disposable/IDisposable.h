#pragma once
#include "../../Object/Object.h"

namespace System
{
    class IDisposable
    {
    public:
        virtual void Dispose() PURE_VIRTUAL()
    };
}
