#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    namespace Reflection
    {
        class CustomAttributeData : public Object
        {
            DECLARE_CLASS_INFO(Object)
        public:
            virtual Type* AttributeType()const { return null; }    
        };
    }
}
