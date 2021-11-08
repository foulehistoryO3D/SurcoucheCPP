#pragma once
#include "../../Object/Object.h"
#include "../Delegate/Delegate.h"

namespace System
{
    template<typename... Args>
    class Event : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            std::vector<Delegate<void, Args...>> mFunctions = std::vector<Delegate<void,Args...>>();
#pragma endregion f/p
#pragma region constructor
    public:
        Event()=default;
        Event(Delegate<void, Args...>&& _function);
        Event(const Event& _event);
#pragma endregion constructor
#pragma region custom methods
    public:
        void Invoke(Args... _args);
#pragma endregion custom methods
#pragma region operator
    public:
        void operator+=(Delegate<void, Args...>&& _function);
        void operator-=(Delegate<void, Args...>&& _function);
        void operator()(Args... _args);
#pragma endregion operator
    };
#pragma region constructor
    template <typename ... Args>
    Event<Args...>::Event(Delegate<void, Args...>&& _function) { mFunctions.push_back(std::move(_function));  }
    template <typename ... Args>
    Event<Args...>::Event(const Event& _event) { mFunctions = std::move(_event.mFunctions);  }

    template <typename ... Args>
    void Event<Args...>::Invoke(Args... _args)
    {
        this->operator()(_args...);
    }
#pragma endregion constructor
#pragma region operator
    template <typename ... Args>
    void Event<Args...>::operator+=(Delegate<void, Args...>&& _function)
    {
        mFunctions.push_back(std::move(_function));
    }

    template <typename ... Args>
    void Event<Args...>::operator-=(Delegate<void, Args...>&& _function)
    {
        const int& _length = mFunctions.size();
        for (int i = 0; i < _length; ++i)
            if (mFunctions[i] == _function)
            {
                mFunctions.erase(mFunctions.begin() + i);
                break;
            }
    }

    template <typename ... Args>
    void Event<Args...>::operator()(Args... _args)
    {
        for (Delegate<void, Args...> _func : mFunctions)
            _func(_args...);
    }
#pragma endregion operator
    typedef Event<> event;
}
