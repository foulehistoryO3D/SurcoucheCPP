#pragma once
#include "../../Object/Object.h"

namespace System
{
    class EventArgs : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region constructor
    public:
        EventArgs()=default;
#pragma endregion constructor
#pragma region override
    public:
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
#pragma endregion override
    };
}
