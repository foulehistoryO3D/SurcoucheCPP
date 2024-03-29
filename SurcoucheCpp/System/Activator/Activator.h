﻿#pragma once
#include "../Object/Object.h"

namespace System
{
    class Activator : public Object
    {
        DECLARE_CLASS_INFO(Object)
    public:
        template<typename T, typename... Args>
        static T* CreateInstance(Args... _args);
    };

    template <typename T, typename ... Args>
    T* Activator::CreateInstance(Args... _args)
    {
        T* _result = new T(_args...);
        return _result;
    }
}
