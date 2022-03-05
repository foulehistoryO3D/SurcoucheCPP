#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/Utils/Template/AreTypesEqual.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename T>
            class Queue sealed : public Object
            {
                static_assert(std::is_base_of_v<Object, T>, "Queue T must be an Object");
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                T* array        = null;
                int capacity    = 0;
                int count       = 0;
                int front       = 0;
                int rear        = -1;
            public:
#pragma endregion f/p
#pragma region constructor
            public:
                Queue() = default;
                Queue(unsigned capacity)
                {
                    this->capacity  = capacity;
                    this->front     = 0;
                    this->rear      = -1;
                    this->count     = 0;
                    this->array     = new T[this->capacity];
                }
#pragma endregion constructor
#pragma region custom methods
            public:
                Boolean IsFull()const { return this->count == this->capacity; }
                Boolean IsEmpty()const { return this->count == 0; }
                void Dequeue()
                {
                    if (IsEmpty()) return;
                    front = (this->front + 1) % this->capacity;
                    this->count -1;
                }
                void EnQueue(T item)
                {
                    if (IsFull()) return;
                    this->rear = (this->rear + 1) % this->capacity;
                    this->array[this->rear] = item;
                    ++this->count;
                }
                T Peek()
                {
                    if (IsEmpty()) return T();
                    return this->array[this->front];
                }
#pragma endregion custom methods
#pragma region override
            public:
                Integer Count() const { return this->count; }
                String ToString() const override
                {
                    string result = string::Empty;
                    for (int i = 0; i < this->count; ++i)
                        result += this->array[i].ToString() + " ";
                    return result;
                }
                Integer GetHashCode() const override
                {
                    int result = 0;
                    for (int i = 0; i < this->count; ++i)
                        result += this->array[i].GetHashCode();
                    return result;
                }
#pragma endregion override
            };
        }
    }
}
