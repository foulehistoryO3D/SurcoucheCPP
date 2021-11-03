#include "FileStream.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Boolean/Boolean.h"
#include "../../Stream/StreamReader/StreamReader.h"
#include "../../Stream/StreamWriter/StreamWriter.h"

#pragma region constructor
System::IO::FileStream::FileStream(const String& _path)
{
    mPath = _path;
    mStreamReader = new StreamReader(_path);
    mStreamWriter = new StreamWriter(_path);
}

System::IO::FileStream::FileStream(const FileStream& _copy)
{
    mPath = std::move(_copy.mPath);
    mStreamReader = std::move(_copy.mStreamReader);
    mStreamWriter = std::move(_copy.mStreamWriter);
}

System::IO::FileStream::~FileStream()
{
    delete mStreamWriter;
    delete mStreamReader;
    mStreamWriter = null;
    mStreamReader = null;
}

System::Boolean System::IO::FileStream::IsValid() const
{
    return mPath != null && mStreamWriter != null && mStreamReader != null;
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
    const FileStream* _fileStream = dynamic_cast<const FileStream*>(object);
    return _fileStream == this;
}

System::Boolean System::IO::FileStream::Equals(const object& object)
{
    const FileStream* _fileStream = dynamic_cast<const FileStream*>(&object);
    return _fileStream == this;
}

size_t System::IO::FileStream::GetHashCode() const
{
    FileStream _fileStream = *this;
    return std::hash<FileStream*>{}(&_fileStream);
}
#pragma endregion override