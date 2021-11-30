#include "Enum.h"
#include "../String/String.h"
#include "../Integer/Integer.h"
#include "../Boolean/Boolean.h"

#pragma region constructor
System::Enum::Enum(std::initializer_list<EnumPair> _pair)
{
    for (EnumPair _p : _pair)
        mContainers.insert(std::pair(_p.Name(), _p));
}

#pragma endregion constructor
#pragma region operator

System::String System::Enum::operator[](const int32 _index)
{
    if (_index < 0 || _index > mContainers.size())
        throw OutOfRange("[Enum] out of range");
    
    for (const std::pair<const char*, EnumPair> _p : mContainers)
        if (_p.second.mValue == _index)
            return _p.first;

    return "";
}

System::Boolean System::Enum::TryParse(const char* _name, Boolean _ignoreCase, Integer& _enum)
{
    const String& _str = _name;
    for (const std::pair<const char*, EnumPair> _p : mContainers)
    {
        const String& _str1 = _p.first;
        
        if (_ignoreCase ? _str.EqualsIgnoreCase(_str1) : _str == _str1)
        {
            _enum = _p.second.Value();
            return true;
        }
    }
    _enum = -1;
    return false;
}
#pragma endregion operator
