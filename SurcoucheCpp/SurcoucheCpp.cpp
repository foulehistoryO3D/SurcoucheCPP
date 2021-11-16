#include "System/IncludeSystem.h"
#include "System.Text.RegularExpressions/Match/Match.h"
#include "System.Text.RegularExpressions/Regex/Regex.h"

int main() 
{

    std::string s("This is one sentence. This is a second sentence.");
    Text::RegularExpressions::Regex _regex = Text::RegularExpressions::Regex("(\\b(\\w+?)[,:;]?\\s?)+[?.!]+");
    Text::RegularExpressions::Match _match = _regex.Match(s.c_str());
    Console::WriteLine(string("Match: {0}, Index: {1}, Length: {2}"), _match.Value(), _match.Index(), _match.Length());
    foreach<KeyValuePair<String,Text::RegularExpressions::Group>>(_match.Groups().GetEnumerator(), [](KeyValuePair<String, Text::RegularExpressions::Group> _pair)
    {
        Console::WriteLine(string("   Group {0}: '{1}' {2}"), _pair.Value.Name(), _pair.Value.Value(), _pair.Value.Index());
        Int _captureCtr = 0;
        foreach<Text::RegularExpressions::Capture>(_pair.Value.Captures().GetEnumerator(), [&](Text::RegularExpressions::Capture _capture)
        {
            _captureCtr++;
            Console::WriteLine(string("      Capture {0}: '{1}' {2}"), _captureCtr, _capture.Value(), _capture.Index());
        });
    });
    return 0;
}
