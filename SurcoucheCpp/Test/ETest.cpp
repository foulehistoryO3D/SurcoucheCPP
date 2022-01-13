#include "ETest.h"

ETest const ETest::Foulehistory("Foulehistory", 22);
ETest const ETest::Foulehistory1("Foulehistory1", 70);


ETest::ETest(string name, Int age) : SmartEnum<ETest>()
{
    this->name = name;
    this->age = age;
    Register(this);
}

String ETest::ToString() const
{
    return name + ", age: " + age;
}
