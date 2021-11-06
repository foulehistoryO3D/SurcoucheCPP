#include <windows.h>
#include "System/IncludeSystem.h"
#include "System/LanguageManager/LanguageManager.h"


template<typename First, typename... Args>
auto Get(size_t _index, First& _arg, Args&&... _args)
{
    if (_index == 0) return _arg;
    return Get(_index--, std::forward<Args>(_args)...);
}

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
