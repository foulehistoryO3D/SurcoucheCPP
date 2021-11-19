#include "System/IncludeSystem.h"
#include "System.Reflection/MethodInfo/MethodInfo.h"
#define FUNCTION_NAME(function) #function


class A : public Object
{
    DECLARE_CLASS_INFO(Object)
public:
    A() = default;

    virtual void Test(String _str, Boolean _b, Int _i){}
};

int main()
{
    SetConsoleOutputCP(65001);
    Reflection::MethodInfo _methodInfo = Reflection::MethodInfo(&A::Test, FUNCTION_NAME(&A::Test));
    const int _count = _methodInfo.Parameters().Count();
    Console::WriteLine(string("Function Name: ")+ _methodInfo.Name());
    for (int i = 0; i < _count; ++i)
    {
        const Reflection::ParameterInfo _info = _methodInfo.Parameters()[i];
        const string _str = string::Format("Type: {1}, Position: {2}", _info.ParameterType()->ClassName(), _info.Position());
        Console::WriteLine(_str);
    }
    
    return 0;
}
