#include "Timer.h"
#include "../ElapsedEventArgs/ElapsedEventArgs.h"

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
    mElapsedEvent->SetSignalTime(DateTime::Now());
    Elapsed(this, mElapsedEvent);
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
