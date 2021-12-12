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
        HWND mWindowInstance = nullptr;
        String mWindowName = "";
        Integer mWidth = 0;
        Integer mHeight = 0;
        Collections::Generic::Dictionary<String, WindowMenu*> mMenus = Collections::Generic::Dictionary<String, WindowMenu*>();
#pragma endregion f/p
#pragma region constructor
    public:
        Window()=default;
        Window(const String& _windowName, const Integer& _width, const Integer& _height, bool _isAsync = true);
        Window(const Window& _copy);
#pragma endregion constructor
#pragma region custom methods
    private:
        void Update();
        LRESULT __stdcall WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp);
        static LRESULT __stdcall WindowProcInternal(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp);
        
    public:
        void Close() const;
    protected:
        WindowMenu* CreateMenu(const String& _name = "");
        virtual void AddMenus(HWND _hwnd);
        virtual void OnWindowUpdate();
#pragma endregion custom methods
#pragma region operator
    public:
        Window& operator=(const Window& _other);
#pragma endregion operator
    };
}
