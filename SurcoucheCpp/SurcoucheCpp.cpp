#include <windows.h>
#include "System/IncludeSystem.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    String _str = "Salut CA VA";
    Console::WriteLine(_str.ToLower().Replace(" ", ""));

    
    return 0;
}
