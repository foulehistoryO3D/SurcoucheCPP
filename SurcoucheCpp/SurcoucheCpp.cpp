#include <windows.h>
#include "System/IncludeSystem.h"
#include "System/DateTime/DateTime.h"
#include "System/Environment/Environment.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    const String& _path = IO::Path::Combine(Environment::CurrentDirectory(), "test.txt");
    StreamWriter _streamWriter = File::CreateText(_path);
    if (!_streamWriter.IsValid())
        return -1;
    _streamWriter.Write('c');
    _streamWriter.Close();
    Diagnostics::Process::Start(_path);
    return 0;
}
