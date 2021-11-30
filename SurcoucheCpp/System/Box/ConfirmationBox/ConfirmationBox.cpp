#include "ConfirmationBox.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"

#pragma region constructor
System::ConfirmationBox::ConfirmationBox(const String& _title, const String& _message)
{
    mTitle = _title;
    mMessage = _message;
}

System::ConfirmationBox::ConfirmationBox(const ConfirmationBox& _copy)
{
    mTitle = std::move(_copy.mTitle);
    mMessage = std::move(_copy.mMessage);
}
#pragma endregion constructor
#pragma region custom methods
System::Boolean System::ConfirmationBox::Open() const
{
    const LPCWSTR& _title = string::ToWString(mTitle)->c_str();
    const LPCWSTR& _message = string::ToWString(mMessage)->c_str();
    const int& _result = MessageBox(nullptr, _message, _title, MB_ICONQUESTION | MB_DEFBUTTON4 | MB_YESNO);
    return _result == 6;
}
#pragma endregion custom methods
#pragma region override
System::String System::ConfirmationBox::ToString() const
{
    return string("title: ") + mTitle + ", Message: " + mMessage;
}

System::Boolean System::ConfirmationBox::Equals(const object* object)
{
    const ConfirmationBox& _box = *dynamic_cast<const ConfirmationBox*>(object);
    return mMessage == _box.mMessage && mTitle == _box.mTitle;
}

System::Boolean System::ConfirmationBox::Equals(const object& object)
{
    const ConfirmationBox& _box = *dynamic_cast<const ConfirmationBox*>(&object);
    return mMessage == _box.mMessage && mTitle == _box.mTitle;
}

size_t System::ConfirmationBox::GetHashCode() const
{
    ConfirmationBox _confirmationBox = *this;
    return std::hash<ConfirmationBox*>{}(&_confirmationBox);
}

System::ConfirmationBox& System::ConfirmationBox::operator=(const ConfirmationBox& _other)
{
    mTitle = std::move(_other.mTitle);
    mMessage = std::move(_other.mMessage);
    return *this;
}
#pragma endregion override
