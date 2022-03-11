#include "ParameterInfo.h"

#include "../../System/Activator/Activator.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"

#pragma region f/p
System::Type* System::Reflection::ParameterInfo::ParameterType() const
{
    return mClassImpl;
}

System::object* System::Reflection::ParameterInfo::DefaultValue() const
{
    return mDefaultValueImpl;
}

System::String System::Reflection::ParameterInfo::Name() const
{
    return mNameImpl;
}

System::Integer System::Reflection::ParameterInfo::Position() const
{
    return mPositionImpl;
}
#pragma endregion f/p
#pragma region constructor

System::Reflection::ParameterInfo::ParameterInfo(Type* _parameterType, const Integer& _position)
{
    mClassImpl = _parameterType;
    mNameImpl = "Default Name";
    mPositionImpl = _position;
    mDefaultValueImpl = static_cast<object*>(*Activator::CreateInstance<decltype(_parameterType)>());
}

System::Reflection::ParameterInfo::ParameterInfo(const ParameterInfo& copy) : Object(copy)
{
    mClassImpl = std::move(copy.mClassImpl);
    mNameImpl = std::move(copy.mNameImpl);
    mPositionImpl = std::move(copy.mPositionImpl);
}
#pragma endregion constructor
#pragma region operator
System::Reflection::ParameterInfo System::Reflection::ParameterInfo::operator=(const ParameterInfo& _other)
{
    mClassImpl = std::move(_other.mClassImpl);
    mNameImpl = std::move(_other.mNameImpl);
    mPositionImpl = std::move(_other.mPositionImpl);
    return *this;
}
#pragma endregion operator