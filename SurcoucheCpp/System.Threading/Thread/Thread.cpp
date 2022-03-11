#include "Thread.h"

#include "../../System/Console/Console.h"

#pragma region f/p
string System::Threading::Thread::Name() const
{
    return this->threadName;
}

System::Bool System::Threading::Thread::IsAlive() const
{
    return this->isAlive;
}

System::Int System::Threading::Thread::ID() const
{
    return std::hash<std::thread::id>{}(this->thread.get_id());
}
#pragma endregion f/p

#pragma region constructor/destructor
System::Threading::Thread::Thread(const Thread& copy) : Object(copy)
{
    this->threadName = std::move(copy.threadName);
    this->isAlive = std::move(copy.isAlive);
    this->isBecomeJoin = std::move(copy.isBecomeJoin);
    this->timeoutJoin = std::move(copy.timeoutJoin);
    this->isSleep = std::move(copy.isSleep);
    this->sleepTime = std::move(copy.sleepTime);
    this->function = std::move(copy.function);
    this->thread = std::thread(&Thread::Update, this);
    this->thread.detach();
}

System::Threading::Thread::~Thread()
{
    if (this->thread.joinable())
        this->thread.join();
}
#pragma endregion constructor/destructor
#pragma region custom methods
void System::Threading::Thread::Update()
{
    while (this->isAlive)
    {
        if (this->isSleep)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(this->sleepTime));
            this->isSleep = false;
        }
        if (this->isBecomeJoin)
        {
            if (this->timeoutJoin < 0) Join();
            else --this->timeoutJoin;
        }
        this->function();
    }
}

void System::Threading::Thread::Join()
{
    this->isAlive = false;
    if (this->thread.joinable())
        this->thread.join();
}

void System::Threading::Thread::Join(const Int& millisecondsTimeout)
{
    if (!this->isAlive)return;
    this->isBecomeJoin = true;
    this->timeoutJoin = millisecondsTimeout;
}

void System::Threading::Thread::Sleep(const Int& millisecondsTimeout)
{
    if (!this->isAlive)return;
    this->sleepTime = millisecondsTimeout;
    this->isSleep = true;
}

void System::Threading::Thread::SetThreadName(const string& newName)
{
    this->threadName = newName;
}
#pragma endregion custom methods
#pragma region override
System::String System::Threading::Thread::ToString() const
{
    return string::Format("name: {0}, id: {1}", this->Name(), this->ID());
}

System::Integer System::Threading::Thread::GetHashCode() const
{
    return this->ID().GetHashCode();
}

System::Threading::Thread& System::Threading::Thread::operator=(const Thread& other)
{
    this->threadName = std::move(other.threadName);
    this->isAlive = std::move(other.isAlive);
    this->isBecomeJoin = std::move(other.isBecomeJoin);
    this->timeoutJoin = std::move(other.timeoutJoin);
    this->isSleep = std::move(other.isSleep);
    this->sleepTime = std::move(other.sleepTime);
    this->function = std::move(other.function);
    return *this;
}
#pragma endregion override
