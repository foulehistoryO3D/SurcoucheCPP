#include "WindowMenu.h"
#include "../../PrimaryType/String/String.h"
#include "../Window.h"
#pragma region f/p
System::String System::WindowMenu::Name() const
{
    return mMenuName;
}
#pragma endregion f/p
#pragma region constructor

System::WindowMenu::WindowMenu(Window* _window, const String& _menuName)
{
    mWindow = _window;
    mMenuName = _menuName;
    mMenu = CreateMenu();
}

System::WindowMenu::WindowMenu(const WindowMenu& _copy)
{
    mMenuName = _copy.mMenuName;
    mMenu = _copy.mMenu;
}

void System::WindowMenu::CreateButtonMenu(const String& _name, Action<> _callback) const
{
    const int _key = mWindow->ActionCount();
    AppendMenu(mMenu, MF_STRING, _key, _name.ToWString()->c_str());
    mWindow->RegisterAction(_key, _callback);
}

void System::WindowMenu::CreateSeparator() const
{
    AppendMenu(mMenu, MF_SEPARATOR, NULL, nullptr);
}

void System::WindowMenu::CreatePopMenu(const WindowMenu* _subMenu) const
{
    const int _key = reinterpret_cast<UINT_PTR>(_subMenu->mMenu);
    AppendMenu(mMenu, MF_POPUP, _key, _subMenu->Name().ToWString()->c_str());
}

#pragma endregion constructor
#pragma region operator
System::WindowMenu& System::WindowMenu::operator=(const WindowMenu& _other)
{
    mMenuName = _other.mMenuName;
    mMenu = _other.mMenu;
    return *this;
}
#pragma endregion operator