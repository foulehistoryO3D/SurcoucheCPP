#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Integer/Integer.h"
#include <Windows.h>

#include "../Enum/DayOfWeek/DayOfWeek.h"

namespace System
{
    
class DateTime sealed : public Object
{
    DECLARE_CLASS_INFO(Object)
    REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
private:
    Int mDay = 0;
    Int mMonth = 0;
    Int mYears = 0;
    Int mHour = 0;
    Int mMinute = 0;
    Int mSecond = 0;
    DayOfWeek dayOfWeek = DayOfWeek::Monday;
public:
    // static const DateTime Now;
    DayOfWeek DayOfWeek()const;
#pragma endregion f/p
#pragma region constructor
public:
    DateTime() = default;
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour, const Integer& _minute, const Integer& _seconds);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour, const Integer& _minute);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour);
    DateTime(const Integer& _day, const Integer& _month, const Integer& _years);
    DateTime(const DateTime& _copy);
#pragma endregion constructor
#pragma region custom methods
private:
    int CalculateDayOfWeek() const;
    static DateTime Now_Interval();
public:
    static DateTime Now();
    static DateTime Parse(const string& date);
    static DateTime Convert(SYSTEMTIME _systemTime);
    static DateTime Convert(time_t _systemTime);
    String ToStringFormat(const String& _format =  "y-m-d h:m:s") const;
    Boolean Equals(const DateTime& _other);
    static DateTime FileTimeToDateTime(const FILETIME& _fileTime);
    void AddDay(const Integer& _value);
    void AddMonth(const Integer& _value);
    void AddYears(const Integer& _value);
    void AddSeconds(const Int& _value);
    void AddMinutes(const Int& _value);
    void AddHours(const Int& _value);
#pragma endregion custom methods
#pragma region override
public:
    String ToString() const override;
    Boolean Equals(const object* _obj) override;
    Boolean Equals(const object& _obj) override;
    Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
    DateTime& operator=(const DateTime& _other)
    {
        mDay = std::move(_other.mDay);
        mMonth = std::move(_other.mMonth);
        mYears = std::move(_other.mYears);
        mHour = std::move(_other.mHour);
        mMinute = std::move(_other.mMinute);
        mSecond = std::move(_other.mSecond);
        return *this;
    }
#pragma endregion operator
};
}
