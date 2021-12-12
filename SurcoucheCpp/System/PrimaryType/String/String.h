#pragma once
#include <string>
#include <windows.h>

#include "../../../System.Collections.Generic/Interface/Enumerable/IEnumerable.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../../Object/Object.h"
#include "../../Interface/Equatable/IEquatable.h"
#include "../../TemplateUtils/TemplateUtils.h"
#include "../Boolean/Boolean.h"

namespace System
{
	class Integer;
	class Float;
	namespace Collections
	{
		namespace Generic
		{
			template<typename T>
			class List;
		}
	}
}

namespace System
{
	class String sealed : public Object, public IEquatable<String>, public Collections::Generic::IEnumerable<char>, public Collections::Generic::IEnumerator<char>
	{
#pragma region f/p
	private:
		const char* mValue = "";
		int mLength = 0;
		char mCurrentValue = 0;
		int mCurrentIndex = -1;
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		String() = default;
		String(const char* _value);
		String(const String& _copy);
#pragma endregion constructor/destructor
#pragma region custom methods
	public:
		Boolean StartWith(const char& _c) const;
		Boolean StartWith(const String& _str) const;
		Boolean EndWith(const char& _c)const;
		Boolean EndWith(const String& _str)const;
		Boolean EqualsIgnoreCase(const String& _str) const;
		void Append(const Object& _object);
		void Append(const Object* _object);
		void Append(const String& _str);
		void Append(const char& _c);
		void Append(const int _i);
		void Append(const Integer& _integer);
		String ToLower() const;
		String ToUpper() const;
		Boolean Contains(const String& _str) const;
		Collections::Generic::List<String> Split(const char& _c) const;
		Collections::Generic::List<String> Split(const String& _value) const;
		String SubString(const Integer& _begin, const Integer& _end)const;
		String SubString(const Integer& _begin)const;
		const char* ToCstr() const;
		String Replace(const char _oldChar, const char _newChar) const;
		String Replace(const String& _old, const String& _new) const;
		static String Empty();
		static bool IsNullOrEmpty(const String& _str);
		Integer LastIndexOf(const char _c) const;
		Integer FirstIndexOf(const char _c)const;
		Integer FirstIndexOf(const String& _str)const;
		Integer Length()const;
		std::wstring* ToWString()const;
		static std::wstring* ToWString(const String& _str);
		static String WStringToString(const std::wstring& _wstring);
		template<typename... Args>
		static String Format(const String& _str, Args... _args);
		String Join(const Collections::Generic::List<String>& _values);
#pragma endregion custom methods
#pragma region override
	public:
		String ToString()const override;
		class Boolean Equals(const object* _obj) override;
		Boolean Equals(const String& _object)override;
		size_t GetHashCode() const override;
		char Current()override;
		bool MoveNext()override;
		void Reset()override;
		IEnumerator<char>* GetEnumerator()override;
#pragma endregion override
#pragma region operator
		operator const char* ()const;
		String operator+(const char* _str);
		String operator+(const String* _str);
		String operator+(const CHAR* _str) const;
		String operator+(const Integer& _integer);
		String operator+(const Float& _float);
		String operator+(const Bool& _bool);
		String operator+(const int _i);
		String operator+(const char& _c);
		char operator[](const int _index) const
		{
			if (_index < 0 || _index > mLength) throw OutOfRange("[String] operator [] => index out of range");
			return mValue[_index];
		}
		String operator=(const String& _str)
		{
			mValue = std::move(_str.mValue);
			mLength = std::move(_str.mLength);
			return *this;
		}
		String& operator+=(char _c);
		String& operator+=(const String& _str);
		Boolean operator==(const String& _other) const;
		Boolean operator== (const char* _other) const;
		Boolean operator!=(const String& _other) const;
		Boolean operator!= (const char* _other) const;
#pragma endregion operator
	};



	template <typename ... Args>
	String String::Format(const String& _str, Args... _args)
	{
		String _result = _str;
		Collections::Generic::List<object*> _package = TemplateUtils::CreateListWithParameterPack<object*>(&_args...);
		const int _count = _package.Count();
		for (int i = 0; i < _count; ++i)
		{
			_result = _result.Replace(String("{") + i + "}", _package[i]->ToString());
		}
		return _result;
	}
}

typedef System::String string;
