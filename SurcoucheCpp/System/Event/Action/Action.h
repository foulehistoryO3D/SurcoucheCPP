#pragma once
#include <iostream>
#include <vector>

#include "../../Object/Object.h"
#include "../Delegate/Delegate.h"

namespace System
{
    template <typename... Args>
    class Action sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        std::vector<Delegate<void, Args...>> mFunctions = std::vector<Delegate<void, Args...>>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Action() = default;
        template <typename Function>
        Action(Function _function);
        ~Action() override;
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        void Invoke(Args ... _args) { this->operator()(_args...); }
#pragma endregion custom methods
#pragma region operator
        template <typename Function>
        void operator+=(Function&& _function);
        template <typename Function>
        void operator-=(Function&& _function);
        void operator()(Args ... _args);
#pragma endregion operator
    };
#pragma region constructor/destructor
    template <typename ... Args>
    template <typename Function>
    Action<Args...>::Action(Function _function)
    {
        Delegate<void, Args...> _delegate = Delegate<void, Args...>(_function);
        mFunctions.push_back(_delegate);
    }

    template <typename ... Args>
    Action<Args...>::~Action()
    {
        mFunctions.clear();
    }
#pragma endregion constructor/destructor
#pragma region operator

    template <typename ... Args>
    template <typename Function>
    void Action<Args...>::operator+=(Function&& _function)
    {
        Delegate<void, Args...> _delegate = _function;
        mFunctions.push_back(_delegate);
    }

    template <typename ... Args>
    template <typename Function>
    void Action<Args...>::operator-=(Function&& _function)
    {
        const int _length = mFunctions.size();
        for (int i = 0; i < _length; ++i)
        {
            if (mFunctions[i] == _function)
            {
                mFunctions.erase(mFunctions.begin() + i);
                return;
            }
        }
    }

    template <typename ... Args>
    void Action<Args...>::operator()(Args ... _args)
    {
        const int _length = mFunctions.size();
        for (int i = 0; i < _length; ++i)
            mFunctions[i].Invoke(_args...);
    }
#pragma endregion operator
}
