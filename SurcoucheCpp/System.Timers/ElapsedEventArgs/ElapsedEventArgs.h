#pragma once
#include "../../System/DateTime/DateTime.h"
#include "../../System/Event/EventArgs/EventArgs.h"

namespace System
{
    namespace Timers
    {
        class ElapsedEventArgs : public EventArgs
        {
            DECLARE_CLASS_INFO(EventArgs)
#pragma region f/p
        private:
            DateTime mSignalTime = DateTime();
        public:
            DateTime SignalTime()const;
#pragma endregion f/p
#pragma region constructor
        public:
            ElapsedEventArgs()=default;
            ElapsedEventArgs(const ElapsedEventArgs& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            void SetSignalTime(const DateTime& _dateTime);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
        };
    }
}
