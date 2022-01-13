﻿#pragma once
#include <map>
#include <string>

#include "../../Console/Console.h"
#include "../../Object/Object.h"
#include "../Integer/Integer.h"

namespace System
{
    class Integer;

    template<typename T>
    class SmartEnum : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        inline static int mCurrentValue = 0;
        inline static std::vector<T*> mValues = std::vector<T*>();
    protected:
        Int value = 0;
    public:
        inline static std::vector<T> Values()
        {
            std::vector<T> result = std::vector<T>();
            for (const T* _value : mValues)
                result.push_back(*_value);
            return result;
        }
#pragma endregion f/p
#pragma region constructor
    public:
        // SmartEnum()=default;
        explicit SmartEnum(System::Integer _value = mCurrentValue++);
        void Register(T* _enum);
#pragma endregion constructor
#pragma region operator
    public:
        virtual operator Int() const  {  return value; }

        virtual void operator=(const Int& _value) { value = _value; }
#pragma endregion operator
    };
    
    template <typename T>
    SmartEnum<T>::SmartEnum(System::Integer _value)
    {
        value = _value;
    }
    template <typename T>
    void SmartEnum<T>::Register(T* _enum)
    {
        mValues.push_back(_enum);
    }

}
