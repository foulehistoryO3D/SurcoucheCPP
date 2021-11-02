#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
namespace System
{
    namespace Diagnostics
    {
        class Process : public System::Object
        {
        public:
            static void Start(const String& _path, const String& _parameters = "");
        };
    }
}
