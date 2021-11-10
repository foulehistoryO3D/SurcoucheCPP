#include "Uri.h"
#include "../PrimaryType/String/String.h"

#pragma region f/p
LPCWSTR System::Uri::GetUriWSTR() const
{
    return String::ToWString(mUri)->c_str();
}
#pragma endregion f/p
#pragma region constructor
System::Uri::Uri(const String& _uri)
{
    mUri = _uri;
}

System::Uri::Uri(const Uri& _copy)
{
    mUri = std::move(_copy.mUri);
}
#pragma endregion constructor