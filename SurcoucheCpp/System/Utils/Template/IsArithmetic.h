#pragma once
#include "../../Type/Type.h"

template<typename T>
struct IsArithmetic { enum { Value = false};};

template<> struct IsArithmetic<float> {enum { Value = true};};
template<> struct IsArithmetic<double> {enum { Value = true};};
template<> struct IsArithmetic<long double> {enum { Value = true};};
template<> struct IsArithmetic<System::uint8> {enum { Value = true};};
template<> struct IsArithmetic<System::uint16> {enum { Value = true};};
template<> struct IsArithmetic<System::uint32> {enum { Value = true};};
template<> struct IsArithmetic<System::uint64> {enum { Value = true};};
template<> struct IsArithmetic<System::int8> {enum { Value = true};};
template<> struct IsArithmetic<System::int16> {enum { Value = true};};
template<> struct IsArithmetic<System::int32> {enum { Value = true};};
template<> struct IsArithmetic<System::int64> {enum { Value = true};};
template<> struct IsArithmetic<long> {enum { Value = true};};
template<> struct IsArithmetic<unsigned long> {enum { Value = true};};
template<> struct IsArithmetic<bool> {enum { Value = true};};
template<> struct IsArithmetic<wchar_t> {enum { Value = true};};
template<> struct IsArithmetic<char> {enum { Value = true};};

template<typename T> struct IsArithmetic<const T> { enum {Value = IsArithmetic<T>::Value};};
template<typename T> struct IsArithmetic<volatile T> { enum {Value = IsArithmetic<T>::Value};};
template<typename T> struct IsArithmetic<const volatile T> { enum {Value = IsArithmetic<T>::Value};};