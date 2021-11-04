#pragma once
#include "../System/Object/Object.h"
#include "../System/PrimaryType/String/String.h"

namespace System
{
    class Integer;
}
class Test : public System::Object
{
private:
    int mAge;
    System::String mName = System::String::Empty();
public:
    Test();
    Test(const int& _age, const System::String& _str);
    Test(const Test& _copy);

    System::Integer Age()const;
    System::String Name()const;
};
