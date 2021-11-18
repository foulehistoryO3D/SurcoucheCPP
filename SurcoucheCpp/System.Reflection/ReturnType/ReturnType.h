#pragma once
#include <iostream>
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/String/String.h"

namespace System
{
    template <typename R, typename... Args>
    struct ReturnType : Object
    {
        using Type = R;
    private:
        const char* mTypeName = "";
    public:
        ReturnType();
        String TypeName()const { return mTypeName; }
        String ToString() const override  { return mTypeName; }
    };

    template <typename R, typename ... Args>
    ReturnType<R, Args...>::ReturnType()
    {
        String _str = typeid(R).name();
        std::cout<< _str << std::endl;
        if (!_str.StartWith("class"))
        {
            _str = _str.SubString(0, _str.FirstIndexOf(' '));
            mTypeName = _str;
            return;
        }
        _str = _str.SubString(_str.FirstIndexOf(':') + 2, _str.FirstIndexOf('('));
        mTypeName = _str;
    }
}
