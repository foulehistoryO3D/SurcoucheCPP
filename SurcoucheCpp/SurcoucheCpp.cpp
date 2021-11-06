#include <windows.h>
#include "System/IncludeSystem.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    LanguageManager::Instance().AddLanguage(Language("fr", "french.txt"));
    LanguageManager::Instance().AddLanguage(Language("en", "english.txt"));
    const String& _message = LanguageManager::Instance().GetLanguage("en").GetMessages("hello");
    const String& _result = LanguageManager::Instance().Translate(_message, "Thomas", "good");
    Console::WriteLine(_result);
    return 0;
}
