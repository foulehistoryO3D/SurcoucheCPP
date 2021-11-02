#include <windows.h>
#include "System/IncludeSystem.h"
#include "System/DateTime/DateTime.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    DateTime _now = DateTime::Now();
    Console::WriteLine(_now.ToString("%d-%m-%Y %H:%M:%S"));
    return 0;
}
