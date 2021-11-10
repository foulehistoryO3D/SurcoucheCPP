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
            HRESULT QueryInterface(const IID& riid, void** ppvObject) override;
            ULONG AddRef() override;
            ULONG Release() override;
            HRESULT OnStartBinding(DWORD dwReserved, IBinding* pib) override;
            HRESULT GetPriority(LONG* pnPriority) override;
            HRESULT OnLowResource(DWORD reserved) override;
            HRESULT OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode,
                LPCWSTR szStatusText) override;
            HRESULT OnStopBinding(HRESULT hresult, LPCWSTR szError) override;
            HRESULT GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo) override;
            HRESULT OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed) override;
            HRESULT OnObjectAvailable(const IID& riid, IUnknown* punk) override;
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
