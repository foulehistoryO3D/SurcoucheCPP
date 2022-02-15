#include "CaptureCollection.h"

#include "../../System/Exception/OutOfRange/OutOfRange.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region override
System::Text::RegularExpressions::CaptureCollection::CaptureCollection(std::initializer_list<Capture> _tab)
{
    for (const Capture& _capture : _tab)
        Add(_capture);
}

System::Text::RegularExpressions::CaptureCollection::CaptureCollection(IEnumerator<Capture>* _enumerator)
{
    while (_enumerator->MoveNext())
        Add(_enumerator->Current());
    _enumerator->Reset();
}

System::Text::RegularExpressions::CaptureCollection::CaptureCollection(const CaptureCollection& _copy)
{
    const int& _length = _copy.Count();
    for (int i = 0; i < _length; ++i)
        Add(_copy[i]);
}

System::Text::RegularExpressions::Capture System::Text::RegularExpressions::CaptureCollection::Current()
{
    return mCurrentItem;
}

bool System::Text::RegularExpressions::CaptureCollection::MoveNext()
{
    if (++mCurrentIndex >= mCount) return false;
    mCurrentItem = mTab[mCurrentIndex];
    return true;
}

void System::Text::RegularExpressions::CaptureCollection::Reset()
{
    mCurrentIndex = -1;
}

System::Collections::Generic::IEnumerator<System::Text::RegularExpressions::Capture>* System::Text::RegularExpressions::
CaptureCollection::GetEnumerator()
{
    return this;
}

System::Integer System::Text::RegularExpressions::CaptureCollection::Count() const
{
    return mCount;
}

void System::Text::RegularExpressions::CaptureCollection::Add(Capture _item)
{
    const Capture* _tmpTab = mTab;
    mTab = new Capture[mCount + 1];
    for (int i = 0; i < mCount; ++i)
        mTab[i] = _tmpTab[i];
    mTab[mCount] = _item;
    delete[] _tmpTab;
    mCount++;
}

void System::Text::RegularExpressions::CaptureCollection::Clear()
{
    delete[] mTab;
    mTab = new Capture[0];
    mCount = 0;
}

bool System::Text::RegularExpressions::CaptureCollection::Contains(Capture _item)
{
    return IndexOf(_item) != -1;
}

void System::Text::RegularExpressions::CaptureCollection::Remove(Capture _item)
{
    const int _index = IndexOf(_item);
    if (_index == -1)
        throw Exception("[CaptureCollection] item doesn't exist !");
    RemoveAt(_index);
}

int System::Text::RegularExpressions::CaptureCollection::IndexOf(Capture _item)
{
    for (int i = 0; i < mCount; ++i)
        if (mTab[i] == _item)
            return i;
    return -1;
}

void System::Text::RegularExpressions::CaptureCollection::Insert(const int32 _index, Capture _item)
{
    if (_index < 0 || _index > mCount + 1)
        throw OutOfRange("[List] => out of range !");
    const Capture* _tmpTab = mTab;
    mTab = new Capture[mCount + 1];
    for (int i = 0; i < _index; ++i)
        mTab[i] = _tmpTab[i];
    const Capture _oldValue = _tmpTab[_index];
    mTab[_index] = _item;
    mTab[_index + 1] = _oldValue;
    for (int i = _index + 1; i < mCount; ++i)
        mTab[i + 1] = _tmpTab[i];
    delete[] _tmpTab;
    mCount++;
}

void System::Text::RegularExpressions::CaptureCollection::RemoveAt(const int32 _index)
{
    Capture* _tmpTab = mTab;
    mTab = new Capture[mCount - 1];
    for (int i = 0; i < _index; ++i)
        mTab[i] = _tmpTab[i];
    for (int i = _index + 1; i < mCount; ++i)
        mTab[i - 1] = _tmpTab[i];
    delete[]_tmpTab;
    mCount--;
}

System::String System::Text::RegularExpressions::CaptureCollection::ToString() const
{
    string str = string::Empty;
    for (int32 i = 0; i < mCount; ++i)
        str += mTab[i].ToString();
    return str;
}

System::Integer System::Text::RegularExpressions::CaptureCollection::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override
#pragma region operator

System::Text::RegularExpressions::Capture& System::Text::RegularExpressions::CaptureCollection::operator[](
    const int32& _index) const
{
    if (_index < 0 || _index > mCount)
        throw OutOfRange("[CaptureCollection] out of range");
    return mTab[_index];
}

System::Text::RegularExpressions::CaptureCollection& System::Text::RegularExpressions::CaptureCollection::operator=(
    const CaptureCollection& _other)
{
    const int& _length = _other.mCount;
    for (int i = 0; i < _length; ++i)
        Add(_other[i]);
    return *this;
}

System::Boolean System::Text::RegularExpressions::CaptureCollection::operator==(const CaptureCollection& _other) const
{
    const int _otherLength = _other.mCount;
    if (mCount != _otherLength) return false;
    for (int i = 0; i < mCount; ++i)
        if (mTab[i] != _other[i])
            return false;
    return true;
}
#pragma endregion operator
