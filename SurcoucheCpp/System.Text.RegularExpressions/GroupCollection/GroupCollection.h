#pragma once
#include "../../System.Collections.Generic/Interface/Dictionary/IDictionary.h"
#include "../Group/Group.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class GroupCollection : public Collections::Generic::IDictionary<String, Group>, public Collections::Generic::IEnumerator<Collections::Generic::KeyValuePair<String, Group>>
            {
#pragma region f/p
            private:
                int mCount = 0;
                int mCurrentIndex = -1;
                Collections::Generic::KeyValuePair<String, Group>* mTab = new Collections::Generic::KeyValuePair<String, Group>[0];
                Collections::Generic::KeyValuePair<String, Group> mCurrentItem = Collections::Generic::KeyValuePair<String, Group>();
#pragma endregion f/p
#pragma region constructor
            public:
                GroupCollection()=default;
                GroupCollection(std::initializer_list<Collections::Generic::KeyValuePair<String, Group>> _tab);
                GroupCollection(IEnumerator<Collections::Generic::KeyValuePair<String, Group>>* _enumerator);
                GroupCollection(const GroupCollection& _copy);
#pragma endregion constructor
#pragma region override
            public:
                int Count() const override;
                void Add(Collections::Generic::KeyValuePair<String, Group> _item) override;
                void Clear() override;
                bool Contains(Collections::Generic::KeyValuePair<String, Group> _item) override;
                void Remove(Collections::Generic::KeyValuePair<String, Group> _item) override;
                Collections::Generic::KeyValuePair<String, Group> Current() override;
                bool MoveNext() override;
                void Reset() override;
                IEnumerator<Collections::Generic::KeyValuePair<String, Group>>* GetEnumerator() override;
                void Add(String _key, Group _value) override;
                Boolean ContainsKey(String _key) override;
                void RemoveItem(String _key) override;
#pragma endregion override
            };
        }
    }
}
