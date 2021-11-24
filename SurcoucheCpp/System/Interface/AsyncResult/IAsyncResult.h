#pragma once
#include "../../Object/Object.h"

namespace System
{
    namespace Threading
    {
        class WaitHandle;
    }
    class IAsyncResult
    {
    public:
        virtual ~IAsyncResult() = default;
        virtual Boolean IsCompleted()const PURE_VIRTUAL()
        virtual Boolean CompletedSynchronously()const PURE_VIRTUAL()
        virtual Threading::WaitHandle AsyncWaitHandle()const PURE_VIRTUAL()
        virtual object* AsyncState()const PURE_VIRTUAL()
    };
}
