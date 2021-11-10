#include <windows.h>

#include "System/IncludeSystem.h"
#include "System.Net/StringEventArgs/DownloadStringCompletedEventArgs.h"
#include "System.Net/WebClient/WebClient.h"
#include "System.Timers/ElapsedEventArgs/ElapsedEventArgs.h"
#include "System.Timers/Timer/Timer.h"
#include "System/Uri/Uri.h"

void OnDownloadCompleted(object* _sender, Net::DownloadStringCompletedEventArgs* _result)
{
    const string& _path = Path::Combine(Environment::CurrentDirectory(), "Sacramento.txt");
    FileStream _stream = File::Create(_path);
    _stream.Writer().Write(_result->Result());
    Diagnostics::Process::Start(_path);
}

void OnDownloadFileCompleted(object* _sender, Net::AsyncCompletedEventArgs* _event, const String& _path)
{
    if (_event->Cancelled())
        Console::WriteLine(string("File download cancelled."));
    else
        Diagnostics::Process::Start(_path);
}

void OnTimerCalled(object* _object, Timers::ElapsedEventArgs* _event)
{
    Console::WriteLine(_object->ToString() + " was call at " + _event->SignalTime().ToString());
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
    //
    Net::WebClient _req = Net::WebClient();
    const Uri& _uri = Uri("https://vp183.cdnweb.xyz/dl/Nkwhj96kVyU/1636556771/ddb57a47d119ca4506bb2a5e1ad642f8fb98660c2cf4e879d9a6b7d56949db21?file=aHR0cHM6Ly9yMS0tLXNuLTRnNWU2bnpsLmdvb2dsZXZpZGVvLmNvbS92aWRlb3BsYXliYWNrP2V4cGlyZT0xNjM2NTc0NzUyJmVpPXdOR0xZYnJfQm9LOTFnTFNtb0RBQlEmaXA9OTQuMTMwLjY5LjMyJmlkPW8tQUxYQThsRmtGR09waTg4VFhYTk1wbEtKaUU0LUNHaFpJY2syTExYOFRyTXgmaXRhZz0xOCZzb3VyY2U9eW91dHViZSZyZXF1aXJlc3NsPXllcyZtaD1WMyZtbT0zMSUyQzI5Jm1uPXNuLTRnNWU2bnpsJTJDc24tNGc1ZWRuc2UmbXM9YXUlMkNyZHUmbXY9bSZtdmk9MSZwbD0yMyZpbml0Y3duZGJwcz01NjAwMDAmdnBydj0xJm1pbWU9dmlkZW8lMkZtcDQmZ2lyPXllcyZjbGVuPTE4ODUyNzQ0JnJhdGVieXBhc3M9eWVzJmR1cj0yMzguOTMzJmxtdD0xNTkzODkxMjM0NjgwNDkwJm10PTE2MzY1NTI2MjgmZnZpcD0xJmZleHA9MjQwMDEzNzMlMkMyNDAwNzI0NiZjPUFORFJPSUQmdHhwPTU1MzE0MjImc3BhcmFtcz1leHBpcmUlMkNlaSUyQ2lwJTJDaWQlMkNpdGFnJTJDc291cmNlJTJDcmVxdWlyZXNzbCUyQ3ZwcnYlMkNtaW1lJTJDZ2lyJTJDY2xlbiUyQ3JhdGVieXBhc3MlMkNkdXIlMkNsbXQmc2lnPUFPcTBRSjh3UmdJaEFJTk5WRGZvVS1YU3lNNnhOX2ZxVnAxazVNQm5jeDJGRVRfM2Q1bDE0b2hiQWlFQW5YQ1c4NXBldW02eFd5SnpIV0lELWlLaU1HUlA5NVNZQnNxVXAtN2F6NmslM0QmbHNwYXJhbXM9bWglMkNtbSUyQ21uJTJDbXMlMkNtdiUyQ212aSUyQ3BsJTJDaW5pdGN3bmRicHMmbHNpZz1BRzNDX3hBd1JBSWdhX3RwUUFXeS1GbWxTYkdVR3NaZ09kdTFtYjdIOGRRWld1VFZmUEpJMDlNQ0lEaDZvemxKNmc4WV9qX3owSnRBYWdYWnpsS1BWSUQ2RGlOS1pNTzBrbW5CJmhvc3Q9cjEtLS1zbi00ZzVlNm56bC5nb29nbGV2aWRlby5jb20mbmFtZT15dDVzLmNvbS1QT1dFUldPTEYrLStSZXN1cnJlY3Rpb24rYnkrRXJlY3Rpb24rKE5ldytWZXJzaW9uKzIwMjApKyhPZmZpY2lhbCtMeXJpYytWaWRlbykrJTdjK05hcGFsbStSZWNvcmRzKDM2MHApLm1wNA");
    _req.OnDownloadProgress += [](float _f)
    {
        const char* _pbstr = "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
        const int _pbwidth = 60;

        const int _pad = (_f/100) * _pbwidth;
        const int _rpad = _pbwidth - _pad;
        printf("\r%3f%% [%.*s%*s]", _f, _pad, _pbstr, _rpad, "");
    };
    _req.DownloadFileCompleted += OnDownloadFileCompleted;
    _req.DownloadFileAsync(_uri, Path::Combine(Environment::CurrentDirectory(), "powerwolf.mp4"));
    std::this_thread::sleep_for(std::chrono::seconds(60 * 2));

    return 0;
}
