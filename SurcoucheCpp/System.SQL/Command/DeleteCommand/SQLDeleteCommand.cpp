#include "SQLDeleteCommand.h"

#pragma region constructor
System::SQL::SQLDeleteCommand::SQLDeleteCommand(const string& command, const string& id, DataBaseTable* table)
{
    this->command   = command;
    this->id        = id;
    this->table     = table;
}

System::SQL::SQLDeleteCommand::SQLDeleteCommand(const SQLDeleteCommand& copy)
{
    this->command   = copy.command;
    this->id        = copy.id;
    this->table     = copy.table;
}

void System::SQL::SQLDeleteCommand::Execute()
{
    this->table->ReplaceLine(id, string::Empty);
}

System::SQL::SQLReader System::SQL::SQLDeleteCommand::ExecuteReader()
{
    this->table->ReplaceLine(id, string::Empty);
    return SQLReader("");
}

System::String System::SQL::SQLDeleteCommand::ToString() const
{
    return this->command;
}

System::Integer System::SQL::SQLDeleteCommand::GetHashCode() const
{
    return ToString().GetHashCode() ^ (this->id.GetHashCode() << 2) ^ (this->table->GetHashCode() >> 2);
}
#pragma endregion constructor
#pragma region custom methods
#pragma endregion custom methods
#pragma region operator
System::SQL::SQLDeleteCommand& System::SQL::SQLDeleteCommand::operator=(const SQLDeleteCommand& other)
{
    this->command   = other.command;
    this->id        = other.id;
    this->table     = other.table;
    return *this;
}
#pragma endregion operator