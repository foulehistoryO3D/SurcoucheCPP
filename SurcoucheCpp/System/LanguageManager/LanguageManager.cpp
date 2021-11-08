#include "LanguageManager.h"
#include "../../System.IO/Path/Path.h"
#include "../../System/Environment/Environment.h"
#include "Language/Language.h"


System::String System::LanguageManager::GetPathToSave() const
{
    return System::IO::Path::Combine(System::Environment::CurrentDirectory(), "Language");
}

System::LanguageManager::LanguageManager()
{
    mLanguages = System::Collections::Generic::Dictionary<System::String, Language*>();
}

System::LanguageManager::~LanguageManager()
{
    mLanguages.Clear();
}

System::Language System::LanguageManager::GetLanguage(const System::String& _name)
{
    return *mLanguages[_name];
}

void System::LanguageManager::AddLanguage(Language* _language)
{
    mLanguages.Add(_language->GetName(), _language);
}
