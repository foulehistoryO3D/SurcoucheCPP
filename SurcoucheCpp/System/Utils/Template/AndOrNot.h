#pragma once

template<typename... Types> struct And;

template<bool lhsValue, typename... rhs>
struct AndValue
{
    static constexpr bool Vlaue = And<rhs...>::value;
    static constexpr bool value = And<rhs...>::value;
};

template<typename... rhs>
struct AndValue<false, rhs...>
{
    static constexpr bool Value = false;
    static constexpr bool value = false;
};

template<typename lhs, typename... rhs>
struct And<lhs, rhs...> : AndValue<lhs::Value, rhs...>
{
    
};

template<>
struct And<>
{
    static constexpr bool Value = true;
    static constexpr bool value = true;
};

template <typename... Types>
struct Or;

template <bool LHSValue, typename... RHS>
struct OrValue
{
    static constexpr bool Value = Or<RHS...>::value;
    static constexpr bool value = Or<RHS...>::value;
};

template <typename... RHS>
struct OrValue<true, RHS...>
{
    static constexpr bool Value = true;
    static constexpr bool value = true;
};

template <typename LHS, typename... RHS>
struct Or<LHS, RHS...> : OrValue<LHS::Value, RHS...>
{
};

template <>
struct Or<>
{
    static constexpr bool Value = false;
    static constexpr bool value = false;
};

template<typename Type>
struct Not
{
    static constexpr bool Value = !Type::Value;
    static constexpr bool value = !Type::value;
};