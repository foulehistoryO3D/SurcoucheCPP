#pragma once
#include <type_traits>
#include <vector>
#include <cstdint>

#pragma warning(disable: 4005)

namespace System
{
    class Boolean;
    class String;
    class Integer;
    class Type;
#pragma region typedef
    typedef unsigned char uint8;
    typedef unsigned short int uint16;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;
    typedef signed char int8;
    typedef signed short int int16;
    typedef signed int int32;
    typedef signed long long int64;
    typedef uint8_t byte;
#pragma endregion typedef
#pragma region define
#define FORCEINLINE __forceinline
#define VARARGS __cdecl
#define interface __interface
#define typeof decltype
#define null nullptr
#define VARARGS     __cdecl
#define IS_ENUM(x) __is_enum(x)
#define PURE_VIRTUAL() = 0;

#define REGISTER_ATTRIBUTE(bitmask)\
    int _bitMask = RegisterAttributes(bitmask);

#define DECLARE_CLASS_INFO(parentClass) \
private:\
typedef parentClass ParentClassType; \
ParentClassType* mParentClass = new parentClass();\
public:\
virtual ParentClassType* GetParentClass()\
{ return mParentClass;}\
typedef parentClass super;\
const int mSubClassCount = RegisterSubClass(this);

#pragma endregion define
#pragma region static methods
    template <typename Base, typename Derived>
    static bool Instanceof(const Derived&)
    {
        return std::is_base_of_v<Base, Derived>;
    }

    template <typename Base, typename Derived>
    static bool Instanceof(const Derived*)
    {
        return std::is_base_of_v<Base, Derived>;
    }
#pragma endregion static methods
#pragma region enum
    enum : uint8
    {
        Interface=1,
        Sealed=2,
        Abstract=4,
        PrimaryType = 8,
        Final = 16,
        Enum = 32,
        ArrayType = 64
    };
#pragma endregion enum
    inline size_t HashCode(const char* s)
    {
        size_t result = 0;
        const size_t length = std::strlen(s);
        for (int i = 0; i < length; i++)
        {
            int m = 1;
            for (int j = 0; j < length - 1 - i; j++)
                m *= 31;
            result += (s[i] * m);
        }
        return result;
    }

    class Type
    {
#pragma region f/p
    private:
        std::vector<Type*> mSubClass = std::vector<Type*>();
        int mBitMask = 0;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Type() = default;
        Type(const Type& _type);
        virtual ~Type();
#pragma endregion constructor/destructor
#pragma region custom methods
    protected:
        int RegisterAttributes(const int _bitMask);
        int RegisterSubClass(const Type* _class);
    public:
        std::vector<Type*> Assembly() const;
        virtual Boolean Equals(const Type* _type);
        virtual Type* GetType();
        virtual Integer GetHashCode() const;
        virtual String ToString() const;
        String FullName() const;
        String ClassName() const;
        String Namespace() const;
        Boolean IsInterface() const;
        Boolean IsSealed() const;
        Boolean IsAbstract() const;
        Boolean IsClass() const;
        Boolean IsType() const;
        Boolean IsFinal()const;
        Boolean IsEnum()const;
        Boolean IsArray()const;
        Boolean IsPrimaryType()const;
        static Type* Clone(const void* _type);
#pragma endregion custom methods
#pragma region operator
    public:
        Type* operator=(const Type* _type);
        virtual Boolean operator==(const Type* _type);
        virtual Boolean operator!=(const Type* _type);
        virtual Type* Clone()
        {
            return new Type(*this);
        }
#pragma endregion operator
    };
}
