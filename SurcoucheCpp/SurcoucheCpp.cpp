#include "System/IncludeSystem.h"
#include "System/Utils/AssertSystem/AssertMacro.h"

class A
{
public:
    void Test()
    {
        Deprecated_Function(1.0, "Test1")
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    A a;
    a.Test();
    return 0;
}
