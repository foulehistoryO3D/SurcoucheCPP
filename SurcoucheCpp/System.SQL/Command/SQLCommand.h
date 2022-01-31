#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Integer/Integer.h"

namespace System
{
    namespace SQL
    {
        class SQLReader;
        class SQLCommand : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
                const char* command = "";
                int timeout = 0;
        public:
#pragma endregion f/p
#pragma region constructor
        public:
                SQLCommand() = default;
                SQLCommand(const String& command, const Integer& timeout = 60);
                SQLCommand(const SQLCommand& copy);
#pragma endregion constructor
#pragma region custom methods
        private:
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
