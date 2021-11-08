#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include <Windows.h>

namespace System
{
    
class DateTime : public Object
{
    DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
    time_t mTime = time_t();
#pragma endregion f/p
#pragma region constructor
public:
    DateTime() = default;
    DateTime(time_t _time);
    DateTime(const DateTime& _copy);
#pragma endregion constructor
#pragma region custom methods
public:
    static DateTime Now();
    static DateTime Convert(SYSTEMTIME _systemTime);
    String ToStringFormat(const String& _format =  "%d-%m-%Y %H:%M:%S") const;
    Boolean Equals(const DateTime& _other);
    static DateTime FileTimeToDateTime(const FILETIME& _fileTime); 
#pragma endregion custom methods
#pragma region override
public:
    String ToString() const override;
    Boolean Equals(const object* _obj) override;
    Boolean Equals(const object& _obj) override;
    size_t GetHashCode() const override;
#pragma endregion override
};
}
