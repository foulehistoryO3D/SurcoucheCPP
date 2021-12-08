#pragma once
#include <iostream>

#include "../../System.Collections.Generic/List/List.h"
#include "../../System/PrimaryType/String/String.h"
#include "../Object/Object.h"
#include "../TemplateUtils/TemplateUtils.h"
#include "../../System.IO/Stream/TextWriter/TextWriter.h"
#include "../../System.IO/Stream/TextReader/TextReader.h"

namespace System
{
    class Float;
    class Double;
    class Byte;
    class Integer;
    class Char;
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
        template<typename... Args>
        static void WriteLine(const String& _str, Args... _args);
        // static void WriteLine(Char _char);
        static void SetIn(IO::TextReader _in);
        static void SetOut(IO::TextWriter _out);
        static void SetError(IO::TextWriter _error);
        static String ReadLine();
        static void Dispose();
#pragma endregion custom methods
    };

    template <typename ... Args>
    void Console::WriteLine(const String& _str, Args... _args)
    {
        Collections::Generic::List<object*> _package = TemplateUtils::CreateListWithParameterPack<object*>(&_args...);
        const int _count = _package.Count();
        String _result = _str;
        for (int i = 0; i < _count; ++i)
            _result = _result.Replace(string("{") + i + "}", _package[i]->ToString());
        
        std::cout << _result << std::endl;
        Out().Write(_result);
    }
}
