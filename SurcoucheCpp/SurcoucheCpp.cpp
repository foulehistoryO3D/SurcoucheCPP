#include "System/IncludeSystem.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Double d = Double::PositiveInfinity;

    Console::WriteLine(Double::IsInfinity(d));
    return 0;
}