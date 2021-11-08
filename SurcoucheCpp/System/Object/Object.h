#pragma once
#include "../Type/Type.h"

#pragma warning(disable: 4584)
#pragma warning(disable: 4996)
#pragma warning(disable: 4244)
#pragma warning(disable: 4267)

namespace System
{
    class Boolean;
#pragma region typedef
    typedef class Object object;
#pragma endregion typedef
    class Object : public Type
    {
        DECLARE_CLASS_INFO(Type)
#pragma region constructor/destructor
    public:
        Object()=default;
        virtual ~Object() override =default;
#pragma endregion constructor/destructor
#pragma region custom methods
    public:
        virtual class Boolean Equals(const object* _obj);
        virtual Boolean Equals(const object& _obj);
        virtual Boolean Equals(const object* _obj, const object* _other);
        virtual Boolean Equals(const object& _obj, const object& _other);
        virtual size_t GetHashCode()const override;
#pragma endregion custom methods
#pragma region operator
        virtual Boolean operator==(const object* _obj);
        virtual Boolean operator!=(const object* _obj);
        virtual Boolean operator==(const object& _obj);
        virtual Boolean operator!=(const object& _obj);
#pragma endregion operator
    };
}
