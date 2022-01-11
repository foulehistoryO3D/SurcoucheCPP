#pragma once
#include <map>
#include <sstream>
#include <string>

#include "../../TemplateUtils/TemplateUtils.h"

#define STRING_REMOVE_CHAR(str, ch) str.erase(std::remove(str.begin(), str.end(), ch), str.end())

inline std::vector<std::string> splitString(std::string str, char sep = ',')
{
    std::vector<std::string> vecString;
    std::string item;

    std::stringstream stringStream(str);

    while (std::getline(stringStream, item, sep))
    {
        vecString.push_back(item);
    }

    return vecString;
}

#define ENUM(name, type, ...) \
enum class name : type \
{ \
__VA_ARGS__ \
}; \
std::map<type, std::string> name##MapName(generateEnumMap<type>(#__VA_ARGS__));\
const char* operator*(name _name)\
{\
return name##MapName[(type)_name].c_str();\
}

template <typename T>
std::map<T, std::string> generateEnumMap(std::string strMap)
{
    STRING_REMOVE_CHAR(strMap, ' ');
    STRING_REMOVE_CHAR(strMap, '(');

    std::vector enumTokens(splitString(strMap));
    std::map<T, std::string> retMap;
    T inxMap;

    inxMap = 0;
    for (auto iter = enumTokens.begin(); iter != enumTokens.end(); ++iter)
    {
        std::string enumName = "";
        T enumValue;
        if (iter->find('=') == std::string::npos)
            enumName = *iter;
        else
        {
            std::vector enumNameValue(splitString(*iter, '='));
            enumName = enumNameValue[0];
            if (std::is_unsigned<T>::value)
                inxMap = static_cast<T>(std::stoull(enumNameValue[1], 0, 0));
            else
                inxMap = static_cast<T>(std::stoll(enumNameValue[1], 0, 0));
        }
        retMap[inxMap++] = enumName;
    }

    return retMap;
}
