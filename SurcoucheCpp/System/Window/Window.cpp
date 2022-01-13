#include "Window.h"

#include <thread>

#include "../Console/Console.h"
#include "../Environment/Environment.h"

#pragma region constructor
void System::Window::Open()
{
    if (mWindowInstance == null)
        throw Exception("Error on creating window !");
    ShowWindow(mWindowInstance, 1);
    if (mIsAsync)
        std::thread(&Window::Update, this);
    else Update();
}

System::Window::Window(const String& _windowName, const Integer& _width, const Integer& _height, bool _isAsync)
{
    mWindowName = _windowName;
    mWidth = _width;
    mHeight = _height;
    mIsAsync = _isAsync;
    const LPCWSTR _ClassName = mWindowName.ToWString()->c_str();
    WNDCLASS _WndClass = {};
    const HINSTANCE _instance = HINSTANCE();
    _WndClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
    _WndClass.hCursor = LoadCursor(_instance, IDC_ARROW);
    _WndClass.lpfnWndProc = WindowProcInternal;
    _WndClass.hInstance = _instance;
    _WndClass.lpszClassName = _ClassName;
    RegisterClass(&_WndClass);
    mWindowInstance = CreateWindowEx(0, _ClassName, mWindowName.ToWString()->c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                     0, 0, _width, _height, null, null, _instance, this);
}

void System::Window::Update()
{
    MSG msg = {};
    while (GetMessage(&msg, null, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        OnWindowUpdate();
    }
}

LRESULT System::Window::WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp)
{
    if (hWindow == nullptr) return 0;
    switch (msg)
    {
    case WM_COMMAND:
        while (mMenus.GetEnumerator()->MoveNext())
        {
            const Collections::Generic::KeyValuePair<String, WindowMenu*> element = mMenus.GetEnumerator()->Current();
            element.Value->InvokeCallback(wp);
        }
        mMenus.GetEnumerator()->Reset();
        break;
    case WM_CREATE:
        AddMenus(hWindow);
        break;
    case WM_DESTROY:
        Environment::Exit(Environment::EXIT_VALID);
        break;
    default:
        return DefWindowProcW(hWindow, msg, wp, lp);
    }
    return 0;
}


void System::Window::OnWindowUpdate()
{
}

System::Window::Window(const Window& _copy)
{
    mWindowInstance = _copy.mWindowInstance;
    mWindowName = _copy.mWindowName;
    mWidth = _copy.mWidth;
    mHeight = _copy.mHeight;
    mMenus = _copy.mMenus;
}
#pragma endregion constructor
#pragma region custom methods

LRESULT System::Window::WindowProcInternal(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp)
{
    if (WM_NCCREATE == msg)
    {
        SetWindowLongPtr(hWindow, GWLP_USERDATA,  reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(lp)->lpCreateParams));
        return TRUE;
    }
    return reinterpret_cast<Window*>(GetWindowLongPtr(hWindow, GWLP_USERDATA))->WindowProc(hWindow, msg, wp, lp);
}


System::WindowMenu* System::Window::CreateMenu(const String& _name)
{
    WindowMenu* _menu = new WindowMenu(_name);
    mMenus.Add(_name, _menu);
    return _menu;
}

System::WindowMenu* System::Window::GetMenu(const string& _menuName)
{
    if (!mMenus.ContainsKey(_menuName))return null;
    return mMenus[_menuName];
}

void System::Window::Close() const
{
    CloseWindow(mWindowInstance);
}

void System::Window::AddMenus(HWND _hwnd)
{
    const WindowMenu* _menu = CreateMenu("Main");
    WindowMenu* _fileMenu = CreateMenu("File");
    _fileMenu->CreateButtonMenu("New", []
    {
        Console::WriteLine("New");
    });
    _menu->CreatePopMenu(_fileMenu);
    SetMenu(_hwnd, *_menu);
}
#pragma endregion custom methods
#pragma region operator
System::Window& System::Window::operator=(const Window& _other)
{
    mWindowInstance = _other.mWindowInstance;
    mWindowName = _other.mWindowName;
    mWidth = _other.mWidth;
    mHeight = _other.mHeight;
    mMenus = _other.mMenus;
    return *this;
}
#pragma endregion operator
