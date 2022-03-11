#pragma once
#include <type_traits>

template<typename Base, typename T>
struct IsBaseOf
{
    enum { Value = std::is_base_of_v<Base, T>};
};
