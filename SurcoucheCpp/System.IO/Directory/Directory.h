#pragma once
#include "../../System/Object/Object.h"

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
            static DirectoryInfo GetParent(const String& _path);
            static Boolean Exists(const String& _path);
        };
    }
}
