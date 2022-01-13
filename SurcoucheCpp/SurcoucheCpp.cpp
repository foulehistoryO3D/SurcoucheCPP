#include "System/IncludeSystem.h"
#include "System/PrimaryType/Enum/Enum.h"
#include "System/Window/Window.h"
#include "Test/ETest.h"

int main()
{
    Window* window = new Window("Test", 600, 800, false);
    WindowMenu* fileMenu = window->GetMenu("File");
    WindowMenu* mainMenu = window->GetMenu("Main");
    if (mainMenu)
    {
        WindowMenu* editMenu = window->CreateMenu("Edit");
        editMenu->CreateButtonMenu("Save", {});
        mainMenu->CreatePopMenu(editMenu);
        mainMenu->CreateButtonMenu("Help", []{});
        
    }
    if (fileMenu)
    {
        fileMenu->CreateButtonMenu("Test", []
        {
        });
        Console::WriteLine("Test");
    }
    window->Open();
    return 0;
}
