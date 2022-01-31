#include "WebClient.h"
#include "../../System/Uri/Uri.h"
#include "../../System/PrimaryType/String/String.h"
#include "../StringEventArgs/DownloadStringCompletedEventArgs.h"

#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include <sstream>
#include <thread>

#include "../WebCallback/WebCallback.h"

System::Net::WebClient::~WebClient()
{
    if (mThread.joinable())
        mThread.detach();
}

void System::Net::WebClient::DownloadStringAsyncInternal(const Uri& _address)
{
    mIsRunning = true;
    const LPCWSTR _uri = _address.GetUriWSTR();
    IStream* _stream;
    const HRESULT result = URLOpenBlockingStream(0, _uri, &_stream, 0, 0);
    STATSTG stat;
    _stream->Stat(&stat, result);

    if (result != 0)
    {
        DownloadStringCompletedEventArgs* _event = new DownloadStringCompletedEventArgs();
        _event->SetResult("");
        _event->SetError(DownloadNetException("[WebClient] error => uri doesn't found"));
        DownloadStringCompleted(this, _event);
        return;
    }

    char buffer[100];
    unsigned long bytesRead;
    unsigned long currentBytes = 0;
    std::stringstream ss;
    _stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U)
    {
        currentBytes += bytesRead;
        const float _percent = currentBytes * 100 / stat.cbSize.LowPart;
        OnDownloadProgress.Invoke(_percent);
        ss.write(buffer, static_cast<long long>(bytesRead));
        _stream->Read(buffer, 100, &bytesRead);
    }
    _stream->Release();
    DownloadStringCompletedEventArgs* _event = new DownloadStringCompletedEventArgs();
    _event->SetResult(ss.str().c_str());
    DownloadStringCompleted(this, _event);
}

void System::Net::WebClient::DownloadFileAsyncInternal(const Uri& _address, const String& _pathFile)
{
    mIsRunning = true;
    const LPCWSTR _uri = _address.GetUriWSTR();
    const LPCWSTR _path = _pathFile.ToWString()->c_str();
    WebCallback* _webCallback = new WebCallback();
    _webCallback->OnDownloadProgress += [&](float _f)
    {
        OnDownloadProgress.Invoke(_f);
    };
    const HRESULT _result = URLDownloadToFile(nullptr, _uri, _path, 0, _webCallback);
    AsyncCompletedEventArgs* _event = new AsyncCompletedEventArgs();
    if (!_result)
    {
        _event->SetError(DownloadNetException("[WebClient] error => uri doesn't valid"));
    }
    _webCallback->Release();
    _event->SetCancelled(_result);
    DownloadFileCompleted(this, _event, _pathFile);
    delete _webCallback;
}

void System::Net::WebClient::DownloadStringAsync(const Uri& _address)
{
    if (mIsRunning) return;
    mThread = std::thread(&WebClient::DownloadStringAsyncInternal, this, _address);
}

void System::Net::WebClient::DownloadString(const Uri& _address)
{
    DownloadStringAsyncInternal(_address);
}

void System::Net::WebClient::DownloadFileAsync(const Uri& _address, const String& _pathFile)
{
    if (mIsRunning) return;
    mThread = std::thread(&WebClient::DownloadFileAsyncInternal, this, _address, _pathFile);
}

void System::Net::WebClient::DownloadFile(const Uri& _address, const String& _pathFile)
{
    DownloadFileAsyncInternal(_address, _pathFile);
}

System::Integer System::Net::WebClient::GetHashCode() const
{
    return Bool(mIsRunning).GetHashCode();
}
