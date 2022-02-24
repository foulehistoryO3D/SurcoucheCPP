#pragma once
#include <memory>
#include "../../Object/Object.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/String/String.h"

#define SmartPointerDebugCheck
#ifdef SmartPointerDebugCheck
template <typename To, typename From>
FORCEINLINE std::shared_ptr<To> debug_checked_pointer_cast(std::shared_ptr<From>&& ptr)
{
    std::shared_ptr<To> result = std::dynamic_pointer_cast<To>(ptr);
    if (result.get() != ptr.get())
    {
#ifdef _WIN32
        __debugbreak();
#endif
    }
    return result;
}
#endif

namespace System
{
    template <typename T>
    class SmartPointer sealed : public Object, public std::shared_ptr<T>
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region using
    public:
        using std::shared_ptr<T>::shared_ptr;
#pragma endregion using
#pragma region constructor
    public:
        template <typename U>
        SmartPointer(const std::shared_ptr<U>& other) : std::shared_ptr<T>(debug_checked_pointer_cast<T>(other))
        {
        }

        template <typename U>
        SmartPointer(const std::shared_ptr<U>&& other) : std::shared_ptr<T>(debug_checked_pointer_cast<T>(other))
        {
        }
#pragma endregion constructor
#pragma region override
    public:
        String ToString() const override
        {
            return super::ToString();
        }
        Integer GetHashCode() const override
        {
            return super::GetHashCode();
        }
#pragma endregion override
#pragma region operator
    public:
        template <typename U>
        SmartPointer<T>& operator=(const std::shared_ptr<U>& other)
        {
            std::shared_ptr<T>::operator=(debug_checked_pointer_cast<T>(other));
            return *this;
        }

        template <typename U>
        SmartPointer<T>& operator=(std::shared_ptr<U>&& other)
        {
            std::shared_ptr<T>::operator=(debug_checked_pointer_cast<T>(other));
            return *this;
        }

        template <typename U>
        operator SmartPointer<U>()
        {
            return debug_checked_pointer_cast<U>(*this);
        }

        template <typename U>
        Boolean operator==(const U* other) const
        {
            return this->get() == other;
        }

        template <typename U>
        Boolean operator!=(const U* other) const
        {
            return this->get() != other;
        }
#pragma endregion operator
    };
    template<typename smartPoint, typename... Args>
    SmartPointer<smartPoint> MakeRefCounted(Args&&... args)
    {
        return std::make_shared<smartPoint>(std::forward<decltype(args)>(args)...);
    }
}
