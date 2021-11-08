#pragma once
#include "../Interface/Equatable/IEquatable.h"
#include "../Object/Object.h"

namespace System
{
    class Integer;
    class Version : public Object, public IEquatable<Version>
    {
#pragma region f/p
    private:
        int32 m0 = -1;
        int32 m1 = -1;
        int32 m2 = -1;
        int32 m3 = -1;
        int32 mMinor = 0;
        int32 mMajor = 0;
    public:
        Integer Major()const;
        Integer Minor()const;
#pragma endregion f/p
#pragma region constructor
    public:
        Version() = default;
        Version(int32 _args0, int32 _args1, int32 _args2 = 0, int32 _args3 = 0);
        Version(const String& _str);
        Version(const Version& _copy);
#pragma endregion constructor
#pragma region override
    public:
        String ToString() const override;
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        size_t GetHashCode() const override;
        Boolean Equals(const Version& _object) override;
#pragma endregion override
    };
}
