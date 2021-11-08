#include <windows.h>
#include "System/IncludeSystem.h"
#include "System/Random/Random.h"

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    // LanguageManager::Instance().AddLanguage(new Language("fr", "french.txt"));
    // LanguageManager::Instance().AddLanguage(new Language("en", "english.txt"));
    // LanguageManager::Instance().GetLanguage("fr").AddMessageToFile("salut", "Salut comment vas-tu ? @0");
    // const String& _message = LanguageManager::Instance().GetLanguage("fr").GetMessages("salut");
    // const String& _result = LanguageManager::Instance().Translate(_message, "Romain");
    // Console::WriteLine(_result);
    Random _random = Random();
    for (Type* _type : _random.Assembly())
    {
        Console::WriteLine(_type->ToString());
    }
    return 0;
}
