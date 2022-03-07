#pragma once
#include <functional>
#include <thread>

#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/String/String.h"

namespace System
{
    namespace Threading
    {
        class Thread sealed : public Object
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            std::thread thread                  = std::thread();
            string threadName                   = string::Empty;
            Bool isAlive                        = false;
            Bool isBecomeJoin                   = false;
            Int timeoutJoin                     = 0;
            Bool isSleep                        = false;
            Int sleepTime                       = 0;
            std::function<void()> function      = null;
        public:
            string Name() const;
            Bool IsAlive() const;
            Int ID() const;
#pragma endregion f/p
#pragma region constructor/destructor
            Thread() = default;
            template <class Function, class... Args>
            Thread(const string& threadName, Function&& function, Args&&... args);
            template <class Function, class... Args>
            Thread(Function&& function, Args&&... args);
            Thread(const Thread& copy);
            ~Thread() override;
#pragma endregion constructor/destructor
#pragma region custom methods
        private:
            void Update();
        public:
            void Join();
            void Join(const Int& millisecondsTimeout);
            void Sleep(const Int& millisecondsTimeout);
            void SetThreadName(const string& newName);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            Thread& operator=(const Thread& other);
#pragma endregion operator
        };

        template <class Function, class... Args>
        Thread::Thread(const string& threadName, Function&& function, Args&&... args)
        {
            this->threadName = threadName;
            this->function = [&] { function(args...); };
            this->thread = std::thread(&Thread::Update, this);
            this->isAlive = true;
            this->thread.detach();
        }

        template <class Function, class ... Args>
        Thread::Thread(Function&& function, Args&&... args)
        {
            this->threadName = string::Empty;
            this->function = [&] { function(args...); };
            this->thread = std::thread(&Thread::Update, this);
            this->isAlive = true;
            this->thread.detach();
        }
    }
}
