#pragma once
#include "../Group/Group.h"
#include "../GroupCollection/GroupCollection.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class Match : public Group
            {
                DECLARE_CLASS_INFO(Group)
#pragma region f/p
            private:
                GroupCollection mGroups = GroupCollection();
            public:
                GroupCollection Groups()const;
#pragma endregion f/p
#pragma region constructor
            public:
                Match()=default;
                Match(const int& _index, const String& _value, const bool _success);
                Match(const Match& _copy);
#pragma endregion constructor
#pragma region override
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                size_t GetHashCode() const override;
#pragma endregion override
#pragma region operator
            public:
                Match& operator=(const Match& _other);
#pragma endregion operator
            };
        }
    }
}
