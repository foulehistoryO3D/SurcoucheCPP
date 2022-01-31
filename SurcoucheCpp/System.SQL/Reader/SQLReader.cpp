#include "SQLReader.h"
#include "../../System/PrimaryType/Array/Array.h"

#pragma region constructor
System::SQL::SQLReader::SQLReader(const String& read)
{
    const Array splitedRead = read.Split(',');
    const Int& length = splitedRead.Count();
    for (int32 i = 0; i < length; ++i)
        this->readerObject.Add(i, splitedRead[i]);
}

System::SQL::SQLReader::SQLReader(const SQLReader& copy)
{
    this->readerObject = copy.readerObject;
}
#pragma endregion constructor
#pragma region override
System::String System::SQL::SQLReader::ToString() const
{
    return this->readerObject.ToString(); 
}

System::Integer System::SQL::SQLReader::GetHashCode() const
{
    return this->readerObject.GetHashCode();
}
#pragma endregion override
#pragma region operator
System::SQL::SQLReader& System::SQL::SQLReader::operator=(const SQLReader& other)
{
    this->readerObject = other.readerObject;
    return *this;
}
#pragma endregion operator