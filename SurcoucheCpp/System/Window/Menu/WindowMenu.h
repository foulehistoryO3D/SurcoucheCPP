#pragma once
#include <windows.h>
#include "../../Object/Object.h"

namespace System
{
    class WindowMenu : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/P
    private:
        HMENU mMenu = nullptr;
        const char* mMenuName = "";
    public:
        String Name() const;
#pragma endregion f/P
#pragma region constructor
    public:
        WindowMenu() = default;
        WindowMenu(const String& _menuName);
        WindowMenu(const WindowMenu& _copy);
#pragma endregion constructor
#pragma region operator
        WindowMenu& operator=(const WindowMenu& _other);
#pragma endregion operator
    };
}
