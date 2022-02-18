#pragma once
#include "../../SqlData.h"
#include "../../../System/Object/Object.h"
#include "../../DataBase/Table/DataBaseTable.h"
#include "../Inteface/ISQLCommand.h"

namespace System
{
    namespace SQL
    {
        class SQLInsertCommand sealed : public Object, public ISQLCommand
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
                string command          = string::Empty;
                DataBaseTable* table    = null;
#pragma endregion f/p
#pragma region constructor
        public:
                SQLInsertCommand() = default;
                SQLInsertCommand(const string& command, DataBaseTable* table);
                SQLInsertCommand(const SQLInsertCommand& copy);
#pragma endregion constructor
#pragma region custom methods
        private:
                string GetLastID() const;
                Collections::Generic::List<SqlData> GetData() const;
            static Array<string> GetValues(const string& line);
        public:
#pragma endregion custom methods
#pragma region override
        public:
            void Execute() override;
            SQLReader ExecuteReader() override;
#pragma endregion override
#pragma region operator
        public:
                SQLInsertCommand& operator=(const SQLInsertCommand& other);
#pragma endregion operator
        };
    }
}
