#include "Language.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
#include "../../../System.IO/Exception/IOException/IOException.h"
#include "../../../System.IO/Stream/StreamReader/StreamReader.h"
#include "../../../System.IO/File/File/File.h"
#include "../../../System.IO/Path/Path.h"
#include "../LanguageManager.h"
#include "../../../System.IO/Stream/StreamWriter/StreamWriter.h"

System::Language::Language(const System::String& _name, const System::String& _fileName)
{
    mName = _name;
    mFileName = _fileName;
    const System::String& _path = System::IO::Path::Combine(LanguageManager::Instance().GetPathToSave(), _fileName);
    mFile = System::IO::FileStream(_path);
    if (!mFile.Exists())
        mFile = System::IO::File::Create(_path);
}

System::Language::Language(const Language& _copy)
{
    mFile = std::move(_copy.mFile);
    mFileName = std::move(_copy.mFileName);
    mName = std::move(_copy.mName);
}

System::String System::Language::GetMessages(const System::String& _key) const
{
    if (!mFile.IsValid())
        throw System::IO::IOException("file doesn't exist !");
    string _str = string::Empty();
    while(mFile.Reader().ReadLine(_str))
        if (_str.Contains(_key))
            return _str.SubString(_str.FirstIndexOf(':')+2, _str.Length());
    
    return "";
}

void System::Language::AddMessageToFile(const System::String& _key, const System::String& _message) const
{
    if (!mFile.IsValid())
        throw System::IO::IOException("file doesn't exist !");
    const System::String _result = _key + ": " + _message;
    mFile.Writer().Write(_result);
}

System::String System::Language::GetFileName() const
{
    return mFileName;
}

System::String System::Language::GetName() const
{
    return mName;
}

System::IO::FileStream System::Language::GetFile() const
{
    return mFile;
}

#pragma region override
System::String System::Language::ToString() const
{
    return mName;
}

System::Boolean System::Language::Equals(const object* object)
{
    const Language& _other = *dynamic_cast<const Language*>(object);
    return mName == _other.mName && mFile == _other.mFile && mFileName == _other.mFileName;
}

System::Boolean System::Language::Equals(const object& object)
{
    const Language& _other = *dynamic_cast<const Language*>(&object);
    return mName == _other.mName && mFile == _other.mFile && mFileName == _other.mFileName;
}

size_t System::Language::GetHashCode() const
{
    Language _this = *this;
    return std::hash<Language*>{}(&_this);
}
#pragma endregion override

System::Language System::Language::operator=(const Language& _copy)
{
    mFile = std::move(_copy.mFile);
    mFileName = std::move(_copy.mFileName);
    mName = std::move(_copy.mName);
    return *this;
}
