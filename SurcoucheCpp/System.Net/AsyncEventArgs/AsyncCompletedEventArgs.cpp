#include "AsyncCompletedEventArgs.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region f/p
System::Net::DownloadNetException System::Net::AsyncCompletedEventArgs::Error() const
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
System::Net::AsyncCompletedEventArgs::AsyncCompletedEventArgs(const DownloadNetException& _exception, const Boolean& _cancelled,
    object* _userState)
{
    mException = _exception;
    mCancelled = _cancelled;
    mUserState = _userState;
}

System::Net::AsyncCompletedEventArgs::AsyncCompletedEventArgs(const AsyncCompletedEventArgs& copy) : EventArgs(copy)
{
    mException = std::move(copy.mException);
    mCancelled = std::move(copy.mCancelled);
    mUserState = std::move(copy.mUserState);
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

void System::Net::AsyncCompletedEventArgs::SetError(const DownloadNetException& _exception)
{
    mException = std::move(_exception);
}

System::String System::Net::AsyncCompletedEventArgs::ToString() const
{
    return EventArgs::ToString();
}

System::Integer System::Net::AsyncCompletedEventArgs::GetHashCode() const
{
    return mUserState->GetHashCode() ^ (Bool(mCancelled).GetHashCode() << 2) ^ (mException.GetHashCode() >> 2);
}
#pragma endregion custom methods
