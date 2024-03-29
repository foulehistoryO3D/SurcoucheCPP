﻿#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    class String;
    namespace IO
    {
        class FileSystemInfo : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        protected:
            const char* mPath = nullptr;
#pragma endregion f/p
#pragma region constructor
        public:
            FileSystemInfo()=default;
            FileSystemInfo(const String& _path);
            FileSystemInfo(const FileSystemInfo& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            virtual String FullPath()const;
            virtual String Name()const;
            virtual String Extension()const;
            virtual Boolean Exists()const;
            virtual void Delete()const{}
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
        };
    }
}
