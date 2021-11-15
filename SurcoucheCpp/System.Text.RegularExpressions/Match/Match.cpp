#include "Match.h"

#pragma region f/p
System::Text::RegularExpressions::GroupCollection System::Text::RegularExpressions::Match::Groups() const
{
    return mGroups;
}
#pragma endregion f/p
System::Text::RegularExpressions::Match::Match(const int& _index, const String& _value, const bool _success) : Group(_index, _value, CaptureCollection())
{
    mSuccess = _success;
}

System::Text::RegularExpressions::Match::Match(const Match& _copy) : Group(_copy)
{
    mGroups = std::move(_copy.mGroups);
}

System::String System::Text::RegularExpressions::Match::ToString() const
{
    return super::ToString();
}

System::Boolean System::Text::RegularExpressions::Match::Equals(const object* object)
{
    const Match& _other = *dynamic_cast<const Match*>(object);
    return super::Equals(object) && mGroups == _other.mGroups;
}

System::Boolean System::Text::RegularExpressions::Match::Equals(const object& object)
{
    const Match& _other = *dynamic_cast<const Match*>(&object);
    return super::Equals(object) && mGroups == _other.mGroups;
}

size_t System::Text::RegularExpressions::Match::GetHashCode() const
{
    return Group::GetHashCode();
}

System::Text::RegularExpressions::Match& System::Text::RegularExpressions::Match::operator=(const Match& _other)
{
    return *this;
}
