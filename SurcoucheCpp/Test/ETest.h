#pragma once
#include "../System/PrimaryType/Enum/SmartEnum.h"

using namespace System;

class ETest : public SmartEnum<ETest>
{
private:
    string name = string::Empty;
    Int age = 0;
public:
    static const ETest Foulehistory;
    static const ETest Foulehistory1;
    ETest(string name, Int age);

    String ToString() const override;
    
};
