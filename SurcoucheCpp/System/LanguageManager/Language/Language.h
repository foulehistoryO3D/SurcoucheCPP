#pragma once
#include "../../Object/Object.h"
#include "../../../System.IO/File/FileStream/FileStream.h"

namespace System
{
    class Language : public Object
    {
        DECLARE_CLASS_INFO(Object)
#pragma region f/p
    private:
        const char* mName = null;
        const char* mFileName = null;
        IO::FileStream mFile = IO::FileStream();
#pragma endregion f/p
#pragma region constructor
    public:
        Language() = default;
        Language(const String& _name, const String& _fileName);
        Language(const Language& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        String GetMessages(const String& _key) const;
        void AddMessageToFile(const String& _key, const String& _message) const;
        String GetFileName() const;
        String GetName() const;
        IO::FileStream GetFile() const;
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
    public:
        Language operator=(const Language& _copy);
#pragma endregion operator
    };
}
