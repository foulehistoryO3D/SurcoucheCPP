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
    return ClassName() == _type->ClassName();
}

System::Type* System::Type::GetType()
{
    return this;
}


System::Integer System::Type::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::String System::Type::ToString() const
{
    return ClassName();
}

System::String System::Type::FullName() const
{
    return typeid(*this).name();
}

System::String System::Type::ClassName() const
{
    std::string _fullName = FullName().ToCstr();
    std::regex regex = std::regex("(::)(.*)(?=(<||))");
    std::smatch match = std::smatch();
    std::regex_search(_fullName, match, regex);
    _fullName = match[0];
    string result = _fullName.c_str();
    if (result.Contains("<"))
    {
        regex = std::regex("(<)(.*)(?=>)");
        std::regex_search(_fullName, match, regex);
        _fullName = match[0];
        result = result.Replace(_fullName.c_str(), "");
        result = result.Replace(">", "");
        return result.SubString(result.LastIndexOf(':') + 1);
    }
    return result.SubString(result.LastIndexOf(':') + 1);
}

System::String System::Type::Namespace() const
{
    std::string _str = FullName().ToCstr();
    String className = ClassName();
    std::regex regex = std::regex("(class)(.*)(?=(<||))");
    std::smatch match = std::smatch();
    std::regex_search(_str, match, regex);
    string test = match[0].str().c_str();
    if (test.Contains("<"))
    {
        regex = std::regex("(<)(.*)(?=>)");
        std::regex_search(_str, match, regex);
        _str = match[0];
        test = test.Replace(_str.c_str(), "");
        test = test.Replace(">", "");
        return test.SubString(test.FirstIndexOf(" ") + 1, test.LastIndexOf(':') - 1);
    }
    return test.SubString(test.FirstIndexOf(" ") + 1, test.FirstIndexOf(":"));
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

System::Boolean System::Type::IsFinal() const
{
    return mBitMask & Final;
}

System::Boolean System::Type::IsEnum() const
{
    return mBitMask & Enum;
}

System::Boolean System::Type::IsArray() const
{
    return mBitMask & ArrayType;
}

System::Boolean System::Type::IsPrimaryType() const
{
    return mBitMask & PrimaryType;
}

System::Boolean System::Type::IsStruct() const
{
    return mBitMask & Struct;
}

System::Type* System::Type::Clone(const void* _type)
{
    Type* _result = new Type();
    std::memcpy(_result, _type, sizeof(Type));
    return _result;
}

System::Type* System::Type::operator=(const Type* _type)
{
    mBitMask = _type->mBitMask;
    return this;
}
#pragma endregion custom methods
#pragma region operator
System::Boolean System::Type::operator==(const Type* _type)
{
    return this == _type;
}

System::Boolean System::Type::operator!=(const Type* _type)
{
    return !this->operator==(_type);
}
#pragma endregion operator
