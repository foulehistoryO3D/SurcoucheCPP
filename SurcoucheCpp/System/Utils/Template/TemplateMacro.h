#pragma once
#include "EnableIf.h"
#include "../../Type/Type.h"

template <typename T>
auto ArrayCountHelper(T& t) -> typename EnableIf<std::is_array_v<T>, char(&)[sizeof(t) / sizeof(t[0]) + 1]>::Type;

template<typename T, System::uint32 N>
char (&ArrayCounterHelper(const T(&)[N]))[N+1];

#define ARRAY_COUNT(array) (sizeof(ArrayCounterHelper(array)) -1)

#define LIKELY(x)			(x)