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
        Console::WriteLine(string("File downloda cancelled."));
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
    bool _isFinish = false;
    Net::WebClient _req = Net::WebClient();
    const Uri& _uri = Uri("https://r2---sn-n4v7snl7.googlevideo.com/videoplayback?expire=1636574060&ei=DM-LYeeZJ8-xkgau4Ln4Cg&ip=154.21.20.21&id=o-AANCKa0SGSwEUk7AvrxAlQY7rcmi2zOeEZNCEA6t6yv2&itag=18&source=youtube&requiressl=yes&mh=fm&mm=31%2C29&mn=sn-n4v7snl7%2Csn-o097znze&ms=au%2Crdu&mv=m&mvi=2&pl=20&initcwndbps=1313750&vprv=1&mime=video%2Fmp4&ns=DXJj40rw1N_bkjDhq6dm12kG&gir=yes&clen=63285981&ratebypass=yes&dur=900.051&lmt=1612957552028188&mt=1636552149&fvip=2&fexp=24001373%2C24007246&c=WEB&txp=5530434&n=NL97aMX1W0yiBA&sparams=expire%2Cei%2Cip%2Cid%2Citag%2Csource%2Crequiressl%2Cvprv%2Cmime%2Cns%2Cgir%2Cclen%2Cratebypass%2Cdur%2Clmt&lsparams=mh%2Cmm%2Cmn%2Cms%2Cmv%2Cmvi%2Cpl%2Cinitcwndbps&lsig=AG3C_xAwRQIgWF1nT8CVCV75K880rye_s_A1_M-jDKhrD6UxsdCKIckCIQD_vKO_wZZoK8eJu6iVRNhd-RXj9begIX9Nk422dKWHIQ%3D%3D&sig=AOq0QJ8wRQIgMMLdbnQ-E8evCgBPBA3JBdN4n071erjh3XbE8CYAd00CIQD58-foK5UIhZJOvLGjsfXWTQZWknsBflNyE6p5n7NG6A%3D%3D");
    _req.OnDownloadProgress += [](float _f)
    {
        const char* _pbstr = "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
        const int _pbwidth = 30;

        const int _pad = (_f/100) * _pbwidth;
        const int _rpad = _pbwidth - _pad;
        printf("\r%3f%% [%.*s%*s]", _f, _pad, _pbstr, _rpad, "");
    };
    _req.DownloadFileCompleted += OnDownloadFileCompleted;
    _req.DownloadFileAsync(_uri, Path::Combine(Environment::CurrentDirectory(), "testvideo.mp4"));
    std::this_thread::sleep_for(std::chrono::seconds(60 * 2));

    return 0;
}
