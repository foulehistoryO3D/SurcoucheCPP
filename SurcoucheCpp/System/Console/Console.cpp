#include "Console.h"

#include "../../System.IO/Exception/IOException/IOException.h"
#include "../../System.IO/File/File/File.h"
#include "../../System.IO/Stream/TextReader/TextReader.h"
#include "../../System.IO/Stream/TextWriter/TextWriter.h"
#include "../../System.IO/File/FileStream/FileStream.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Double/Double.h"
#include "../../System/PrimaryType/Byte/Byte.h"
#include "../../System/PrimaryType/Float/Float.h"
#include "../../System/PrimaryType/Integer/Integer.h"

System::IO::TextWriter System::Console::mOut = IO::TextWriter();
System::IO::TextReader System::Console::mIn = IO::TextReader();
System::IO::TextWriter System::Console::mError = IO::TextWriter();

System::IO::TextWriter& System::Console::Error()
{
    return mError;
}

System::IO::TextReader& System::Console::In()
{
    return mIn;
}

System::IO::TextWriter& System::Console::Out()
{
    return mOut;
}

void System::Console::WriteLine(const object* _object)
{
    std::cout << _object->ToString() << std::endl;
    Out().Write(_object);
}

void System::Console::WriteLine(const object& _object)
{
    std::cout << _object.ToString() << std::endl;
    Out().Write(_object);
}

void System::Console::WriteLine(const string* _str)
{
    std::cout << _str->ToString() << std::endl;
    Out().Write(_str);
}

void System::Console::WriteLine(const char* _str)
{
    std::cout << _str << std::endl;
    Out().Write(string(_str));
}

void System::Console::WriteLine(const Boolean& _bool)
{
    std::cout << _bool.ToString() << std::endl;
    Out().Write(_bool);
}

void System::Console::WriteLine(const Float& _float)
{
    std::cout << _float.ToString() << std::endl;
    Out().Write(_float);
}

void System::Console::WriteLine(const Double& _double)
{
    std::cout << _double.ToString() << std::endl;
    Out().Write(_double);
}

void System::Console::WriteLine(const Byte& _byte)
{
    std::cout << _byte.ToString() << std::endl;
    Out().Write(_byte);
}

void System::Console::WriteLine(const String& _str)
{
    std::cout << _str.ToString() << std::endl;
    Out().Write(_str);
}

void System::Console::WriteLine(const Integer& _int)
{
    std::cout << _int.ToString() << std::endl;
    Out().Write(_int);
}

void System::Console::WriteLine(char _char)
{
    std::cout << _char << std::endl;
    Out().Write(_char);
}

void System::Console::SetIn(IO::TextReader _in)
{
    if (!IO::File::Exists(_in.Path()))
    {
        if (!IO::File::Create(_in.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    mIn = std::move(_in);
}

void System::Console::SetOut(IO::TextWriter _out)
{
    if (!IO::File::Exists(_out.Path()))
    {
        if (!IO::File::Create(_out.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    mOut = std::move(_out);
}

void System::Console::SetError(IO::TextWriter _error)
{
    if (!IO::File::Exists(_error.Path()))
    {
        if (!IO::File::Create(_error.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    mError = std::move(_error);
}

System::String System::Console::ReadLine()
{
    // if (std::cin.get() == '\n') return "";
    // std::string _str = "";
    // std::getline(std::cin, _str);
    return string::Empty();
}
