#pragma once
#include "../../System/Object/Object.h"

namespace System
{
    class Integer;
    namespace Reflection
    {
        class ParameterInfo : public Object
        {
            DECLARE_CLASS_INFO(Object)
#pragma region f/p
        protected:
            Type* mClassImpl = nullptr;
            object* mDefaultValueImpl = nullptr;
            const char* mNameImpl = "";
            int mPositionImpl = 0;
        public:
            Type* ParameterType()const;
            object* DefaultValue()const;
            String Name()const;
            Integer Position()const;
#pragma endregion f/P
#pragma region constructor
        public:
            ParameterInfo()=default;
            ParameterInfo(Type* _parameterType, const Integer& _position);
            ParameterInfo(const ParameterInfo& copy);
#pragma region constructor
#pragma region operator
        public:
            ParameterInfo operator=(const ParameterInfo& _other);
#pragma endregion operator
        };
    }
}
