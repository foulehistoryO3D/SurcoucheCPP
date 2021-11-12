#include "TimeZone.h"
#include <ctime>

#include "../DateTime/DateTime.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"

#pragma region constructor
System::TimeZone::TimeZone(const ETimeZoneName& _timeZone)
{
    mTimeZone = _timeZone;
    Init();
}

System::TimeZone::TimeZone(const TimeZone& _copy)
{
    mResult = std::move(_copy.mResult);
    mTime = std::move(_copy.mTime);
    mTimeZone = std::move(_copy.mTimeZone);
    mTimeZoneName = std::move(_copy.mTimeZoneName);
}
#pragma endregion constructor
#pragma region custom methods
void System::TimeZone::Init()
{
    DYNAMIC_TIME_ZONE_INFORMATION _timeZoneInformation = DYNAMIC_TIME_ZONE_INFORMATION();
    memset(&_timeZoneInformation, 0, sizeof _timeZoneInformation);
    mResult = EnumDynamicTimeZoneInformation((int)mTimeZone, &_timeZoneInformation);
    if (mResult != ERROR_SUCCESS) return;
    SYSTEMTIME _systemtime = {0};
    SYSTEMTIME _localTime = {0};
    GetSystemTime(&_systemtime);
    SystemTimeToTzSpecificLocalTimeEx(&_timeZoneInformation, &_systemtime, &_localTime);
    WCHAR _time[250] = {0};
    GetTimeFormatEx(LOCALE_NAME_USER_DEFAULT, 0, &_localTime, L"HH':'mm':'ss tt", _time, 250);
    mTime = ConvertSystemTime(_localTime);
    mTimeZoneName = string::WStringToString(_timeZoneInformation.TimeZoneKeyName);
}

time_t System::TimeZone::ConvertSystemTime(SYSTEMTIME _time)
{
    std::tm _tm = std::tm();
    _tm.tm_sec = _time.wSecond;
    _tm.tm_min = _time.wMinute;
    _tm.tm_hour = _time.wHour;
    _tm.tm_mday = _time.wDay;
    _tm.tm_mon = _time.wMonth - 1;
    _tm.tm_year = _time.wYear - 1900;
    _tm.tm_isdst = -1;
    return std::mktime(&_tm);;
}

System::DateTime System::TimeZone::Time() const
{
    return DateTime::Convert(mTime);
}

System::String System::TimeZone::TimeZoneName() const
{
    return mTimeZoneName;
}
#pragma endregion custom
#pragma region override
System::String System::TimeZone::ToString() const
{
    return string("TimeZone: ") + mTimeZoneName + ", " + Time().ToString();
}

System::Boolean System::TimeZone::Equals(const object* object)
{
    return object == this;
}

System::Boolean System::TimeZone::Equals(const object& object)
{
    return &object == this;
}

size_t System::TimeZone::GetHashCode() const
{
    TimeZone _timeZone = *this;
    return std::hash<TimeZone*>{}(&_timeZone);
}
#pragma endregion override
