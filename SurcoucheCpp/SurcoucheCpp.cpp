#include <thread>

#include "System/IncludeSystem.h"
#include "System.SQL/Command/SQLCommand.h"
#include "System.SQL/Reader/SQLReader.h"
#include "System.SQL/DataBase/DataBaseLocal/DataBaseLocal.h"
#include "System.SQL/Exception/SQLException.h"
#include "System.Text.RegularExpressions/Regex/Regex.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // string path = Path::Combine(Environment::SpecialFolder(SpecialFolder::Dekstop), "Tables");
    // SQL::DataBaseLocal* dbl = new SQL::DataBaseLocal(path);
    // try
    // {
    //     const SQL::SQLCommand command = SQL::SQLCommand(dbl, "UPDATE 'user' SET money = '100000' WHERE id = 4");
    //     const SQL::SQLReader reader = command.ExecuteReader();
    //     Console::WriteLine(reader["id"]);
    //     Console::WriteLine(reader["username"]);
    //     Console::WriteLine(reader["money"]);
    // }
    // catch (SQL::SQLException e)
    // {
    //     Console::WriteLine(e);
    // }
    // delete dbl;
    
    return 0;
}
