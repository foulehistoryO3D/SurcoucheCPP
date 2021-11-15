#include <string>
#include <iostream>
#include <regex>

int main() 
{

    std::string s("This is one sentence. This is a second sentence.");
    std::regex re("(\\b(\\w+?)[,:;]?\\s?)+[?.!]");

    if (std::regex_match(s, re)) 
    {
        for (std::smatch m; std::regex_search(s, m, re); s = m.suffix())
        {
            std::cout << m[1] << "\t\t" << m[2] << "\t\t" << m[3] << std::endl;
        }
    }

    return 0;
}