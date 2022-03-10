#pragma once
#include <iostream>

#include "../../System.Collections.Generic/List/List.h"
#include "../../System/PrimaryType/String/String.h"
#include "../Object/Object.h"
#include "../TemplateUtils/TemplateUtils.h"
#include "../../System.IO/Stream/TextWriter/TextWriter.h"
#include "../../System.IO/Stream/TextReader/TextReader.h"
#include "../../System.Text.RegularExpressions/Regex/Regex.h"
#include "../PrimaryType/Double/Double.h"
#include "../PrimaryType/Float/Float.h"
#include "Enum/ConsoleColor.h"
#include "../PrimaryType/Array/Array.h"

namespace System
{
    class Float;
    class Double;
    class Byte;
    class Integer;
    class Char;

    class Console sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
    private:
        inline static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    public:
        static IO::TextWriter Out;
        static IO::TextReader In;
        static IO::TextWriter Error;
#pragma endregion f/p
#pragma region custom methods
    private:
        static String DirectoryPath();
        static IO::TextWriter OutInternal();
        static IO::TextReader InInternal();
        static IO::TextWriter ErrorInternal();
        template <class ... Args>
        static void FormatDecimalValue(Collections::Generic::List<object*> _package, String& result, int i,
                                       Text::RegularExpressions::Regex regex);
    public:
        static void WriteLine(const object* _object);
        static void WriteLine(const object& _object);
        static void WriteLine(const string& str);
        static void WriteLineColor(const object& obj, const ConsoleColor& color);

        template <typename... Args>
        static void WriteLine(const String& _str, Args ... _args);
        // static void WriteLine(Char _char);
        static void SetIn(IO::TextReader _in);
        static void SetOut(IO::TextWriter _out);
        static void SetError(IO::TextWriter _error);
        static String ReadLine();
        static void Dispose();
#pragma endregion custom methods
    };

    template <typename ... Args>
    void Console::FormatDecimalValue(Collections::Generic::List<object*> _package, String& result, int i,
                                     Text::RegularExpressions::Regex regex)
    {
        std::ostringstream ostringstream = std::ostringstream();
        string findedStr = regex.Find(result)[0];
        const int index = findedStr.FirstIndexOf(':') + 1;
        Int precision = Int::Parse(findedStr.SubString(index, index + 1));
        if (Float* f = dynamic_cast<Float*>(_package[i]))
            ostringstream << std::fixed << std::setprecision(precision) << f->operator*();
        else if (Double* d = dynamic_cast<Double*>(_package[i]))
            ostringstream << std::fixed << std::setprecision(precision) << d->operator*();
        result = regex.Replace(result, ostringstream.str().c_str());
    }

    template <typename ... Args>
    void Console::WriteLine(const String& _str, Args ... _args)
    {
        SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::Gray));
        Collections::Generic::List<object*> _package = TemplateUtils::CreateListWithParameterPack<object*>(&_args...);
        const int _count = _package.Count();
        String result = _str;
        for (int i = 0; i < _count; ++i)
        {
            Text::RegularExpressions::Regex regex = Text::RegularExpressions::Regex(string("\\{") + i + ":\\d\\w\\}");
            if (regex.IsMatch(result))
                FormatDecimalValue<Args...>(_package, result, i, regex);
            else
            {
                regex = Text::RegularExpressions::Regex(string("\\{") + i + "\\}");
                if (regex.IsMatch(result))
                    result = regex.Replace(result, _package[i]->ToString());
            }
        }
        std::cout << result << std::endl;
        
        Out.Write(string("[Log] => ") + result);
    }
}
