#include "Object.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/String/String.h"

#pragma region constructor
#pragma endregion constructor
#pragma region custom methods
System::Boolean System::Object::Equals(const object* _obj)
{
    return this == _obj;
}

System::Bool System::Object::Equals(const object& _obj)
{
    return this == &_obj;
}

System::Bool System::Object::Equals(const object* _obj, const object* _other)
{
    return _obj == _other;
}

System::Bool System::Object::Equals(const object& _obj, const object& _other)
{
    return &_obj == &_other;
}
System::Integer System::Object::GetHashCode() const
{
    return ToString().GetHashCode();
}
#pragma endregion custom methods
#pragma region operator
System::Bool System::Object::operator==(const object* _obj)
{
    return Equals(_obj);
}

System::Bool System::Object::operator!=(const object* _obj)
{
    return !Equals(_obj);
}

System::Bool System::Object::operator==(const object& _obj)
{
    return Equals(_obj);
}

System::Bool System::Object::operator!=(const object& _obj)
{
    return !Equals(_obj);
}
#pragma endregion operator
