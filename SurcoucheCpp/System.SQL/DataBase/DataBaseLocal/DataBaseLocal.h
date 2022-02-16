#pragma once
#include <map>

#include "../../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Array/Array.h"
#include "../../../System.IO/File/FileStream/FileStream.h"
#include "../Table/DataBaseTable.h"

namespace System
{
    namespace SQL
    {
        class DataBaseLocal sealed : public Object, public IDisposable
        {
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
                std::map<string, DataBaseTable*> tables = std::map<string, DataBaseTable*>(); 
                const char* path = "";
#pragma endregion f/p
#pragma region constructor
        public:
                DataBaseLocal()=default;
                DataBaseLocal(const String& path);
                ~DataBaseLocal()override;
#pragma endregion constructor
#pragma region custom methods
        private:
        public:
                DataBaseTable* GetTable(const string& tableName);
                Array<DataBaseTable*> GetTables() const;
#pragma endregion custom methods
#pragma region override
        public:
                String ToString() const override;
                Integer GetHashCode() const override;
                void Dispose() override;
#pragma endregion override
#pragma region operator
        public:
                
#pragma endregion operator
            
        };
    }
}
