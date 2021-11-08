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


namespace System
{
    class Language;

    class LanguageManager : public Utils::Singleton<LanguageManager>
    {
        DECLARE_CLASS_INFO(Singleton<LanguageManager>)
    private:
        Collections::Generic::Dictionary<String, Language*> mLanguages =
            System::Collections::Generic::Dictionary<String, Language*>();
    public:
        LanguageManager();
        ~LanguageManager() override;

        Language GetLanguage(const String& _name);
        void AddLanguage(Language* _language);
        template <typename... Args>
        String Translate(const System::String& _messageToTranslate, Args&&... _args);
        String GetPathToSave() const;
    };

    template <typename ... Args>
    System::String LanguageManager::Translate(const System::String& _messageToTranslate, Args&&... _args)
    {
        string _result = _messageToTranslate;
        const size_t _length = System::TemplateUtils::SizeOfPackageParameters(_args...);
        System::Collections::Generic::List<System::String> _package =
            System::TemplateUtils::CreateVectorWithParameterPack<System::String>(_args...);
        for (int i = 0; i < _length; ++i)
        {
            const System::String& _str = _package[i];
            _result = _result.Replace(string("@") + System::Integer(i), _str);
        }
        return _result;
    }
}
