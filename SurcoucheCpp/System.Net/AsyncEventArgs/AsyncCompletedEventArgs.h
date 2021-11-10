#pragma once
#include "../../System/Event/EventArgs/EventArgs.h"
#include "../../System/Exception/Exception/Exception.h"

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
            Exception mException = Exception();
            object* mUserState = null;
        public:
            Exception Error() const;
            Boolean Cancelled() const;
            object* UserState() const;
#pragma endregion f/p
#pragma region constructor
        public:
            AsyncCompletedEventArgs() = default;
            AsyncCompletedEventArgs(const Exception& _exception, const Boolean& _cancelled, object* _userState);
            AsyncCompletedEventArgs(const AsyncCompletedEventArgs& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            void SetCancelled(const bool& _status);
            void SetUserState(object* _userState);
            void SetError(const Exception& _exception);
#pragma endregion custom methods
        };
    }
}
