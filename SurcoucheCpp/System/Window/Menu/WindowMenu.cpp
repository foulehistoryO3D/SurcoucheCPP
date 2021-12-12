#include "WindowMenu.h"
#include "../../PrimaryType/String/String.h"
#pragma region f/p
System::String System::WindowMenu::Name() const
{
    return mMenuName;
}
#pragma endregion f/p
#pragma region constructor
System::WindowMenu::WindowMenu(const String& _menuName)
{
    mMenuName = _menuName;
    mMenu = CreateMenu();
}

System::WindowMenu::WindowMenu(const WindowMenu& _copy)
{
    mMenuName = _copy.mMenuName;
    mMenu = _copy.mMenu;
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