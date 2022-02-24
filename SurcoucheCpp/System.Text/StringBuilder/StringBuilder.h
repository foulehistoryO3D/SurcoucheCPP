#pragma once
#include "../../System/Object/Object.h"
#include "../../System/PrimaryType/Char/Char.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/TemplateUtils/TemplateUtils.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename T>
            class List;
        }
    }

    class Integer;
    class Char;

    namespace Text
    {
        class StringBuilder : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        private:
            const char* mValue = "";
            int mLength = 0;
            int mCapacity = 0;
            int mCapacityMax = 255;
        public:
#pragma endregion f/p
#pragma region constructor
        public:
            StringBuilder() = default;
            StringBuilder(const Integer& _capacity);
            StringBuilder(const Integer& _capacity, const Integer& _capacityMax);
            StringBuilder(const String& _str);
            StringBuilder(const String& _str, const Integer& _capacity);
            StringBuilder(const char* _str);
            StringBuilder(const StringBuilder& _copy);
#pragma endregion constructor
#pragma region custom methods
            StringBuilder& Append(const Object& _object);
            StringBuilder& Append(const Object* _object);
            StringBuilder& Append(const char* _str);
            StringBuilder& Append(Collections::Generic::List<char> _char);
            StringBuilder& Append(const Char& _char);
            StringBuilder& Append(const int& _int);
            StringBuilder& Append(const float& _float);
            StringBuilder& Append(const double& _double);
            StringBuilder& Clear();
            StringBuilder& Replace(const char& _old, const char& _new);
            template <typename T, typename ... Args>
            StringBuilder& AppendFormat(const String& _str, Args ... _args);
            Boolean Equals(const StringBuilder& _builder);
#pragma endregion custom methods
#pragma region override
        public:
            String ToString() const override;
            Boolean Equals(const object* _obj) override;
            Boolean Equals(const object& _obj) override;
            Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
        public:
            operator const char*() const;
            StringBuilder& operator=(const StringBuilder& other);
#pragma endregion operator
        };

        template <typename T, typename ... Args>
        StringBuilder& StringBuilder::AppendFormat(const String& _str, Args ... _args)
        {
            Collections::Generic::List<T> _splitedArgs = TemplateUtils::CreateListWithParameterPack<T>(_args...);
            const int _length = _splitedArgs.Count();
            String _result = _str;
            for (int i = 0; i < _length; ++i)
            {
                const char _c = _splitedArgs[i];
                string _old = string("{") + Integer(i) + "}";
                _result = _result.Replace(_old, Char(_c).ToString());
            }
            return Append(_result);
        }
    }
}
