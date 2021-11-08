#pragma once
#include <tuple>
#include <type_traits>
#include "../../System.Collections.Generic/List/List.h"

namespace System
{
    class TemplateUtils : public Object
    {
        DECLARE_CLASS_INFO(Object)
    public:
        template <size_t Index, typename... Args>
        static auto GetPackageParameterValueWithIndex(Args&&... _args);
        template<typename T, typename... Args>
        static Collections::Generic::List<T> CreateVectorWithParameterPack(Args... _args);
        template<typename... Args>
        static size_t SizeOfPackageParameters(Args&&... _args);
    };

    template <size_t Index, typename ... Args>
    auto TemplateUtils::GetPackageParameterValueWithIndex(Args&&... _args)
    {
        return std::get<Index>(std::forward_as_tuple(std::forward<Args>(_args)...));
    }

    template <typename T, typename ... Args>
    Collections::Generic::List<T> TemplateUtils::CreateVectorWithParameterPack(Args... _args)
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
}
