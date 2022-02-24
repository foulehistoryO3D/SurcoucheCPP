#pragma once
#include "../../../System.Utils/Template/IsPointer/IsPointer.h"
#include "../../Console/Console.h"
#include "../../Object/Object.h"

namespace System
{
    struct Memory sealed : Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
    public:
        template<typename T>
        static FORCEINLINE void Memset(T& src, uint8 valueToSet)
        {
            if (IsPointer<T>::Value)
            {
                Console::WriteLineColor(string("For pointers use the three parameters function"), ConsoleColor::Red);
                return;
            }
            ::memset(&src, valueToSet, sizeof(T));
        }

        static FORCEINLINE void* Memset(void* Dest, uint8 Char, size_t count)
        {
            return ::memset(Dest, Char, count);
        }

        template<typename T>
        static FORCEINLINE void MemZero(T& src)
        {
            if (IsPointer<T>::Value)
            {
                Console::WriteLineColor(string("For pointers use the two parameters function"), ConsoleColor::Red);
                return;
            }
            ::memset(&src, 0, sizeof(T));
        }

        static FORCEINLINE void* MemZero(void* dest, size_t count)
        {
            return ::memset(dest, 0, count);
        }
    };
}
