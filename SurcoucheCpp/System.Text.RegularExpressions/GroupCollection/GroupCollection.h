#pragma once
#include "../../System.Collections.Generic/Interface/Dictionary/IDictionary.h"
#include "../../System/PrimaryType/String/String.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"
#include "../Group/Group.h"

namespace System
{
    namespace Text
    {
        namespace RegularExpressions
        {
            class GroupCollection : public Object, public Collections::Generic::IDictionary<String, Group>,
                                    public Collections::Generic::IEnumerator<Collections::Generic::KeyValuePair<
                                        String, Group>>
            {
                DECLARE_CLASS_INFO(Object)
#pragma region f/p
            private:
                int mCount = 0;
                int mCurrentIndex = -1;
                Collections::Generic::KeyValuePair<String, Group>* mTab = new Collections::Generic::KeyValuePair<
                    String, Group>[0];
                Collections::Generic::KeyValuePair<String, Group> mCurrentItem = Collections::Generic::KeyValuePair<
                    String, Group>();
#pragma endregion f/p
#pragma region constructor
            public:
                GroupCollection() = default;
                GroupCollection(std::initializer_list<Collections::Generic::KeyValuePair<String, Group>> _tab);
                GroupCollection(IEnumerator<Collections::Generic::KeyValuePair<String, Group>>* _enumerator);
                GroupCollection(const GroupCollection& copy);
#pragma endregion constructor
#pragma region custom methods
            private:
                int IndexOf(const String& _key) const;
                void RemoveAt(const int& _index);
#pragma endregion custom methods
#pragma region override
            public:
                Integer Count() const override;
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
                String ToString() const override;
                Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
                Collections::Generic::KeyValuePair<String, Group>& operator[](const int32& _index) const;
                GroupCollection& operator=(const GroupCollection& _other);
                Boolean operator==(const GroupCollection& _other) const;
#pragma endregion operator
            };
        }
    }
}
