#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class File;
    }

    namespace Collections
    {
        namespace Generic
        {
            template <typename T>
            class List;
        }
    }

    namespace IO
    {
        class DirectoryInfo;

        class Directory : public Object
        {
            DECLARE_CLASS_INFO(Object)
        public:
            static DirectoryInfo MakeDirectory(const String& _path);
            static DirectoryInfo GetDirectory(const String& _path);
            static void Delete(const String& _path, bool _sub = false);
            static Collections::Generic::List<String> GetDirectories(const String& _path);
            static Collections::Generic::List<File> GetFiles(const String& _path, const String& ext);
            static void Move(const String& _path, const String& _newLocation);
            static DirectoryInfo GetParent(const String& _path);
            static Boolean Exists(const String& _path);
        };
    }
}
