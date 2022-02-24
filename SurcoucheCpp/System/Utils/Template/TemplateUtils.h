#pragma once
#include "AndOrNot.h"
#include "AreTypesEqual.h"
#include "EnableIf.h"
#include "IsArithmetic.h"
#include "RemoveReference.h"
#include "TemplateMacro.h"
#include "../../../System.Utils/Template/IsPointer/IsPointer.h"
#include "../../Type/Type.h"

template<typename T> struct IsLValueReferenceType {enum { Value = false};};
template<typename T> struct IsLValueReferenceType<T&> {enum { Value = true};};


template<typename T> struct IsRValueReferenceType { enum { Value = false};};
template<typename T> struct IsRValueReferenceType<T&&> { enum { Value = true};};

template <typename T> struct RValueToLValueReference      { typedef T  Type; };
template <typename T> struct RValueToLValueReference<T&&> { typedef T& Type; };

template<System::int32 size, System::uint32 alignment>
struct AlignedBytes;


template<System::int32 size>
struct AlignedBytes<size, 1>
{
    System::uint8 bytes[size];
};

#define IMPLEMENT_ALIGNED_STORAGE(align)\
    template<System::int32 size> \
    struct AlignedBytes<size, align> \
    {\
        System::uint8 bytes[size]; \
        static_assert(size % align == 0, "clr interop types must not be aligned."); \
    };

IMPLEMENT_ALIGNED_STORAGE(16);
IMPLEMENT_ALIGNED_STORAGE(8);
IMPLEMENT_ALIGNED_STORAGE(4);
IMPLEMENT_ALIGNED_STORAGE(2);

template<typename Type>
struct TypeCompatibleBytes : AlignedBytes<sizeof(Type), alignof(Type)>
{
    Type* GetTypedPtr() { return static_cast<Type*>(this);}
    const Type* GetTypedPtr()const { return static_cast<const Type*>(this); }
};

template<typename T>
FORCEINLINE typename RemoveReference<T>::Type&& MoveTemp(T&& obj)
{
    typedef typename RemoveReference<T>::Type CastType;
    static_assert(IsLValueReferenceType<T>::Value, "MoveTemp called on an rvalue");
    static_assert(!AreTypesEqual<CastType&, const CastType&>::Value, "MoveTemp called on a const object");
    return static_cast<CastType&&>(obj);
}

static FORCEINLINE void* Memcpy(void* dest, const void* src, size_t count)
{
    return memcpy(dest, src, count);
}

template<typename T>
static FORCEINLINE void Memcpy(T& dest, const T& src)
{
    static_assert(!IsPointer<T>::Value, "For pointers use the three parameters function");
    Memcpy(&dest, &src, sizeof(T));
}

template<typename T>
static FORCEINLINE T CopyTemp(T& val)
{
    return const_cast<const T&>(val);
}

template<typename T>
static FORCEINLINE T&& CopyTemp(T&& val)
{
    return MoveTemp(val);
}

template<typename T>
static FORCEINLINE T&& Forward(typename RemoveReference<T>::Type& obj)
{
    return static_cast<T&&>(obj);
}

template<typename T>
struct UseBitwiseSwap
{
    enum { Value = !OrValue<IS_ENUM(T), IsPointer<T>, IsArithmetic<T>>::Value};
};
template <typename T>
inline typename EnableIf<UseBitwiseSwap<T>::Value>::Type Swap(T& A, T& B)
{
    if (LIKELY(&A != &B))
    {
        TypeCompatibleBytes<T> Temp;
        Memcpy(&Temp, &A, sizeof(T));
        Memcpy(&A, &B, sizeof(T));
        Memcpy(&B, &Temp, sizeof(T));
    }
}

template <typename T>
inline typename EnableIf<!UseBitwiseSwap<T>::Value>::Type Swap(T& A, T& B)
{
    T Temp = MoveTemp(A);
    A = MoveTemp(B);
    B = MoveTemp(Temp);
}

template<typename T>
FORCEINLINE void Exchange(T& a, T&b)
{
    Swap(a, b);
}

template<typename T, typename Type>
FORCEINLINE T StaticCast(Type&& type)
{
    return static_cast<T>(type);
}
