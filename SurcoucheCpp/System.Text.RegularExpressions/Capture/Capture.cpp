#include "Capture.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region f/p
System::String System::Text::RegularExpressions::Capture::Value() const
{
    return mValue;
}

System::Integer System::Text::RegularExpressions::Capture::Index() const
{
    return mIndex;
}

System::Integer System::Text::RegularExpressions::Capture::Length() const
{
    return mLength;
}
#pragma endregion f/p
#pragma region constructor

System::Text::RegularExpressions::Capture::Capture(const Capture& _copy)
{
    mIndex = std::move(_copy.mIndex);
    mValue = std::move(_copy.mValue);
    mLength = std::move(_copy.mLength);
}
#pragma endregion constructor
#pragma region custom methods
void System::Text::RegularExpressions::Capture::SetIndex(const int _index)
{
    mIndex = _index;
}

void System::Text::RegularExpressions::Capture::SetValue(const String& _value)
{
    mValue = std::move(_value);
    mLength = std::move(_value.Length());
}
#pragma endregion custom methods
#pragma region override
System::String System::Text::RegularExpressions::Capture::ToString() const
{
    return mValue;
}

System::Boolean System::Text::RegularExpressions::Capture::Equals(const object* object)
{
    const Capture& _other = *dynamic_cast<const Capture*>(object);
    return mValue == _other.mValue && mIndex == _other.mIndex && mLength == _other.mLength;
    
}

System::Boolean System::Text::RegularExpressions::Capture::Equals(const object& object)
{
    const Capture& _other = *dynamic_cast<const Capture*>(&object);
    return mValue == _other.mValue && mIndex == _other.mIndex && mLength == _other.mLength;
}

size_t System::Text::RegularExpressions::Capture::GetHashCode() const
{
    Capture _capture = *this;
    return std::hash<Capture*>{}(&_capture);
}
#pragma endregion override
