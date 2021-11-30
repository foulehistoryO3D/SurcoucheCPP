#pragma once
#include <map>
#include <string>

#include "../../Object/Object.h"

namespace System
{
    class Integer;
    
    struct EnumPair : Object
    {
        int mValue;
        const char* mName;

        EnumPair(int _value, const char* _name)
        {
            mValue = _value;
            mName = _name;
        }

        int Value()const { return mValue; }
        const char* Name()const { return mName; }
        
    };
    
    class Enum : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        std::map<const char*, EnumPair> mContainers = std::map<const char*, EnumPair>();
#pragma endregion f/p
#pragma region constructor
    public:
        Enum()=default;
        Enum(std::initializer_list<EnumPair> _pair);
#pragma endregion constructor
#pragma region operator
    public:
        String operator[](const int32 _index);
        Boolean TryParse(const char* _name, Boolean _ignoreCase, Integer& _enum);
#pragma endregion operator
    };
}
