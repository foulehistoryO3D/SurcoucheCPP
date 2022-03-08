#include "Console.h"

#include "../../System.IO/Exception/IOException/IOException.h"
#include "../../System.IO/File/File/File.h"
#include "../../System.IO/Stream/TextReader/TextReader.h"
#include "../../System.IO/Stream/TextWriter/TextWriter.h"
#include "../../System.IO/File/FileStream/FileStream.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System.IO/Path/Path.h"
#include "../Environment/Environment.h"

System::IO::TextWriter System::Console::Out = OutInternal();
System::IO::TextReader System::Console::In = InInternal();
System::IO::TextWriter System::Console::Error = ErrorInternal();

System::String System::Console::DirectoryPath()
{
    return IO::Path::Combine(Environment::CurrentDirectory(), "Log");
}

System::IO::TextWriter System::Console::OutInternal()
{
    const string& path = IO::Path::Combine(DirectoryPath(), "Out.txt");
    if (!IO::File::Exists(path))
        IO::File::Create(path);

    IO::TextWriter writer = IO::TextWriter(path);
    writer.Clear();
    return writer;
}

System::IO::TextReader System::Console::InInternal()
{
    const string& path = IO::Path::Combine(DirectoryPath(), "In.txt");
    if (!IO::File::Exists(path))
        IO::File::Create(path);
    return path;
}

System::IO::TextWriter System::Console::ErrorInternal()
{
    const string& path = IO::Path::Combine(DirectoryPath(), "Error.txt");
    if (!IO::File::Exists(path))
        IO::File::Create(path);

    IO::TextWriter writer = IO::TextWriter(path);
    writer.Clear();
    return writer;
}

void System::Console::WriteLine(const object* _object)
{
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::Gray));
    std::cout << _object->ToString() << std::endl;
    Out.Write(_object);
}

void System::Console::WriteLine(const object& _object)
{
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::Gray));
    std::cout << std::setprecision(1)<< _object.ToString() << std::fixed << std::endl;
    Out.Write(_object);
}

void System::Console::WriteLine(const string& str)
{
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::Gray));
    std::cout << str << std::endl;
    Out.Write(str);
}

void System::Console::WriteLineColor(const object& obj, const ConsoleColor& color)
{
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    std::cout << obj.ToString() << std::endl;
    Out.Write(obj);
}

void System::Console::SetIn(IO::TextReader _in)
{
    if (!IO::File::Exists(_in.Path()))
    {
        if (!IO::File::Create(_in.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    In = std::move(_in);
}

void System::Console::SetOut(IO::TextWriter _out)
{
    if (!IO::File::Exists(_out.Path()))
    {
        if (!IO::File::Create(_out.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    Out = std::move(_out);
}

void System::Console::SetError(IO::TextWriter _error)
{
    if (!IO::File::Exists(_error.Path()))
    {
        if (!IO::File::Create(_error.Path()).Exists())
            throw IO::IOException("error on created file");
    }
    Error = std::move(_error);
}

System::String System::Console::ReadLine()
{
    Collections::Generic::List<string> list = IO::File::ReadAllLines(Out.Path());
    return list[list.Count()-1];
}

void System::Console::Dispose()
{
    Out.Dispose();
    In.Dispose();
    Error.Dispose();
}
