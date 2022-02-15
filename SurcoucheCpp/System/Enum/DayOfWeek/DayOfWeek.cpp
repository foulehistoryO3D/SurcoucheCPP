#include "DayOfWeek.h"

#pragma region f/p

DayOfWeek const DayOfWeek::Sunday("Sunday");
DayOfWeek const DayOfWeek::Monday("Monday");
DayOfWeek const DayOfWeek::Tuesday("Tuesday");
DayOfWeek const DayOfWeek::Wednesday("Wednesday");
DayOfWeek const DayOfWeek::Thursday("Thursday");
DayOfWeek const DayOfWeek::Friday("Friday");
DayOfWeek const DayOfWeek::Saturday("Saturday");


string DayOfWeek::DayName() const
{
    return dayName;
}
#pragma endregion f/p
#pragma region constructor
DayOfWeek::DayOfWeek(const string& dayName) : SmartEnum<DayOfWeek>()
{
    this->dayName = dayName;
    Register(this);
}

System::String DayOfWeek::ToString() const
{
    return dayName;
}

System::Boolean DayOfWeek::operator==(DayOfWeek other)
{
    return dayName.EqualsIgnoreCase(other.dayName);
}

System::Boolean DayOfWeek::operator!=(DayOfWeek other)
{
    return dayName.EqualsIgnoreCase(other.dayName);
}
#pragma endregion constructor
