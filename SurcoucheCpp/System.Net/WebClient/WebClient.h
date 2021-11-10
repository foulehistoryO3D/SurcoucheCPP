#pragma once
#include "../../System/Event/Delegate/Delegate.h"
#include "../../System/Object/Object.h"

namespace System
{
    class Uri;
    namespace Net
    {
        class DownloadStringCompletedEventArgs;
        class WebClient : public Object
        {
#pragma region event
        public:
            Delegate<void, object*, DownloadStringCompletedEventArgs*> DownloadStringCompleted;
#pragma endregion event
#pragma region constructor
        public:
            WebClient()=default;
#pragma endregion constructor
#pragma region custom methods
        public:
            void DownloadStringAsync(const Uri& _address);
#pragma endregion custom methods
        };
    }
}
