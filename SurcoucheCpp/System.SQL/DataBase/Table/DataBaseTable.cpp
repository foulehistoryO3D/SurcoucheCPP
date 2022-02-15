#include "DataBaseTable.h"

#include "../../../System/Console/Console.h"
#include "../../../System/Event/Action/Action.h"
#include "../../../System/Exception/IndexOutOfRange/IndexOutOfRangeException.h"

#pragma region constructor
System::SQL::DataBaseTable::DataBaseTable(const IO::File& file)
{
    this->file = file;
}

System::SQL::DataBaseTable::DataBaseTable(const DataBaseTable& copy)
{
    this->file = copy.file;
}

#pragma endregion constructor
#pragma region custom methods
System::String System::SQL::DataBaseTable::GetValueFromIndex(const Integer& index) const
{
    Collections::Generic::List<string> splited = this->file.ReadAllLines();
    if (index < 0 || index > splited.Count())
        throw IndexOutOfRangeException("Invalid index DataBaseTable");
    return splited[index];
}
#pragma endregion custom methods
#pragma region override
#pragma endregion override
#pragma region operator
System::SQL::DataBaseTable& System::SQL::DataBaseTable::operator=(const DataBaseTable& other)
{
    this->file = other.file;
    return *this;
}
#pragma endregion operator