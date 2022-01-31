#include "SQLCommand.h"
#include "../Reader/SQLReader.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region constructor
System::SQL::SQLCommand::SQLCommand(const String& command, const Integer& timeout)
{
    this->command = command;
    this->timeout = timeout;
}

System::SQL::SQLCommand::SQLCommand(const SQLCommand& copy)
{
    this->command = std::move(copy.command);
    this->timeout = std::move(copy.timeout);
}
#pragma endregion constructor
#pragma region custom methods
void System::SQL::SQLCommand::ExecuteNoQuery() 
{
}

System::SQL::SQLReader System::SQL::SQLCommand::ExecuteReader()
{
    return SQLReader();
}
#pragma endregion custom methods
#pragma region override
System::String System::SQL::SQLCommand::ToString() const
{
    return command;
}

System::Integer System::SQL::SQLCommand::GetHashCode() const
{
    return ToString().GetHashCode() ^ (Int(timeout).GetHashCode() << 2);
}
#pragma endregion override
#pragma region operator
System::SQL::SQLCommand& System::SQL::SQLCommand::operator=(const SQLCommand& other)
{
    this->command = other.command;
    this->timeout = other.timeout;
    return *this;
}

System::Boolean System::SQL::SQLCommand::operator==(const SQLCommand& other) const
{
    return command == other.command && timeout == other.timeout;
}

System::Boolean System::SQL::SQLCommand::operator!=(const SQLCommand& other) const
{
    return !this->operator==(other);
}
#pragma endregion operator
