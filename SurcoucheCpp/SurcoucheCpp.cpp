#include <string>
#include <iostream>
#include <regex>

int main() 
{

    std::string s("This is one sentence.");
    const std::regex re("(\\b(\\w+?)[,:;]?\\s?)+[?.!]+");

    if (std::regex_match(s, re)) 
    {
        for (std::smatch m; std::regex_search(s, m, re); s = m.suffix())
        {
            std::cout << m[0] << " " << m[1] << " " << m[2] << " " << m[3];
        }
    }

    return 0;
}