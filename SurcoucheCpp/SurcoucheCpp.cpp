#include "System/IncludeSystem.h"

struct Void : Object
{
  operator void();  
};

class Test
{
    Void Salut()
    {
        
    }
};

int main() 
{
    SetConsoleOutputCP(65001);
    return 0;
}
