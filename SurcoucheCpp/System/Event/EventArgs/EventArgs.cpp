#include "EventArgs.h"
#include "../../PrimaryType/Boolean/Boolean.h"

System::Boolean System::EventArgs::Equals(const object* object)
{
    return object == this;
}

System::Boolean System::EventArgs::Equals(const object& object)
{
    return &object == this;
}

size_t System::EventArgs::GetHashCode() const
{
    EventArgs _eventArgs = *this;
    return std::hash<EventArgs*>{}(&_eventArgs);
}
