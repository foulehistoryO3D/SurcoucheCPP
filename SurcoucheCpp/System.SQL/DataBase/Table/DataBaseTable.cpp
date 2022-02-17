#include "DataBaseTable.h"

#include "../../../System/Console/Console.h"
#include "../../../System/Event/Action/Action.h"
#include "../../../System.IO/Stream/StreamWriter/StreamWriter.h"
#include "../../Exception/SQLException.h"

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
System::String System::SQL::DataBaseTable::GetValueFromIndex(const string& index) const
{
    Collections::Generic::List<string> splited = this->file.ReadAllLines();
    const int count = splited.Count();
    for (int i = 0; i < count; ++i)
    {
        if (splited[i].StartWith(string::Format("id: {0}", index)))
            return splited[i];
    }
    throw SQLException("id not found");
}

void System::SQL::DataBaseTable::ReplaceLine(const string& id, const string& newLine) const
{
    Collections::Generic::List<string> lines = this->file.ReadAllLines();
    IO::StreamWriter writer = this->file.OpenWriter();
    writer.Clear();

    const int count = lines.Count();
    for (int i = 0; i < count; i++)
    {
        string strID = string("id: ") + id;
        if (lines[i].StartWith(strID))
            lines[i] = newLine;
    }
    lines.RemoveAll(string::Empty);
    writer.WriteAllText(lines);
    writer.Dispose();
}

System::String System::SQL::DataBaseTable::ToString() const
{
    return this->file.Path();
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