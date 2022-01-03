#pragma once
#include "../System/PrimaryType/Enum/Enum.h"
#include "../System/PrimaryType/Integer/Integer.h"

class ETest : public System::Enum<ETest>
{
private:
    System::String name = System::String::Empty();
    System::Int age = 0;
public:
    static const ETest Thomas;
    static const ETest Jean;
    ETest()=default;
    ETest(System::String name, System::Int age);

    System::String Name()const { return name;}
    System::Int Age()const { return age; }

    System::String ToString() const override;
    
};
