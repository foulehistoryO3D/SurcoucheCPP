#include "SqlData.h"

#pragma region f/p
string System::SQL::SqlData::Key() const
{
    return this->key;
}

string System::SQL::SqlData::Value() const
{
    return this->value;
}
#pragma endregion f/p
#pragma region constructor
System::SQL::SqlData::SqlData(const string& key, const string& value)
{
    this->key   = key;
    this->value = value;
}

System::SQL::SqlData::SqlData(const SqlData& copy) : Object(copy)
{
    this->key   = copy.key;
    this->value = copy.value;
}
#pragma endregion constructor
#pragma region custom methods
void System::SQL::SqlData::SetValue(const string& newValue)
{
    this->value = string("'") + newValue + "'";
}

string System::SQL::SqlData::GetData() const
{
    return string::Format("{0}: {1}", this->key, this->value);
}
#pragma endregion custom methods
#pragma region override
System::String System::SQL::SqlData::ToString() const
{
    return string::Format("Key: {0}, Value: {1}", this->key, this->value);
}

System::Integer System::SQL::SqlData::GetHashCode() const
{
    return this->key.GetHashCode() ^ this->value.GetHashCode() << 2;
}
#pragma endregion override
#pragma region operator
System::SQL::SqlData& System::SQL::SqlData::operator=(const SqlData& other)
{
    this->key   = other.key;
    this->value = other.value;
    return *this;
}
#pragma endregion operator