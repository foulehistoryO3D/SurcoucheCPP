#include "StreamReader.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Integer/Integer.h"

System::IO::StreamReader::StreamReader() : TextReader() {}

System::IO::StreamReader::StreamReader(const String& _path) : TextReader(_path) {}

System::IO::StreamReader::StreamReader(StreamReader&& _copy) noexcept
{
    mStream = std::move(_copy.mStream);
}

System::String System::IO::StreamReader::ToString() const
{
    return super::ToString();
}

System::Integer System::IO::StreamReader::GetHashCode() const
{
    return super::GetHashCode();
}
