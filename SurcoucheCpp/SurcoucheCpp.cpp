#include <windows.h>
#include "System/IncludeSystem.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    const String _path = IO::Path::GetPath("F:/Objectif3D/P3/Exo/SurcoucheCpp/Test/Test1/Test2");
    IO::DirectoryInfo _str = IO::Directory::GetParent(_path);
    Console::WriteLine(_str.FullPath());
    Console::WriteLine(_str.Name());
    return 0;
}
