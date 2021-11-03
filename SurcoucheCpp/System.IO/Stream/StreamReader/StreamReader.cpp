#include "StreamReader.h"

System::IO::StreamReader::StreamReader() : TextReader() {}

System::IO::StreamReader::StreamReader(const String& _path) : TextReader(_path) {}

System::IO::StreamReader::StreamReader(StreamReader&& _copy)
{
    mStream = std::move(_copy.mStream);
}
