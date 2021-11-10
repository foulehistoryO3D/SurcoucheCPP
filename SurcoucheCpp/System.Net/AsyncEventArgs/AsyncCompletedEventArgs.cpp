#include "AsyncCompletedEventArgs.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

#pragma region f/p
System::Exception System::Net::AsyncCompletedEventArgs::Error() const
{
    return mException;
}

System::Boolean System::Net::AsyncCompletedEventArgs::Cancelled() const
{
    return mCancelled;
}

System::object* System::Net::AsyncCompletedEventArgs::UserState() const
{
    return mUserState;
}
#pragma endregion f/p
#pragma region constructor
System::Net::AsyncCompletedEventArgs::AsyncCompletedEventArgs(const Exception& _exception, const Boolean& _cancelled,
    object* _userState)
{
    mException = _exception;
    mCancelled = _cancelled;
    mUserState = _userState;
}

System::Net::AsyncCompletedEventArgs::AsyncCompletedEventArgs(const AsyncCompletedEventArgs& _copy)
{
    mException = std::move(_copy.mException);
    mCancelled = std::move(_copy.mCancelled);
    mUserState = std::move(_copy.mUserState);
}
#pragma endregion constructor
#pragma region custom methods
void System::Net::AsyncCompletedEventArgs::SetCancelled(const bool& _status)
{
    mCancelled = _status;
}

void System::Net::AsyncCompletedEventArgs::SetUserState(object* _userState)
{
    mUserState = _userState;
}

void System::Net::AsyncCompletedEventArgs::SetError(const Exception& _exception)
{
    mException = _exception;
}
#pragma endregion custom methods