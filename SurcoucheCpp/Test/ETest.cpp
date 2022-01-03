#include "ETest.h"

const ETest ETest::Thomas("Thomas", 22);
const ETest ETest::Jean("Jean", 23);

ETest::ETest(System::String name, System::Int age)
{
    this->name = name;
    this->age = age;
}

System::String ETest::ToString() const
{
    return string("name: ") + name + ", age: " + age;
}
