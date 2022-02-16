#include <thread>

#include "System/IncludeSystem.h"
#include "System.SQL/Command/SQLCommand.h"
#include "System.SQL/Reader/SQLReader.h"
#include "System.SQL/DataBase/DataBaseLocal/DataBaseLocal.h"
#include "System.Text.RegularExpressions/Regex/Regex.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    string path = Path::Combine(Environment::SpecialFolder(SpecialFolder::Dekstop), "Tables");
    SQL::DataBaseLocal* dbl = new SQL::DataBaseLocal(path);
    SQL::SQLCommand command = SQL::SQLCommand(dbl, "UPDATE 'user' SET money = 1000, username = 'Jean' WHERE id = '1'");
    Console::WriteLine(command.ExecuteReader());
    delete dbl;
    return 0;
}
