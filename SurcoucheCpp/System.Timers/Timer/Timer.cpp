#include "Timer.h"
#include "../ElapsedEventArgs/ElapsedEventArgs.h"
#include "../../System/PrimaryType/Double/Double.h"

#pragma region constructor
System::Timers::Timer::Timer(const int& _interval)
{
    mElapsedEvent = new ElapsedEventArgs();
    mInterval = Interval(_interval);
}

System::Timers::Timer::Timer(const Timer& _timer)
{
    mElapsedEvent = std::move(_timer.mElapsedEvent);
    Elapsed = std::move(_timer.Elapsed);
    mInterval = std::move(_timer.mInterval);
}

void System::Timers::Timer::SleepThenTimeout()
{
    std::this_thread::sleep_for(mInterval);
    if (!mIsRunning)return;
    mElapsedEvent->SetSignalTime(DateTime::Now);
    Elapsed.Invoke(this, mElapsedEvent);
}

void System::Timers::Timer::Start()
{
    if (mIsRunning) return;
    mIsRunning = true;
    mThread = std::thread(&Timer::Update, this);
}

void System::Timers::Timer::Update()
{
    while(mIsRunning)
        SleepThenTimeout();
}

void System::Timers::Timer::Stop()
{
    mIsRunning = false;
    mThread.join();
}

#pragma endregion constructor
#pragma region override
System::String System::Timers::Timer::ToString() const
{
    return mElapsedEvent != nullptr ? mElapsedEvent->ToString() : string::Empty;
}

System::Integer System::Timers::Timer::GetHashCode() const
{
    const Int& hash = mElapsedEvent != nullptr ? mElapsedEvent->GetHashCode() : Int(0);
    return hash ^ (Double(mInterval.count()).GetHashCode() << 2);
}
#pragma endregion override
#pragma region operator
System::Timers::Timer& System::Timers::Timer::operator=(const Timer& _other)
{
    mElapsedEvent = std::move(_other.mElapsedEvent);
    Elapsed = std::move(_other.Elapsed);
    mInterval = std::move(_other.mInterval);
    return *this;
}
#pragma endregion operator