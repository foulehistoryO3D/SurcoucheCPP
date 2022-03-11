#include "FileStream.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
#include "../../Stream/StreamReader/StreamReader.h"
#include "../../Stream/StreamWriter/StreamWriter.h"

#pragma region constructor
System::IO::FileStream::FileStream(const String& _path)
{
    mPath = _path;
    mStreamReader = new StreamReader(_path);
    mStreamWriter = new StreamWriter(_path);
}

System::IO::FileStream::FileStream(const FileStream& copy) : Object(copy)
{
    mPath = std::move(copy.mPath);
    mStreamReader = std::move(copy.mStreamReader);
    mStreamWriter = std::move(copy.mStreamWriter);
}

System::IO::FileStream::~FileStream()
{
    mStreamWriter = nullptr;
    mStreamReader = nullptr;
}

System::Boolean System::IO::FileStream::Exists() const
{
    const std::ifstream _stream(mPath);
    return _stream.good();
}

System::Boolean System::IO::FileStream::IsValid() const
{
    return mPath != nullptr && mStreamWriter != nullptr && mStreamReader != nullptr && Exists();
}

void System::IO::FileStream::Close() const
{
    if (!IsValid())return;
    mStreamWriter->Close();
    mStreamReader->Close();
}

System::IO::StreamWriter& System::IO::FileStream::Writer() const
{
    return *mStreamWriter;
}

System::IO::StreamReader& System::IO::FileStream::Reader() const
{
    return *mStreamReader;
}

System::String System::IO::FileStream::FullPath() const
{
    return mPath;
}
#pragma endregion constructor
#pragma region override
System::String System::IO::FileStream::ToString() const
{
    return Object::ToString();
}

System::Boolean System::IO::FileStream::Equals(const object* object)
{
    const FileStream& _fileStream = *dynamic_cast<const FileStream*>(object);
    return mPath == _fileStream.mPath && mStreamReader == _fileStream.mStreamReader && mStreamWriter == _fileStream.
        mStreamWriter;
}

System::Boolean System::IO::FileStream::Equals(const object& object)
{
    const FileStream& _fileStream = *dynamic_cast<const FileStream*>(&object);
    return mPath == _fileStream.mPath && mStreamReader == _fileStream.mStreamReader && mStreamWriter == _fileStream.
        mStreamWriter;
}

System::Integer System::IO::FileStream::GetHashCode() const
{
    return ToString().GetHashCode() ^ (mStreamWriter->GetHashCode() << 2) ^ (mStreamReader->GetHashCode() >> 2);
}

void System::IO::FileStream::Dispose()
{
    mStreamReader->Dispose();
    mStreamWriter->Dispose();
}

System::IO::FileStream System::IO::FileStream::operator=(const FileStream& _other)
{
    mPath = std::move(_other.mPath);
    mStreamWriter = std::move(_other.mStreamWriter);
    mStreamReader = std::move(_other.mStreamReader);
    return *this;
}
#pragma endregion override
