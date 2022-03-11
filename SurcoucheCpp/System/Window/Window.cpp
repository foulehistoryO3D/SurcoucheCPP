#include "Window.h"
#include "../Console/Console.h"
#include "../Environment/Environment.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/Float/Float.h"

#pragma warning(disable:4834)

#pragma region constructor
System::Window::Window(const String& _windowName, const Integer& _width, const Integer& _height, bool _isAsync)
{
    mWindowName = _windowName;
    mWidth = _width;
    mHeight = _height;
    mIsAsync = _isAsync;

    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    const LPCWSTR _ClassName = mWindowName.ToWString()->c_str();
    WNDCLASS _WndClass = {};
    const HINSTANCE _instance = HINSTANCE();
    _WndClass.style = CS_HREDRAW | CS_VREDRAW;
    _WndClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
    _WndClass.hCursor = LoadCursor(_instance, IDC_ARROW);
    _WndClass.lpfnWndProc = WindowProcInternal;
    _WndClass.hInstance = _instance;
    _WndClass.lpszClassName = _ClassName;
    RegisterClass(&_WndClass);
    mWindowInstance = CreateWindowEx(0, _ClassName, mWindowName.ToWString()->c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX,
                                     CW_USEDEFAULT, CW_USEDEFAULT, _width, _height, nullptr, nullptr, _instance, this);
    // TextBlock = CreateWindowEx(WS_EX_CLIENTEDGE , TEXT("Edit"), TEXT("test"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 20, 140, 20, mWindowInstance, NULL, NULL, NULL);
    // HWND hwndButton = CreateWindow(L"BUTTON", L"Ok", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 20, 30, 20, mWindowInstance, (HMENU)mMenuAction.Count(), null, null);
}


int System::Window::ActionCount() const
{
    return mMenuAction.Count();
}

void System::Window::Open()
{
    if (mWindowInstance == nullptr)
        throw Exception("Error on creating window !");
    ShowWindow(mWindowInstance, 1);
    UpdateWindow(mWindowInstance);
    if (mIsAsync)
        std::thread(&Window::Update, this);
    else Update();
}

void System::Window::Update()
{
    INT64 count_per_sec = 0;
    QueryPerformanceFrequency((LARGE_INTEGER*) &count_per_sec);
    float sec_per_count = 1.0f / (float) count_per_sec;
    INT64 prev_time = 0;
    QueryPerformanceCounter((LARGE_INTEGER*) &prev_time);
    
    
    MSG msg = {};
    while (!mIsClose)
    {
        RedrawWindow(mWindowInstance, nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW);
        OnWindowUpdate();
        while (PeekMessage(&msg, mWindowInstance, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        INT64 current_time = 0;
        QueryPerformanceCounter((LARGE_INTEGER*) &current_time);
        mDeltaTime = (current_time - prev_time) * sec_per_count;
        prev_time = current_time;
    }
}

void System::Window::RegisterAction(const int _index, Action<> _callback)
{
    mMenuAction.Add(_index, _callback);
}

LRESULT System::Window::WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp)
{
    if (hWindow == nullptr) return 0;
    PAINTSTRUCT paintStruct = PAINTSTRUCT();
    switch (msg)
    {
    case WM_COMMAND:
        if (!mMenuAction.ContainsKey(wp)) return 0;
        mMenuAction[wp].Invoke();
        break;
    case WM_PAINT:
        return 0;
    case WM_CREATE:
        AddMenus(hWindow);
        break;
    case WM_DESTROY:
        Close();
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

System::Window::Window(const Window& copy) : Object(copy)
{
    hdc = copy.hdc;
    hinstAcc = copy.hinstAcc;
    gdiplusToken = copy.gdiplusToken;
    mWindowInstance = copy.mWindowInstance;
    mWindowName = copy.mWindowName;
    mWidth = copy.mWidth;
    mHeight = copy.mHeight;
    mMenus = copy.mMenus;
}
#pragma endregion constructor
#pragma region custom methods

LRESULT System::Window::WindowProcInternal(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp)
{
    if (WM_NCCREATE == msg)
    {
        SetWindowLongPtr(hWindow, GWLP_USERDATA,
                         reinterpret_cast<LONG_PTR>(reinterpret_cast<CREATESTRUCT*>(lp)->lpCreateParams));
        return TRUE;
    }
    return reinterpret_cast<Window*>(GetWindowLongPtr(hWindow, GWLP_USERDATA))->WindowProc(hWindow, msg, wp, lp);
}


System::WindowMenu* System::Window::CreateMenu(const String& _name)
{
    WindowMenu* _menu = new WindowMenu(this, _name);
    mMenus.Add(_name, _menu);
    return _menu;
}

System::WindowMenu* System::Window::GetMenu(const string& _menuName)
{
    if (!mMenus.ContainsKey(_menuName)) return nullptr;
    return mMenus[_menuName];
}

void System::Window::Close()
{
    GdiplusShutdown(gdiplusToken);
    CloseWindow(mWindowInstance);
    mIsClose = true;
}

void System::Window::AddMenus(const HWND hwnd)
{
    const WindowMenu* _menu = CreateMenu();
    const WindowMenu* _fileMenu = CreateMenu("File");
    _fileMenu->CreateButtonMenu("New", []
    {
        Console::WriteLine("New");
    });
    _menu->CreatePopMenu(_fileMenu);
    SetMenu(hwnd, *_menu);
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
