#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/String/String.h"

namespace System
{
    namespace Diagnostics
    {
        class Process : public Object
        {
            DECLARE_CLASS_INFO(Object)
        public:
            static void Start(const String& _path, const String& _parameters = "");
        };
    }
}
