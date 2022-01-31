#include "BoxFile.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../../PrimaryType/Integer/Integer.h"


#pragma region constructor
System::BoxFile::BoxFile(const String& _title)
{
    mTitle = _title;
}

System::BoxFile::BoxFile(const BoxFile& _copy)
{
    mTitle = std::move(_copy.mTitle);
    mHResult = std::move(_copy.mHResult);
    mPathResult = std::move(_copy.mPathResult);
}
#pragma endregion constructor
#pragma region custom methods
#pragma region private
bool System::BoxFile::CreateInstanceDialog(IFileOpenDialog*& _fileOpen)
{
    _fileOpen = {0};
    mHResult = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_IFileOpenDialog,
                                reinterpret_cast<void**>(&_fileOpen));
    if (!SUCCEEDED(mHResult))return false;
    return true;
}

bool System::BoxFile::OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item)
{
    _fileOpen->SetTitle(string::ToWString(mTitle)->c_str());
    mHResult = _fileOpen->Show(nullptr); //TODO replace for main window
    if (!SUCCEEDED(mHResult))return false;
    mHResult = _fileOpen->GetResult(&_item);
    if (!SUCCEEDED(mHResult))return false;
    return true;
}

bool System::BoxFile::GetDisplayName(IShellItem* _item, PWSTR& _filePath)
{
    _filePath = (0);
    mHResult = _item->GetDisplayName(SIGDN_FILESYSPATH, &_filePath);
    if (!SUCCEEDED(mHResult))return false;
    return true;
}

void System::BoxFile::SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath)
{
    mPathResult = String::WStringToString(_filePath);
    CoTaskMemFree(_filePath);
    _item->Release();
    _fileOpen->Release();
    CoUninitialize();
}

bool System::BoxFile::InitializeBox()
{
    mHResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (!SUCCEEDED(mHResult))return false;
    return true;
}
#pragma endregion private
#pragma region public
void System::BoxFile::Open()
{
    if (!InitializeBox()) return;
    IFileOpenDialog* _fileOpen;
    if (!CreateInstanceDialog(_fileOpen)) return;
    IShellItem* _item = nullptr;
    if (!OpenFile(_fileOpen, _item)) return;
    PWSTR _filePath;
    if (!GetDisplayName(_item, _filePath)) return;
    SaveResult(_fileOpen, _item, _filePath);
}

void System::BoxFile::DisplayMessageBox(const String& _title, const bool& _noDisplayIsNull) const
{
    if (_noDisplayIsNull && string::IsNullOrEmpty(mPathResult))return;
    MessageBox(nullptr, String::ToWString(mPathResult)->c_str(), _title.ToWString()->c_str(), MB_OK);
}

System::String System::BoxFile::PathResult() const
{
    return mPathResult;
}
#pragma endregion public
#pragma endregion custom methods
#pragma region override
System::String System::BoxFile::ToString() const
{
    return Object::ToString();
}

System::Boolean System::BoxFile::Equals(const object* object)
{
    const BoxFile& _box = *dynamic_cast<const BoxFile*>(object);
    return mTitle == _box.mTitle && mPathResult == _box.mPathResult;
}

System::Boolean System::BoxFile::Equals(const object& object)
{
    const BoxFile& _box = *dynamic_cast<const BoxFile*>(&object);
    return mTitle == _box.mTitle && mPathResult == _box.mPathResult;
}

System::Integer System::BoxFile::GetHashCode() const
{
    return string(mTitle).GetHashCode() ^ (string(mPathResult).GetHashCode() << 2);
}

#pragma endregion override
#pragma region operator

System::BoxFile& System::BoxFile::operator=(const BoxFile& _other)
{
    mTitle = std::move(_other.mTitle);
    mHResult = std::move(_other.mHResult);
    mPathResult = std::move(_other.mPathResult);
    return *this;
}
#pragma endregion operator
