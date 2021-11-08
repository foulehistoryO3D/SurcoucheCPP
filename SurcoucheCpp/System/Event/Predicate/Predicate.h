#pragma once
#include "../../Object/Object.h"
#include "../Delegate/Delegate.h"

namespace System
{
    template<typename Item>
    class Predicate sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
    private:
        Delegate<bool, Item> mFunction = null;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Predicate()=default;
        template<typename Function>
        Predicate(Function _function);
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        bool Invoke(Item _item) { return this->operator()(_item); }
#pragma endregion custom methods
#pragma region operator
    public:
        bool operator()(Item _item)
        {
            return mFunction.Invoke(_item);
        }
#pragma endregion operator
    };

    template <typename Item>
    template <typename Function>
    Predicate<Item>::Predicate(Function _function)
    {
        mFunction = _function;
    }
}
