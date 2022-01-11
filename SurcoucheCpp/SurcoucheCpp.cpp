#include "System/IncludeSystem.h"
#include "System/PrimaryType/Enum/Enum.h"
#include "System/Window/Window.h"

ENUM(Test, uint8, Thomas, Jean)

int main()
{
    // Window _window = Window("Test", 500,500, false);
    Console::WriteLine(*Test::Thomas);
    Console::WriteLine(Int((int)Test::Thomas));
    Console::WriteLine(*Test::Jean);
    Console::WriteLine(Int((int)Test::Jean));
    
    
    return 0;
}
