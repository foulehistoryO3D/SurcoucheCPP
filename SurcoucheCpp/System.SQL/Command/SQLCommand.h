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
            Collections::Generic::List<SqlData> sqlData;
            Collections::Generic::List<SqlData> valuesData;
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
            Collections::Generic::List<SqlData> RegisterValues(Collections::Generic::List<string> values);
            Collections::Generic::List<SqlData> GetDataValues(const string& str);
            SqlData* GetData(const string& key);
            string GetID() const;
            Collections::Generic::List<string> GetValues() const;
            void UpdateValues();
            SQLReader ExecuteUpdateReader_Internal(Collections::Generic::List<string> _commandParsed);
            SQLReader ExecuteDeleteReader_Internal(Collections::Generic::List<string> _commandParsed);
        public:
            void ExecuteNoQuery();
            SQLReader ExecuteReader();
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
