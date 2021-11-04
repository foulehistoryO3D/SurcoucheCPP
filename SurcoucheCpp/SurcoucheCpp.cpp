#include <windows.h>
#include "System/IncludeSystem.h"
#include "System/Activator/Activator.h"
#include "Test/Test.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    const String& _pathLog = Path::Combine(Environment::CurrentDirectory(), "Debug","Log.txt");
    const String& _pathError = Path::Combine(Environment::CurrentDirectory(), "Debug","LogError.txt");
    Console::SetIn(TextReader(_pathLog));
    Console::SetOut(TextWriter(_pathLog));
    Console::SetError(TextWriter(_pathError));

    object* _o = Activator::CreateInstance<Test>(22, "Thomas");
    const Test* _test = static_cast<Test*>(_o);
    if (!_test)
    {
        Console::Error().Write(string("[Main] => Error on cast object to Test"));
        return -1;
    }
    Console::WriteLine(_test->Name());
    Console::WriteLine(_test->Age());

    return 0;
}
