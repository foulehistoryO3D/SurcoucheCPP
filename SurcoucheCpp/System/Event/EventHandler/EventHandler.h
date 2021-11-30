#pragma once
#include <type_traits>
#include "../../Object/Object.h"
#include "../Delegate/delegates.h"


namespace System
{
    template<class T>
    using IsSame = std::enable_if_t<std::is_base_of_v<EventArgs, T>>;
    
    template<typename Event, class = IsSame<Event>>
    class EventHandler : public Object
    {
        DECLARE_CLASS_INFO(Object)
    private:
        std::vector<Delegate<void, object*, Event*>> mFunctions = std::vector<Delegate<void, object*, Event*>>();
    public:
        EventHandler() = default;
        template<typename Function>
        EventHandler(Function _function);
        EventHandler(nullptr_t);
    public:
        void Invoke(object* _sender, Event* _args);
    public:
        void operator+=(Delegate<void, object*, Event*>&& _function);
        void operator-=(Delegate<void, object*, Event*>&& _function);
        void operator()(object* _sender, Event* _event);
        EventHandler& operator=(const EventHandler& _other);
        void operator=(Delegate<void, object*, Event*>&& _function);
        void operator=(nullptr_t);
    };


#pragma region constructor/destructor

    template <typename Event, class T0>
    template <typename Function>
    ::System::EventHandler<Event, T0>::EventHandler(Function _function)
    {
        mFunctions.push_back(std::move(_function));
    }
    
    template <typename Event, class T0>
    ::System::EventHandler<Event, T0>::EventHandler(nullptr_t)
    {
        mFunctions = std::vector<Delegate<void, object*, Event*>>();
    }

    template <typename Event, class T0>
    FORCEINLINE void ::System::EventHandler<Event, T0>::Invoke(object* _sender, Event* _args)
    {
        this->operator()(_sender, _args);
    }
#pragma endregion constructor/destructor
#pragma region operator
    template <typename Event, class T0>
    FORCEINLINE void ::System::EventHandler<Event, T0>::operator+=(Delegate<void, object*, Event*>&& _function)
    {
        mFunctions.push_back(std::move(_function));
    }
    template <typename Event, class T0>
    FORCEINLINE void ::System::EventHandler<Event, T0>::operator-=(Delegate<void, object*, Event*>&& _function)
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
    template <typename Event, class T0>
    FORCEINLINE void ::System::EventHandler<Event, T0>::operator()(object* _sender, Event* _event)
    {
        const int _length = mFunctions.size();
        for (int i = 0; i < _length; ++i)
            mFunctions[i].Invoke(_sender, _event);
    }

    template <typename Event, class T0>
    EventHandler<Event, T0>& EventHandler<Event, T0>::operator=(const EventHandler& _other)
    {
        mFunctions = std::move(_other.mFunctions);
        return *this;
    }


    template <typename Event, class T0>
    void ::System::EventHandler<Event, T0>::operator=(Delegate<void, object*, Event*>&& _function)
    {
        mFunctions.clear();
        mFunctions.push_back(_function);
    }

    template <typename Event, class T0>
    FORCEINLINE void ::System::EventHandler<Event, T0>::operator=(nullptr_t)
    {
        mFunctions.clear();
    }
#pragma endregion operator
}
