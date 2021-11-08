#pragma once
#include "../../Object/Object.h"
#include "../../../System.IO/File/FileStream/FileStream.h"

namespace System
{
    class Language : public Object
    {
        DECLARE_CLASS_INFO(Object)
    private:
        const char* mName = null;
        const char* mFileName = null;
        System::IO::FileStream mFile = System::IO::FileStream();
    private:
    public:
        Language() = default;
        Language(const System::String& _name, const System::String& _fileName);
        Language(const Language& _copy);
        System::String GetMessages(const System::String& _key) const;
        void AddMessageToFile(const System::String& _key, const System::String& _message) const;
        System::String GetFileName() const;
        System::String GetName() const;
        System::IO::FileStream GetFile() const;

        Language operator=(const Language& _copy);
    };
}
