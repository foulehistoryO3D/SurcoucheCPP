#include "WebClient.h"
#include "../../System/Uri/Uri.h"
#include "../../System/PrimaryType/String/String.h"
#include "../StringEventArgs/DownloadStringCompletedEventArgs.h"

#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include <sstream>

void System::Net::WebClient::DownloadStringAsync(const Uri& _address)
{
    LPCWSTR _uri = _address.GetUriWSTR();
    IStream* _stream;
    HRESULT result = URLOpenBlockingStream(0, _uri, &_stream, 0, 0);
    
    if (result != 0)
    {
        DownloadStringCompletedEventArgs* _event = new DownloadStringCompletedEventArgs();
        _event->SetResult("");
        _event->SetError(Exception("[WebClient] error => uri doesn't found"));
        DownloadStringCompleted(this, _event);
        return;
    }
    
    char buffer[100];
    unsigned long bytesRead;
    std::stringstream ss;
    _stream->Read(buffer, 100, &bytesRead);
    while (bytesRead > 0U)
    {
        ss.write(buffer, static_cast<long long>(bytesRead));
        _stream->Read(buffer, 100, &bytesRead);
    }
    _stream->Release();
    DownloadStringCompletedEventArgs* _event = new DownloadStringCompletedEventArgs();
    _event->SetResult(ss.str().c_str());
    DownloadStringCompleted(this, _event);
}
