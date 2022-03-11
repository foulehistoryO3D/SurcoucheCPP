#include "ElapsedEventArgs.h"

#pragma region f/p
System::DateTime System::Timers::ElapsedEventArgs::SignalTime() const
{
    return mSignalTime;
}
#pragma endregion f/p
#pragma region constructor
System::Timers::ElapsedEventArgs::ElapsedEventArgs(const ElapsedEventArgs& copy) : EventArgs(copy)
{
    mSignalTime = std::move(copy.mSignalTime);
}
#pragma endregion constructor
#pragma region custom methods
void System::Timers::ElapsedEventArgs::SetSignalTime(const DateTime& _dateTime)
{
    mSignalTime = _dateTime;
}
#pragma endregion custom methods
#pragma region override
System::String System::Timers::ElapsedEventArgs::ToString() const
{
    return mSignalTime.ToString();
}

System::Integer System::Timers::ElapsedEventArgs::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override