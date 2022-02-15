#pragma once
#include "../../Object/Object.h"

namespace System
{
    class Boolean;
    class Byte;
    class Char;
    class DateTime;
    class Float;
    class Double;
    class Integer;
    
    class IConvertible
    {
    public:
        virtual ~IConvertible() = default;
        virtual Boolean ToBoolean() PURE_VIRTUAL()
        virtual Byte ToByte() PURE_VIRTUAL()
        virtual Char ToChar() PURE_VIRTUAL()
        virtual DateTime ToDateTime() PURE_VIRTUAL()
        virtual Float ToFloat() PURE_VIRTUAL()
        virtual Double ToDouble() PURE_VIRTUAL()
        virtual Integer ToInteger() PURE_VIRTUAL()
    };
}
