#pragma once
#include "../System/Object/Object.h"
#include "../System/PrimaryType/String/String.h"

namespace System
{
    namespace SQL
    {
        struct SqlData sealed : Object
        {
            DECLARE_CLASS_INFO(Object)
            REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
        private:
            string key      = string::Empty;
            string value    = string::Empty;
        public:
            string Key()const;
            string Value()const;
#pragma endregion f/p
#pragma region constructor
        public:
            SqlData() = default;
            SqlData(const string& key, const string& value);
            SqlData(const SqlData& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            void SetValue(const string& newValue);
            string GetData()const;
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            SqlData& operator=(const SqlData& other);
#pragma endregion operator
        };
    }
}
