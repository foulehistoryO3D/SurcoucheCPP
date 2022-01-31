#include "LanguageManager.h"

#include "../../System.IO/Directory/Directory.h"
#include "../../System.IO/Path/Path.h"
#include "../../System/Environment/Environment.h"
#include "Language/Language.h"


System::String System::LanguageManager::GetPathToSave() const
{
    return IO::Path::Combine(Environment::CurrentDirectory, "Language");
}

System::Integer System::LanguageManager::GetHashCode() const
{
    return mLanguages.GetHashCode();
}

System::LanguageManager::LanguageManager()
{
    mLanguages = System::Collections::Generic::Dictionary<String, Language*>();
}

System::LanguageManager::~LanguageManager()
{
    mLanguages.Clear();
}

System::Language System::LanguageManager::GetLanguage(const String& _name)
{
    return *mLanguages[_name];
}

void System::LanguageManager::AddLanguage(Language* _language)
{
    mLanguages.Add(_language->GetName(), _language);
}
