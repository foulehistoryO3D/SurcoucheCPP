#include "ETest.h"

const ETest ETest::Thomas("Thomas", 22);
const ETest ETest::Jean("Jean", 23);

ETest::ETest(System::String name, System::Int age, System::Integer _value)
{
    this->name = name;
    this->age = age;
    this->value = _value;
}

System::String ETest::ToString() const
{
    return string("name: ") + name + ", age: " + age;
}

ETest::operator System::Integer() const
{
    return value;
}


ETest ETest::operator=(const ETest& _item)
{
    value = _item.value;
    mCurrentValue = _item.mCurrentValue;
    return *this;
}
