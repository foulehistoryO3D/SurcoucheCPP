#include "Exception.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Integer/Integer.h"

System::String System::Exception::Message() const
{
    return what();
}

System::Integer System::Exception::GetHashCode() const
{
    return Message().GetHashCode();
}

System::String System::Exception::ToString() const
{
    return Message();
}
