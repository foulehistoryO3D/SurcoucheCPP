#pragma once
#include "../../Object/Object.h"

namespace System
{
    class IDisposable
    {
    public:
        virtual ~IDisposable() = default;
        virtual void Dispose() PURE_VIRTUAL()
    };
}
