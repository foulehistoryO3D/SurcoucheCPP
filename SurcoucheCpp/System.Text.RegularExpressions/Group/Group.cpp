#include "Group.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

#pragma region f/p
System::Text::RegularExpressions::CaptureCollection System::Text::RegularExpressions::Group::Captures() const
{
    return mCaptureCollection;
}

System::String System::Text::RegularExpressions::Group::Name() const
{
    return mName;
}

System::Boolean System::Text::RegularExpressions::Group::Success() const
{
    return mSuccess;
}
#pragma endregion f/p
#pragma region constructor
System::Text::RegularExpressions::Group::Group(const int& _index, const String& _value,
                                               const CaptureCollection& _collection) : Capture(_index, _value)
{
    mCaptureCollection = std::move(_collection);
}

System::Text::RegularExpressions::Group::Group(const Group& _copy) : Capture(_copy)
{
    mCaptureCollection = std::move(_copy.mCaptureCollection);
}

System::String System::Text::RegularExpressions::Group::ToString() const
{
    return mValue;
}

System::Boolean System::Text::RegularExpressions::Group::Equals(const object* object)
{
    const Group& _group = *dynamic_cast<const Group*>(object);
    return super::Equals(object) && mName == _group.mName && mCaptureCollection == _group.mCaptureCollection;
}

System::Boolean System::Text::RegularExpressions::Group::Equals(const object& object)
{
    const Group& _group = *dynamic_cast<const Group*>(&object);
    return super::Equals(object) && mName == _group.mName && mCaptureCollection == _group.mCaptureCollection;
}

size_t System::Text::RegularExpressions::Group::GetHashCode() const
{
    Group _group = *this;
    return std::hash<Group*>{}(&_group);
}
#pragma endregion constructor
