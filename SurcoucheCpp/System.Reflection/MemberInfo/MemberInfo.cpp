#include "MemberInfo.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../../System/Event/Func/Func.h"

System::Collections::Generic::IEnumerable<System::Reflection::CustomAttributeData*> System::Reflection::MemberInfo::CustomAttributes() const
{
    return Collections::Generic::IEnumerable<CustomAttributeData*>();
}

System::String System::Reflection::MemberInfo::ToString() const
{
    return ICustomAttributeProvider::ToString();
}

System::Boolean System::Reflection::MemberInfo::Equals(const object* object)
{
    const MemberInfo& _other = *dynamic_cast<const MemberInfo*>(object);
    return mCustomAttributes == _other.mCustomAttributes;
}

System::Boolean System::Reflection::MemberInfo::Equals(const object& object)
{
    const MemberInfo& _other = *dynamic_cast<const MemberInfo*>(&object);
    return mCustomAttributes == _other.mCustomAttributes;
}

System::Collections::Generic::List<System::Object*> System::Reflection::MemberInfo::GetCustomAttributes()
{
    if (mCustomAttributes.Count() == 0)
    {
        Collections::Generic::IEnumerator<CustomAttributeData*>* _enumerator = CustomAttributes().GetEnumerator();
        while(_enumerator->MoveNext())
            mCustomAttributes.Add(_enumerator->Current());
        _enumerator->Reset();
    }
    return mCustomAttributes;
}

System::Collections::Generic::List<System::Object*> System::Reflection::MemberInfo::GetCustomAttributes(const Type* _type)
{
    if (mCustomAttributes.Count() == 0)
    {
        Collections::Generic::IEnumerator<CustomAttributeData*>* _enumerator =  CustomAttributes().GetEnumerator();
        while (_enumerator->MoveNext())
            mCustomAttributes.Add(_enumerator->Current());
        _enumerator->Reset();
    }
    return mCustomAttributes.Where([&](object* _obj)
    {
        return _obj->GetType()->Equals(_type);
    });
}

System::Boolean System::Reflection::MemberInfo::IsDefined(const Type* _type)
{
    return mCustomAttributes.Any([&](object* o)
    {
       return o->GetType()->Equals(_type); 
    });
}
