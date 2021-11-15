#include "GroupCollection.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"s

#pragma region constructor
System::Text::RegularExpressions::GroupCollection::GroupCollection(
    std::initializer_list<Collections::Generic::KeyValuePair<String, Group>> _tab)
{
}

System::Text::RegularExpressions::GroupCollection::GroupCollection(
    IEnumerator<Collections::Generic::KeyValuePair<String, Group>>* _enumerator)
{
}

System::Text::RegularExpressions::GroupCollection::GroupCollection(const GroupCollection& _copy)
{
}
#pragma endregion constructor
#pragma region override
int System::Text::RegularExpressions::GroupCollection::Count() const
{
}

void System::Text::RegularExpressions::GroupCollection::Add(Collections::Generic::KeyValuePair<String, Group> _item)
{
}

void System::Text::RegularExpressions::GroupCollection::Clear()
{
}

bool System::Text::RegularExpressions::GroupCollection::Contains(
    Collections::Generic::KeyValuePair<String, Group> _item)
{
}

void System::Text::RegularExpressions::GroupCollection::Remove(Collections::Generic::KeyValuePair<String, Group> _item)
{
}

System::Collections::Generic::KeyValuePair<System::String, System::Text::RegularExpressions::Group> System::Text::
RegularExpressions::GroupCollection::Current()
{
}

bool System::Text::RegularExpressions::GroupCollection::MoveNext()
{
}

void System::Text::RegularExpressions::GroupCollection::Reset()
{
}

System::Collections::Generic::IEnumerator<System::Collections::Generic::KeyValuePair<System::String, System::Text::
RegularExpressions::Group>>* System::Text::RegularExpressions::GroupCollection::GetEnumerator()
{
}

void System::Text::RegularExpressions::GroupCollection::Add(String _key, Group _value)
{
}

System::Boolean System::Text::RegularExpressions::GroupCollection::ContainsKey(String _key)
{
}

void System::Text::RegularExpressions::GroupCollection::RemoveItem(String _key)
{
}
#pragma endregion override