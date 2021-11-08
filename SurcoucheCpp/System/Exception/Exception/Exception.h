#pragma once
#include "../../Object/Object.h"

namespace System
{
    class Exception : public Object, public std::exception
    {
        DECLARE_CLASS_INFO(Object)
#pragma region constructor/destructor
    public:
        Exception() noexcept : std::exception() {}
        explicit Exception(char const* const _message) noexcept : std::exception(_message) {}
        Exception(char const* const _message, int _i) noexcept : std::exception(_message, _i) {}
        Exception(Exception const& _other) noexcept : std::exception(_other) {}
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        String Message()const;
#pragma endregion custom methods
#pragma region Override
    public:
        String ToString() const override;
#pragma endregion Override
    };
}
