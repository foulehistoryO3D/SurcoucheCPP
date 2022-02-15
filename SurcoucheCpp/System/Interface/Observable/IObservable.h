#pragma once
#include "../Disposable/IDisposable.h"

namespace System
{
    template<typename T>
    class IObserver;
    
    template<typename T>
    class IObservable
    {
    public:
        virtual ~IObservable() = default;
        virtual IDisposable* Subscribe(IObserver<T>* observer) PURE_VIRTUAL()
    };
}
