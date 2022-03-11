#include "Match.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region f/p
System::Collections::Generic::List<System::Text::RegularExpressions::Group> System::Text::RegularExpressions::Match::Groups() const
{
    return mGroups;
}
#pragma endregion f/p
System::Text::RegularExpressions::Match::Match(const bool _success)
{
    mSuccess = _success;
}

System::Text::RegularExpressions::Match::Match(const Match& copy) : Group(copy)
{
    mCaptureCollection = std::move(copy.mCaptureCollection);
    mName = std::move(copy.mName);
    mSuccess = std::move(copy.mSuccess);
    mValue = std::move(copy.mValue);
    mIndex = std::move(copy.mIndex);
    mLength = std::move(copy.mLength);
    mGroups = std::move(copy.mGroups);
}

void System::Text::RegularExpressions::Match::AddGroup(const String& _key, const Collections::Generic::List<String>& _value, const Integer& _index)
{
    mGroups.Add(Group(_key, _value, _index));
}

void System::Text::RegularExpressions::Match::AddGroup(const String& _key, const String& _value, const Integer& _index)
{
    mGroups.Add(Group(_key, _value, _index));
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

System::Integer System::Text::RegularExpressions::Match::GetHashCode() const
{
    return super::GetHashCode() ^ (mGroups.GetHashCode() << 2);
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
