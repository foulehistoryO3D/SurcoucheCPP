#include "System/IncludeSystem.h"
#include "System.Numerics/Vector/Vector2/Vector2.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Numerics::Vector2 vec = Numerics::Vector2(10, 100);
    Numerics::Vector2 vec1 = Numerics::Vector2(200 , 50);

    Console::WriteLine(Numerics::Vector2::Max(vec, vec1));

    
    return 0;
}
