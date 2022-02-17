#pragma once
#include <map>

#include "../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../System/Object/Object.h"

namespace System
{
    namespace SQL
    {
        class SQLReader : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            std::map<string, string> readerObject = std::map<string, string>();
#pragma endregion f/p
#pragma region constructor
        public:
            SQLReader()=default; 
            SQLReader(const String& read);
            SQLReader(const SQLReader& copy);
#pragma endregion constructor
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            SQLReader& operator=(const SQLReader& other);
            string operator[](const string& key) const;
            string operator[](const int& key) const;
#pragma endregion operator
        };
    }
}
