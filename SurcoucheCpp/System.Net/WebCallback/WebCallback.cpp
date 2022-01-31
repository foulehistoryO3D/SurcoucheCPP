#include "WebCallback.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

#include <iostream>

#pragma region override
#pragma region IBindStatusCallback
System::Net::WebCallback::WebCallback(const WebCallback& _copy)
{
    mPercentLast = std::move(_copy.mPercentLast);
}

HRESULT System::Net::WebCallback::QueryInterface(const IID& riid, void** ppvObject)
{
    if(IsEqualIID(IID_IBindStatusCallback, riid) ||IsEqualIID(IID_IUnknown, riid))
    {
        *ppvObject = reinterpret_cast<void*>(this);
        return S_OK;
    }
    return E_NOINTERFACE;
}

ULONG System::Net::WebCallback::AddRef()
{
    return 2UL;
}

ULONG System::Net::WebCallback::Release()
{
    return 1UL;
}

HRESULT System::Net::WebCallback::OnStartBinding(DWORD dwReserved, IBinding* pib)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::GetPriority(LONG* pnPriority)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::OnLowResource(DWORD reserved)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode,
    LPCWSTR szStatusText)
{
    switch (ulStatusCode)
    {
    case BINDSTATUS_FINDINGRESOURCE:
        std::cout << "Finding resource..." << std::endl;
        break;
    case BINDSTATUS_CONNECTING:
        std::cout << "Connecting..." << std::endl;
        break;
    case BINDSTATUS_SENDINGREQUEST:
        std::cout << "Sending request..." << std::endl;
        break;
    case BINDSTATUS_MIMETYPEAVAILABLE:
        std::cout << "Mime type available" << std::endl;
        break;
    case BINDSTATUS_CACHEFILENAMEAVAILABLE:
        std::cout << "Cache filename available" << std::endl;
        break;
    case BINDSTATUS_BEGINDOWNLOADDATA:
        std::cout << "Begin download" << std::endl;
        break;
    case BINDSTATUS_DOWNLOADINGDATA:
    case BINDSTATUS_ENDDOWNLOADDATA:
        {
            const float _percent = (100.0 * static_cast<float>(ulProgress) / static_cast<float>(ulProgressMax));
            if (mPercentLast < _percent)
                OnDownloadProgress.Invoke(mPercentLast = _percent);
            if (ulStatusCode == BINDSTATUS_ENDDOWNLOADDATA)
                std::cout << std::endl << "End download" << std::endl;
        }
        break;

    default:
        {
            std::cout << "Status code : " << ulStatusCode << std::endl;
        }
    }
    // The download can be cancelled by returning E_ABORT here
    // of from any other of the methods.
    return S_OK;
}

HRESULT System::Net::WebCallback::OnStopBinding(HRESULT hresult, LPCWSTR szError)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc,
    STGMEDIUM* pstgmed)
{
    return E_NOTIMPL;
}

HRESULT System::Net::WebCallback::OnObjectAvailable(const IID& riid, IUnknown* punk)
{
    return E_NOTIMPL;
}
#pragma endregion IBindStatusCallback
#pragma region object
System::Boolean System::Net::WebCallback::Equals(const object* object)
{
    const WebCallback& _webcallback = static_cast<const WebCallback&>(*object);
    return mPercentLast == _webcallback.mPercentLast;
}

System::Boolean System::Net::WebCallback::Equals(const object& object)
{
    const WebCallback& _webcallback = static_cast<const WebCallback&>(object);
    return mPercentLast == _webcallback.mPercentLast;
}

System::Integer System::Net::WebCallback::GetHashCode() const
{
    return Int(mPercentLast).GetHashCode();
}
#pragma endregion object
#pragma endregion override
