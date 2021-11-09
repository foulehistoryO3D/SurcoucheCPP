#include "ElapsedEventArgs.h"

#pragma region f/p
System::DateTime System::Timers::ElapsedEventArgs::SignalTime() const
{
    return mSignalTime;
}
#pragma endregion f/p
#pragma region constructor
System::Timers::ElapsedEventArgs::ElapsedEventArgs(const ElapsedEventArgs& _copy)
{
    mSignalTime = std::move(_copy.mSignalTime);
}
#pragma endregion constructor
#pragma region custom methods
void System::Timers::ElapsedEventArgs::SetSignalTime(const DateTime& _dateTime)
{
    mSignalTime = _dateTime;
}
#pragma endregion custom methods