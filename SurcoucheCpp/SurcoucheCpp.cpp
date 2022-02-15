#include <thread>

#include "System/IncludeSystem.h"
#include "System.SQL/DataBase/DataBaseLocal/DataBaseLocal.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string path = Path::Combine(Environment::SpecialFolder(SpecialFolder::Dekstop), "Tables");
    SQL::DataBaseLocal dbl = SQL::DataBaseLocal(path);
    Array<string> tables = dbl.GetTables();
    for (int i = 0; i < tables.Count(); ++i)
    {
        Console::WriteLine(tables[i]);
    }
    return 0;
}
