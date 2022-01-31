#pragma once
#include <chrono>
#include <thread>

#include "../../System/Object/Object.h"
#include "../../System/Event/Action/Action.h"

namespace System
{
    namespace Timers
    {
        class ElapsedEventArgs;
#pragma region Typedef
        typedef std::chrono::milliseconds Interval;
#pragma endregion Typedef
        class Timer : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            std::thread mThread = std::thread();
            Interval mInterval = Interval(0);
            ElapsedEventArgs* mElapsedEvent = nullptr;
            bool mIsRunning = false;
        public:
            Action<object*, ElapsedEventArgs*> Elapsed = Action<object*, ElapsedEventArgs*>();
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            Timer()=default;
            Timer(const int& _interval);
            Timer(const Timer& _timer);
#pragma endregion constructor/destructor
#pragma region custom methods
        private:
            void SleepThenTimeout();
        public:
            void Start();
            void Update();
            void Stop();
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
            Timer& operator=(const Timer& _other);
#pragma endregion operator
        };
    }
}
