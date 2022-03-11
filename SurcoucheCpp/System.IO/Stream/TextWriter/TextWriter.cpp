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

System::IO::TextWriter::TextWriter(TextWriter&& copy) noexcept : Object(copy)
{
    mStream = std::move(copy.mStream);
    mPath = std::move(copy.mPath);
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

System::String System::IO::TextWriter::ToString() const
{
    return mPath;
}

System::Integer System::IO::TextWriter::GetHashCode() const
{
    return ToString().GetHashCode();
}

void System::IO::TextWriter::Close()
{
    if (mStream.is_open())
        mStream.close();
}


void System::IO::TextWriter::Write(const object& _value)
{
    if (!IsOpen())return;
    mStream <<_value.ToString();
    mStream << std::endl;
}

void System::IO::TextWriter::Write(const object* _value)
{
    if (!IsOpen())return;
    mStream <<_value->ToString();
    mStream << std::endl;
}

void System::IO::TextWriter::Write(const String& _value)
{
    if (!IsOpen())return;
    mStream << _value;
    mStream << std::endl;
}

void System::IO::TextWriter::Clear()
{
    Dispose();
    std::ofstream ofs;
    ofs.open(mPath, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    mStream = std::ofstream(mPath, std::ios_base::app | std::ios_base::out);
}

System::Boolean System::IO::TextWriter::Equals(const object* object)
{
    const TextWriter& _writer = *dynamic_cast<const TextWriter*>(object);
    return mPath == _writer.mPath;
}

System::Boolean System::IO::TextWriter::Equals(const object& object)
{
    const TextWriter& _writer = *dynamic_cast<const TextWriter*>(&object);
    return mPath == _writer.mPath;
}

void System::IO::TextWriter::Dispose()
{
    mStream.close();
}

void System::IO::TextWriter::operator<<(const object& _obj)
{
    mStream << _obj.ToString();
    mStream << std::endl;
}

void System::IO::TextWriter::operator<<(const object* _obj)
{
    mStream << _obj->ToString();
    mStream << std::endl;
}
#pragma endregion custom methods

