#pragma once
#include "../../../System.Collections.Generic/Dictionary/Dictionary.h"
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/Array/Array.h"
#include "../../../System.IO/File/FileStream/FileStream.h"

namespace System
{
    namespace IO
    {
        class DataBaseLocal : public Object, public IDisposable
        {
        private:
                DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
                Collections::Generic::Dictionary<string, Array<string>> rows = Collections::Generic::Dictionary<string, Array<string>>();
                const char* path = "";
                FileStream fileStream = FileStream(); 
#pragma endregion f/p
#pragma region constructor
        public:
                DataBaseLocal()=default;
                DataBaseLocal(const String& path);
                ~DataBaseLocal()override;
#pragma endregion constructor
#pragma region custom methods
        private:
                // void RegisterRows(const String& str);
        public:
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
