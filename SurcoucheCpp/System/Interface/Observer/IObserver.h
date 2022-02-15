#pragma once
#include "../../Exception/Exception/Exception.h"

namespace System
{
    template<typename T>
    class IObserver
    {
    public:
        virtual ~IObserver() = default;
        virtual void OnCompleted() PURE_VIRTUAL()
        virtual void OnError(const Exception& exception) PURE_VIRTUAL()
        virtual void OnNext(const T& item) PURE_VIRTUAL()
    };
}