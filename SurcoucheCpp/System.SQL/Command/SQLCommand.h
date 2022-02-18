#pragma once
#include "../SqlData.h"
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/String/String.h"
#include "../DataBase/DataBaseLocal/DataBaseLocal.h"

namespace System
{
    namespace SQL
    {
        class SQLReader;

        class SQLCommand sealed : public Object
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            String command = "";
            Integer timeout = 0;
            DataBaseLocal* databaseLocal = null;
        public:
            String Command() const;
            Integer Timeout() const;
            DataBaseLocal* DataBase() const;
            Boolean IsValid() const;
#pragma endregion f/p
#pragma region constructor
        public:
            SQLCommand() = default;
            SQLCommand(DataBaseLocal* databaseLocal, const String& command, const Integer& timeout = 60);
            SQLCommand(const SQLCommand& copy);
#pragma endregion constructor
#pragma region custom methods
        private:
            string GetID() const;
            DataBaseTable*  GetTable(string tableName) const;
            SQLReader ExecuteUpdateReader_Internal(Collections::Generic::List<string> commandParsed) const;
            void ExecuteUpdate_Internal(Collections::Generic::List<string> commandParsed) const;
            void ExecuteDelete_Internal(Collections::Generic::List<string> commandParsed) const;
            void GetValuesCommand(Collections::Generic::List<String> commandParsed, DataBaseTable*& table, string& id) const;
            SQLReader ExecuteDeleteReader_Internal(Collections::Generic::List<string> commandParsed) const;
        public:
            void ExecuteNoQuery() const;
            SQLReader ExecuteReader() const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            SQLCommand& operator=(const SQLCommand& other);
            Boolean operator==(const SQLCommand& other) const;
            Boolean operator!=(const SQLCommand& other) const;
#pragma endregion operator
        };
    }
}
