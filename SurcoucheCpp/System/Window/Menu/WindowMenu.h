#pragma once
#include <windows.h>

#include "../../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../Object/Object.h"
#include "../../Event/Action/Action.h"
#include "../../../System.Collections.Generic/List/List.h"

namespace System
{
    class WindowMenu : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/P
    private:
        Collections::Generic::Dictionary<int, Action<>> mMenuAction = Collections::Generic::Dictionary<int, Action<>>();
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
#pragma region custom methods
    public:
        void CreateButtonMenu(const String& _name, Action<> _callback);
        void CreateSeparator() const;
        void CreatePopMenu(const WindowMenu* _subMenu) const;
        void InvokeCallback(const int _key);
#pragma endregion custom methods
#pragma region operator
        WindowMenu& operator=(const WindowMenu& _other);
        operator HMENU() const
        {
            return mMenu;
        }
#pragma endregion operator
    };
}
