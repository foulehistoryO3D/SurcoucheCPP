#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../DataBase/Table/DataBaseTable.h"
#include "../../SqlData.h"
#include "../Inteface/ISQLCommand.h"


namespace System
{
    namespace SQL
    {
        class SQLUpdateCommand sealed : public Object, public ISQLCommand
        {
        private:
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            string command                                      = string::Empty;
            string id                                           = string::Empty;
            DataBaseTable* table                                = null;
            Collections::Generic::List<SqlData> sqlData         = Collections::Generic::List<SqlData>();
            Collections::Generic::List<SqlData> valuesData      = Collections::Generic::List<SqlData>();
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            SQLUpdateCommand()=default;
            SQLUpdateCommand(const string& command, const string& id, DataBaseTable* table);
            SQLUpdateCommand(const SQLUpdateCommand& copy);
#pragma endregion constructor/destructor
#pragma region custom methods
        private:
            Collections::Generic::List<SqlData> RegisterValues(Collections::Generic::List<string> values);
            Collections::Generic::List<SqlData> GetDataValues(const string& str);
            SqlData* GetData(const string& key);
            Collections::Generic::List<string> GetValues() const;
            void UpdateValues();
            string ConstructNewLine(const string& id);
#pragma endregion custom methods
#pragma region override
        public:
            void Execute() override;
            SQLReader ExecuteReader() override;
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            SQLUpdateCommand& operator=(const SQLUpdateCommand& other);
#pragma endregion operator
        };
    }
}
