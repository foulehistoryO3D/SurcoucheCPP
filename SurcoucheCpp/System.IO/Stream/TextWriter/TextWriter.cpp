#include "TextWriter.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../../System/PrimaryType/Float/Float.h"
#include "../../../System/PrimaryType/Double/Double.h"
#include "../../../System/PrimaryType/Integer/Integer.h"

#pragma region constructor/destructor
System::IO::TextWriter::TextWriter(const String& _path)
{
    mStream = std::ofstream(_path, std::ios_base::app | std::ios_base::out);
    mPath = _path;
}

System::IO::TextWriter::TextWriter(TextWriter&& _copy) noexcept
{
    mStream = std::move(_copy.mStream);
    mPath = std::move(_copy.mPath);
}


#pragma endregion constructor/destructor
#pragma region custom methods

System::Boolean System::IO::TextWriter::IsOpen() const
{
    return mStream.is_open();
}

System::String System::IO::TextWriter::Path() const
{
    return mPath;
}

System::Boolean System::IO::TextWriter::IsValid() const
{
    return mStream.good() && IsOpen();
}

System::Boolean System::IO::TextWriter::Exists() const
{
    const std::ifstream _stream(mPath);
    return _stream.good();
}

void System::IO::TextWriter::Close()
{
    if (mStream.is_open())
        mStream.close();
}

void System::IO::TextWriter::Write(const Boolean& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
}

void System::IO::TextWriter::Write(const char _value)
{
    if (!IsOpen())return;
    mStream <<_value;
}

void System::IO::TextWriter::Write(const Float& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
}

void System::IO::TextWriter::Write(const Double& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
}

void System::IO::TextWriter::Write(const Integer& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
}

void System::IO::TextWriter::Write(const object& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
}

void System::IO::TextWriter::Write(const String& _value)
{
    if (!IsOpen())return;
    mStream <<_value;
    mStream << std::endl;
}

System::Boolean System::IO::TextWriter::Equals(const object* object)
{
    return this == object;
}

System::Boolean System::IO::TextWriter::Equals(const object& object)
{
    return this == &object;
}
#pragma endregion custom methods
