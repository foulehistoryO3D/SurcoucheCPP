#pragma once
#include "../../System/Object/Object.h"
#include "../ParameterInfo/ParameterInfo.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../../System/TemplateUtils/TemplateUtils.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

namespace System
{
    namespace Reflection
    {
        class MethodInfo : public Object
        {
#pragma region f/p
        private:
            String mName = "";
            Collections::Generic::List<ParameterInfo> mParameters = Collections::Generic::List<ParameterInfo>();
        public:
            String Name()const;
            Collections::Generic::List<ParameterInfo> Parameters()const;
#pragma endregion f/p
#pragma region constructor
        public:
            MethodInfo()=default;
            template<typename C, typename... Args>
            MethodInfo(void(C::*ptr)(Args...), const String& _functionName);
            MethodInfo(const MethodInfo& _method);
#pragma endregion constructor
        };

        template <typename C, typename ... Args>
        MethodInfo::MethodInfo(void(C::*ptr)(Args...), const String& _functionName)
        {
            mParameters = TemplateUtils::GetParametersFunction(ptr);
            mName = _functionName.SubString(_functionName.LastIndexOf(':')+1, _functionName.Length());
        }
    }
}
