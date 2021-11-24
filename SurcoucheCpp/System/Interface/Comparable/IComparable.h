#pragma once
#include "../../Object/Object.h"

namespace System
{
    template<typename T>
    class IComparable
    {
    public:
        virtual ~IComparable() = default;
        virtual int CompareTo(const T& _other) PURE_VIRTUAL()
    };
}
