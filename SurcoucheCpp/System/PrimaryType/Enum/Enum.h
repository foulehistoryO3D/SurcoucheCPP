#pragma once
#include <map>
#include <string>

#include "../../Console/Console.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../../Object/Object.h"
#include "../Boolean/Boolean.h"

namespace System
{
    class Integer;

    template<typename T>
    struct EnumPair : Object
    {
        int mValue;
        T mItem;

        EnumPair(int _value, T _item)
        {
            mValue = _value;
            mItem = _item;
        }

        int Value()const { return mValue; }
        T Item()const { return mItem; }
        
    };

    template<typename T>
    class Enum : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        std::map<const char*, EnumPair<T>> mContainers = std::map<const char*, EnumPair<T>>();
#pragma endregion f/p
#pragma region constructor
    public:
        Enum()=default;
        Enum(std::initializer_list<EnumPair<T>> _pair);
#pragma endregion constructor
#pragma region operator
    public:
        T operator[](const int32 _index);
#pragma endregion operator
    };

    template <typename T>
    Enum<T>::Enum(std::initializer_list<EnumPair<T>> _pair)
    {
        for (EnumPair<T>& _item : _pair)
            mContainers.insert(std::pair<int, EnumPair<T>>(_item.Value(), _item.Item()));
    }

    template <typename T>
    T Enum<T>::operator[](const int32 _index)
    {
        if (_index < 0 || _index > mContainers.size())
            throw OutOfRange("[Enum] out of range !");
        return mContainers[_index];
    }
}
