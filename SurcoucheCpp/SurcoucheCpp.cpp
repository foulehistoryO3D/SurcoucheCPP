#include "System/IncludeSystem.h"
#include "System.Collections.Generic/LinkedList/LinkedList.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Int tabInt[5] = {0,1,2,3,4};
    LinkedList<Int> tab = LinkedList<Int>({0,1,2,3,4,5});
    Console::WriteLine(tab);
    return 0;
}
