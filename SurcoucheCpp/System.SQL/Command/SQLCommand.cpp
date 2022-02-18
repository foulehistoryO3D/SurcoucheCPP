#include "SQLCommand.h"

#include "UpdateCommand/SQLUpdateCommand.h"
#include "../Reader/SQLReader.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System.Text.RegularExpressions/Regex/Regex.h"
#include "../Exception/SQLException.h"
#include "../../System/Event/Action/Action.h"
#include "DeleteCommand/SQLDeleteCommand.h"
#include "InsertCommand/SQLInsertCommand.h"

#pragma region f/p
System::String System::SQL::SQLCommand::Command() const
{
    return this->command;
}

System::Integer System::SQL::SQLCommand::Timeout() const
{
    return this->timeout;
}

System::SQL::DataBaseLocal* System::SQL::SQLCommand::DataBase() const
{
    return this->databaseLocal;
}

System::Boolean System::SQL::SQLCommand::IsValid() const
{
    return this->databaseLocal != null;
}
#pragma endregion f/p
#pragma region constructor
System::SQL::SQLCommand::SQLCommand(DataBaseLocal* databaseLocal, const String& command, const Integer& timeout)
{
    this->databaseLocal = databaseLocal;
    this->command = command;
    this->timeout = timeout;
}

System::SQL::SQLCommand::SQLCommand(const SQLCommand& copy)
{
    this->databaseLocal = std::move(copy.databaseLocal);
    this->command = std::move(copy.command);
    this->timeout = std::move(copy.timeout);
}
#pragma endregion constructor

#pragma region custom methods

string System::SQL::SQLCommand::GetID() const
{
    const Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex("WHERE [\\w]+(=| =) ([\\d]|'[\\d]')");
    string where = regex.Find(this->command)[0];
    return where.SubString(where.LastIndexOf('=')+1).Replace("'", "").Trim();
}

System::SQL::DataBaseTable* System::SQL::SQLCommand::GetTable(const string tableName) const
{
    DataBaseTable* table = this->databaseLocal->GetTable(tableName);
    if (table == null) throw SQLException(string::Format("Table: {0} doesn't exist", tableName));
    return table;
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteUpdateReader_Internal(Collections::Generic::List<string> commandParsed) const
{
    DataBaseTable* table;
    string id;
    GetValuesCommand(commandParsed, table, id);
    return SQLUpdateCommand(this->command, id, table).ExecuteReader();
}

void System::SQL::SQLCommand::ExecuteUpdate_Internal(Collections::Generic::List<string> commandParsed) const
{
    DataBaseTable* table;
    string id;
    GetValuesCommand(commandParsed, table, id);
    SQLUpdateCommand(this->command, id, table).Execute();
}

void System::SQL::SQLCommand::ExecuteDelete_Internal(Collections::Generic::List<string> commandParsed) const
{
    DataBaseTable* table;
    string id;
    GetValuesCommand(commandParsed, table, id);
    SQLDeleteCommand(command, id, table).Execute();
}

void System::SQL::SQLCommand::GetValuesCommand(System::Collections::Generic::List<System::String> commandParsed, System::SQL::DataBaseTable*& table, string& id) const
{
    const string tableName = commandParsed[1].Replace("'", "");
    table = GetTable(tableName);
    id = GetID();
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteDeleteReader_Internal(Collections::Generic::List<string> commandParsed) const
{
    DataBaseTable* table;
    string id;
    GetValuesCommand(commandParsed, table, id);
    return SQLDeleteCommand(command, id, table).ExecuteReader();
}
#pragma endregion constructor
#pragma region custom methods
void System::SQL::SQLCommand::ExecuteNoQuery() const
{
    if (!IsValid()) throw SQLException("DataBase is not open");
    Collections::Generic::List<string> commandParsed = this->command.Split(' ');
    const string item = commandParsed[0];
    if (item == "UPDATE")
        ExecuteUpdate_Internal(commandParsed);
    else if (item == "DELETE")
        ExecuteDelete_Internal(commandParsed);
    else if (item == "INSERT")
        SQLInsertCommand(this->command, GetTable("user")).Execute();
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteReader() const
{
    if (!IsValid()) throw SQLException("DataBase is not open");
    Collections::Generic::List<string> commandParsed = this->command.Split(' ');
    const string item = commandParsed[0];
    if (item == "UPDATE")
        return ExecuteUpdateReader_Internal(commandParsed);
    if (item == "DELETE")
        return ExecuteDeleteReader_Internal(commandParsed);
    if (item == "INSERT")
        return SQLInsertCommand(this->command, GetTable("user")).ExecuteReader();
    return SQLReader();
}
#pragma endregion custom methods
#pragma region override
System::String System::SQL::SQLCommand::ToString() const
{
    return command;
}

System::Integer System::SQL::SQLCommand::GetHashCode() const
{
    return ToString().GetHashCode() ^ (Int(timeout).GetHashCode() << 2);
}
#pragma endregion override
#pragma region operator
System::SQL::SQLCommand& System::SQL::SQLCommand::operator=(const SQLCommand& other)
{
    this->databaseLocal = other.databaseLocal;
    this->command = other.command;
    this->timeout = other.timeout;
    return *this;
}

System::Boolean System::SQL::SQLCommand::operator==(const SQLCommand& other) const
{
    return command == other.command && timeout == other.timeout;
}

System::Boolean System::SQL::SQLCommand::operator!=(const SQLCommand& other) const
{
    return !this->operator==(other);
}
#pragma endregion operator
