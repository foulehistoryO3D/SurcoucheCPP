#include "StreamWriter.h"
#include "../../../PrimaryType/String/String.h"
#include "../../../PrimaryType/Boolean/Boolean.h"
#include "../../../Collection/Generic/List/List.h"

#pragma region constructor/destructor
System::IO::StreamWriter::StreamWriter() : TextWriter() {}

System::IO::StreamWriter::StreamWriter(const String& _path) : TextWriter(_path) {}

System::IO::StreamWriter::StreamWriter(StreamWriter&& _copy) noexcept
{
    mStream = std::move(_copy.mStream);
}

void System::IO::StreamWriter::WriteAllText(const Collections::Generic::List<String> _values)
{
    if (!IsOpen())return;
    const int _length = _values.Count();
    for (int i=0; i< _length; ++i)
        Write(_values[i]);
}
#pragma endregion constructor/destructor
#pragma region override

System::Boolean System::IO::StreamWriter::Equals(const object* object)
{
    return object == this;
}

System::Boolean System::IO::StreamWriter::Equals(const object& object)
{
    return &object == this;
}

#pragma endregion override

