#pragma once
#include "../../Object/Object.h"

namespace System
{
    class ConfirmationBox : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        const char* mTitle = "Confirmation Box";
        const char* mMessage = "";
#pragma endregion f/p
#pragma region constructor
    public:
        ConfirmationBox()=default;
        ConfirmationBox(const String& _title, const String& _message);
        ConfirmationBox(const ConfirmationBox& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        Boolean Open()const;
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
#pragma endregion override
    };
}
