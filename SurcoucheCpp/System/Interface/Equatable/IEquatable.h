﻿#pragma once
#include "../../Object/Object.h"

namespace System
{
    class Boolean;
    template <typename T>

    class IEquatable : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Interface)
    public:
        virtual Boolean Equals(const T& _object) PURE_VIRTUAL()
    };
}
