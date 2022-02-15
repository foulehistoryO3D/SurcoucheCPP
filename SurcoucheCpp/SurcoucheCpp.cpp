#include <thread>

#include "System/IncludeSystem.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Console::WriteLine(DateTime::Now().DayOfWeek());
    return 0;
}
