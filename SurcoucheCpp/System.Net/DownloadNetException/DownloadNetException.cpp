#include "DownloadNetException.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region f/p
System::String System::Net::DownloadNetException::Message() const
{
    return mMessage;
}
#pragma endregion f/p
#pragma region constructor
System::Net::DownloadNetException::DownloadNetException(const String& _message)
{
    mMessage = std::move(_message);
}

System::Net::DownloadNetException::DownloadNetException(const DownloadNetException& _copy)
{
    mMessage = std::move(_copy.mMessage);
}
#pragma endregion constructor
#pragma region override
System::String System::Net::DownloadNetException::ToString() const
{
    return mMessage;
}

System::Boolean System::Net::DownloadNetException::Equals(const object* object)
{
    const DownloadNetException& _exception = static_cast<const DownloadNetException&>(*object);
    return mMessage = _exception.mMessage;
}

System::Boolean System::Net::DownloadNetException::Equals(const object& object)
{
    const DownloadNetException& _exception = static_cast<const DownloadNetException&>(object);
    return mMessage = _exception.mMessage;
}

System::Integer System::Net::DownloadNetException::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override