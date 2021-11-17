#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class List;
        }
    }
    namespace Reflection
    {
        class ICustomAttributeProvider : public Object
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Interface)
        public:
            virtual Collections::Generic::List<object*> GetCustomAttributes()PURE_VIRTUAL()
            virtual Collections::Generic::List<object*> GetCustomAttributes(const Type* _type)PURE_VIRTUAL()
            virtual Boolean IsDefined(const Type* _type)PURE_VIRTUAL()
        };
    }
}
