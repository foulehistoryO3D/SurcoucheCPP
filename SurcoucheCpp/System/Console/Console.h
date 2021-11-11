#pragma once
#include <iostream>
#include "../Object/Object.h"

namespace System
{
    class Float;
    class Double;
    class Byte;
    class Integer;
    namespace IO
    {
        class TextWriter;
        class TextReader;
    }
    class Console : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        static IO::TextWriter mOut;
        static IO::TextReader mIn;
        static IO::TextWriter mError;
#pragma endregion f/p
#pragma region custom methods
     public:
        static IO::TextWriter& Error();
        static IO::TextReader& In();
        static IO::TextWriter& Out();
        
        static void WriteLine(const object* _object);
        static void WriteLine(const object& _object);
        static void WriteLine(const String* _str);
        static void WriteLine(const char* _str);
        static void WriteLine(const Boolean& _bool);
        static void WriteLine(const Float& _float);
        static void WriteLine(const Double& _double);
        static void WriteLine(const Byte& _byte);
        static void WriteLine(const String& _str);
        static void WriteLine(const Integer& _int);
        static void WriteLine(char _char);
        static void SetIn(IO::TextReader _in);
        static void SetOut(IO::TextWriter _out);
        static void SetError(IO::TextWriter _error);
        static String ReadLine();
#pragma endregion custom methods
    };

}
