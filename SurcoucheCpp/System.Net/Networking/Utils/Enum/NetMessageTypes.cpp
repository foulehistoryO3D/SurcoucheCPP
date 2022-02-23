#include "NetMessageTypes.h"

#pragma region f/p

System::Net::NetMessageTypes const System::Net::NetMessageTypes::ServerAccept("ServerAccept");
System::Net::NetMessageTypes const System::Net::NetMessageTypes::ServerDeny("ServerDeny");
System::Net::NetMessageTypes const System::Net::NetMessageTypes::ServerPing("ServerPing");
System::Net::NetMessageTypes const System::Net::NetMessageTypes::MessageAll("MessageAll");
System::Net::NetMessageTypes const System::Net::NetMessageTypes::CustomMessage("CustomMessage");
System::Net::NetMessageTypes const System::Net::NetMessageTypes::ServerMessage("ServerMessage");

string System::Net::NetMessageTypes::Name() const
{
    return this->name;
}
#pragma endregion f/p
#pragma region constructor
System::Net::NetMessageTypes::NetMessageTypes(const string& name) : SmartEnum<NetMessageTypes>()
{
    this->name = name;
    Register(this);
}
#pragma endregion constructor
#pragma region override
System::String System::Net::NetMessageTypes::ToString() const
{
    return name;
}
#pragma endregion override