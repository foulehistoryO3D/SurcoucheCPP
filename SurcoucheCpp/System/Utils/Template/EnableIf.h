#pragma once

template <bool Predicate, typename Result = void>
class EnableIf;

template <typename Result>
class EnableIf<true, Result>
{
public:
    using type = Result;
    using Type = Result;
};

template <typename Result>
class EnableIf<false, Result>
{ };
