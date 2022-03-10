#include "System/IncludeSystem.h"

class A
{
public:
    void Test(Int a, String str, Float test)
    {
        Console::WriteLine(__PARAMETER__);
    }
};

template <typename Res, typename C, typename ... Args>
void Get(Res(C::*ptr)(Args...))
{
    Console::WriteLine(typeid(ptr).name());
}


template <typename ... Args>
void T(std::function<void(Args...)> func)
{
    Console::WriteLine(typeid(func).name());
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // Get(&A::Test);
    A a = A();
    a.Test(0, "", 5.0f);
    return 0;
}
