﻿#pragma once
#include "../../../System.Collections.Generic/List/List.h"
#include "../../Exception/OutOfRange/OutOfRange.h"
#include "../../Interface/Cloneable/ICloneable.h"
#include "../../Object/Object.h"
#include "../Boolean/Boolean.h"
#include "../String/String.h"
#include "../Integer/Integer.h"

namespace System
{
    template <typename Item>
    class Array sealed : public Object, public ICloneable<Array<Item>>, public Collections::Generic::IEnumerator<Item>, public Collections::Generic::IEnumerable<Item>
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed | PrimaryType | ArrayType)
#pragma region f/p
    private:
        Item* mItems = new Item[0];
        Item mCurrentItem = Item();
        int mCount = 0;
        int mCurrentIndex = -1;
        
    public:
        Integer Count() const;
#pragma endregion f/p
#pragma region constructor
    public:
        Array() = default;

        Array(std::size_t _count);

        Array(Collections::Generic::List<Item> _tab);

        Array(std::initializer_list<Item> tab);

        Array(const Array& _copy);
#pragma endregion constructor
#pragma region custom methods
    public:
        static void Clear(Array& _array, const int _count);
        static void Clear(Array& _array, int _index, int _length);
        void Clear(const int _newCount);
        void InsertAt(const Integer& index, const Item& item);
        Collections::Generic::List<Item> ToList();
#pragma endregion custom methods
#pragma region override methods
#pragma region object
        Boolean Equals(const object* _obj) override;
        Boolean Equals(const object& _obj) override;
        Integer GetHashCode() const override;
        String ToString() const override;
#pragma endregion object
#pragma region ICloneable
        Array<Item>* Clone() override;
#pragma endregion ICloneable
#pragma region Enumerator
        Item Current() override;
        bool MoveNext() override;
        void Reset() override;
        Collections::Generic::IEnumerator<Item>* GetEnumerator() override;
#pragma endregion Enumerator
#pragma endregion override methods
#pragma region operator
        Item& operator[](const int& _index)const;
        Array operator=(const Array& other);
#pragma endregion operator
    };
#pragma region f/p
    template <typename Item>
    System::Integer Array<Item>::Count() const
    {
        return mCount;
    }

#pragma endregion f/p
#pragma region constructor
    template <typename Item>
    Array<Item>::Array(std::size_t _count)
    {
        mItems = new Item[_count];
        mCount = _count;
    }

    template <typename Item>
    Array<Item>::Array(Collections::Generic::List<Item> _tab)
    {
        const int _count = _tab.Count();
        mItems = new Item[_count];
        mCount = _count;
        for (int i = 0; i < _count; ++i)
            mItems[i] = _tab[i];
    }

    template <typename Item>
    Array<Item>::Array(std::initializer_list<Item> tab)
    {
        const int _count = tab.size();
        mItems = new Item[_count];
        mCount = _count;
        int index = 0;
        for (const Item& item : tab)
            mItems[index++] = item;
    }

    template <typename Item>
    Array<Item>::Array(const Array& copy) : Object(copy)
    {
        mItems = std::move(copy.mItems);
        mCount = std::move(copy.mCount);
    }
#pragma endregion constructor
#pragma region custom methods
    template <typename Item>
    void Array<Item>::Clear(Array& _array, const int _count)
    {
        delete[] _array.mItems;
        _array.mItems = new Item[_count];
        _array.mCount = _count;
    }

    template <typename Item>
    void Array<Item>:: Clear(Array& _array, int _index, int _length)
    {
        
    }

    template <typename Item>
    void Array<Item>::Clear(const int _newCount)
    {
        delete[] mItems;
        mItems = new Item[_newCount];
        mCount = _newCount;
    }

    template <typename Item>
    void Array<Item>::InsertAt(const Integer& index, const Item& item)
    {
            if (index < 0 || index > mCount)
                throw OutOfRange("[Array] => out of range !");
        this->mItems[index] = item;
    }

    template <typename Item>
    Collections::Generic::List<Item> Array<Item>::ToList()
    {
        Collections::Generic::List<Item> result = Collections::Generic::List<Item>();
        for (int32 i = 0; i < mCount; i++)
            result.Add(mItems[i]);
        return result;
    }
#pragma endregion custom methods
#pragma region override
#pragma region object
    template <typename Item>
    Boolean Array<Item>::Equals(const object* object)
    {
        const Array& _array = *static_cast<const Array*>(object);
        return mCount == _array.mCount && mItems == _array.mItems;
    }

    template <typename Item>
    Boolean Array<Item>::Equals(const object& object)
    {
        const Array& _array = *static_cast<const Array*>(&object);
        return mCount == _array.mCount && mItems == _array.mItems;
    }

    template <typename Item>
    System::Integer Array<Item>::GetHashCode() const
    {
        int result = 0;
        for (int32 i = 0; i < mCount; ++i)
        {
            object* o = reinterpret_cast<object*>(&mItems[i]);
            if (!o)continue;
            result += o->GetHashCode();
        }
        return result;
    }

    template <typename Item>
    String Array<Item>::ToString() const
    {
        string _result = string::Empty;
        for (int i = 0; i < mCount; ++i)
        {
            const Type * type = reinterpret_cast<Type*>(&mItems[i]);
            _result += type->ToString() + " ";
        }
        return _result;
    }
#pragma endregion object
#pragma region Enumerator
    template <typename Item>
    Item Array<Item>::Current()
    {
        return mCurrentItem;
    }

    template <typename Item>
    bool Array<Item>::MoveNext()
    {
        if (++mCurrentIndex >= mCount) return false;
        mCurrentItem = mItems[mCurrentIndex];
        return true;
    }

    template <typename Item>
    void Array<Item>::Reset()
    {
        mCurrentIndex = -1;
    }

    template <typename Item>
    Collections::Generic::IEnumerator<Item>* Array<Item>::GetEnumerator()
    {
        return this;
    }
#pragma endregion Enumerator
#pragma region ICloneable
    template <typename Item>
    Array<Item>* Array<Item>::Clone()
    {
        return new Array(*this);
    }
#pragma endregion ICloneable
#pragma endregion override
#pragma region operator
    template <typename Item>
    Item& Array<Item>::operator[](const int& _index) const
    {
        if (_index < 0 || _index > mCount)
            throw OutOfRange("[Array] => out of range !");
        return mItems[_index];
    }

    template <typename Item>
    Array<Item> Array<Item>::operator=(const Array& other)
    {
        mCount = std::move(other.mCount);
        mItems = std::move(other.mItems);
        mCurrentIndex = std::move(other.mCurrentIndex);
        mCurrentItem = std::move(other.mCurrentItem);
        return *this;
    }
#pragma endregion operator
}
