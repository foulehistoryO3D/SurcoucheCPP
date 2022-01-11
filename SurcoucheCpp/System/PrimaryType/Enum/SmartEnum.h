#pragma once
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
    protected:
        Int value = 0;
    public:
        Int Value()const;
#pragma endregion f/p
#pragma region constructor
    public:
        // Enum()=default;
        explicit SmartEnum(System::Integer _value = mCurrentValue++);
#pragma endregion constructor
#pragma region operator
    public:
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
    Int SmartEnum<T>::Value() const
    {
        return value;
    }
    
    template <typename T>
    SmartEnum<T>::SmartEnum(System::Integer _value)
    {
        value = _value;
    }
}
