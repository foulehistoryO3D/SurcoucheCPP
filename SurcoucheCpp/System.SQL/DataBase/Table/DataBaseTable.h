#pragma once
#include "../../../System/Interface/Disposable/IDisposable.h"
#include "../../../System/Object/Object.h"
#include "../../../System.IO/File/File/File.h"
#include "../../../System/PrimaryType/String/String.h"

namespace System
{
    namespace SQL
    {
        class DataBaseTable : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            IO::File file = IO::File();
#pragma endregion f/p
#pragma region constructor
        public:
            DataBaseTable()=default;
            DataBaseTable(const IO::File& file);
            DataBaseTable(const DataBaseTable& copy);
#pragma endregion constructor
#pragma region custom methods
        public:
            String GetValueFromIndex(const Integer& index) const;
#pragma endregion custom methods
#pragma region override
        public:
#pragma endregion custom methods
#pragma region override
        public:
#pragma endregion override
#pragma region operator
        public:
            DataBaseTable& operator=(const DataBaseTable& other);
#pragma endregion operator
        };
    }
}
