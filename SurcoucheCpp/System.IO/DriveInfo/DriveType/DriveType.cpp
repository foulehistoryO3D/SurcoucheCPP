#include "DriveType.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"

#pragma region constructor
System::IO::DriveType::DriveType(const int& _value)
{
    mTypeName = GetTypeName((EDriveType)_value);
}

System::IO::DriveType::DriveType(const DriveType& _copy)
{
    mTypeName = _copy.mTypeName;
}
#pragma endregion constructor
#pragma region custom methods
System::String System::IO::DriveType::GetTypeName(const EDriveType& _driveType)
{
    switch (_driveType)
    {
    case Unknown: return "Unknown";
    case NoRootDir: return "NoRootDir";
    case Removable: return "Removable";
    case Fixed: return "Fixed";
    case Remote: return "Remote";
    case CdRom: return "CdRom";
    case RamDisk: return "RamDisk";
    default: return "Unknown";
    }
}

System::String System::IO::DriveType::TypeName() const
{
    return mTypeName;
}
#pragma endregion custom methods
#pragma region override
System::String System::IO::DriveType::ToString() const
{
    return mTypeName;
}

System::Boolean System::IO::DriveType::Equals(const object* object)
{
    return this == object;
}

System::Boolean System::IO::DriveType::Equals(const object& object)
{
    return this == &object;
}

System::Integer System::IO::DriveType::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion override