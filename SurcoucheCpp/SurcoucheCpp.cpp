#include <thread>
#include <windows.h>
#include "System/IncludeSystem.h"
#include "System.Text/StringBuilder/StringBuilder.h"
#include "System.Timers/ElapsedEventArgs/ElapsedEventArgs.h"
#include "System.Timers/Timer/Timer.h"

void OnTimedEvent(object* _sender, Timers::ElapsedEventArgs* _event)
{
    Console::WriteLine(_sender->ToString() + " event was raised at " + _event->SignalTime().ToString());
}

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    // LanguageManager::Instance().AddLanguage(new Language("fr", "french.txt"));
    // LanguageManager::Instance().AddLanguage(new Language("en", "english.txt"));
    // LanguageManager::Instance().GetLanguage("fr").AddMessageToFile("salut", "Salut comment vas-tu ? @0");
    // const String& _message = LanguageManager::Instance().GetLanguage("fr").GetMessages("salut");
    // const String& _result = LanguageManager::Instance().Translate(_message, "Romain");
    Timers::Timer _timer = Timers::Timer(10);
    _timer.Elapsed += OnTimedEvent;
    _timer.Start();
    return 0;
}
