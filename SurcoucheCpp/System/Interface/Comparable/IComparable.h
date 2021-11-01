#pragma once
#include "../../Object/Object.h"

namespace System
{
    template<typename T>
    class IComparable : public Object
    {
        REGISTER_ATTRIBUTE(Interface)
    public:
        virtual int CompareTo(const T& _other) PURE_VIRTUAL()
    };
}
