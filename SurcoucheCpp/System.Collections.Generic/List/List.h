#pragma once
#include "../Interface/Enumerator/IEnumerator.h"
#include "../Interface/Enumerable/IEnumerable.h"
#include "../Interface/List/IList.h"

namespace System
{
    template<typename... Args>
    class Action;
    template<typename out, typename... Args>
    class Func;
    template<typename Item>
    class Predicate;
    
    namespace Collections
    {
        namespace Generic
        {
            template <typename Item>
            class List sealed : public Object, public IList<Item>, public IEnumerator<Item>
            {
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                Item* mTab = new Item[0];
                Item mCurrentItem = Item();
                int mCount = 0;
                int mCurrentIndex = -1;
#pragma endregion f/p
#pragma region constructor/destructor
            public:
                List();
                List(IEnumerable<Item>* _enumerable);
                List(std::initializer_list<Item> _tab);
                List(const List<Item>& _copy);
                ~List() override;
#pragma endregion constructor/destructor
#pragma region Linq
            public:
                void ForEach(Action<Item> _action);
                List<Item> OrderBy(Func<bool, Item, Item> _selector);
                List<Item> Where(Func<bool, Item> _selector);
                Item Find(Predicate<Item> _pred);
#pragma endregion Linq
#pragma region override
            public:
                int Count() const override;
                void Add(Item _item) override;
                void Clear() override;
                bool Contains(Item _item) override;
                void Remove(Item _item) override;
                IEnumerator<Item>* GetEnumerator() override;
                int IndexOf(Item _item) override;
                void Insert(const int32 _index, Item _item) override;
                void RemoveAt(const int32 _index) override;
                Item Current() override;
                bool MoveNext() override;
                void Reset() override;
#pragma endregion override
#pragma region operator
                List<Item>* operator=(const IEnumerable<Item>* _enumerable);
                Item& operator[](const int _index);
                Item& operator[](const int _index)const;
#pragma endregion operator
            };
#pragma region constructor/destructor
            template <typename Item>
            List<Item>::List()
            {
                mTab = new Item[0];
                mCount = 0;
                mCurrentIndex = -1;
            }

            template <typename Item>
            List<Item>::List(IEnumerable<Item>* _enumerable)
            {
                while (_enumerable->GetEnumerator()->MoveNext())
                {
                    List<Item>::Add(_enumerable->GetEnumerator()->Current());
                }
                _enumerable->GetEnumerator()->Reset();
            }

            template <typename Item>
            List<Item>::List(std::initializer_list<Item> _tab)
            {
                for (const Item& _item : _tab)
                    Add(_item);
            }

            template <typename Item>
            List<Item>::List(const List<Item>& _copy)
            {
                for (int i = 0; i < _copy.mCount; ++i)
                    Add(_copy.mTab[i]);
            }

            template <typename Item>
            List<Item>::~List()
            {
                Clear();
            }
#pragma endregion constructor/destructor
#pragma region Linq
            template <typename Item>
            void List<Item>::ForEach(Action<Item> _action)
            {
                while (MoveNext())
                    _action.Invoke(Current());
                Reset();
            }

            template <typename Item>
            List<Item> List<Item>::OrderBy(Func<bool, Item, Item> _selector)
            {
                List<Item> _result = *this;
                for (int gap = mCount/2; gap > 0; gap /= 2) 
                { 
                    for (int i = gap; i < mCount; i += 1) 
                    { 
                        Item temp = _result.mTab[i]; 
                        int j; 
                        for (j = i; j >= gap && _selector.Invoke(_result.mTab[j - gap], temp); j -= gap) 
                            _result.mTab[j] = _result.mTab[j - gap]; 
                        _result.mTab[j] = temp; 
                    } 
                }
                return _result;
            }

            template <typename Item>
            List<Item> List<Item>::Where(Func<bool, Item> _selector)
            {
                List<Item> _result = List<Item>();
                while (MoveNext())
                {
                    const Item _item =Current();
                    if (_selector(_item))
                        _result.Add(_item);
                }
                Reset();
                return _result;
            }

            template <typename Item>
            Item List<Item>::Find(Predicate<Item> _pred)
            {
                while (MoveNext())
                {
                    if (_pred(Current()))
                    {
                        Reset();
                        return Current();
                    }
                }
                Reset();
                return Item();
            }
#pragma endregion Linq
#pragma region custom methods
            template <typename Item>
            int List<Item>::Count() const { return mCount; }

            template <typename Item>
            void List<Item>::Add(Item _item)
            {
                Item* _tmpTab = mTab;
                mTab = new Item[mCount + 1];
                for (int i = 0; i < mCount; ++i)
                    mTab[i] = _tmpTab[i];
                mTab[mCount] = _item;
                delete[] _tmpTab;
                mCount++;
            }

            template <typename Item>
            void List<Item>::Clear()
            {
                delete[] mTab;
                mTab = new Item[0];
                mCount = 0;
            }

            template <typename Item>
            bool List<Item>::Contains(Item _item)
            {
                for (int i = 0; i < mCount; ++i)
                    if (mTab[i] == _item)
                        return true;
                return false;
            }

            template <typename Item>
            void List<Item>::Remove(Item _item)
            {
                const int _index = IndexOf(_item);
                if (_index == -1)
                    throw Exception("[List] item doesn't exist");
                RemoveAt(_index);
            }

            template <typename Item>
            IEnumerator<Item>* List<Item>::GetEnumerator() { return this; }

            template <typename Item>
            int List<Item>::IndexOf(Item _item)
            {
                for (int i = 0; i < mCount; ++i)
                    if (mTab[i] == _item)
                        return i;
                return -1;
            }

            template <typename Item>
            void List<Item>::Insert(const int32 _index, Item _item)
            {
                if (_index < 0 || _index > mCount + 1)
                    throw OutOfRange("[List] => out of range !");
                Item* _tmpTab = mTab;
                mTab = new Item[mCount + 1];
                for (int i = 0; i < _index; ++i)
                    mTab[i] = _tmpTab[i];
                Item _oldValue = _tmpTab[_index];
                mTab[_index] = _item;
                mTab[_index + 1] = _oldValue;
                for (int i = _index + 1; i < mCount; ++i)
                    mTab[i + 1] = _tmpTab[i];
                delete[] _tmpTab;
                mCount++;
            }

            template <typename Item>
            void List<Item>::RemoveAt(const int32 _index)
            {
                Item* _tmpTab = mTab;
                mTab = new Item[mCount - 1];
                for (int i = 0; i < _index; ++i)
                    mTab[i] = _tmpTab[i];
                for (int i = _index + 1; i < mCount; ++i)
                    mTab[i - 1] = _tmpTab[i];
                delete[]_tmpTab;
                mCount--;
            }

            template <typename Item>
            Item List<Item>::Current()
            {
                return mCurrentItem;
            }

            template <typename Item>
            bool List<Item>::MoveNext()
            {
                if (++mCurrentIndex >= mCount) return false;
                mCurrentItem = mTab[mCurrentIndex];
                return true;
            }

            template <typename Item>
            void List<Item>::Reset()
            {
                mCurrentIndex = -1;
            }

#pragma endregion custom methods
#pragma region operator
            template <typename Item>
            List<Item>* List<Item>::operator=(const IEnumerable<Item>* _enumerable)
            {
                while (_enumerable->GetEnumerator()->MoveNext())
                {
                    Add(_enumerable->GetEnumerator()->Current());
                }
                _enumerable->GetEnumerator()->Reset();
                return *this;
            }

            template <typename Item>
            Item& List<Item>::operator[](const int _index)
            {
                if (_index < 0 || _index > mCount) throw OutOfRange("[List] out of range");
                return mTab[_index];
            }

            template <typename Item>
            Item& List<Item>::operator[](const int _index) const
            {
                if (_index < 0 || _index > mCount) throw OutOfRange("[List] out of range");
                return mTab[_index];
            }
#pragma endregion operator
        }
    }
}
