#include "System/IncludeSystem.h"
#include "System/Window/Window.h"
#include "Test/ETest.h"

int main()
{
    // Window _window = Window("Test", 500,500, false);
    for(ETest _value : ETest::Values())
    {
        Console::WriteLine(_value);
    }
    return 0;
}
