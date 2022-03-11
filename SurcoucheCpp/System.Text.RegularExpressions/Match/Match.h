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
                Collections::Generic::List<Group> mGroups = Collections::Generic::List<Group>();
            public:
                Collections::Generic::List<Group> Groups()const;
#pragma endregion f/p
#pragma region constructor
            public:
                Match()=default;
                Match(const bool _success);
                Match(const Match& copy);
#pragma endregion constructor
#pragma region custom methods
            public:
                void AddGroup(const String& _key, const Collections::Generic::List<String>& _value, const Integer& _index);
                void AddGroup(const String& _key, const String& _value, const Integer& _index);
#pragma endregion custom methods
#pragma region override
            public:
                String ToString() const override;
                Boolean Equals(const object* _obj) override;
                Boolean Equals(const object& _obj) override;
                Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
            public:
                Match operator=(const Match& _other);
#pragma endregion operator
            };
        }
    }
}
