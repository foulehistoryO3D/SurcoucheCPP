#pragma once
#include <windows.h>
#include "../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../Object/Object.h"
#include "../Event/Action/Action.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Integer/Integer.h"
#include "Menu/WindowMenu.h"

namespace System
{
    class Window : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        String mWindowName = "";
        Integer mWidth = 0;
        Integer mHeight = 0;
        Collections::Generic::List<Action<>> mMenuAction = Collections::Generic::List<Action<>>();
        Collections::Generic::Dictionary<String, WindowMenu> mMenus = Collections::Generic::Dictionary<String, WindowMenu>();
#pragma endregion f/p
#pragma region constructor
    public:
        Window()=default;
        Window(const String& _windowName, const Integer& _width, const Integer& _height);
        Window(const Window& _copy);
#pragma endregion constructor
#pragma region custom methods
        WindowMenu CreateMenu(const String& _name);
        void Close();
#pragma endregion custom methods
#pragma region operator
    public:
        Window& operator=(const Window& _other);
#pragma endregion operator
    };
}
