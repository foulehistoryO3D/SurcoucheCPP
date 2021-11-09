#pragma once
#include <shobjidl_core.h>

#include "../../DateTime/DateTime.h"
#include "../../Object/Object.h"

namespace System
{
    class BoxFile : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        const char* mTitle = "find path";
        HRESULT mHResult = HRESULT();
        const char* mPathResult = null;
#pragma endregion f/p
#pragma region constructor
    public:
        BoxFile()=default;
        BoxFile(const String& _title);
        BoxFile(const BoxFile& _copy);
#pragma endregion constructor
#pragma region custom methods
    private:
        bool CreateInstanceDialog(IFileOpenDialog*& _fileOpen);
        bool OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item);
        bool GetDisplayName(IShellItem* _item, PWSTR& _filePath);
        void SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath);
        bool InitializeBox();
    public:
        void Open();
        void DisplayMessageBox(const String& _message, const bool& _noDisplayIsNull = true) const;
        String PathResult()const;
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
#pragma endregion override
    };
}
