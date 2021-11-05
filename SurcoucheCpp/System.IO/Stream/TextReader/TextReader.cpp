#include "TextReader.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"

#pragma region constructor
System::IO::TextReader::TextReader(const String& _path)
{
    mStream = std::ifstream(_path);
    mPath = _path;
}

System::IO::TextReader::TextReader(TextReader&& _copy) noexcept
{
    mStream = std::move(_copy.mStream);
    mPath = std::move(_copy.mPath);
}


void System::IO::TextReader::Close()
{
    if (mStream.is_open())
        mStream.close();
}

System::Boolean System::IO::TextReader::IsOpen() const
{
    return mStream.is_open();
}

System::Boolean System::IO::TextReader::IsValid() const
{
    return mStream.good() && IsOpen();
}
#pragma endregion constructor
#pragma region custom methods


System::Boolean System::IO::TextReader::ReadLine(String& _out)
{
    if (!IsValid())return false;
    std::string _str = "";
    std::getline(mStream, _str);
    _out = _str.c_str();
    return !string::IsNullOrEmpty(_out);
}

System::String System::IO::TextReader::ReadLine()
{
    if (!IsValid())return "";
    std::string _str = "";
    std::getline(mStream, _str);
    return _str.c_str();
}

System::String System::IO::TextReader::ReadToEnd()
{
    String _result = String::Empty();
    char _c = -1;
    while (mStream.get(_c))
        _result += _c;
    return _result;
}

System::String System::IO::TextReader::Path() const
{
    return mPath;
}

char System::IO::TextReader::Read()
{
    if (!IsValid()) return -1;
    char _result = -1;
    mStream.get(_result);
    return _result;
}
#pragma endregion custom methods
