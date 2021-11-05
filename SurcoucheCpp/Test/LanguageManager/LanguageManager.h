#pragma once
#include <format>
#include <iostream>
#include <map>
#include <ostream>

#include "../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../System.IO/File/FileStream/FileStream.h"
#include "../../System.Utils/Singleton/Singleton.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/TemplateUtils/TemplateUtils.h"

class Language : public System::Object
{
private:
    const char* mName = null;
    const char* mFileName = null;
    System::IO::FileStream mFile = System::IO::FileStream();
private:
    
public:
    Language()=default;
    Language(const System::String& _name, const System::String& _fileName);
    Language(const Language& _copy);
    System::String GetMessages(const System::String& _key) const;

    System::String GetFileName() const;
    System::String GetName() const;
    System::IO::FileStream GetFile() const;

    Language operator=(const Language& _copy);
};

class LanguageManager : public System::Utils::Singleton<LanguageManager>
{
private:
    System::Collections::Generic::Dictionary<System::String, Language> mLanguages = System::Collections::Generic::Dictionary<System::String, Language>();
public:
    LanguageManager();
    ~LanguageManager() override;

    Language GetLanguage(const System::String& _name);
    void AddLanguage(const Language& _language);
    template<typename... Args>
    System::String Translate(const System::String& _messageToTranslate, Args&&... _args);
    System::String GetPathToSave()const;
};

template <typename ... Args>
System::String LanguageManager::Translate(const System::String& _messageToTranslate, Args&&... _args)
{
    string _result = _messageToTranslate;
    const size_t _length = sizeof...(_args);
    for (int i = 0; i <_length; ++i)
    {
        const System::String& _str = System::TemplateUtils::GetPackageParameterValue<System::String>(i, _args...);
        string _replace = "@";
        _replace.Append(System::Integer(i));
        _result = _result.Replace(_replace, _str);
    }
    return _result;
}
