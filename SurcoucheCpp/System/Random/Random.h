#pragma once
#include "../Object/Object.h"

namespace System
{
    class Integer;
    class Float;
    class Random : public Object
    {
    public:
        Integer Next()const;
        Integer Next(const Integer& _min, const Integer& _max)const;
        Float NextFloat()const;
        Float NextFloat(const Float& _min, const Float& _max)const;
        Float Sample()const;
    };
}
