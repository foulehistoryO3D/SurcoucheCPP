#include "SQLUpdateCommand.h"
#include "../../../System.Text.RegularExpressions/Regex/Regex.h"

#pragma region constructor/destructor
System::SQL::SQLUpdateCommand::SQLUpdateCommand(const string& command, const string& id, DataBaseTable* table)
{
    this->id        = id;
    this->command   = command;
    this->table     = table;
}

System::SQL::SQLUpdateCommand::SQLUpdateCommand(const SQLUpdateCommand& copy)
{
    this->id        = copy.id;
    this->command   = copy.command;
    this->table     = copy.table;
}
#pragma endregion constructor/destructor
#pragma region custom methods
System::Collections::Generic::List<System::SQL::SqlData> System::SQL::SQLUpdateCommand::RegisterValues(Collections::Generic::List<string> values)
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

System::Collections::Generic::List<System::SQL::SqlData> System::SQL::SQLUpdateCommand::GetDataValues(const string& str)
{
    Collections::Generic::List<SqlData> data = Collections::Generic::List<SqlData>();
    const Array strValue = str.Split(",");
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

System::SQL::SqlData* System::SQL::SQLUpdateCommand::GetData(const string& key)
{
    const int count = valuesData.Count();
    for (int i = 0; i < count; ++i)
    {
        if (valuesData[i].Key() == key)
            return &valuesData[i];
    }
    return null;
}


System::Collections::Generic::List<string> System::SQL::SQLUpdateCommand::GetValues() const
{
    Collections::Generic::List<string> result = Collections::Generic::List<string>();
    const System::Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex("(SET)(.*)(?=WHERE)");
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

void System::SQL::SQLUpdateCommand::UpdateValues()
{
    const int count = sqlData.Count();
    for (int i = 0; i < count; ++i)
    {
        const SqlData& data = sqlData[i];
        GetData(data.Key())->SetValue(data.Value());
    }
}

string System::SQL::SQLUpdateCommand::ConstructNewLine(const string& id)
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

#pragma endregion custom methods
#pragma region override
void System::SQL::SQLUpdateCommand::Execute()
{
    this->sqlData = RegisterValues(GetValues());
    const string dataValue = table->GetValueFromIndex(this->id);
    this->valuesData = GetDataValues(dataValue);
    UpdateValues();
    const string& newLine = ConstructNewLine(this->id);
    this->table->ReplaceLine(this->id, newLine);
}

System::SQL::SQLReader System::SQL::SQLUpdateCommand::ExecuteReader()
{
    this->sqlData = RegisterValues(GetValues());
    const string dataValue = table->GetValueFromIndex(this->id);
    this->valuesData = GetDataValues(dataValue);
    UpdateValues();
    const string& newLine = ConstructNewLine(this->id);
    this->table->ReplaceLine(this->id, newLine);
    return newLine;
}

System::String System::SQL::SQLUpdateCommand::ToString() const
{
    return Object::ToString();
}

System::Integer System::SQL::SQLUpdateCommand::GetHashCode() const
{
    return Object::GetHashCode();
}
#pragma endregion override
#pragma region operator
System::SQL::SQLUpdateCommand& System::SQL::SQLUpdateCommand::operator=(const SQLUpdateCommand& other)
{
    this->id        = other.id;
    this->command   = other.command;
    this->table     = other.table;
    return *this;
}
#pragma endregion operator
