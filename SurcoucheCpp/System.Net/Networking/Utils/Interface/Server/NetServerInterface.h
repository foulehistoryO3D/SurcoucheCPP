#pragma once
#include "../../NetInclude.h"
#include "../../NetMessage/NetMessage.h"
#include "../../NetQueue/NetQueue.h"

namespace Net
{
    template<typename T>
    class NetServerInterface
    {
#pragma region f/p
    protected:
        NetQueue<NetOwnedMessage<T>> messagesIn                     = NetQueue<NetOwnedMessage<T>>();
        std::deque<std::shared_ptr<NetConnection<T>>> connections   = std::deque<std::shared_ptr<NetConnection<T>>>();
        asio::io_context asioContext                                = asio::io_context();
        std::thread threadContext                                   = std::thread();
        asio::ip::tcp::acceptor asioAcceptor                        = asio::ip::tcp::acceptor(nullptr);
        uint32_t idCounter                                          = 0;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        NetServerInterface(uint16_t port)
        {
            this->asioAcceptor(this->asioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
        }
        virtual ~NetServerInterface() { Stop(); }
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        bool Start()
        {
            try
            {
                WaitForClientConnection();
                threadContext = std::thread([this] { this->asioContext.run(); });
            }
            catch (std::exception& exception)
            {
                std::cerr << "[Server] Exception: " << exception.what() << std::endl;
                return false;
            }
            std::cout << "[Server] Started!" << std::endl;
            return true;
        }

        void Stop()
        {
            this->asioContext.stop();
            if (threadContext.joinable()) threadContext.join();
            std::cout << "[Server] Stopped!" << std::endl;
        }

        void WaitForClientConnection()
        {
            this->asioAcceptor.async_accept([this](const std::error_code& ec, asio::ip::tcp::socket socket){
                if (!ec)
                {
                    std::cout << "[SERVER] New connection: " << socket.remote_endpoint() << std::endl;
                    std::shared_ptr<NetConnection<T>> newConnection = std::make_shared<NetConnection<T>>(NetConnection<T>(NetConnection<T>::NetOwner::Server, this->asioContext, std::move(socket), this->messagesIn));
                    if (OnClientConnect(newConnection))
                    {
                        connections.push_back(std::move(newConnection));
                        connections.back().ConnectToClient(this, idCounter++);
                        std::cout << "[" << connections.back()->ID() << "] Connection approved !" << std::endl;
                    }
                    else
                        std::cout << "[SERVER] Connection Denied" << std::endl;
                }
                else
                    std::cout << "[SERVER] New connection error: " << ec.message() << std::endl;
                WaitForClientConnection();
            });
        }

        void MessageClient(std::shared_ptr<NetConnection<T>> client, const NetMessage<T>& message)
        {
            if (client && client->IsConnected())
                client->Send(message);
            else
            {
                OnClientDisconnect(client);
                client.reset();
                connections.erase(std::remove(connections.begin(), connections.end(), client), connections.end());
            }
        }

        void MessageAllClients(const NetMessage<T>& message, std::vector<std::shared_ptr<NetConnection<T>>> ignoreClient = nullptr)
        {
            bool invalidClientExists = false;
            for (auto& client : connections)
            {
                if (client && client->IsConnected())
                {
                    if (std::find(ignoreClient.begin(), ignoreClient.end(), client) == nullptr)
                    {
                        client->Send(message);
                    }
                    else
                    {
                        OnClientDisconnect(client);
                        client.reset();
                        invalidClientExists = true;
                    }
                }
            }
            if (invalidClientExists)
                connections.erase(std::remove(connections.begin(), connections.end(), nullptr), connections.end());
        }

        void Update(size_t maxMessages = -1, bool wait = false)
        {
            if (wait) messagesIn.Wait();
            size_t messageCount = 0;
            while (messageCount < maxMessages && !messagesIn.Empty())
            {
                NetOwnedMessage<T> message = messagesIn.PopFront();
                OnMessage(message.Remote, message.Message);
                messageCount++;
            }
        }

    protected:
        virtual bool OnClientConnect(std::shared_ptr<NetConnection<T>> client) { return false; }
        virtual void OnClientDisconnect(std::shared_ptr<NetConnection<T>> client){}
        virtual void OnMessage(std::shared_ptr<NetConnection<T>> client, NetMessage<T>& message){}
    public:
        virtual void OnClientValidated(std::shared_ptr<NetConnection<T>> client){}
#pragma endregion custom methods
        
    };
}
