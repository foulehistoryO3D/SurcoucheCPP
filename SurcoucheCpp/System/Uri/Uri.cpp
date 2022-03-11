#include "Uri.h"
#include "../PrimaryType/String/String.h"

#pragma region f/p
LPCWSTR System::Uri::GetUriWSTR() const
{
    return String::ToWString(mUri)->c_str();
}

System::String System::Uri::ToString() const
{
    return mUri;
}

System::Integer System::Uri::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion f/p
#pragma region constructor
System::Uri::Uri(const String& _uri)
{
    mUri = _uri;
}

System::Uri::Uri(const Uri& copy) : Object(copy)
{
    mUri = std::move(copy.mUri);
}
#pragma endregion constructor