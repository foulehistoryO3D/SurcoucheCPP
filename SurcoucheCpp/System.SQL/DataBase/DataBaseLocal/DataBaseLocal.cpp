#include "DataBaseLocal.h"

#include "../../../System.IO/File/File/File.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Array/Array.h"
#include "../../../System.IO/Directory/Directory.h"
#include "../../../System/Event/Action/Action.h"
#include "../../../System.IO/Directory/DirectoryInfo/DirectoryInfo.h"
#include "../../../System.IO/Path/Path.h"

#pragma region constructor
System::SQL::DataBaseLocal::DataBaseLocal(const String& path)
{
    this->path = path;
    if (!IO::Directory::Exists(path)) IO::Directory::MakeDirectory(path);

    Collections::Generic::List<IO::File> files = IO::Directory::GetFiles(path, ".db");
    files.ForEach([this](IO::File file)
    {
        string filePath = IO::Path::GetFileNameWithoutExtension(file.Path());
        filePath = filePath.SubString(filePath.LastIndexOf('\\') + 1);
        tables.Add(filePath, DataBaseTable(file));
    });
}

System::SQL::DataBaseLocal::~DataBaseLocal()
{
}

System::SQL::DataBaseTable& System::SQL::DataBaseLocal::GetTable(const string& tableName)
{
    DataBaseTable result = DataBaseTable();
    if (!this->tables.ContainsKey(tableName)) return result;
    return this->tables[tableName];
}

System::Array<System::String> System::SQL::DataBaseLocal::GetTables()
{
    Array<string> result = Array<string>(this->tables.Count());
    int index = 0;
    while (this->tables.GetEnumerator()->MoveNext())
    {
        result.InsertAt(index, this->tables.GetEnumerator()->Current().Key);
        index++;
    }
    this->tables.Reset();
    return result;
}
#pragma endregion constructor
#pragma region custom methods

#pragma endregion custom methods
#pragma region override
System::String System::SQL::DataBaseLocal::ToString() const
{
    return path;
}

System::Integer System::SQL::DataBaseLocal::GetHashCode() const
{
    return ToString().GetHashCode();
}

void System::SQL::DataBaseLocal::Dispose()
{
}
#pragma endregion override
