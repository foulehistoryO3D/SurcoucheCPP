# Tutorial for Web Client

```cpp

void OnDownloadFileCompleted(object* _sender, const Net::AsyncCompletedEventArgs* _event, const String& _path)
{
    if (_event->Cancelled())
        Console::WriteLine(_event->Error());
    else
        Diagnostics::Process::Start(_path);
}


int main()
{
    // Declare web client
    Net::WebClient _req = Net::WebClient();
    // create uri for download
    const Uri& _uri = Uri("https://us.123rf.com/450wm/przemekklos/przemekklos1810/przemekklos181000032/109894128-écran-d-ordinateur-affichant-le-code-du-programme-le-développement-de-sites-web-la-création-d-applic.jpg?ver=6");
    // subscribes a function to Action (OnDownloadProgress)
    _req.OnDownloadProgress += [](float _f)
    {
        const char* pbstr = "====================================================================";
        constexpr int _pbwidth = 60;
        const int _pad = (_f/100) * _pbwidth;
        const int _rpad = _pbwidth - _pad;
        printf("\r%.0f%% [%.*s%s%*s]", _f, _pad, pbstr, ">", _rpad, "");
    };
    // subscribes function for callback when file is downloaded
    _req.DownloadFileCompleted += OnDownloadFileCompleted;
    // start the download
    _req.DownloadFileAsync(_uri, Path::Combine(Environment::CurrentDirectory(), "movie.mp4"));
}
```
