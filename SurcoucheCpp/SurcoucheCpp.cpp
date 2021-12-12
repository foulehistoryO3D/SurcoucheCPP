#include <windows.h>

#include "System/Event/Action/Action.h"
#include "System.Collections.Generic/Dictionary/Dictionary.h"
#include "System/Console/Console.h"
#include "System/Environment/Environment.h"


LRESULT CALLBACK WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp);

void AddMenus(HWND hwnd);
void CreatePopupMenu(HMENU _menu, HMENU _subMenu, LPCWSTR _name);
void CreateButtonMenu(HMENU _menu, LPCWSTR _name, System::Action<> _callback);
void CreateSeparator(HMENU _menu);

bool mTest = true;
HMENU hMenu;
System::Collections::Generic::Dictionary<int, System::Action<>> menuAction = System::Collections::Generic::Dictionary<
    int, System::Action<>>();

int main()
{
    // constexpr wchar_t CLASS_NAME[] = L"Sample Window Class";
    // WNDCLASS wc = {};
    // const HINSTANCE hInstance = HINSTANCE();
    // wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
    // wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    // wc.lpfnWndProc = WindowProc;
    // wc.hInstance = hInstance;
    // wc.lpszClassName = CLASS_NAME;
    // RegisterClass(&wc);
    //
    // const HWND hwnd = CreateWindowEx(0, CLASS_NAME, L"Test Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
    //                                  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    //                                  nullptr, nullptr, hInstance, nullptr);
    //
    // if (hwnd == nullptr) return 0;
    // ShowWindow(hwnd, 1);
    //
    // MSG msg = {};
    // while (GetMessage(&msg, nullptr, 0, 0) > 0)
    // {
    //     TranslateMessage(&msg);
    //     DispatchMessage(&msg);
    // }

    return 0;
}

LRESULT __stdcall WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:
        if (menuAction.ContainsKey(wp)) menuAction[wp]();
        break;
    case WM_CREATE:
        AddMenus(hWindow);
        break;
    case WM_DESTROY:
        System::Environment::Exit(System::Environment::EXIT_VALID);
        break;
    default:
        return DefWindowProcW(hWindow, msg, wp, lp);
    }
    return 0;
}

void AddMenus(HWND hwnd)
{
    hMenu = CreateMenu();
    const HMENU hFileMenu = CreateMenu();
    const HMENU hSubMenu = CreateMenu();

    CreateButtonMenu(hSubMenu, L"Test", []
    {
       System::Console::WriteLine("Test"); 
    });
    
    CreateButtonMenu(hFileMenu, L"New", []
    {
        System::Console::WriteLine("New");
    });
    CreateSeparator(hFileMenu);
    CreatePopupMenu(hFileMenu, hSubMenu, L"Open");
    CreatePopupMenu(hMenu, hFileMenu, L"File");
    CreateButtonMenu(hMenu, L"Help", []
    {
        System::Console::WriteLine("Help");
    });
    SetMenu(hwnd, hMenu);
}

void CreateButtonMenu(HMENU _menu, LPCWSTR _name, System::Action<> _callback)
{
    const int _key = menuAction.Count();
    AppendMenu(_menu, MF_STRING, _key, _name);
    menuAction.Add(_key, _callback);
}

void CreateSeparator(HMENU _menu)
{
    AppendMenu(_menu, MF_SEPARATOR, NULL, nullptr);
}

void CreatePopupMenu(HMENU _menu, HMENU _subMenu, LPCWSTR _name)
{
    const int _key = reinterpret_cast<UINT_PTR>(_subMenu);
    AppendMenu(_menu, MF_POPUP, _key, _name);
    
}

