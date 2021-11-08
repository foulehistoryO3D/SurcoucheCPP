#pragma once
#include <type_traits>
#include <vector>

namespace System
{
    class Boolean;
    class String;
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
    typedef unsigned char byte;
#pragma endregion typedef
#pragma region define
#define FORCEINLINE __forceinline
#define VARARGS __cdecl
// #define interface __interface
#define null nullptr
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
    template<typename Base, typename Derived>
    static bool Instanceof(const Derived&)
    {
        return std::is_base_of_v<Base,Derived>;
    }
    template<typename Base, typename Derived>
    static bool Instanceof(const Derived*)
    {
        return std::is_base_of_v<Base,Derived>;
    }
#pragma endregion static methods
#pragma region enum
    enum : uint8
    {
        Interface=1,
        Sealed=2,
        Abstract=4,
        PrimaryType = 8,
    };
#pragma endregion enum
    class Type
    {
#pragma region f/p
    private:
        std::vector<Type*> mSubClass = std::vector<Type*>();
        int mBitMask = 0;
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Type()=default;
        Type(const Type& _type);
        virtual ~Type();
#pragma endregion constructor/destructor
#pragma region custom methods
    protected:
        int RegisterAttributes(const int _bitMask);
        int RegisterSubClass(const Type* _class);
    public:
        std::vector<Type*> Assembly()const;
        virtual Boolean Equals(const Type* _type);
        virtual Type* GetType();
        virtual size_t GetHashCode() const;
        virtual String ToString()const;
        String FullName()const;
        Boolean IsInterface()const;
        Boolean IsSealed()const;
        Boolean IsAbstract()const;
        Boolean IsClass()const;
        Boolean IsType()const;
#pragma endregion custom methods
#pragma region operator
    public:
        virtual Boolean operator==(const Type* _type);
        virtual Boolean operator!=(const Type* _type);
#pragma endregion operator
    };
}
