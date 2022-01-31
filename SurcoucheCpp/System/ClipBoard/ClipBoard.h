#pragma once
#include "../Object/Object.h"

namespace System
{
    class ClipBoard : public Object
    {
        DECLARE_CLASS_INFO(Object)
    public:
        static String Paste();
        static void Copy(const String& text);
    };
}
