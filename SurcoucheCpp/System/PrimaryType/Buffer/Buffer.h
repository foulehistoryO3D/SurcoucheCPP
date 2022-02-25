#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/Integer/Integer.h"
#include "../../PrimaryType/Char/Char.h"
#include "../Array/Array.h"

namespace System
{
    class Buffer sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        std::vector<Byte> buffer    = std::vector<Byte>();
    public:
        Integer Size()const;
#pragma endregion f/p
#pragma region constructor
    public:
        Buffer() = default;
        Buffer(const Integer& size);
        Buffer(std::initializer_list<Byte> items);
        Buffer(const Buffer& copy);
        ~Buffer()override;
#pragma endregion constructor
#pragma region custom methods
    public:
        void Insert(Byte c);
        void CopyTo(Array<Byte>& out);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;
        Boolean operator==(const object& _obj) override;
        Boolean operator==(const object* _obj) override;
        Boolean operator==(const Buffer& other);
#pragma endregion override
#pragma region operator
    public:
        Buffer& operator=(const Buffer& other);
        Byte& operator[](const Integer& index);
#pragma endregion operator
    };
}
