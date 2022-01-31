#pragma once
#include "../../../System/Object/Object.h"
#include "../../File/FileSystemInfo/FileSystemInfo.h"

namespace System
{
    class DateTime;
    namespace IO
    {
        class DirectoryInfo : public FileSystemInfo
        {
            DECLARE_CLASS_INFO(FileSystemInfo)
#pragma region constructor
        public:
            DirectoryInfo() : FileSystemInfo(){}
            DirectoryInfo(const String& _path) : FileSystemInfo(_path){}
            DirectoryInfo(const DirectoryInfo& _directoryInfo) : FileSystemInfo(_directoryInfo){}
#pragma endregion constructor
#pragma region override
        public:
            String FullPath() const override;
            String Extension() const override;
            Boolean Exists() const override;
            void Delete()const override;
            String ToString() const override;
            Integer GetHashCode() const override;
            DateTime GetCreationTime() const;
            DateTime GetLastAccessTime() const;
            DateTime GetLastWriteTime() const;
            
#pragma endregion override
        };
    }
}
