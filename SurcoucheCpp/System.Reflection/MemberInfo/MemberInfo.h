#pragma once
#include "../../System.Collections.Generic/List/List.h"
#include "../Enum/MemberTypes/MemberTypes.h"
#include "../ReturnType/ReturnType.h"

namespace System
{
    namespace Reflection
    {
        class MemberInfo : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            Collections::Generic::List<object*> mCustomAttributes = Collections::Generic::List<object*>();
#pragma endregion f/p
#pragma region constructor
        public:
            MemberInfo()=default;
#pragma endregion constructor
#pragma region custom methods
        public:
            virtual Collections::Generic::IEnumerable<object*> CustomAttributes()const;
            virtual Type* DeclaringType()const PURE_VIRTUAL()
            virtual MemberTypes MemberType()const PURE_VIRTUAL()
            virtual String Name() PURE_VIRTUAL()
            virtual Type* ReflectedType()const PURE_VIRTUAL()
            virtual Type* ReturnType()const { return null; }
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Collections::Generic::List<object*> GetCustomAttributes() const;
            Collections::Generic::List<object*> GetCustomAttributes(const Type* _type);
            Boolean IsDefined(const Type* _type);
#pragma endregion override
#pragma region operator
        public:
            MemberInfo& operator=(const MemberInfo& _other);
#pragma endregion operator
        };
    }
}
