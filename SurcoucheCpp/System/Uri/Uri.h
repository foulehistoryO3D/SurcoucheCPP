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
#pragma region constructor
    public:
        Uri()=default;
        Uri(const String& _uri);
        Uri(const Uri& _copy);
#pragma endregion constructor
    };
}
