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
        tables.insert(std::pair(filePath, new DataBaseTable(file)));
    });
}

System::SQL::DataBaseLocal::DataBaseLocal(const DataBaseLocal& copy) : Object(copy)
{
    this->tables = copy.tables;
    this->path = copy.path;
}

System::SQL::DataBaseLocal::~DataBaseLocal()
{
}

System::SQL::DataBaseTable* System::SQL::DataBaseLocal::GetTable(const string& tableName)
{
    std::pmr::map<string, DataBaseTable*>::const_iterator begin = this->tables.begin();
    for (; begin != this->tables.end(); ++begin)
        if (begin->first == tableName)
            return begin->second;
    return null;
}

System::Array<System::SQL::DataBaseTable*> System::SQL::DataBaseLocal::GetTables() const
{
    Array<DataBaseTable*> result = Array<DataBaseTable*>(this->tables.size());
    int index = 0;
    for (std::pair<string, DataBaseTable*> pair : this->tables)
    {
        result.InsertAt(index, pair.second);
        index++;
    }
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
