#pragma once
#include <format>
#include <iostream>
#include <map>
#include <ostream>

#include "../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../System.Utils/Singleton/Singleton.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/TemplateUtils/TemplateUtils.h"

class Language;

class LanguageManager : public System::Utils::Singleton<LanguageManager>
{
private:
    System::Collections::Generic::Dictionary<System::String, Language*> mLanguages = System::Collections::Generic::Dictionary<System::String, Language*>();
public:
    LanguageManager();
    ~LanguageManager() override;

    Language GetLanguage(const System::String& _name);
    void AddLanguage(Language* _language);
    template<typename... Args>
    System::String Translate(const System::String& _messageToTranslate, Args&&... _args);
    System::String GetPathToSave()const;
};

template <typename ... Args>
System::String LanguageManager::Translate(const System::String& _messageToTranslate, Args&&... _args)
{
    string _result = _messageToTranslate;
    const size_t _length = sizeof...(_args);
    System::Collections::Generic::List<System::String> _package = System::TemplateUtils::CreateVectorWithParameterPack<System::String>(_args...);
    for (int i = 0; i <_length; ++i)
    {
        const System::String& _str = _package[i];
        string _replace = string("@") + System::Integer(i);
        _result = _result.Replace(_replace, _str);
    }
    return _result;
}
