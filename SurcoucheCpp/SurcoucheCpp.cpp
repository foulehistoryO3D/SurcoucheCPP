#include <windows.h>

#include "System/IncludeSystem.h"
#include "System.Net/StringEventArgs/DownloadStringCompletedEventArgs.h"
#include "System.Net/WebClient/WebClient.h"
#include "System.Timers/ElapsedEventArgs/ElapsedEventArgs.h"
#include "System/Uri/Uri.h"

void OnDownloadCompleted(object* _sender, Net::DownloadStringCompletedEventArgs* _result)
{
    const string& _path = Path::Combine(Environment::CurrentDirectory(), "Sacramento.txt");
    FileStream _stream = File::Create(_path);
    _stream.Writer().Write(_result->Result());
    Diagnostics::Process::Start(_path);
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
    // LPCWSTR _uri = L"https://raw.githubusercontent.com/foulehistory/SurcoucheCPP/master/DateTime/Time.txt";

    Net::WebClient _req = Net::WebClient();
    _req.DownloadStringCompleted = OnDownloadCompleted;
    _req.DownloadStringAsync(Uri("https://cdn.discordapp.com/attachments/227541817963446272/763337270324756490/test.txt"));
    return 0;
}
