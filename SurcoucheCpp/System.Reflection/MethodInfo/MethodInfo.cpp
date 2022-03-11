#include "MethodInfo.h"

#pragma region f/p
System::String System::Reflection::MethodInfo::Name() const
{
    return mName;
}

System::Collections::Generic::List<System::Reflection::ParameterInfo> System::Reflection::MethodInfo::Parameters() const
{
    return mParameters;
}

System::Object* System::Reflection::MethodInfo::Owner() const
{
    return mOwner;
}
#pragma endregion f/p
#pragma region constructor
System::Reflection::MethodInfo::MethodInfo(const MethodInfo& copy) : Object(copy)
{
    mName = std::move(copy.mName);
    mParameters = std::move(copy.mParameters);
}
#pragma endregion constructor