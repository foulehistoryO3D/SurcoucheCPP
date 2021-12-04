#pragma once
#include <iostream>
#include <tuple>
#include <type_traits>
#include "../../System.Collections.Generic/List/List.h"
#include "../../System.Reflection/ParameterInfo/ParameterInfo.h"
#include "../PrimaryType/Boolean/Boolean.h"

namespace System
{
    class TemplateUtils : public Object
    {
        DECLARE_CLASS_INFO(Object)
    public:
        template <size_t Index, typename... Args>
        static auto GetPackageParameterValueWithIndex(Args&&... _args);
        template<typename T, typename... Args>
        static Collections::Generic::List<T> CreateListWithParameterPack(Args... _args);
        template<typename... Args>
        static size_t SizeOfPackageParameters(Args&&... _args);
        template <typename C, typename... Args>
        static Collections::Generic::List<Reflection::ParameterInfo> GetParametersFunction(void (C::*func)(Args ... _args));
        template<typename T>
        static Boolean IsNull();
    };

    template <size_t Index, typename ... Args>
    auto TemplateUtils::GetPackageParameterValueWithIndex(Args&&... _args)
    {
        return std::get<Index>(std::forward_as_tuple(std::forward<Args>(_args)...));
    }

    template <typename T, typename ... Args>
    Collections::Generic::List<T> TemplateUtils::CreateListWithParameterPack(Args... _args)
    {
        Collections::Generic::List<T> _result = Collections::Generic::List<T>();
        (_result.Add(_args), ...);
        return _result;
    }

    template <typename ... Args>
    size_t TemplateUtils::SizeOfPackageParameters(Args&&... _args)
    {
        return sizeof...(_args);
    }

    template <typename C, typename ... Args>
    Collections::Generic::List<Reflection::ParameterInfo> TemplateUtils::GetParametersFunction(void(C::*ptr)(Args... _args))
    {
        std::tuple<Args...> _tuple = std::tuple<Args...>();
    
        Collections::Generic::List<Reflection::ParameterInfo> _tab = Collections::Generic::List<Reflection::ParameterInfo>();
        int _index = 0;
        std::apply([&](auto&&... _args)
        {
            (_tab.Add(Reflection::ParameterInfo(_args.Clone(static_cast<void*>(&_args)), _index++)), ...);
        }, _tuple);
        return _tab;
    }

    template <typename T>
    Boolean TemplateUtils::IsNull() { return std::is_null_pointer_v<T>; }
}
