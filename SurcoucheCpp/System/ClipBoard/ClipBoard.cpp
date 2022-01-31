#include "ClipBoard.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Integer/Integer.h"

System::String System::ClipBoard::Paste()
{
    if (!IsClipboardFormatAvailable(CF_UNICODETEXT))
    {
        throw Exception("Failed to get the clipboard date in Unicode format.");
    }
    if (!OpenClipboard(nullptr))
        throw Exception("Failed to open the win32 clipboard.");
    const HANDLE clipboardHandle = GetClipboardData(CF_UNICODETEXT);
    if (!clipboardHandle)
    {
        CloseClipboard();
        throw Exception("Failed to get win32 handle for clipboard content.");
    }

    std::wstring ws(static_cast<wchar_t*>(GlobalLock(clipboardHandle)));
    // const std::string str();
    string result = string(ws.begin(), ws.end());
    GlobalUnlock(clipboardHandle);
    CloseClipboard();
    return result;
}

void System::ClipBoard::Copy(const String& text)
{
    if (!OpenClipboard(nullptr))
        throw Exception("Failed to open the win32 clipboard.");
    if (!EmptyClipboard())
        throw Exception("Failed to empty the win32 clipboard");
    const wchar_t* textChar = String::ToWString(text)->c_str();
    const size_t string_size =  (std::wcslen(textChar) + 1 ) * sizeof(wchar_t);
    if (const HANDLE string_handle = GlobalAlloc(GMEM_MOVEABLE, string_size))
    {
        memcpy(GlobalLock(string_handle), textChar, string_size);
        GlobalUnlock(string_handle);
        SetClipboardData(CF_UNICODETEXT, string_handle);
    }
    CloseClipboard();
}
