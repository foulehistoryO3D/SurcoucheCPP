#pragma once
#include <iostream>

#include "../Object/Object.h"

namespace System
{
    class Console : public Object
    {
    public:
        static void WriteLine(const object* _object);
        static void WriteLine(const object& _object);
        static void WriteLine(const string* _str);
        static void WriteLine(const Boolean& _bool);
        static void WriteLine(const Float& _float);
        static void WriteLine(const Double& _double);
        static void WriteLine(const Byte& _byte);
        static void WriteLine(const String& _str);
    };

    inline void Console::WriteLine(const object* _object)
    {
        std::cout << _object->ToString() << std::endl;
    }

    inline void Console::WriteLine(const object& _object)
    {
        std::cout << _object.ToString() << std::endl;
    }

    inline void Console::WriteLine(const string* _str)
    {
        std::cout << _str->ToString() << std::endl;
    }

    inline void Console::WriteLine(const Boolean& _bool)
    {
        std::cout << _bool.ToString() << std::endl;
    }

    inline void Console::WriteLine(const Float& _float)
    {
        std::cout << _float.ToString() << std::endl;
    }

    inline void Console::WriteLine(const Double& _double)
    {
        std::cout << _double.ToString() << std::endl;
    }

    inline void Console::WriteLine(const Byte& _byte)
    {
        std::cout << _byte.ToString() << std::endl;
    }

    inline void Console::WriteLine(const String& _str)
    {
        std::cout << _str.ToString() << std::endl;
    }
}
