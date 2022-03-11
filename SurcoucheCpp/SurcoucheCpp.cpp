#include "System/IncludeSystem.h"
#include "System/Utils/AssertSystem/AssertMacro.h"

class Attribute : public Object
{
private:
    
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Int t;
    List<Int> a;
    Dictionary<Int, String> b;
    Console::WriteLine(t.Namespace());
    Console::WriteLine(a.Namespace());
    Console::WriteLine(b.Namespace());
    // Console::WriteLine(t.Namespace());
    return 0;
}