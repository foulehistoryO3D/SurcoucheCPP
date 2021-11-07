#pragma once
#include "../../System/Exception/Exception/Exception.h"
#include "../../System/Object/Object.h"
#include "../Interface/Dictionary/IDictionary.h"
#include "../KeyValuePair/KeyValuePair.h"
#include "../../System/PrimaryType/Boolean/Boolean.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename TKey, typename TValue>
            class Dictionary : public Object, public IDictionary<TKey, TValue>,
                               public IEnumerator<KeyValuePair<TKey, TValue>>
            {
#pragma region f/p
            private:
                KeyValuePair<TKey, TValue>* mTab = new KeyValuePair<TKey, TValue>[0];
                int mCount = 0;
                int mCurrentIndex = -1;
                KeyValuePair<TKey, TValue> mCurrentItem = KeyValuePair<TKey, TValue>();
#pragma endregion f/p
#pragma region constructor
            public:
                Dictionary() = default;
                Dictionary(IEnumerable<KeyValuePair<TKey, TValue>>* _enumerable);
                Dictionary(std::initializer_list<KeyValuePair<TKey, TValue>> _tab);
                Dictionary(const Dictionary& _other);
#pragma endregion constructor
#pragma region custom methods
            private:
                int IndexOfKey(TKey _key);
                void RemoveAt(const int& _index);
#pragma endregion custom methods
#pragma region override
            public:
                int Count() const override;
                void Add(KeyValuePair<TKey, TValue> _item) override;
                void Clear() override;
                bool Contains(KeyValuePair<TKey, TValue> _item) override;
                void Remove(KeyValuePair<TKey, TValue> _item) override;
                IEnumerator<KeyValuePair<TKey, TValue>>* GetEnumerator() override;
                void Add(TKey _key, TValue _value) override;
                Boolean ContainsKey(TKey _key) override;
                void RemoveItem(TKey _key) override;
                KeyValuePair<TKey, TValue> Current() override;
                bool MoveNext() override;
                void Reset() override;
#pragma endregion override
#pragma region operator
            public:
                TValue& operator[](const TKey& _key);
                TValue& operator[](const TKey& _key)const;
#pragma endregion operator
            };

#pragma region constructor
            template <typename TKey, typename TValue>
            Dictionary<TKey, TValue>::Dictionary(IEnumerable<KeyValuePair<TKey, TValue>>* _enumerable)
            {
                while (_enumerable->GetEnumerator()->MoveNext())
                    Dictionary<TKey, TValue>::Add(_enumerable->GetEnumerator()->Current());
                _enumerable->GetEnumerator()->Reset();
            }

            template <typename TKey, typename TValue>
            Dictionary<TKey, TValue>::Dictionary(std::initializer_list<KeyValuePair<TKey, TValue>> _tab)
            {
                for (const KeyValuePair<TKey, TValue>& _pair : _tab)
                    Dictionary<TKey, TValue>::Add(_pair);
            }

            template <typename TKey, typename TValue>
            Dictionary<TKey, TValue>::Dictionary(const Dictionary& _other)
            {
                mCount = std::move(_other.mCount);
                mTab = std::move(_other.mTab);
                mCurrentIndex = std::move(_other.mCurrentIndex);
                mCurrentItem = std::move(_other.mCurrentItem);
            }

            template <typename TKey, typename TValue>
            int Dictionary<TKey, TValue>::IndexOfKey(TKey _key)
            {
                for (int i = 0; i < mCount; ++i)
                    if (mTab[i].Key == _key)
                        return i;
                return -1;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::RemoveAt(const int& _index)
            {
                KeyValuePair<TKey, TValue>* _tmpTab = mTab;
                mTab = new KeyValuePair<TKey, TValue>[mCount - 1];
                for (int i = 0; i < _index; ++i)
                    mTab[i] = _tmpTab[i];
                for (int i = _index + 1; i < mCount; ++i)
                    mTab[i - 1] = _tmpTab[i];
                delete[]_tmpTab;
                mCount--;
            }
#pragma endregion constructor
#pragma region override
            template <typename TKey, typename TValue>
            int Dictionary<TKey, TValue>::Count() const
            {
                return mCount;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::Add(KeyValuePair<TKey, TValue> _item)
            {
                if (Contains(_item))
                    throw Exception("key is already exist !");
                KeyValuePair<TKey, TValue>* _tmpTab = mTab;
                mTab = new KeyValuePair<TKey, TValue>[mCount + 1];
                for (int i = 0; i < mCount; ++i)
                    mTab[i] = _tmpTab[i];
                mTab[mCount] = _item;
                delete[] _tmpTab;
                mCount++;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::Clear()
            {
                delete[] mTab;
                mTab = new KeyValuePair<TKey, TValue>[0];
                mCount = 0;
            }

            template <typename TKey, typename TValue>
            bool Dictionary<TKey, TValue>::Contains(KeyValuePair<TKey, TValue> _item)
            {
                return IndexOfKey(_item.Key) != -1;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::Remove(KeyValuePair<TKey, TValue> _item)
            {
                const int& _index = IndexOfKey(_item.Key);
                if (_index == -1)
                    throw Exception("key doesn't exist");
                RemoveAt(_index);
            }

            template <typename TKey, typename TValue>
            IEnumerator<KeyValuePair<TKey, TValue>>* Dictionary<TKey, TValue>::GetEnumerator()
            {
                return this;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::Add(TKey _key, TValue _value)
            {
                Add(KeyValuePair<TKey, TValue>(_key, _value));
            }

            template <typename TKey, typename TValue>
            Boolean Dictionary<TKey, TValue>::ContainsKey(TKey _key)
            {
                return IndexOfKey(_key) != -1;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::RemoveItem(TKey _key)
            {
                const int _index = IndexOfKey(_key);
                if (_index == -1)
                    throw Exception("key doesn't exist");
                RemoveAt(_index);
                
            }

            template <typename TKey, typename TValue>
            KeyValuePair<TKey, TValue> Dictionary<TKey, TValue>::Current()
            {
                return mCurrentItem;
            }

            template <typename TKey, typename TValue>
            bool Dictionary<TKey, TValue>::MoveNext()
            {
                if (++mCurrentIndex >= mCount) return false;
                mCurrentItem = mTab[mCurrentIndex];
                return true;
            }

            template <typename TKey, typename TValue>
            void Dictionary<TKey, TValue>::Reset()
            {
                mCurrentIndex = -1;
            }

            template <typename TKey, typename TValue>
            TValue& Dictionary<TKey, TValue>::operator[](const TKey& _key)
            {
                const int _index = IndexOfKey(_key);
                if (_index == -1)
                    throw Exception("key doesn't exist");
                return mTab[_index].Value;
            }

            template <typename TKey, typename TValue>
            TValue& Dictionary<TKey, TValue>::operator[](const TKey& _key) const
            {
                const int _index = IndexOfKey(_key);
                if (_index == -1)
                    throw Exception("key doesn't exist");
                return mTab[_index].Value;
            }
#pragma endregion override
        }
    }
}
