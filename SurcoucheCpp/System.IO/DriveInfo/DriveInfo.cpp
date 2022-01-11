#include "DriveInfo.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System.Collections.Generic/List/List.h"

#pragma region constructor
System::IO::DriveInfo::DriveInfo(const String& _path)
{
    mPath = _path;
    mName = _path;
    mDriveType = DriveType(GetDriveTypeA(_path.ToCstr()));
    mAvailableFreeSpace = GetDiskBytes();
    mVolumeLabel = GetVolumeLabel();
}

System::IO::DriveInfo::DriveInfo(const DriveInfo& _copy)
{
    mPath = _copy.mPath;
    mName = _copy.mName;
    mDriveType = _copy.mDriveType;
    mAvailableFreeSpace = _copy.mAvailableFreeSpace;
    mVolumeLabel = _copy.mVolumeLabel;
}
#pragma endregion constructor
#pragma region custom methods
System::int64 System::IO::DriveInfo::GetDiskBytes() const
{
    unsigned __int64 _freeBytesToCaller, _totalBytes, _freeBytes;
    const bool _result = GetDiskFreeSpaceEx(string(mPath).ToWString()->c_str(), (PULARGE_INTEGER)&_freeBytesToCaller, (PULARGE_INTEGER)&_totalBytes, (PULARGE_INTEGER)&_freeBytes);
    if (!_result)return -1;
    return _freeBytes / (1024*1024);
}

System::String System::IO::DriveInfo::GetVolumeLabel() const
{
    const LPWSTR _label = LPWSTR();
    DWORD _dword = DWORD();
    if (GetVolumeInformation(string(mPath).ToWString()->c_str(), _label, sizeof(_label), null, &_dword, &_dword, null, 0))
    {
        if (_label == null) return string::Empty;
        std::wstring _str = _label;
        const std::string _result = std::string(_str.begin(), _str.end());
        return _result.c_str();
    }
    return string::Empty;
}

System::String System::IO::DriveInfo::DriveName() const
{
    return mName;
}

System::String System::IO::DriveInfo::DriveTypeName() const
{
    return mDriveType.TypeName();
}

System::Integer System::IO::DriveInfo::AvailableFreeSpace() const
{
    return mAvailableFreeSpace;
}

System::Collections::Generic::List<System::IO::DriveInfo> System::IO::DriveInfo::GetDrives()
{
    Collections::Generic::List<DriveInfo> _result = Collections::Generic::List<DriveInfo>();
    char* _drives = new char[MAX_PATH]();
    if (GetLogicalDriveStringsA(MAX_PATH, _drives))
        for (int i = 0; i < 100; i+=4)
            if (_drives[i] != (char)0)
            {
                String _path = std::string{_drives[i],_drives[i+1],_drives[i+2]}.c_str();
                _result.Add(DriveInfo(_path));
            }
    return _result;
}
#pragma endregion custom methods
#pragma region override
System::String System::IO::DriveInfo::ToString() const
{
    return mName;
}

System::Boolean System::IO::DriveInfo::Equals(const object* object)
{
    return object == this;
}

System::Boolean System::IO::DriveInfo::Equals(const object& object)
{
    return &object == this;
}

size_t System::IO::DriveInfo::GetHashCode() const
{
    DriveInfo _driveInfo = *this;
    return std::hash<DriveInfo*>{}(&_driveInfo);
}
#pragma endregion override
