#pragma once
#include <map>
#include <string>

#include "../../Console/Console.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../../Object/Object.h"
#include "../Boolean/Boolean.h"
#include "../Integer/Integer.h"

namespace System
{
    class Integer;

    template<typename T>
    struct EnumPair : Object
    {
        Integer mValue;
        T mItem;

        EnumPair(T _item)
        {
            mItem = _item;
            mValue = 0;
        }

        int Value()const { return mValue; }
        T Item()const { return mItem; }

        EnumPair& operator=(const Integer& _value)
        {
            mValue = _value;
            return *this;
        }
    };

    template<typename T>
    class Enum : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    protected:
        Int value = 0;
    private:
        std::map<int, EnumPair<T>> mContainers = std::map<int, EnumPair<T>>();
#pragma endregion f/p
#pragma region constructor
    public:
        Enum()=default;
        Enum(std::initializer_list<EnumPair<T>> _pair);
#pragma endregion constructor
#pragma region operator
    public:
        T operator[](const int32 _index);
        virtual operator Int() const
        {
            return value;
        }

        virtual void operator=(const Int& _value)
        {
            value = _value;
        }
#pragma endregion operator
    };

    template <typename T>
    Enum<T>::Enum(std::initializer_list<EnumPair<T>> _pair)
    {
        int32 index = 0;
        for (const EnumPair<T>& _item : _pair)
        {
            EnumPair<T> _enumValue = _item;
            _enumValue = index;
            mContainers.insert(std::pair<int, EnumPair<T>>(index, _enumValue));
            index++;
        }
    }

    template <typename T>
    T Enum<T>::operator[](const int32 _index)
    {
        if (_index < 0 || _index > mContainers.size())
            throw OutOfRange("[Enum] out of range !");
        return mContainers[_index];
    }
}
