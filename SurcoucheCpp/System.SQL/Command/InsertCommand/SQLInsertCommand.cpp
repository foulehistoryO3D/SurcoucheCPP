#include "SQLInsertCommand.h"

#include "../../../System/Exception/Cast/InvalidCastException.h"
#include "../../../System/PrimaryType/Array/Array.h"
#include "../../../System.Text.RegularExpressions/Regex/Regex.h"
#include "../../../System.Text/StringBuilder/StringBuilder.h"

#pragma region constructor
System::SQL::SQLInsertCommand::SQLInsertCommand(const string& command, DataBaseTable* table)
{
    this->command = command;
    this->table = table;
}

System::SQL::SQLInsertCommand::SQLInsertCommand(const SQLInsertCommand& copy)
{
    this->command = copy.command;
    this->table = copy.table;
}
#pragma endregion constructor
#pragma region custom methods
#pragma endregion custom methods
#pragma region override
string System::SQL::SQLInsertCommand::GetLastID() const
{
    const Array allLines = this->table->GetLines();
    const string& lastLine = allLines[allLines.Count() - 1];
    return lastLine.SubString(lastLine.FirstIndexOf(':') + 1, lastLine.FirstIndexOf(',')).Trim();
}

System::Collections::Generic::List<System::SQL::SqlData> System::SQL::SQLInsertCommand::GetData() const
{
    Collections::Generic::List<SqlData> data = Collections::Generic::List<SqlData>();
    const string dataSubstr = this->command.SubString(this->command.FirstIndexOf('(') + 1,
                                                      this->command.FirstIndexOf(')')).Trim();
    const Array dataParsed = dataSubstr.Split(',');
    const Array values = GetValues(this->command);
    for (int i = 0; i < dataParsed.Count(); i++)
        data.Add(SqlData(dataParsed[i], values[i]));
    return data;
}

System::Array<System::String> System::SQL::SQLInsertCommand::GetValues(const string& line)
{
    Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex("(VALUES)(.*)(?=\\))");
    Collections::Generic::List<string> result = Collections::Generic::List<string>();
    string lineValues = regex.Find(line)[0];
    lineValues = lineValues.Replace("VALUES", "").Replace("(", "").Replace(")", "").Trim();
    Array values = lineValues.Split(',');
    const int count = values.Count();
    for (int i = 0; i < count; ++i)
    {
        string str = values[i];
        if (str.StartWith(' ')) str = str.SubString(1);
        str = str.Replace("'", "");
        result.Add(str);
    }
    return result.ToArray();
}

void System::SQL::SQLInsertCommand::Execute()
{
    Int id = 0;
    const Boolean parseValid = Int::TryParse(GetLastID(), id);
    if (!parseValid) return;
    ++id;
    Text::StringBuilder builder = "id: ";
    builder.Append(id.ToString() + ", ");
    Collections::Generic::List<SqlData> data = GetData();
    for (int i = 0; i < data.Count(); ++i)
    {
        const SqlData& currentData = data[i];
        if (i < data.Count() - 1)
            builder.Append(string::Format("{0}: '{1}', ", currentData.Key(), currentData.Value()));
        else builder.Append(string::Format("{0}: '{1}'", currentData.Key(), currentData.Value()));
    }
    this->table->AddLine(builder.ToString());
}

System::SQL::SQLReader System::SQL::SQLInsertCommand::ExecuteReader()
{
    Int id = 0;
    const Boolean parseValid = Int::TryParse(GetLastID(), id);
    if (!parseValid) return SQLReader();
    ++id;
    Text::StringBuilder builder = "id: ";
    builder.Append(id.ToString() + ", ");
    Collections::Generic::List<SqlData> data = GetData();
    for (int i = 0; i < data.Count(); ++i)
    {
        const SqlData& currentData = data[i];
        if (i < data.Count() - 1)
            builder.Append(string::Format("{0}: '{1}', ", currentData.Key(), currentData.Value()));
        else builder.Append(string::Format("{0}: '{1}'", currentData.Key(), currentData.Value()));
    }
    this->table->AddLine(builder.ToString());
    return SQLReader(builder.ToString());
}
#pragma endregion override
#pragma region operator
System::SQL::SQLInsertCommand& System::SQL::SQLInsertCommand::operator=(const SQLInsertCommand& other)
{
    this->command = other.command;
    this->table = other.table;
    return *this;
}
#pragma endregion operator
