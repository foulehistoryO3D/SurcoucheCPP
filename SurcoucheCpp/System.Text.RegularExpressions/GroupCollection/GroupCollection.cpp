#include "GroupCollection.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region constructor
System::Text::RegularExpressions::GroupCollection::GroupCollection(
    std::initializer_list<Collections::Generic::KeyValuePair<String, Group>> _tab)
{
    for (const Collections::Generic::KeyValuePair<String, Group> _pair : _tab)
        GroupCollection::Add(_pair);
}

System::Text::RegularExpressions::GroupCollection::GroupCollection(
    IEnumerator<Collections::Generic::KeyValuePair<String, Group>>* _enumerator)
{
    while(_enumerator->MoveNext())
        GroupCollection::Add(_enumerator->Current());
    _enumerator->Reset();
}

System::Text::RegularExpressions::GroupCollection::GroupCollection(const GroupCollection& _copy)
{
    const int _count = _copy.Count();
    for (int i = 0; i < _count; ++i)
        GroupCollection::Add(_copy.mTab[i]);
    mCurrentIndex = std::move(_copy.mCurrentIndex);
    mCurrentItem = std::move(_copy.mCurrentItem);
}
#pragma endregion constructor
#pragma region custom methods
int System::Text::RegularExpressions::GroupCollection::IndexOf(const String& _key) const
{
    for (int i = 0; i < mCount; ++i)
        if (mTab[i].Key == _key)
            return i;
    return -1;
}

void System::Text::RegularExpressions::GroupCollection::RemoveAt(const int& _index)
{
    const Collections::Generic::KeyValuePair<String, Group>* _tmpTab = mTab;
    mTab = new Collections::Generic::KeyValuePair<String, Group>[mCount - 1];
    for (int i = 0; i < _index; ++i)
        mTab[i] = _tmpTab[i];
    for (int i = _index + 1; i < mCount; ++i)
        mTab[i - 1] = _tmpTab[i];
    delete[]_tmpTab;
    mCount--;
}
#pragma endregion custom methods
#pragma region override
System::Integer System::Text::RegularExpressions::GroupCollection::Count() const
{
    return mCount;
}

void System::Text::RegularExpressions::GroupCollection::Add(Collections::Generic::KeyValuePair<String, Group> _item)
{
    if (Contains(_item))
        throw Exception("key is already exist !");
    const Collections::Generic::KeyValuePair<String, Group>* _tmpTab = mTab;
    mTab = new Collections::Generic::KeyValuePair<String, Group>[mCount + 1];
    for (int i = 0; i < mCount; ++i)
        mTab[i] = _tmpTab[i];
    mTab[mCount] = _item;
    delete[] _tmpTab;
    mCount++;
}

void System::Text::RegularExpressions::GroupCollection::Clear()
{
    delete[] mTab;
    mTab = new Collections::Generic::KeyValuePair<String, Group>[0];
    mCount = 0;
}

bool System::Text::RegularExpressions::GroupCollection::Contains(
    Collections::Generic::KeyValuePair<String, Group> _item)
{
    for (int i = 0; i < mCount; ++i)
        if (mTab[i] == _item)
            return true;
    return false;
}

void System::Text::RegularExpressions::GroupCollection::Remove(Collections::Generic::KeyValuePair<String, Group> _item)
{
    const int& _index = IndexOf(_item.Key);
    if (_index == -1)
        throw Exception("key doesn't exist");
    RemoveAt(_index);
}

System::Collections::Generic::KeyValuePair<System::String, System::Text::RegularExpressions::Group> System::Text::
RegularExpressions::GroupCollection::Current()
{
    return mCurrentItem;
}

bool System::Text::RegularExpressions::GroupCollection::MoveNext()
{
    if (++mCurrentIndex >= mCount) return false;
    mCurrentItem = mTab[mCurrentIndex];
    return true;
}

void System::Text::RegularExpressions::GroupCollection::Reset()
{
    mCurrentIndex = -1;
}

System::Collections::Generic::IEnumerator<System::Collections::Generic::KeyValuePair<System::String, System::Text::
RegularExpressions::Group>>* System::Text::RegularExpressions::GroupCollection::GetEnumerator()
{
    return this;
}

void System::Text::RegularExpressions::GroupCollection::Add(String _key, Group _value)
{
    Add(Collections::Generic::KeyValuePair(_key, _value));
}

System::Boolean System::Text::RegularExpressions::GroupCollection::ContainsKey(String _key)
{
    return IndexOf(_key) != -1;
}

void System::Text::RegularExpressions::GroupCollection::RemoveItem(String _key)
{
    const int _index = IndexOf(_key);
    if (_index == -1)
        throw Exception("key doesn't exist");
    RemoveAt(_index);
}

System::String System::Text::RegularExpressions::GroupCollection::ToString() const
{
    string result = string::Empty;
    for(int32 i = 0; i < mCount; ++i)
        result += mTab[i].Value.ToString();
    return result;
}

System::Integer System::Text::RegularExpressions::GroupCollection::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override
#pragma region operator
System::Collections::Generic::KeyValuePair<System::String, System::Text::RegularExpressions::Group>& System::Text::
RegularExpressions::GroupCollection::operator[](const int32& _index) const
{
    if (_index < 0 || _index > mCount)
        throw OutOfRange("[GroupCollection] out of range");
    return mTab[_index];
}

System::Text::RegularExpressions::GroupCollection& System::Text::RegularExpressions::GroupCollection::operator=(
    const GroupCollection& _other)
{
    const int _count = _other.Count();
    for (int i = 0; i < _count; ++i)
        Add(_other.mTab[i]);
    mCurrentIndex = std::move(_other.mCurrentIndex);
    mCurrentItem = std::move(_other.mCurrentItem);
    return *this;
}

System::Boolean System::Text::RegularExpressions::GroupCollection::operator==(const GroupCollection& _other) const
{
    if (mCount != _other.mCount) return false;
    for (int i = 0; i < mCount; ++i)
        if (mTab[i] != _other[i])
            return false;
    return true;
}
#pragma endregion operator
