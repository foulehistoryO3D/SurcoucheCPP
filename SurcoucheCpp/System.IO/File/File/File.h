#pragma once
#include "../../../System/Object/Object.h"

namespace System
{
    class DateTime;
    namespace Collections
    {
        namespace Generic
        {
            template<typename T>
            class List;
        }
    }
    namespace IO
    {
        class StreamWriter;
        class StreamReader;
        class FileStream;
        class File : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            const char* mPath = nullptr;
#pragma endregion f/p
#pragma region constructor
        public:
            File()=default;
            File(const String& _path);
            File(const File& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            DateTime GetCreationTime() const;
            DateTime GetLastAccessTime() const;
            DateTime GetLastWriteTime() const;
            void Delete() const;
            StreamReader OpenReader() const;
            StreamWriter OpenWriter() const;
            String ReadAllText() const;
            Collections::Generic::List<String> ReadAllLines() const;
            String Path()const;
            
            static DateTime GetCreationTime(const String& _path);
            static DateTime GetLastAccessTime(const String& _path);
            static DateTime GetLastWriteTime(const String& _path);
            static void Delete(const String& _path);
            static Boolean Exists(const String& _path);
            static FileStream Create(const String& _path);
            static StreamWriter CreateText(const String& _path);
            static StreamReader OpenText(const String& _path);
            static String ReadAllText(const String& _path);
            static Collections::Generic::List<String> ReadAllLines(const String& _path);
#pragma endregion custom methods
#pragma region override
        public:
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Integer GetHashCode() const override;
            String ToString() const override;
            File& operator=(const File& other);
#pragma endregion override
        };
    }
}
