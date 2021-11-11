#include <windows.h>

#include "System/IncludeSystem.h"
#include "System.Net/StringEventArgs/DownloadStringCompletedEventArgs.h"
#include "System.Net/WebClient/WebClient.h"
#include "System.Timers/ElapsedEventArgs/ElapsedEventArgs.h"
#include "System.Timers/Timer/Timer.h"
#include "System/Uri/Uri.h"

void OnDownloadCompleted(object* _sender, const Net::DownloadStringCompletedEventArgs* _result)
{
    const string& _path = Path::Combine(Environment::CurrentDirectory(), "Sacramento.txt");
    const FileStream _stream = File::Create(_path);
    _stream.Writer().Write(_result->Result());
    Diagnostics::Process::Start(_path);
}

void OnDownloadFileCompleted(object* _sender, const Net::AsyncCompletedEventArgs* _event, const String& _path)
{
    if (_event->Cancelled())
        Console::WriteLine(_event->Error());
    else
        Diagnostics::Process::Start(_path);
}

void OnTimerCalled(const object* _object, const Timers::ElapsedEventArgs* _event)
{
    Console::WriteLine(_object->ToString() + " was call at " + _event->SignalTime().ToString());
}

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    // LanguageManager::Instance().AddLanguage(new Language("fr", "french.txt"));
    // LanguageManager::Instance().AddLanguage(new Language("en", "english.txt"));
    // LanguageManager::Instance().GetLanguage("fr").AddMessageToFile("HelloWorld", "Hello comment vas-tu ? @0");
    // const String& _message = LanguageManager::Instance().GetLanguage("fr").GetMessages("HelloWorld");
    // const String& _result = LanguageManager::Instance().Translate(_message, "Romain");
    // Timers::Timer _timer = Timers::Timer(1000);
    // _timer.Elapsed += OnTimedEvent;
    // _timer.Start();
    //
    Net::WebClient _req = Net::WebClient();
    const Uri& _uri = Uri("https://r2---sn-n4v7snee.googlevideo.com/videoplayback?expire=1636608728&ei=eFaMYdfVD5yRsfIP64GR8Ac&ip=66.115.165.202&id=o-AIEU0kvj6GA79fMrYM2Ri0L1EkrOunRUm9_mJURPP5VT&itag=18&source=youtube&requiressl=yes&mh=NX&mm=31%2C26&mn=sn-n4v7snee%2Csn-a5mekn6s&ms=au%2Conr&mv=m&mvi=2&pl=25&initcwndbps=525000&vprv=1&mime=video%2Fmp4&ns=TDfCqiWo4MPYpS4jHFZrXpIG&gir=yes&clen=329399001&ratebypass=yes&dur=4606.815&lmt=1550909418747220&mt=1636586958&fvip=2&fexp=24001373%2C24007246&c=WEB&txp=5531432&n=sR6CPPUNMEGj9A&sparams=expire%2Cei%2Cip%2Cid%2Citag%2Csource%2Crequiressl%2Cvprv%2Cmime%2Cns%2Cgir%2Cclen%2Cratebypass%2Cdur%2Clmt&sig=AOq0QJ8wRgIhAM9OqE74AZtt7xn1cBbu0VwXhGzYIRdUMBqU_qk6gaTUAiEA8lGvhmfODpxL4PX4PrweY5NDmak7Cl9t6XmqS10phgA%3D&lsparams=mh%2Cmm%2Cmn%2Cms%2Cmv%2Cmvi%2Cpl%2Cinitcwndbps&lsig=AG3C_xAwRgIhANah0hb_FLiMzgHmiqP9tHO-jdY80gqpAOu4fbownnoJAiEAkoTm_cl5P1qFLubJt74uPCZIJGuypRYCWFDM_4qJl8o%3D");
    _req.OnDownloadProgress += [](float _f)
    {
        const char* pbstr = "====================================================================";
        constexpr int _pbwidth = 60;
        const int _pad = (_f/100) * _pbwidth;
        const int _rpad = _pbwidth - _pad;
        printf("\r%.0f%% [%.*s%s%*s]", _f, _pad, pbstr, ">", _rpad, "");
    };
    _req.DownloadFileCompleted += OnDownloadFileCompleted;
    _req.DownloadFileAsync(_uri, Path::Combine(Environment::CurrentDirectory(), "movie.mp4"));
    std::this_thread::sleep_for(std::chrono::seconds(60 * 2));

    return 0;
}
