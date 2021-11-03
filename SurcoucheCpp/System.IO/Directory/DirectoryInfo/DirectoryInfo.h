#pragma once
#include "../../../System/Object/Object.h"
#include "../../File/FileSystemInfo/FileSystemInfo.h"

namespace System
{
    namespace IO
    {
        class DirectoryInfo : public Object, public FileSystemInfo
        {
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
            size_t GetHashCode() const override;
#pragma endregion override
        };
    }
}
