#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../DataBase/Table/DataBaseTable.h"
#include "../Inteface/ISQLCommand.h"

namespace System
{
    namespace SQL
    {
        class SQLDeleteCommand sealed : public Object, public ISQLCommand
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            string command          = string::Empty;
            string id               = string::Empty;
            DataBaseTable* table    = null;
#pragma endregion f/p
#pragma region constructor
        public:
            SQLDeleteCommand() = default;
            SQLDeleteCommand(const string& command, const string& id, DataBaseTable* table);
            SQLDeleteCommand(const SQLDeleteCommand& copy);
#pragma endregion constructor
#pragma region override
        public:
            void Execute() override;
            SQLReader ExecuteReader() override;
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion custom methods
#pragma region operator
        public:
            SQLDeleteCommand& operator=(const SQLDeleteCommand& other);
#pragma endregion operator
        };
    }
}
