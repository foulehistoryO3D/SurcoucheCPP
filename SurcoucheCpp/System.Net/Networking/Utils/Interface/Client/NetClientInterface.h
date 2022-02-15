#pragma once
#include "../../NetInclude.h"
#include "../../NetConnection/NetConnection.h"

namespace Net
{
    template<typename T>
    class NetClientInterface
    {
#pragma region f/p
    protected:
        asio::io_context context                        = asio::io_context();
        std::thread threadContext                       = std::thread();
        std::unique_ptr<NetConnection<T>> connection    = std::unique_ptr<NetConnection<T>>();
    private:
        NetQueue<NetOwnedMessage<T>> messagesIn         = NetQueue<NetOwnedMessage<T>>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        NetClientInterface()=default;
        virtual ~NetClientInterface() { Disconnect(); }
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        bool Connect(const std::string& host, const uint16_t port)
        {
            try
            {
                asio::ip::tcp::resolver resolver = asio::ip::tcp::resolver(this->context);
                asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, std::to_string(port));
                this->connection->ConnectToServer(endpoints);
                this->threadContext = std::thread([this]{ this->context.run(); });
            }
            catch (std::exception& exception)
            {
                std::cerr << "[Client] Exception: " << exception.what() << std::endl;
                return false;
            }
            return true;
        }

        void Disconnect()
        {
            if (IsConnected()) this->connection->Disconnect();
            this->context.stop();
            if (this->threadContext.joinable()) this->threadContext.join();
            this->connection.release();
        }

        bool IsConnected()
        {
            if (this->connection) return this->connection->IsConnected();
            return false;
        }

        void Send(const NetMessage<T>& message)
        {
            if (IsConnected()) this->connection->Send(message);
        }
        
        NetQueue<NetOwnedMessage<T>>& Incoming() { return this->messagesIn; }

        template<typename Data>
        NetMessage<T> CreateMessage(const T& id, const Data& data)
        {
            NetMessage<T> message = NetMessage<T>();
            message.Header.ID = id;
            message << data;
            return message;
        }
#pragma endregion custom methods
    };
}
