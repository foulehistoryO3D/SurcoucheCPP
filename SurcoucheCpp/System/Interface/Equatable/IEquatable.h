﻿#pragma once
#include "../../Object/Object.h"

namespace System
{
    class Boolean;
    template <typename T>

    class IEquatable
    {
    public:
        virtual ~IEquatable() = default;
        virtual Boolean Equals(const T& _object) PURE_VIRTUAL()
    };
}
