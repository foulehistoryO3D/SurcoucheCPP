#pragma once
#include <tuple>
#include <type_traits>

namespace System
{
    class TemplateUtils : public Object
    {
    private:
        template<typename T>
        static T GetPackageParameterValue(T _t);
    public:
        template<typename T, typename... Args>
        static T GetPackageParameterValue(size_t _index, Args... _args);
        template <size_t Index, typename... Args>
        static auto GetPackageParameterValueWithIndex(Args&&... _args);
    };


    template <typename T>
    T TemplateUtils::GetPackageParameterValue(T _t)
    {
        return _t;
    }

    template <typename T, typename ... Args>
    T TemplateUtils::GetPackageParameterValue(size_t _index, Args... _args)
    {
        std::vector<T> _vector = std::vector<T>();
        (_vector.push_back(_args), ...);
        return _vector[_index];
    }

    template <size_t Index, typename ... Args>
    auto TemplateUtils::GetPackageParameterValueWithIndex(Args&&... _args)
    {
        return std::get<Index>(std::forward_as_tuple(std::forward<Args>(_args)...));
    }
}
