#pragma once
#include "../../PrimaryType/Enum/SmartEnum.h"

class DayOfWeek : public System::SmartEnum<DayOfWeek>
{
#pragma region f/p
private:
    string dayName = string::Empty;
public:
    string DayName()const;
    static const DayOfWeek Sunday;
    static const DayOfWeek Monday;
    static const DayOfWeek Tuesday;
    static const DayOfWeek Wednesday;
    static const DayOfWeek Thursday;
    static const DayOfWeek Friday;
    static const DayOfWeek Saturday;
#pragma endregion f/p
#pragma region constructor
public:
    DayOfWeek()=default;
    DayOfWeek(const string& dayName);
#pragma endregion constructor
#pragma region override
public:
    System::String ToString() const override;
#pragma endregion override
#pragma region operator
    
    virtual DayOfWeek& operator=(const DayOfWeek& _value)
    {
        dayName = _value.dayName;
        return *this;
    }

    System::Boolean operator==(DayOfWeek other) override;
    System::Boolean operator!=(DayOfWeek other) override;
#pragma endregion operator
    
};
