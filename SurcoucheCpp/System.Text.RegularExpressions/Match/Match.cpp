#include "Match.h"

#pragma region f/p
System::Text::RegularExpressions::GroupCollection System::Text::RegularExpressions::Match::Groups() const
{
    return mGroups;
}
#pragma endregion f/p
System::Text::RegularExpressions::Match::Match(const bool _success)
{
    mSuccess = _success;
}

System::Text::RegularExpressions::Match::Match(const Match& _copy)
{
    mCaptureCollection = std::move(_copy.mCaptureCollection);
    mName = std::move(_copy.mName);
    mSuccess = std::move(_copy.mSuccess);
    mValue = std::move(_copy.mValue);
    mIndex = std::move(_copy.mIndex);
    mLength = std::move(_copy.mLength);
    mGroups = std::move(_copy.mGroups);
}

void System::Text::RegularExpressions::Match::AddGroup(const String& _key, const Group& _group)
{
    mGroups.Add(_key, _group);
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

System::Text::RegularExpressions::Match System::Text::RegularExpressions::Match::operator=(const Match& _other)
{
    mCaptureCollection = std::move(_other.mCaptureCollection);
    mName = std::move(_other.mName);
    mSuccess = std::move(_other.mSuccess);
    mValue = std::move(_other.mValue);
    mIndex = std::move(_other.mIndex);
    mLength = std::move(_other.mLength);
    mGroups = std::move(_other.mGroups);
    return *this;
}
