#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    namespace Utils
    {
        template<typename T>
        class Singleton : public Object
        {
#pragma region f/p
        private:
            static T* instance;
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            Singleton();
            ~Singleton()override;
#pragma endregion constructor/destructor
#pragma region custom methods
        public:
            static T& Instance();
            void Destroy();
#pragma endregion custom methods
        };
        template<typename T>
        T* Singleton<T>::instance = null;
        template <typename T>
        Singleton<T>::Singleton() : Object()
        {
        }

        template <typename T>
        Singleton<T>::~Singleton()
        {
            delete instance;
        }

        template <typename T>
        T& Singleton<T>::Instance()
        {
            if (!instance)
                instance = new T();
            return *instance;
        }

        template <typename T>
        void Singleton<T>::Destroy()
        {
            this->~Singleton();
        }
    }
}
