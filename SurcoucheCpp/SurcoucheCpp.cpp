#include <windows.h>

#include "System/IncludeSystem.h"
#include "System.Text/StringBuilder/StringBuilder.h"
#include "System.Timers/ElapsedEventArgs/ElapsedEventArgs.h"
#include "System.Timers/Timer/Timer.h"

#pragma comment(lib, "urlmon.lib")

#include <urlmon.h>
#include <sstream>

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
    // Timers::Timer _timer = Timers::Timer(1000);
    // _timer.Elapsed += OnTimedEvent;
    // _timer.Start();
    
    IStream* stream = null;

    LPCWSTR _uri = L"https://raw.githubusercontent.com/foulehistory/SurcoucheCPP/master/DateTime/Time.txt";
#pragma region hide
    HRESULT result = URLOpenBlockingStream(0, _uri, &stream, 0, 0);
    
    if (result != 0)
    {
        return 1;
    }
    char buffer[100];
    unsigned long bytesRead;
    std::stringstream ss;
    stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U)
    {
        ss.write(buffer, (long long)bytesRead);
        stream->Read(buffer, 100, &bytesRead);
    }
    stream->Release();
#pragma endregion hide
    string resultString = ss.str().c_str();

    const string& _path = Path::Combine(Environment::CurrentDirectory(), "Sacramento.txt");
    FileStream _stream = File::Create(_path);
    _stream.Writer().Write(resultString);
    Diagnostics::Process::Start(_path);
    return 0;
}
