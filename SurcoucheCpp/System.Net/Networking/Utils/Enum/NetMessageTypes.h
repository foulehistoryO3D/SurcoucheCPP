#pragma once
#include "../../../../System/PrimaryType/Enum/SmartEnum.h"

// enum class NetMessageTypes : uint32_t
// {
//     ServerAccept,
//     ServerDeny,
//     ServerPing,
//     MessageAll,
//     CustomMessage,
//     ServerMessage,
// };
//
namespace System
{
    namespace Net
    {
        class NetMessageTypes : public SmartEnum<NetMessageTypes>
        {
#pragma region f/p
        private:
            string name = string::Empty;
        public:
            FORCEINLINE string Name()const;
            static const NetMessageTypes ServerAccept;
            static const NetMessageTypes ServerDeny;
            static const NetMessageTypes ServerPing;
            static const NetMessageTypes MessageAll;
            static const NetMessageTypes CustomMessage;
            static const NetMessageTypes ServerMessage;
#pragma endregion f/p
#pragma region constructor
        public:
            NetMessageTypes()=default;
            NetMessageTypes(const string& name);
#pragma endregion constructor
#pragma region override
        public:
            String ToString() const override;
#pragma endregion override
        };
    }
}