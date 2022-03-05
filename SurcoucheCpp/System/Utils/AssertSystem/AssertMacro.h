#pragma once
#include "../../Object/Object.h"


namespace System
{
    class AssertMacro sealed : public Object
    {
        DECLARE_CLASS_INFO(object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region static methods
    public:
        static void VARARGS CheckVerifyFailed(const char* expr, const char* functionName, const int line, const wchar_t* format, ...);
        static void DebugWarningDeprecated(const int line, const char* message);
        static void DebugWarningDeprecatedVersion(const int line, const float version, const char* message);
#pragma endregion static methods
        class DebugWarningClass
        {
        public:
            DebugWarningClass(const int line, const float version, const char* message)
            {
                DebugWarningDeprecatedVersion(line, version, message);
            }
        };
    };
}

#define UNLIKELY(x)			(x)

#define Check(expr, ...) \
{ \
    if (UNLIKELY(!(expr))) \
    { \
        AssertMacro::CheckVerifyFailed(#expr, __FUNCTION__, __LINE__, TEXT(""), __VA_ARGS__); \
    } \
}

#define Emit_Custom_Warning_At_Line(line, warning) AssertMacro::DebugWarningDeprecated(line, warning)
#define Emit_Custom_Warning_At_Line_With_Version(line, version, warning) AssertMacro::DebugWarningClass instance = {line, version, warning};

#define Deprecated_Macro(version, message) Emit_Custom_Warning_At_Line_With_Version(__LINE__, version, message ", please update your code");
#define Deprecated_Function(version, newFunction) Emit_Custom_Warning_At_Line_With_Version(__LINE__, version, __FUNCTION__ " is deprecated please update your code, please use " newFunction);
#define TEST(str) [[deprecated(str)]]