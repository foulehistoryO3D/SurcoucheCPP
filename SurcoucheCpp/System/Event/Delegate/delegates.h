﻿#pragma once
#include <functional>

#include "../../Object/Object.h"

namespace System
{
    template<typename Res, typename... Args>
    class Delegate : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        std::function<Res(Args...)> mFunction = null;
    public:
        std::function<Res(Args...)> Function()const { return mFunction; }
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Delegate() { mFunction = null; }
        template<typename Function>
        Delegate(Function&& _function) { mFunction = std::move(_function);}
#pragma endregion constructor/destructor
#pragma region custom methods
        Res Invoke(Args... _args) { return mFunction(_args...); }
#pragma endregion custom methods
#pragma region operator
        Res operator()(Args... _args) { return mFunction(_args...);}
        bool operator==(const Delegate<Res, Args...> _other)
        {
            return mFunction.template target<Res(Args...)>() == _other.mFunction.template target<Res(Args...)>();
        }
        bool operator !=(const Delegate<Res, Args...> _other)
        {
            return !(this->operator==(_other));
        }
        Delegate& operator=(const Delegate& _other)
        {
            mFunction = std::move(_other.mFunction);
            return *this;
        }
#pragma endregion operator
    };
}
