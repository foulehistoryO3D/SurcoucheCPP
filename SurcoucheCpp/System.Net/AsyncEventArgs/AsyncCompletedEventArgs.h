#pragma once
#include "../../System/Event/EventArgs/EventArgs.h"
#include "../DownloadNetException/DownloadNetException.h"

namespace System
{
    class Exception;

    namespace Net
    {
        class AsyncCompletedEventArgs : public EventArgs
        {
            DECLARE_CLASS_INFO(EventArgs)
#pragma region f/p
        protected:
            bool mCancelled = false;
            DownloadNetException mException = DownloadNetException();
            object* mUserState = nullptr;
        public:
            DownloadNetException Error() const;
            Boolean Cancelled() const;
            object* UserState() const;
#pragma endregion f/p
#pragma region constructor
        public:
            AsyncCompletedEventArgs() = default;
            AsyncCompletedEventArgs(const DownloadNetException& _exception, const Boolean& _cancelled, object* _userState);
            AsyncCompletedEventArgs(const AsyncCompletedEventArgs& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            void SetCancelled(const bool& _status);
            void SetUserState(object* _userState);
            void SetError(const DownloadNetException& _exception);
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion custom methods
        };
    }
}
