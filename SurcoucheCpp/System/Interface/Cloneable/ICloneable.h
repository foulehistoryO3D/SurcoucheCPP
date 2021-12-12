#pragma once
#include "../../Object/Object.h"

template<typename T>
class ICloneable
{
public:
    virtual ~ICloneable() = default;
    virtual T Clone() PURE_VIRTUAL()
};