#pragma once
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
        class DirectoryInfo;
        
        class Directory : public Object
        {
        public:
            static DirectoryInfo MakeDirectory(const String& _path);
            static void Delete(const String& _path, bool _sub = false);
            static Collections::Generic::List<String> GetDirectories(const String& _path);
            static void Move(const String& _path, const String& _newLocation);
        };
    }
}
