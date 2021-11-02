#include "DateTime.h"
#include "../PrimaryType/String/String.h"
#include <time.h>

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
    time_t now = time(nullptr);
    struct tm tstruct;
    char buff[80];
    tstruct = *localtime(&now);
    return now;
}

System::String System::DateTime::ToString(const String& _format) const
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


