#include "AssertMacro.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Float/Float.h"
#include "../../Console/Enum/ConsoleColor.h"
#include "../../Console/Console.h"

#include <cstdarg>

#include "../Template/TemplateMacro.h"

void System::AssertMacro::CheckVerifyFailed(const char* expr, const char* functionName, const int line,  const wchar_t* format, ...)
{
    va_list args;
    va_start(args, format);
    va_end(args);
    const string message = string("error: ") + expr + " in function: " + functionName + " line: " + Int(line).ToString();
    Console::WriteLineColor(message, ConsoleColor::Red);
}

void System::AssertMacro::DebugWarningDeprecated(const int line, const char* message)
{
    const string messageWarning = string("Line: ") + Int(line) + " " + message;
    Console::WriteLineColor(messageWarning, ConsoleColor::Yellow);
}

void System::AssertMacro::DebugWarningDeprecatedVersion(const int line, const float version, const char* message)
{
    const string messageWarning = string("Line: ") + Int(line) + " " + message + ", old version: " + Float(version).ToString(2);
    Console::WriteLineColor(messageWarning, ConsoleColor::Yellow);
}
