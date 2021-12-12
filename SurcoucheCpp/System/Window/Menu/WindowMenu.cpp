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

void System::WindowMenu::CreateButtonMenu(const String& _name, Action<> _callback)
{
    const int _key = mMenuAction.Count();
    AppendMenu(mMenu, MF_STRING, _key, _name.ToWString()->c_str());
    mMenuAction.Add(_key, _callback);
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

void System::WindowMenu::InvokeCallback(const int _key)
{
    if (mMenuAction.ContainsKey(_key))
        mMenuAction[_key]();
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