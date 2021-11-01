#include <string>
#include <windows.h>
#include "System/IncludeSystem.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    try
    {
        Byte _b = -1;
        Console::WriteLine(_b);
    }
    catch (OutOfRange _exception)
    {
        Console::WriteLine(_exception);
        throw;
    }
    return 0;
}
