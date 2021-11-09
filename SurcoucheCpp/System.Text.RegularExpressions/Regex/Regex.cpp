#include "Regex.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

#pragma region constructor
System::Text::RegularExpressions::Regex::Regex(const String& _pattern)
{
    mPattern = _pattern;
    mExpression = _pattern;
}

System::Text::RegularExpressions::Regex::Regex(const Regex& _copy)
{
    mPattern = std::move(_copy.mPattern);
    mExpression = std::move(_copy.mExpression);
}
#pragma endregion constructor
#pragma region custom methods
System::Boolean System::Text::RegularExpressions::Regex::IsMatch(const String& _input) const
{
    return std::regex_search(_input.ToCstr(), mExpression);
}

System::String System::Text::RegularExpressions::Regex::Replace(const String& _input, const String& _replacement) const
{
    return std::regex_replace(_input.ToCstr(), mExpression, _replacement.ToCstr()).c_str();
}
#pragma endregion custom methods
#pragma region override
System::String System::Text::RegularExpressions::Regex::ToString() const
{
    return mPattern;
}

System::Boolean System::Text::RegularExpressions::Regex::Equals(const object* _obj)
{
    const Regex& _regex = *dynamic_cast<const Regex*>(_obj);
    return Equals(_regex);
}

System::Boolean System::Text::RegularExpressions::Regex::Equals(const object& _obj)
{
    const Regex& _regex = *dynamic_cast<const Regex*>(&_obj);
    return Equals(_regex);
}

size_t System::Text::RegularExpressions::Regex::GetHashCode() const
{
    Regex _regex = *this;
    return std::hash<Regex*>{}(&_regex);
}

System::Boolean System::Text::RegularExpressions::Regex::Equals(const Regex& _object)
{
    return mPattern == _object.mPattern;
}
#pragma endregion override