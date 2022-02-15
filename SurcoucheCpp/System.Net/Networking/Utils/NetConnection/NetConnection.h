#pragma once
#include <memory>

#include "../NetInclude.h"
#include "../NetMessage/NetMessage.h"
#include "../NetQueue/NetQueue.h"

namespace Net
{
    template<typename T>
    class NetServerInterface;

    template<typename T>
    class NetConnection : public std::enable_shared_from_this<NetConnection<T>>
    {
#pragma region enum
    public:
        enum class NetOwner { Server, Client };
#pragma endregion enum
#pragma region f/p
    protected:
        asio::ip::tcp::socket socket                = asio::ip::tcp::socket(nullptr);
        asio::io_context& asioContext               = asio::io_context();
        NetQueue<NetMessage<T>> messagesOut         = NetQueue<NetMessage<T>>();
        NetQueue<NetOwnedMessage<T>> messagesIn     = NetQueue<NetOwnedMessage<T>>();
        NetMessage<T> messageTemporaryIn            = NetMessage<T>();
        NetOwner owner                              = NetOwner::Server;

        uint64_t handShakeOut                       = 0;
        uint64_t handShakeIn                        = 0;
        uint64_t handShakeCheck                     = 0;

        bool validHandShake                         = false;
        bool connectionEstablished                  = false;
        uint32_t id = 0;
    public:
        uint32_t ID() const { return id;}
#pragma endregion f/p
#pragma region constructor / destructor
    public:
        NetConnection(NetOwner parent, asio::io_context& asioContext, asio::ip::tcp::socket socket, NetQueue<NetOwnedMessage<T>>& messagesIn)
        {
            this->asioContext   = asioContext;
            this->socket        = std::move(socket);
            this->messagesIn    = messagesIn;
            this->owner         = parent;

            if (owner == NetOwner::Server)
            {
                handShakeOut = std::chrono::system_clock::now().time_since_epoch().count();
                handShakeCheck = Scramble(handShakeOut);
            }
            else
            {
                handShakeIn = 0;
                handShakeOut = 0;
            }
        }
        virtual ~NetConnection() { }
#pragma endregion constructor / destructor
#pragma region custom methods
    public:
        void ConnectToClient(NetServerInterface<T>* server, uint32_t uid = 0)
        {
            if (this->owner == NetOwner::Server)
            {
                if (this->socket.is_open())
                {
                    id = uid;
                    WriteValidation();
                    ReadValidation(server);
                }
            }
        }

        void ConnectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
        {
            if (this->owner == NetOwner::Client)
            {
                asio::async_connect(this->socket, endpoints, [this](const std::error_code ec, asio::ip::tcp::endpoint endpoint)
                {
                   if (!ec) ReadValidation(); 
                });
            }
        }

        void Disconnect()
        {
            if (IsConnected()) asio::post(this->asioContext, [this] { this->socket.close(); });
        }

        bool IsConnected()const
        {
            return this->socket.is_open();
        }

        void StartListening(){}

        void Send(const NetMessage<T>& message)
        {
            asio::post(this->asioContext, [this, message]
            {
                const bool writingMessage = ! messagesOut.Empty();
                messagesOut.PushBack(message);
                if (!writingMessage) WriteHeader();
            });
        }

    private:
        void WriteHeader()
        {
            asio::async_write(this->socket, asio::buffer(&messagesOut.Front().Header, sizeof NetMessageHeader<T>),
                [this](const std::error_code ec, size_t length)
                {
                   if (!ec)
                   {
                       if (messagesOut.Front().Body.size() > 0) WriteBody();
                       else
                       {
                           messagesOut.PopFront();
                           if (!messagesOut.Empty()) WriteHeader();
                       }
                   }
                    else
                    {
                        std::cout << "[" << id << "] Write Header Fail." << std::endl;
                        this->socket.close();
                    }
                });
        }

        void WriteBody()
        {
            asio::async_write(this->socket, asio::buffer(messagesOut.Front().Body.data(), messagesOut.Front().Body.size()),
                [this](const std::error_code ec, size_t length)
                {
                   if (!ec)
                   {
                       messagesOut.PopFront();
                       if (!messagesOut.Empty()) WriteHeader();
                   }
                    else
                    {
                        std::cout << "[" << id << "] Write Body Fail." << std::endl;
                        this->socket.close();
                    }
                });
        }

        void ReadHeader()
        {
            asio::async_read(this->socket, asio::buffer(&messageTemporaryIn.Header, sizeof NetMessageHeader<T>),
                [this](const std::error_code ec, size_t length)
                {
                   if (!ec)
                   {
                       if (messageTemporaryIn.Header.Size > 0)
                       {
                           messageTemporaryIn.Body.resize(messageTemporaryIn.Header.Size);
                            ReadBody();
                       }
                       else AddToIncomingMessageQueue();
                   }
                    else
                    {
                        std::cout << "[" << id << "] Read Header Fail." << std::endl;
                    }
                });
        }

        void ReadBody()
        {
            asio::async_read(this->socket, asio::buffer(messageTemporaryIn.Body.data(), messageTemporaryIn.Body.size()),
                [this](const std::error_code ec, size_t length)
                {
                   if (!ec) AddToIncomingMessageQueue();
                    else
                    {
                        std::cout << "[" << id << "] Read Body Fail." << std::endl;
                        this->socket.close();
                    }
                });
        }

        static uint64_t Scramble(uint64_t input)
        {
            uint64_t out = input ^ 0xDEADBEEFC0DECAFE;
            out = (out & 0xF0F0F0F0F0F0F0) >> 4 | (out & 0xF0F0F0F0F0F0F0) << 4;
                return out ^ 0xC0DEFACE12345678;
        }

        void WriteValidation()
        {
            asio::async_write(this->socket, asio::buffer(&handShakeOut, sizeof(uint64_t),
                [this](const std::error_code ec, size_t length)
                {
                    if (!ec)
                    {
                        if (this->owner == NetOwner::Client) ReadHeader();
                    }
                    else this->socket.close();
                }));
        }

        void ReadValidation(NetServerInterface<T>* server = nullptr)
        {
            asio::async_read(this->socket, asio::buffer(&handShakeIn, sizeof uint64_t),
                [this, server](const std::error_code ec, size_t length)
                {
                   if (!ec)
                   {
                       if (this->owner == NetOwner::Server)
                       {
                           if (this->handShakeIn == this->handShakeCheck)
                           {
                               std::cout << "Client Validated" << std::endl;
                               server->OnClientValidated(this->shared_from_this());
                               ReadHeader();
                           }
                           else
                           {
                               std::cout << "Client Disconnected (Fail Validation)" << std::endl;
                               this->socket.close();
                           }
                       }
                       else
                       {
                           this->handShakeOut = Scramble(this->handShakeIn);
                           WriteValidation();
                       }
                   }
                    else
                    {
                        std::cout << "Client Disconnected (ReadValidation)" << std::endl;
                        this->socket.close();
                    }
                });
        }

        void AddToIncomingMessageQueue()
        {
            if (this->owner == NetOwner::Server)
                this->messagesIn.PushBack({this->shared_from_this(), this->messageTemporaryIn});
            else
                this->messagesIn.PushBack({nullptr, this->messageTemporaryIn});
            ReadHeader();
        }
        
#pragma endregion custom methods
    };
}
