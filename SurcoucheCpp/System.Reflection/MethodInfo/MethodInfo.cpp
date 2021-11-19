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
#pragma endregion f/p
#pragma region constructor
System::Reflection::MethodInfo::MethodInfo(const MethodInfo& _method)
{
    mName = std::move(_method.mName);
    mParameters = std::move(_method.mParameters);
}
#pragma endregion constructor