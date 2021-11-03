#include "DateTime.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include <ctime>


System::DateTime::DateTime(time_t _time)
{
    mTime = _time;
}

System::DateTime::DateTime(const DateTime& _copy)
{
    mTime = _copy.mTime;
}

System::DateTime System::DateTime::Now()
{
    const time_t now = time(nullptr);
    *localtime(&now);
    return DateTime(now);
}

System::String System::DateTime::ToStringFormat(const String& _format) const
{
    if (mTime == time_t()) return "time equal to null";
    if (String::IsNullOrEmpty(_format)) return "format error";
    String _result = "";
    struct tm tstruct;
    char buff[80];
    tstruct = *localtime(&mTime);
    strftime(buff, sizeof buff, _format, &tstruct);
    _result = buff;
    return _result;
}

System::Boolean System::DateTime::Equals(const DateTime& _other)
{
    return mTime == _other.mTime;
}

System::DateTime System::DateTime::FileTimeToDateTime(const FILETIME& _fileTime)
{
    ULARGE_INTEGER ull;
    ull.LowPart = _fileTime.dwLowDateTime;
    ull.HighPart = _fileTime.dwHighDateTime;
    const time_t _time = ull.QuadPart / 10000000ULL - 11644473600ULL;
    return DateTime(_time);
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


