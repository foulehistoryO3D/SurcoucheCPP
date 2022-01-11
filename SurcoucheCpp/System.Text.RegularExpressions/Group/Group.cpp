#include "Group.h"

#include <regex>

#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"

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

System::Text::RegularExpressions::Group::Group(const String& _key,  const Collections::Generic::List<String>& _values, const Integer& _index)
{
    mValue = std::move(_key);
    mIndex = std::move(_index);
    string _str = string::Empty;
    _str.Join(_values);
    const int& _count = _values.Count();
    int _length = 0;
    for (int i = 0; i < _count; ++i)
    {
        std::smatch _match = std::smatch();
        std::regex _regex = std::regex(_values[i].ToCstr());
        std::string _s = std::string(_str.ToCstr());
        if (std::regex_search(_s, _match, _regex))
        {
            Capture _capture = Capture();
            _str = _str.SubString(_values[i].Length(), _str.Length());
            _capture.SetValue(_match.str(0).c_str());
            _capture.SetIndex(Int(_match.position()) + _length);
            _length += _values[i].Length();
            mCaptureCollection.Add(_capture);
        }
        
    }
}

System::Text::RegularExpressions::Group::Group(const String& _key, const String& _value, const Integer& _index)
{
    mValue = std::move(_key);
    mIndex = std::move(_index);
    Capture _capture = Capture();
    _capture.SetIndex(_index);
    _capture.SetValue(_value);
    mCaptureCollection.Add(_capture);
}

System::Text::RegularExpressions::Group::Group(const Group& _copy)
{
    mCaptureCollection = std::move(_copy.mCaptureCollection);
    mName = std::move(_copy.mName);
    mSuccess = std::move(_copy.mSuccess);
    mValue = std::move(_copy.mValue);
    mIndex = std::move(_copy.mIndex);
    mLength = std::move(_copy.mLength);
}
#pragma endregion constructor
#pragma region custom methods
void System::Text::RegularExpressions::Group::SetName(const String& _name)
{
    mName = std::move(_name);
}

void System::Text::RegularExpressions::Group::SetSuccess(const bool _success)
{
    mSuccess = _success;
}

// void System::Text::RegularExpressions::Group::AddCapture(const Capture& _capture)
// {
//     mCaptureCollection.Add(_capture);
// }
#pragma endregion custom methods
#pragma region override
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
#pragma endregion override
#pragma region operator
System::Text::RegularExpressions::Group System::Text::RegularExpressions::Group::operator=(const Group& _other)
{
    mCaptureCollection = std::move(_other.mCaptureCollection);
    mName = std::move(_other.mName);
    mSuccess = std::move(_other.mSuccess);
    mValue = std::move(_other.mValue);
    mIndex = std::move(_other.mIndex);
    mLength = std::move(_other.mLength);
    return *this;
}
#pragma endregion operator