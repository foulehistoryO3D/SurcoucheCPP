#pragma once
#include "../System/PrimaryType/Enum/Enum.h"
#include "../System/PrimaryType/Integer/Integer.h"

class ETest : public System::Enum<ETest>
{
private:
    System::String name = System::String::Empty;
    System::Int age = 0;
    inline static int mCurrentValue = 0;
public:
    static const ETest Thomas;
    static const ETest Jean;
    ETest()=default;
    ETest(System::String name, System::Int age, System::Int _value = mCurrentValue++);

    System::String Name()const { return name;}
    System::Int Age()const { return age; }

    System::String ToString() const override;
    operator System::Integer() const override;
    ETest operator=(const ETest& _item);
};
