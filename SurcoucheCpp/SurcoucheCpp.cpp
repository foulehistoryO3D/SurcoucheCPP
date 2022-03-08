#include "System/IncludeSystem.h"
#include "System.Numerics/Matrix/Matrix4x4/Matrix4x4.h"
#include "System.Numerics/Quaternion/Quaternion.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Console::WriteLine(Numerics::Matrix4x4::CreateTranslation(Numerics::Vector3(1,10,6)));
    return 0;
}
