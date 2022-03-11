#pragma once
#include <windows.h>
#include <thread>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#include "../../System.Collections.Generic/Dictionary/Dictionary.h"
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
        float test = 0;
        HDC hdc;
        HANDLE hinstAcc;
        float mDeltaTime = 0.0f;

        GdiplusStartupInput gdiplusStartupInput;
        ULONG_PTR           gdiplusToken;
        HWND mWindowInstance = nullptr;
        String mWindowName = "";
        Integer mWidth = 0;
        Integer mHeight = 0;
        Bool mIsAsync = false;
        Bool mIsClose = false;
        Collections::Generic::Dictionary<String, WindowMenu*> mMenus = Collections::Generic::Dictionary<String, WindowMenu*>();
        Collections::Generic::Dictionary<Int, Action<>> mMenuAction = Collections::Generic::Dictionary<Int, Action<>>();
    public:
        int ActionCount()const;
#pragma endregion f/p
#pragma region constructor
    public:
        Window()=default;
        Window(const String& _windowName, const Integer& _width, const Integer& _height, bool _isAsync = true);
        Window(const Window& copy);
#pragma endregion constructor
#pragma region custom methods
    private:
        void Update();
        LRESULT __stdcall WindowProc(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp);
        static LRESULT __stdcall WindowProcInternal(HWND hWindow, UINT msg, WPARAM wp, LPARAM lp);

    public:
        void RegisterAction(const int _index, Action<> _callback);
        void Open();
        void Close();
        WindowMenu* CreateMenu(const String& _name = "");
        WindowMenu* GetMenu(const string& _menuName);
    protected:
        virtual void AddMenus(HWND hwnd);
        virtual void OnWindowUpdate();
#pragma endregion custom methods
#pragma region operator
    public:
        Window& operator=(const Window& _other);
#pragma endregion operator
    };
}