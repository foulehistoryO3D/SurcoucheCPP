#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/Integer/Integer.h"
#include "../../PrimaryType/Char/Char.h"

namespace System
{
    class Buffer sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType)
#pragma region f/p
    private:
        std::vector<Char> buffer    = std::vector<Char>();
    public:
        Integer Size()const;
#pragma endregion f/p
#pragma region constructor
    public:
        Buffer() = default;
        Buffer(const Integer& size);
        Buffer(std::initializer_list<Char> items);
        Buffer(const Buffer& copy);
        ~Buffer()override;
#pragma endregion constructor
#pragma region custom methods
    public:
        void Insert(Char c);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;
        Boolean operator==(const object& _obj) override;
        Boolean operator==(const object* _obj) override;
        
#pragma endregion override
#pragma region operator
    public:
        Buffer& operator=(const Buffer& other);
        Char& operator[](const Integer& index);
#pragma endregion operator
    };
}
