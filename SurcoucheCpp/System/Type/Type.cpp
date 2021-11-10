#include "Type.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Integer/Integer.h"
#include <memory>
#include <vcruntime_typeinfo.h>

#pragma region constructor/destructor
System::Type::Type(const Type& _type)
{
    mBitMask = std::move(_type.mBitMask);
    mSubClass = std::move(_type.mSubClass);
}

System::Type::~Type()
{
}

#pragma endregion constructor/destructor
#pragma region custom methods
int System::Type::RegisterAttributes(const int _bitMask)
{
    return mBitMask = _bitMask;
}

int System::Type::RegisterSubClass(const Type* _class)
{
    Type* _classToAdd = new Type();
    memcpy(_classToAdd, _class, sizeof(Type));
    mSubClass.push_back(_classToAdd);
    return mSubClass.size();
}

std::vector<System::Type*> System::Type::Assembly() const
{
    return mSubClass;
}

System::Boolean System::Type::Equals(const Type* _type)
{
    return this == _type;
}

System::Type* System::Type::GetType()
{
    return this;
}


size_t System::Type::GetHashCode() const
{
    Type _obj = *this;
    return std::hash<Type*>{}(&_obj);
}

System::String System::Type::ToString() const
{
    String _fullName = FullName();
    const Integer& _index = _fullName.LastIndexOf(':');
    if (_index > -1)
        _fullName = _fullName.SubString(_index+1, _fullName.Length());
    return _fullName;
}

System::String System::Type::FullName() const
{
    return typeid(*this).name();
}

System::Boolean System::Type::IsInterface() const
{
    return mBitMask & Interface;
}

System::Boolean System::Type::IsSealed() const
{
    return mBitMask & Sealed;
}

System::Boolean System::Type::IsAbstract() const
{
    return mBitMask & Abstract;
}

System::Boolean System::Type::IsClass() const
{
    return !(mBitMask & Interface || mBitMask & PrimaryType);
}

System::Boolean System::Type::IsType() const
{
    return mBitMask & PrimaryType;
}
#pragma endregion custom methods
#pragma region operator
System::Boolean System::Type::operator==(const Type* _type)
{
    return Equals(_type);
}

System::Boolean System::Type::operator!=(const Type* _type)
{
    return !Equals(_type);
}
#pragma endregion operator
