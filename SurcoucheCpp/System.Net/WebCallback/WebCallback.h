#pragma once
#include "../../System/Object/Object.h"
#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>

#include "../../System/Event/Action/Action.h"

namespace System
{
    namespace Net
    {
        class WebCallback : public Object, public IBindStatusCallback
        {
            DECLARE_CLASS_INFO(Object)
#pragma region event
        public:
            Action<float> OnDownloadProgress;
#pragma endregion event
#pragma region f/p
        private:
            int mPercentLast = 0;
#pragma endregion f/p
#pragma region constructor
        public:
            WebCallback()=default;
            WebCallback(const WebCallback& _copy);
#pragma endregion constructor
#pragma region override
#pragma region IBindStatusCallback
        public:
            HRESULT STDMETHODCALLTYPE QueryInterface(const IID& riid, void** ppvObject) override;
            ULONG STDMETHODCALLTYPE  AddRef() override;
            ULONG STDMETHODCALLTYPE  Release() override;
            HRESULT STDMETHODCALLTYPE  OnStartBinding(DWORD dwReserved, IBinding* pib) override;
            HRESULT STDMETHODCALLTYPE  GetPriority(LONG* pnPriority) override;
            HRESULT STDMETHODCALLTYPE  OnLowResource(DWORD reserved) override;
            HRESULT STDMETHODCALLTYPE  OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode,
                LPCWSTR szStatusText) override;
            HRESULT STDMETHODCALLTYPE  OnStopBinding(HRESULT hresult, LPCWSTR szError) override;
            HRESULT STDMETHODCALLTYPE  GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo) override;
            HRESULT STDMETHODCALLTYPE  OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed) override;
            HRESULT STDMETHODCALLTYPE  OnObjectAvailable(const IID& riid, IUnknown* punk) override;
#pragma endregion IBindStatusCallback
#pragma region object
        public:
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            size_t GetHashCode() const override;
#pragma endregion object
#pragma endregion override
        };
    }
}
