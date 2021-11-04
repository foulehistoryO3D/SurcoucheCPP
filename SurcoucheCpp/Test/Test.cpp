#include "Test.h"
#include "../System/PrimaryType/Integer/Integer.h"

Test::Test()
{
    mAge = -1;
    mName = string::Empty();
}

Test::Test(const int& _age, const System::String& _str)
{
    mAge = _age;
    mName = _str;
}

Test::Test(const Test& _copy)
{
    mAge = std::move(_copy.mAge);
    mName = std::move(_copy.mName);
}

System::Integer Test::Age() const
{
    return mAge;
}

System::String Test::Name() const
{
    return mName;
}
