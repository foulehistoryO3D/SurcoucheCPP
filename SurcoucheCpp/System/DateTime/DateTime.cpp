#include "DateTime.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/Integer/Integer.h"
#include <ctime>

System::DateTime::DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour,
    const Integer& _minute, const Integer& _seconds)
{
    mDay = _day;
    mMonth = _month;
    mYears = _years;
    mHour = _hour;
    mMinute = _minute;
    mSecond = _seconds;
}

System::DateTime::DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour,
    const Integer& _minute) : DateTime(_day, _month, _years, _hour, _minute, 0) {}

System::DateTime::DateTime(const Integer& _day, const Integer& _month, const Integer& _years, const Integer& _hour)
    : DateTime(_day, _month, _years, _hour, 0, 0){}

System::DateTime::DateTime(const Integer& _day, const Integer& _month, const Integer& _years)
    : DateTime(_day, _month, _years, 0, 0, 0){}

System::DateTime::DateTime(const DateTime& _copy)
{
    mDay = std::move(_copy.mDay);
    mMonth = std::move(_copy.mMonth);
    mYears = std::move(_copy.mYears);
    mHour = std::move(_copy.mHour);
    mMinute = std::move(_copy.mMinute);
    mSecond = std::move(_copy.mSecond);
}

System::DateTime System::DateTime::Now()
{
    const time_t now = time(nullptr);
    const std::tm _tm = *localtime(&now);
    return DateTime(_tm.tm_mday, _tm.tm_mon, _tm.tm_year, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
}

System::DateTime System::DateTime::Convert(SYSTEMTIME _systemTime)
{
    std::tm _tm = std::tm();
    _tm.tm_sec = _systemTime.wSecond;
    _tm.tm_min = _systemTime.wMinute;
    _tm.tm_hour = _systemTime.wHour;
    _tm.tm_mday = _systemTime.wDay;
    _tm.tm_mon = _systemTime.wMonth - 1;
    _tm.tm_year = _systemTime.wYear - 1900;
    _tm.tm_isdst = -1;
    return DateTime(_tm.tm_mday, _tm.tm_mon, _tm.tm_year, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
}

System::String System::DateTime::ToStringFormat(const String& _format) const
{
    if (String::IsNullOrEmpty(_format)) return "format error";
    String _result = "";
    // struct tm tstruct;
    // char buff[80];
    // tstruct = *localtime(&mTime);
    // strftime(buff, sizeof buff, _format, &tstruct);
    // _result = buff;
    
    return _result;
}

System::Boolean System::DateTime::Equals(const DateTime& _other)
{
    return mDay == _other.mDay && mMonth == _other.mMonth && mYears == _other.mYears
    && mHour == _other.mHour && mMinute == _other.mMinute && mSecond == _other.mSecond;
}

System::DateTime System::DateTime::FileTimeToDateTime(const FILETIME& _fileTime)
{
    SYSTEMTIME _time;
    FileTimeToSystemTime(&_fileTime, &_time);
    return Convert(_time);
}

#pragma region override
System::String System::DateTime::ToString() const
{
    return ToStringFormat();
}

System::Boolean System::DateTime::Equals(const object* _object)
{
    const DateTime& _dateTime = *dynamic_cast<const DateTime*>(_object);
    return Equals(_dateTime);
}

System::Boolean System::DateTime::Equals(const object& _object)
{
    const DateTime& _dateTime = *dynamic_cast<const DateTime*>(&_object);
    return Equals(_dateTime);
}

size_t System::DateTime::GetHashCode() const
{
    DateTime _time = *this;
    return std::hash<DateTime*>{}(&_time);
}
#pragma endregion override


