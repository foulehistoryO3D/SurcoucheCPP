#pragma once
#include "../AsyncEventArgs/AsyncCompletedEventArgs.h"

namespace System
{
    namespace Net
    {
        class DownloadStringCompletedEventArgs : public AsyncCompletedEventArgs
        {
            DECLARE_CLASS_INFO(AsyncCompletedEventArgs)
#pragma region f/p
        private:
            const char* mResult = "";
        public:
            String Result()const;
#pragma endregion f/p
#pragma region constructor
        public:
            DownloadStringCompletedEventArgs()=default;
            DownloadStringCompletedEventArgs(const DownloadStringCompletedEventArgs& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            void SetResult(const String& _result);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
        };
    }
}
