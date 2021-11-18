#include "System/IncludeSystem.h"


template<typename... Args>
void Test(void(*func)(Args... _args))
{
    List<object*> _tab = TemplateUtils::CreateVectorWithParameterPack<Args...>(_args);
    
    // _tab.ForEach([](object* o)
    // {
    //    Console::WriteLine(o->ToString()); 
    // });
}

void Hello(Int _a, Float _f, String _str)
{
    
}

int main()
{
    SetConsoleOutputCP(65001);
    Test(Hello);
    
    return 0;
}
