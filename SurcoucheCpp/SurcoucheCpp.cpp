#include "System/IncludeSystem.h"
#include "System/Window/Window.h"
#include "Test/ETest.h"

int main()
{
    // Window _window = Window("Test", 500,500, false);
    const Integer& _test = ETest::Jean;
    const Integer& _thomas = ETest::Thomas;
    Console::WriteLine(string("Thomas: ") + _thomas + " Jean: " + _test);
    Console::WriteLine(ETest::Thomas);
    return 0;
}
