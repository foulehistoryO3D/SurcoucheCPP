#include <windows.h>

#include "System/Console/Console.h"
#include "System/DateTime/DateTime.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    System::DateTime _date = System::DateTime::Now();
    System::Console::WriteLine(_date.ToStringFormat("y-m-d h:m:s"));
    return 0;
}
