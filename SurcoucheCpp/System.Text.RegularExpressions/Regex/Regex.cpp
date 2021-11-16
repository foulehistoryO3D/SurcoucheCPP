#include "Regex.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../../System/PrimaryType/Integer/Integer.h"
#include "../../System.Collections.Generic/List/List.h"
#include "../../System/Console/Console.h"
#include "../Match/Match.h"

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

void System::Text::RegularExpressions::Regex::InitMatchRegex(std::string& _str, int _index, RegularExpressions::Match& _match, std::smatch m) const
{
    const char* _value = m[0].str().c_str();
    const char* _key = m[1].str().c_str();
    _match.SetValue(_value);
    _str = m.suffix();
    _match.SetIndex(_index = _index == -1 ? m.position() : _index);
    Group _group = Group();
    _group.SetName(Int(1).ToString());
    _group.SetValue(_match.Value());
    _group.SetIndex(_index);
    Capture _capture = Capture();
    _capture.SetIndex(_index);
    _capture.SetValue(_match.Value());
    _group.AddCapture(_capture);
    _match.AddGroup(Int(1).ToString(), _group);
    InitMatchRegexInternal(_match, _key, _value);
}

void System::Text::RegularExpressions::Regex::InitMatchRegexInternal(RegularExpressions::Match& _match,
    const String& _key, const String& _str) const
{
    Group _group = Group();
    _group.SetName(Int(2).ToString());
    _group.SetValue(_key);
    Collections::Generic::List<String> _splitedString = _str.Split(' ');
    const int _count = _splitedString.Count();
    for (int i = 1; i < _count; ++i)
    {
        Capture _capture = Capture();
        _capture.SetValue(_splitedString[i]);
        _group.AddCapture(_capture);
    }
    _match.AddGroup(_group.Value(), _group);
}


System::Text::RegularExpressions::Match System::Text::RegularExpressions::Regex::Match(const String& _input) const
{
    std::string _str = _input.ToCstr();
    const bool _isSuccess = IsMatch(_input);
    int _index = -1;
    RegularExpressions::Match _match = RegularExpressions::Match(_isSuccess);
    std::smatch m = std::smatch();
    std::regex_search(_str, m, mExpression);
    InitMatchRegex(_str, _index, _match, m);
    
    for (; std::regex_search(_str, m, mExpression); _str = m.suffix())
    {
        Console::WriteLine(m[1].str().c_str());
    }
    return _match;
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
