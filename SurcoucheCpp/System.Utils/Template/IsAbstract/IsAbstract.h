#pragma once

template <typename T>
struct IsAbstract
{
    enum { Value = __is_abstract(T) };
};
