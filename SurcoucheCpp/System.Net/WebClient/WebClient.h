#pragma once
#include <thread>

#include "../../System/Event/Action/Action.h"
#include "../../System/Object/Object.h"
#include "../AsyncEventArgs/AsyncCompletedEventArgs.h"

namespace System
{
    class Uri;
    namespace Net
    {
        class DownloadStringCompletedEventArgs;
        class WebClient : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            std::thread mThread = std::thread();
            bool mIsRunning = false;
#pragma endregion f/p
#pragma region event
        public:
            Action<object*, DownloadStringCompletedEventArgs*> DownloadStringCompleted;
            Action<object*, AsyncCompletedEventArgs*, const String&> DownloadFileCompleted;
            Action<float> OnDownloadProgress;
#pragma endregion event
#pragma region constructor
        public:
            WebClient()=default;
            ~WebClient()override;
#pragma endregion constructor
#pragma region custom methods
        private:
            void DownloadStringAsyncInternal(const Uri& _address);
            void DownloadFileAsyncInternal(const Uri& _address, const String& _pathFile);
        public:
            void DownloadStringAsync(const Uri& _address);
            void DownloadFileAsync(const Uri& _address, const String& _pathFile);

#pragma endregion custom methods
        };
    }
}
