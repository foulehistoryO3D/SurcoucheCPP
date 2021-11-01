#include "Exception.h"
#include "../../PrimaryType/String/String.h"

System::String System::Exception::Message() const
{
    return what();
}

System::String System::Exception::ToString() const
{
    return Message();
}
