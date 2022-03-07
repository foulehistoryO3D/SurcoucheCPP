#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/String/String.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename T>
            class Stack sealed : public Object
            {
                static_assert(std::is_base_of_v<Object, T>, "Stack T must be an Object");
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                int top = -1;
                inline static constexpr int arrayMax = 1000;
                T array[arrayMax];
            public:
                typedef T* iterator;
                typedef const T* const_iterator;
                iterator begin() { return &array[0];}
                const_iterator begin() const { return &array[0];}
                iterator end() { return &array[top+1];}
                const_iterator end()const { return &array[top+1];}
#pragma endregion f/p
#pragma region constructor
            public:
                Stack() = default;
#pragma endregion constructor
#pragma region custom methods
            public:
                Boolean Push(T item)
                {
                    if (this->top >= (this->arrayMax - 1)) return false;
                    this->array[++this->top] = item;
                    return true;
                }

                T Pop()
                {
                    if (this->top < 0) return T();
                    return this->array[this->top--];
                }

                T Peek()
                {
                    if (this->top < 0) return T();
                    return this->array[this->top];
                }

                Boolean IsEmpty()const { return this->top < 0; }
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override
                {
                    string result = string::Empty;
                    for (int i = this->top; i > -1; --i)
                        result += this->array[i].ToString() + " ";
                    return result;
                }
                Integer GetHashCode() const override
                {
                    int result = 0;
                    for (int i = this->top; i > -1; --i)
                        result += this->array[i].GetHashCode();
                    return result;
                }
#pragma endregion override
            };
        }
    }
}
