#include "Regex.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System/PrimaryType/Array/Array.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../../System/Console/Console.h"
#include "../Match/Match.h"

#pragma region constructor
System::Text::RegularExpressions::Regex::Regex(const String& _pattern)
{
    mPattern = _pattern;
    mExpression = std::regex(std::string(_pattern), static_cast<std::regex::flag_type>(std::regex_constants::ECMAScript ));
}

System::Text::RegularExpressions::Regex::Regex(const Regex& copy) : Object(copy)
{
    mPattern = std::move(copy.mPattern);
    mExpression = std::move(copy.mExpression);
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

System::Text::RegularExpressions::Match System::Text::RegularExpressions::Regex::Match(const String& _input) const
{
    std::string _str = _input.ToCstr();
    std::smatch _match = std::smatch();
    RegularExpressions::Match _result = RegularExpressions::Match();
    const bool _success = std::regex_search(_str, _match, mExpression);
    
    _result.SetSuccess(_success);
    if (!_success)return _result;
    const int _count = _match.size();
    const String& _resultStr = _match.str(0).c_str();
    _result.SetValue(_resultStr);
    _result.SetIndex(_match.position(0));
    _result.AddGroup(_resultStr, _resultStr, _match.position(0));
    
    for (int32 i = 1; i < _count; ++i)
    {
        Collections::Generic::List<String> _splitedString = _resultStr.Split(' ');
        _result.AddGroup(_match.str(i).c_str(), _splitedString, _match.position(i));
    }
    return _result;
}

System::Array<System::String> System::Text::RegularExpressions::Regex::Find(const String& input) const
{
    std::string str = input.ToCstr();
    std::smatch match = std::smatch();
    std::regex_search(str, match, this->mExpression);
    Array<string> result = Array<string>(match.size());
    int index = 0;
    for (auto item : match)
    {
        result.InsertAt(index, item.str().c_str());
        index++;
    }
    return result;
}

string System::Text::RegularExpressions::Regex::FindFirst(const String& input) const
{
    return Find(input)[0];
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

System::Integer System::Text::RegularExpressions::Regex::GetHashCode() const
{
    return ToString().GetHashCode();
}

System::Boolean System::Text::RegularExpressions::Regex::Equals(const Regex& _object)
{
    return mPattern == _object.mPattern;
}
#pragma endregion override
