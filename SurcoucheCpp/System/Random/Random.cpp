#include "Random.h"

#include <random>

#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/Float/Float.h"

System::Integer System::Random::Next() const
{
    return Next(0, Integer::MaxValue);
}

System::Integer System::Random::Next(const Integer& _min, const Integer& _max) const
{
    std::random_device _rd = std::random_device();
    std::mt19937 _gen(_rd());
    const std::uniform_int_distribution<> _distr = std::uniform_int_distribution<>(_min, _max);
    return _distr(_gen);
}

System::Float System::Random::NextFloat() const
{
    return NextFloat(0.0f, Float::MaxValue);
}

System::Float System::Random::NextFloat(const Float& _min, const Float& _max) const
{
    const float random = ((float) rand()) / (float) RAND_MAX;
    const float range = _max - _min;  
    return (random*range) + _min;
}

System::Float System::Random::Sample() const
{
    return NextFloat(0.0f, 1.0f);
}
