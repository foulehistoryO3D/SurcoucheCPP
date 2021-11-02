#pragma once
#include "../Object/Object.h"

namespace System
{
    
class DateTime : public Object
{
private:
    time_t mTime = time_t();
public:
    DateTime() = default;
    DateTime(time_t _time);
    DateTime(const DateTime& _copy);
public:
    static DateTime Now();
    String ToString(const String& _format) const;
};
}
