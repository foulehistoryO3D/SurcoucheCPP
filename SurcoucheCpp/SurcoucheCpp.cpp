#include "System/IncludeSystem.h"

#include "System.Text.RegularExpressions/Match/Match.h"
#include "System.Text.RegularExpressions/Regex/Regex.h"

using namespace Text::RegularExpressions;

int main()
{
    SetConsoleOutputCP(65001);
    Regex _regex = Regex("(\\b(\\w+?)[,:;]?\\s?)+[?.!]");
    const String& _str = "This is one sentence. This is a second sentence.";
    Match _match = _regex.Match(_str);
    Console::WriteLine(string("Match: ") + _match.Value() + " index: " + _match.Index());
    const int count = _match.Groups().Count();
    for (int i = 0; i < count; ++i)
    {
        Console::WriteLine("\tGroup {0}: '{1}' index: {2}", Int(i+1), _match.Groups()[i].Value(), _match.Groups()[i].Index());
        const int _count1 = _match.Groups()[i].Captures().Count();
        for (int j = 0; j < _count1; ++j)
        {
            Console::WriteLine("\t\tCapture {0}: '{1}' index: {2}", Int(j+1), _match.Groups()[i].Captures()[j].Value(), _match.Groups()[i].Captures()[j].Index());
        }
    }
    return 0;
}
