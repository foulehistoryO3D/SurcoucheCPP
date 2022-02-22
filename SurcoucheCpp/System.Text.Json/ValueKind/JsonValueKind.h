#pragma once
#include "../../System/PrimaryType/Enum/Enum.h"

namespace System
{
    namespace Text
    {
        namespace Json
        {
            enum class JsonValueKind : uint8
            {
                Undefined,
                Object,
                Array,
                String,
                Number,
                True,
                False,
                Null
            };
        }
    }
}