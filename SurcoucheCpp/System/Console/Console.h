#pragma once
#include <iostream>

#include "../../System.Collections.Generic/List/List.h"
#include "../../System/PrimaryType/String/String.h"
#include "../Object/Object.h"
#include "../TemplateUtils/TemplateUtils.h"

namespace System
{
    class Float;
    class Double;
    class Byte;
    class Integer;
    class Char;
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
        // static void WriteLine(const char* _str);
        // static void WriteLine(const Boolean& _bool);
        // static void WriteLine(const Float& _float);
        // static void WriteLine(const Double& _double);
        // static void WriteLine(const Byte& _byte);
        // // static void WriteLine(const String& _str);
        // static void WriteLine(const Integer& _int);
        template<typename... Args>
        static void WriteLine(const String& _str, Args... _args);
        // static void WriteLine(Char _char);
        static void SetIn(IO::TextReader _in);
        static void SetOut(IO::TextWriter _out);
        static void SetError(IO::TextWriter _error);
        static String ReadLine();
#pragma endregion custom methods
    };

    template <typename ... Args>
    void Console::WriteLine(const String& _str, Args... _args)
    {
        Collections::Generic::List<object*> _package = TemplateUtils::CreateListWithParameterPack<object*>(&_args...);
        const int _count = _package.Count();
        String _result = _str;
        for (int i = 0; i < _count; ++i)
        {
            _result = _result.Replace(string("{") + i + "}", _package[i]->ToString());
        }
        std::cout << _result << std::endl;
    }
}
