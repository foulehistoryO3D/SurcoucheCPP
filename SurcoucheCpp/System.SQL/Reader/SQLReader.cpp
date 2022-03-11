#include "SQLReader.h"

#include "../../System/Exception/IndexOutOfRange/IndexOutOfRangeException.h"
#include "../../System/PrimaryType/Array/Array.h"
#include "../../System/Event/Action/Action.h"

#pragma region constructor
System::SQL::SQLReader::SQLReader(const String& read)
{
    const Array splitedRead = read.Split(',').ToArray();
    const int size = splitedRead.Count();
    for (int i = 0; i < size; ++i)
    {
        string str = splitedRead[i];
        str = str.Replace(":", "");
        str = str.Replace("'", "");
        const Array data = str.Split(" ");
        this->readerObject.insert(std::pair<string, string>(data[0], data[1]));
    }
}

System::SQL::SQLReader::SQLReader(const SQLReader& copy) : Object(copy)
{
    this->readerObject = copy.readerObject;
}
#pragma endregion constructor
#pragma region override
System::String System::SQL::SQLReader::ToString() const
{
    string result = string::Empty;
    for (const std::pair<string, string> pair : this->readerObject)
        result += string::Format("Key: {0}, Value: {1}", pair.first, pair.second) + "\n";
    return result;
}

System::Integer System::SQL::SQLReader::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override
#pragma region operator
System::SQL::SQLReader& System::SQL::SQLReader::operator=(const SQLReader& other)
{
    this->readerObject = other.readerObject;
    return *this;
}

string System::SQL::SQLReader::operator[](const string& key) const
{
    for (std::pair<string, string> pair : this->readerObject)
        if (pair.first == key)
            return pair.second;
    return string::Empty;
}

string System::SQL::SQLReader::operator[](const int& key) const
{
    if (key < 0 || key > this->readerObject.size())
        throw IndexOutOfRangeException("invalid index sqlReader");
    int index = 0;
    for (std::pair<string, string> pair : this->readerObject)
    {
        if (index == key)
            return pair.second;
        index++;
    }
    return string::Empty;
}
#pragma endregion operator
