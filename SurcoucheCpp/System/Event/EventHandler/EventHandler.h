#pragma once
#include "../../Object/Object.h"
#include "../Delegate/delegates.h"


namespace System
{
    template<typename Event>
    class EventHandler : public Object
    {
        DECLARE_CLASS_INFO(Object)
    private:
        std::vector<Delegate<void, object*, Event*>> mFunctions = std::vector<Delegate<void, object*, Event*>>();
    public:
        EventHandler() = default;
    public:
        void Invoke(object* _sender, Event* _args);
    public:
        void operator+=(Delegate<void, object*, Event*>&& _function);
        void operator-=(Delegate<void, object*, Event*>&& _function);
        void operator()(object* _sender, Event* _event);
    };
#pragma region constructor/destructor
    template<typename Event>
    inline void EventHandler<Event>::Invoke(object* _sender, Event* _args)
    {
        this->operator()(_sender, _args);
    }
#pragma endregion constructor/destructor
#pragma region operator
    template<typename Event>
    FORCEINLINE void EventHandler<Event>::operator+=(Delegate<void, object*, Event*>&& _function)
    {
        mFunctions.push_back(std::move(_function));
    }
    template<typename Event>
    FORCEINLINE void EventHandler<Event>::operator-=(Delegate<void, object*, Event*>&& _function)
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
    template<typename Event>
    FORCEINLINE void EventHandler<Event>::operator()(object* _sender, Event* _event)
    {
        const int _length = mFunctions.size();
        for (int i = 0; i < _length; ++i)
            mFunctions[i].Invoke(_sender, _event);
    }
#pragma endregion operator
}
