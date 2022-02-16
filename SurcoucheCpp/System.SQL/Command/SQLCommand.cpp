#include "SQLCommand.h"
#include "../Reader/SQLReader.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System.Text.RegularExpressions/Regex/Regex.h"
#include "../Exception/SQLException.h"
#include "../../System/Event/Action/Action.h"

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

System::Collections::Generic::List<System::SQL::SqlData> System::SQL::SQLCommand::RegisterValues(Collections::Generic::List<string> values)
{
    Collections::Generic::List<SqlData> data = Collections::Generic::List<SqlData>();
    const int count = values.Count();
    for (int i = 0; i < count; ++i)
    {
        string str = values[i];
        Array valuesSplited = str.Split(" ");
        data.Add({valuesSplited[0].Trim(), valuesSplited[1].Trim()});
    }
    return data;
}

System::Collections::Generic::List<System::SQL::SqlData> System::SQL::SQLCommand::GetDataValues(const string& str)
{
    Collections::Generic::List<SqlData> data = Collections::Generic::List<SqlData>();
    Array strValue = str.Split(",");
    const int count = strValue.Count();
    for (int i = 1; i < count; ++i)
    {
        string value = strValue[i];
        if (value[0] == ' ') value = value.SubString(1);

        Array splitedValues = value.Split(":");
        data.Add({splitedValues[0].Trim(), splitedValues[1].Trim()});
    }    
    return data;
}

System::SQL::SqlData* System::SQL::SQLCommand::GetData(const string& key)
{
    const int count = valuesData.Count();
    for (int i = 0; i < count; ++i)
    {
        if (valuesData[i].Key() == key)
            return &valuesData[i];
    }
    return null;
}

string System::SQL::SQLCommand::GetID() const
{
    const Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex("WHERE [\\w]+(=| =) ([\\d]|'[\\d]')");
    string where = regex.Find(this->command)[0];
    return where.SubString(where.LastIndexOf('=')+1).Replace("'", "").Trim();
}

System::Collections::Generic::List<string> System::SQL::SQLCommand::GetValues() const
{
    Collections::Generic::List<string> result = Collections::Generic::List<string>();
    std::string t = "(?<=SET)(.*)(?=WHERE)";
    const Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex("(SET)(.*)(?=WHERE)");
    string value = regex.Find(this->command)[0];
    value = value.Replace("SET", "");
    if (value[0] == ' ') value = value.SubString(1);
    Collections::Generic::List<string> splitedValues = value.Split(',');
    const int count = splitedValues.Count();
    for (int i = 0; i < count; ++i)
    {
        string str = splitedValues[i];
        if (str.StartWith(' '))
            str = str.SubString(1);
        str = str.Replace("=", "");
        str = str.Replace("'", "");
        result.Add(str);
    }
    return result;
}

void System::SQL::SQLCommand::UpdateValues()
{
    const int count = sqlData.Count();
    for (int i = 0; i < count; ++i)
    {
        const SqlData& data = sqlData[i];
        GetData(data.Key())->SetValue(data.Value());
    }

    valuesData.ForEach([](SqlData d)
    {
        Console::WriteLine(d); 
    });
}

string System::SQL::SQLCommand::ConstructNewLine(const string& id)
{
    string newLine = string::Format("id: {0}, ", id);
    const int count = valuesData.Count();
    for (int i = 0; i < count; ++i)
    {
        newLine += valuesData[i].GetData();
        if (i < count - 1) newLine += ", ";
    }
    return newLine;
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteUpdateReader_Internal(Collections::Generic::List<string> commandParsed)
{
    const string tableName = commandParsed[1].Replace("'", "");
    DataBaseTable* table = this->databaseLocal->GetTable(tableName);
    if (table == null) throw SQLException(string::Format("Table: {0} doesn't exist", tableName));

    const string id = GetID();
    sqlData = RegisterValues(GetValues());
    const string dataValue = table->GetValueFromIndex(id);
    valuesData = GetDataValues(dataValue);
    UpdateValues();
    string newLine = ConstructNewLine(id);
    table->ReplaceLine(id, newLine);
    
    return SQLReader();
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteDeleteReader_Internal(Collections::Generic::List<string> commandParsed)
{
    return SQLReader();
}
#pragma endregion constructor
#pragma region custom methods
void System::SQL::SQLCommand::ExecuteNoQuery() 
{
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteReader()
{
    if (!IsValid()) throw SQLException("DataBase is not open");
    Collections::Generic::List<string> commandParsed = this->command.Split(' ');
    string item = commandParsed[0];
    if (item == "UPDATE")
        return ExecuteUpdateReader_Internal(commandParsed);
    if (item == "DELETE")
        return ExecuteDeleteReader_Internal(commandParsed);
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
