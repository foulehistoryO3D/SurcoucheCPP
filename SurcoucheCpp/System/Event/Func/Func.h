#pragma once
#include <vector>

#include "../../Object/Object.h"
#include "../Delegate/Delegate.h"

namespace System
{
    template <typename Out, typename... Args>
    class Func sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        Delegate<Out, Args...> mFunctions = Delegate<Out, Args...>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Func() = default;
        template <typename Function>
        Func(Function _function);
        ~Func() override;
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        Out Invoke(Args ... _args) { return this->operator()(_args...); }
#pragma endregion custom methods
#pragma region operator
        template <typename Function>
        void operator+=(Function&& _function);
        template <typename Function>
        void operator-=(Function&& _function);
        Out operator()(Args ... _args);
#pragma endregion operator
    };

    template <typename Out, typename ... Args>
    template <typename Function>
    Func<Out, Args...>::Func(Function _function)
    {
        Delegate<Out, Args...> _delegate = Delegate<Out, Args...>(_function);
        mFunctions = _delegate;
    }

    template <typename Out, typename ... Args>
    Func<Out, Args...>::~Func()
    {
        mFunctions = null;
    }

    template <typename Out, typename ... Args>
    template <typename Function>
    void Func<Out, Args...>::operator+=(Function&& _function)
    {
        Delegate<Out, Args...> _delegate = _function;
        mFunctions = _delegate;
    }

    template <typename Out, typename ... Args>
    template <typename Function>
    void Func<Out, Args...>::operator-=(Function&& _function)
    {
        if (mFunctions == _function)
            mFunctions = null;
    }

    template <typename Out, typename ... Args>
    Out Func<Out, Args...>::operator()(Args ... _args)
    {
        return mFunctions.Invoke(_args...);
    }
}
