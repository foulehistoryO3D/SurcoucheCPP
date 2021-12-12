#include "Window.h"

#pragma region constructor
System::Window::Window(const String& _windowName, const Integer& _width, const Integer& _height)
{
    mWindowName = _windowName;
    mWidth = _width;
    mHeight = _height;
}

System::Window::Window(const Window& _copy)
{
    mWindowName = _copy.mWindowName;
    mWidth = _copy.mWidth;
    mHeight = _copy.mHeight;
}
#pragma endregion constructor
#pragma region custom methods
System::WindowMenu System::Window::CreateMenu(const String& _name)
{
    WindowMenu _menu = WindowMenu(_name);
    mMenus.Add(_name, _menu);
    return _menu;
}

void System::Window::Close()
{
}
#pragma endregion custom methods
#pragma region operator
System::Window& System::Window::operator=(const Window& _other)
{
    mWindowName = _other.mWindowName;
    mWidth = _other.mWidth;
    mHeight = _other.mHeight;
    return *this;
}
#pragma endregion operator