#pragma once
#include <functional>
#include <iostream>

#include "../../Object/Object.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/Integer/Integer.h"

namespace System
{
    template <typename Res, typename... Args>
    class Delegate : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        std::function<Res(Args ...)> mFunction = nullptr;
    public:
        std::function<Res(Args ...)> Function() const { return mFunction; }
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Delegate() = default;

        template <typename Function>
        Delegate(Function _function) { mFunction = std::move(_function); }

        Delegate(nullptr_t);
#pragma endregion constructor/destructor
#pragma region custom methods
        Res Invoke(Args ... _args) { return this->operator()(_args...); }
#pragma endregion custom methods
#pragma region override
    public:
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        Res operator()(Args ... _args)
        {
            if (mFunction == nullptr) return Res();
            return mFunction(_args...);
        }

        Delegate& operator=(const Delegate& _other)
        {
            mFunction = std::move(_other.mFunction);
            return *this;
        }

        template <typename Function>
        Delegate& operator=(Function _func)
        {
            mFunction = _func;
            return *this;
        }

        Delegate& operator=(nullptr_t)
        {
            mFunction = nullptr;
            return *this;
        }

#pragma endregion operator
    };
#pragma region constructor
    template <typename Res, typename ... Args>
    Delegate<Res, Args...>::Delegate(nullptr_t)
    {
        mFunction = nullptr;
    }
#pragma endregion constructor
#pragma region override
    template <typename Res, typename ... Args>
    Boolean Delegate<Res, Args...>::Equals(const object* object)
    {
        const Delegate& _del = *dynamic_cast<const Delegate*>(object);
        return mFunction.template target<Res(Args ...)>() == _del.mFunction.template target<Res(Args ...)>();
    }

    template <typename Res, typename ... Args>
    Boolean Delegate<Res, Args...>::Equals(const object& object)
    {
        const Delegate& _del = *dynamic_cast<const Delegate*>(&object);
        return mFunction.template target<Res(Args ...)>() == _del.mFunction.template target<Res(Args ...)>();
    }

    template <typename Res, typename ... Args>
    Integer Delegate<Res, Args...>::GetHashCode() const
    {
        Delegate _del = *this;
        return std::hash<Delegate*>{}(&_del);
    }
#pragma endregion override
}
