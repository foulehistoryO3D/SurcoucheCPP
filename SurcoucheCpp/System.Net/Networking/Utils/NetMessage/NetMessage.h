#pragma once
#include <ostream>
#include <vector>

namespace Net
{
    template<typename TID>
    struct NetMessageHeader
    {
        TID ID = TID();
        size_t Size = 0;
    };

    template<typename TID>
    struct NetMessage
    {
#pragma region f/p
        NetMessageHeader<TID> Header = NetMessageHeader<TID>();
        std::vector<uint8_t> Body = std::vector<uint8_t>();

        size_t Size() const { return Body.size(); }
#pragma endregion f/p
#pragma region operator
        friend std::ostream& operator<<(std::ostream& os, const NetMessage<TID>& msg)
        {
            os << "ID: " << static_cast<int>(msg.Header.ID) << " Size: " << msg.Header.Size;
            return os;
        }
        template<typename Data>
        friend NetMessage<TID>& operator<<(NetMessage<TID>& msg, const Data& data)
        {
            static_assert(std::is_standard_layout_v<Data>, "Data is too complex to be pushed into vector<uint8_t>");
            size_t size = msg.Body.size();
            msg.Body.resize(msg.Body.size() + sizeof(Data));
            std::memcpy(msg.Body.data() + size, &data, sizeof(Data));
            msg.Header.Size = msg.Size();
            return msg;
        }
        
        template<typename DataType>
        friend NetMessage<TID>& operator >> (NetMessage<TID>& msg, DataType& data)
        {
            static_assert(std::is_standard_layout_v<DataType>, "Data is too complex to be pulled from vector<uint8_t>");

            size_t i = msg.Body.size() - sizeof(DataType);

            std::memcpy(&data, msg.Body.data() + i, sizeof(DataType));

            msg.Body.resize(i);

            msg.Header.size = msg.Size();

            return msg;
        }

        friend NetMessage<TID>& operator >> (NetMessage<TID>& msg, std::string& data)
        {
            data = std::string(msg.Body.begin(), msg.Body.end());
            return msg;
        }

        friend NetMessage<TID>& operator<<(NetMessage<TID>& msg, const std::string data)
        {
            msg.Body = std::vector<uint8_t>(data.begin(), data.end());
            msg.Header.Size = msg.Body.size();
            return msg;
        }
#pragma endregion operator
    };

    template<typename TID>
    class NetConnection;

    template<typename TID>
    struct NetOwnedMessage
    {
#pragma region f/p
        std::shared_ptr<NetConnection<TID>> Remote = nullptr;
        NetMessage<TID> Message;
#pragma endregion f/p
#pragma region operator
        friend std::ostream& operator<<(std::ostream& os, const NetOwnedMessage<TID>& msg)
        {
            os << msg.Message;
            return os;
        }
#pragma endregion operator
    };
}
