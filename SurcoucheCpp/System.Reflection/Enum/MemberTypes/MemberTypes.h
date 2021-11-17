#pragma once
#include "../../../System/Type/Type.h"

namespace System
{
    namespace Reflection
    {
        enum class MemberTypes : uint8
        {
            Constructor = 1,
            Custom = 64,
            Event = 2,
            Field = 4,
            Method = 8,
            NestedType = 128,
            Property = 16,
            TypeInfo = 32
        };
    }
}