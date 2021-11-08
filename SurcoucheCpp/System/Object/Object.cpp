#include "Object.h"
#include "../PrimaryType/Boolean/Boolean.h"

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
size_t System::Object::GetHashCode() const
{
    object _obj = *this;
    return std::hash<object*>{}(&_obj);
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
