#pragma once
#include "../../System.Collections.Generic/List/List.h"
#include "../CustomAttributeData/CustomAttributeData.h"
#include "../Enum/MemberTypes/MemberTypes.h"
#include "../Interface/CustomAttributeProvider/ICustomAttributeProvider.h"

namespace System
{
    namespace Reflection
    {
        class MemberInfo : public ICustomAttributeProvider
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
            virtual Collections::Generic::IEnumerable<CustomAttributeData*> CustomAttributes()const;
            virtual Type* DeclaringType()const PURE_VIRTUAL()
            virtual MemberTypes MemberType()const PURE_VIRTUAL()
            virtual String Name() PURE_VIRTUAL()
            virtual Type* ReflectedType()const PURE_VIRTUAL()
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Collections::Generic::List<object*> GetCustomAttributes() override;
            Collections::Generic::List<object*> GetCustomAttributes(const Type* _type) override;
            Boolean IsDefined(const Type* _type) override;
#pragma endregion override
#pragma region operator
        public:
            MemberInfo& operator=(const MemberInfo& _other);
#pragma endregion operator
        };
    }
}
