#pragma once
#include "../Box/BoxFile/BoxFile.h"
#include "../Object/Object.h"

namespace System
{
    class Uri : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        const char* mUri = "";
    public:
        LPCWSTR GetUriWSTR()const;
#pragma endregion f/p
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;
#pragma endregion override
#pragma region constructor
    public:
        Uri()=default;
        Uri(const String& _uri);
        Uri(const Uri& copy);
#pragma endregion constructor
    };
}
