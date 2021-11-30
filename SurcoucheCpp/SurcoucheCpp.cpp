#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "System/IncludeSystem.h"
#include "System.IO/DriveInfo/DriveInfo.h"


#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

#define MAKE_STRING(str, ...) #str, MAKE_STRING1_(__VA_ARGS__)
#define MAKE_STRING1_(str, ...) #str, MAKE_STRING2_(__VA_ARGS__)
#define MAKE_STRING2_(str, ...) #str, MAKE_STRING3_(__VA_ARGS__)
#define MAKE_STRING3_(str, ...) #str, MAKE_STRING4_(__VA_ARGS__)
#define MAKE_STRING4_(str, ...) #str, MAKE_STRING5_(__VA_ARGS__)
#define MAKE_STRING5_(str, ...) #str, MAKE_STRING6_(__VA_ARGS__)
#define MAKE_STRING6_(str, ...) #str, MAKE_STRING7_(__VA_ARGS__)
#define MAKE_STRING7_(str, ...) #str, MAKE_STRING8_(__VA_ARGS__)
#define MAKE_STRING8_(str, ...) #str, MAKE_STRING9_(__VA_ARGS__)
#define MAKE_STRING9_(str, ...) #str, MAKE_STRING10_(__VA_ARGS__)
#define MAKE_STRING10_(str) #str

#define MAKE_ENUM(name, ...) MAKE_ENUM_(, name, __VA_ARGS__)
#define MAKE_CLASS_ENUM(name, ...) MAKE_ENUM_(friend, name, __VA_ARGS__)

#define MAKE_ENUM_(attribute, name, ...) name { __VA_ARGS__ }; \
attribute std::istream& operator>>(std::istream& is, name& e) { \
const char* name##Str[] = { MAKE_STRING(__VA_ARGS__) }; \
std::string str; \
std::istream& r = is >> str; \
const size_t len = sizeof(name##Str)/sizeof(name##Str[0]); \
const std::vector<std::string> enumStr(name##Str, name##Str + len); \
const std::vector<std::string>::const_iterator it = std::find(enumStr.begin(), enumStr.end(), str); \
if (it != enumStr.end())\
e = name(it - enumStr.begin()); \
else \
throw std::runtime_error("Value \"" + str + "\" is not part of enum "#name); \
return r; \
}; \
attribute std::ostream& operator<<(std::ostream& os, const name& e) { \
const char* name##Str[] = { MAKE_STRING(__VA_ARGS__) }; \
return (os << name##Str[e]); \
}


int main()
{
    SetConsoleOutputCP(65001);
   
    String _name = *ETest::Backward;
    
    return 0;
}
