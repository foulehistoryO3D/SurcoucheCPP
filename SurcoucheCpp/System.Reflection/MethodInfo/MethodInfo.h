﻿#pragma once
#include <functional>

#include "../../System/Object/Object.h"
#include "../ParameterInfo/ParameterInfo.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../../System/TemplateUtils/TemplateUtils.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/Console/Console.h"

#pragma region define
#define FUNCTION_NAME(function) #function
#pragma endregion define

namespace System
{
    namespace Reflection
    {
        class MethodInfo : public Object
        {
#pragma region f/p
        private:
            object* mOwner = nullptr;
            String mName = "";
            Collections::Generic::List<ParameterInfo> mParameters = Collections::Generic::List<ParameterInfo>();
        public:
            String Name()const;
            Collections::Generic::List<ParameterInfo> Parameters()const;
            object* Owner()const;
#pragma endregion f/p
#pragma region constructor
        public:
            MethodInfo()=default;
            template<typename Res, typename C, typename... Args>
            MethodInfo(Res(C::*ptr)(Args...), object* _owner, const String& _functionName);
            MethodInfo(const MethodInfo& copy);
#pragma endregion constructor
#pragma region custom methods
            // template<typename... Args>
            // auto Invoke(Args... _args);
#pragma endregion custom methods
        };

        template <typename Res, typename C, typename ... Args>
        MethodInfo::MethodInfo(Res(C::*ptr)(Args...), object* _owner, const String& _functionName)
        {
            mOwner = std::move(_owner);
            mParameters = std::move(TemplateUtils::GetParametersFunction(ptr));
            mName = std::move(_functionName.SubString(_functionName.LastIndexOf(':')+1, _functionName.Length()));
        }
    }
}
