#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    namespace Net
    {
        class DownloadNetException : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            const char* mMessage = "";
        public:
            String Message()const;
#pragma endregion f/p
#pragma region constructor
        public:
            DownloadNetException()=default;
            DownloadNetException(const String& _message);
            DownloadNetException(const DownloadNetException& _copy);
#pragma endregion constructor
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
            DownloadNetException& operator=(const DownloadNetException& _exception)
            {
                mMessage = std::move(_exception.mMessage);
                return *this;
            }
#pragma endregion operator
        };
    }
}
