#pragma once
#include "../../System/Object/Object.h"
#include "DriveType/DriveType.h"

namespace System
{
    class Integer;
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
        class DriveInfo : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            const char* mPath = nullptr;
            const char* mName = nullptr;
            const char* mVolumeLabel = nullptr;
            int64 mAvailableFreeSpace = 0;
            DriveType mDriveType = DriveType();
#pragma endregion f/p
#pragma region constructor
        public:
            DriveInfo()=default;
            DriveInfo(const String& _path);
            DriveInfo(const DriveInfo& copy);
#pragma endregion constructor
#pragma region custom methods
        private:
            int64 GetDiskBytes() const;
            String GetVolumeLabel() const;
        public:
            String DriveName()const;
            String DriveTypeName()const;
            Integer AvailableFreeSpace()const;
        public:
            static Collections::Generic::List<DriveInfo> GetDrives();
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            DriveInfo operator=(const DriveInfo& _copy)
            {
                mPath = _copy.mPath;
                mName = _copy.mName;
                mDriveType = _copy.mDriveType;
                mAvailableFreeSpace = _copy.mAvailableFreeSpace;
                return *this;
            }
#pragma endregion operator
        };
    }
}
