#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    namespace IO
    {
        class DriveType : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region enum
        private:
            enum EDriveType { Unknown, NoRootDir, Removable, Fixed, Remote, CdRom, RamDisk };
#pragma endregion enum
#pragma region f/p
        private:
            const char* mTypeName = null;
            String GetTypeName(const EDriveType& _driveType);
#pragma endregion f/p
#pragma region constructor
        public:
            DriveType()=default;
            DriveType(const int& _value);
            DriveType(const DriveType& _copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            String TypeName()const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            DriveType operator=(const DriveType& _driveType)
            {
                mTypeName = _driveType.mTypeName;
                return *this;
            }
#pragma endregion operator
        };
    }
}
