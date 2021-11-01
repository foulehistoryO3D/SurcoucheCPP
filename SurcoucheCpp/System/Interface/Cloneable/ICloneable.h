#pragma once
#include "../../Object/Object.h"

namespace System
{
    template<typename T>
    class ICloneable : public Object
    {
        REGISTER_ATTRIBUTE(Interface)
    public:
        virtual T Clone()PURE_VIRTUAL()
    };
}
