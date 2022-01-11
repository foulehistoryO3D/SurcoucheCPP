#pragma once

class [[attribute]] Range
{
private:
    int begin = 0;
    int end = 0;
public:
    constexpr Range(const float begin, const float end);
    constexpr bool between(const float x)const;
    
};

constexpr Range::Range(const float begin, const float end)
{
    this->begin = begin;
    this->end = end;
}

constexpr bool Range::between(const float x) const
{
    return x > begin && x < end;
}
