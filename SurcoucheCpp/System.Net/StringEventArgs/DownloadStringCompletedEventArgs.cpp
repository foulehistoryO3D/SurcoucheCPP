#include "DownloadStringCompletedEventArgs.h"
#include "../../System/PrimaryType/String/String.h"

#pragma region f/p
System::String System::Net::DownloadStringCompletedEventArgs::Result() const
{
    return mResult;
}
#pragma endregion f/p
#pragma region constructor
System::Net::DownloadStringCompletedEventArgs::DownloadStringCompletedEventArgs(
    const DownloadStringCompletedEventArgs& _copy)
{
    mResult = std::move(_copy.mResult);
}
#pragma endregion constructor
#pragma region custom methods
void System::Net::DownloadStringCompletedEventArgs::SetResult(const String& _result)
{
    mResult = _result;
}
#pragma endregion custom methods