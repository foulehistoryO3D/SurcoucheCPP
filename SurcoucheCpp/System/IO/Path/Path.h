﻿#pragma once
#include "../../Object/Object.h"

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
    namespace IO
    {
        class Path : public Object
        {
        public:
            static String GetPath(const String& _path);
            static String Combine(const String& _a, const String& _b);
            static String Combine(Collections::Generic::List<String> _str);
            static String GetExtension(const String& _path);
            static String GetFileNameWithoutExtension(const String& _path);
            static String GetDirectoryName(const String& _path);
            static Boolean HasExtension(const String& _path);
        };
    }
}