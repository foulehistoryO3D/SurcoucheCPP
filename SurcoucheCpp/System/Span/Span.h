#pragma once
#include "../Exception/IndexOutOfRange/IndexOutOfRangeException.h"
#include "../Object/Object.h"
#include "../PrimaryType/Array/Array.h"

namespace System
{
    template <typename Item>
    class Span sealed : public Object
    {
        DECLARE_CLASS_INFO(Object)
        REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
    private:
        Array<Item> tab = Array<Item>();
    public:
        Integer Length()const;
        Boolean IsEmpty()const;
        static const Span Empty;
#pragma endregion f/p
#pragma region constructor
    public:
        Span()=default;
        Span(Array<Item> items);
        Span(const Span<Item>& copy);
#pragma endregion constructor
#pragma region custom methods
    private:
    public:
        void Clear();
        void CopyTo(Span<Item>& out);
        void Fill(Item item);
        Array<Item> ToArray();
        Span Slice(const Integer& start);
#pragma endregion custom methods
#pragma region override
    public:
        String ToString() const override;
        Integer GetHashCode() const override;
#pragma endregion override
#pragma region operator
    public:
        Span<Item>& operator=(const Span<Item>& other);
        Item operator[](const Integer& index)const;
        Item& operator[](const Integer& index);
#pragma endregion operator
    };
#pragma region f/p

    template<typename Item> Span<Item> const Span<Item>::Empty = Span();
    
    template <typename Item>
    Integer Span<Item>::Length() const
    {
        return tab.Count();
    }

    template <typename Item>
    Boolean Span<Item>::IsEmpty() const
    {
        return tab.Count() == 0;
    }
#pragma endregion f/p
#pragma region custom methods
    template <typename Item>
    Span<Item>::Span(Array<Item> items)
    {
        tab = items;
    }

    template <typename Item>
    Span<Item>::Span(const Span<Item>& copy) : Object(copy)
    {
        this->tab = copy.tab;
    }

    template <typename Item>
    void Span<Item>::Clear()
    {
        tab.Clear();
    }

    template <typename Item>
    void Span<Item>::CopyTo(Span<Item>& out)
    {
        out.tab = tab;
    }

    template <typename Item>
    void Span<Item>::Fill(Item item)
    {
        const int32 length = tab.Count();
        for (int32 i = 0; i < length; ++i)
            tab[i] = item;
    }

    template <typename Item>
    Array<Item> Span<Item>::ToArray()
    {
        return Array<Item>(tab);
    }

    template <typename Item>
    Span<Item> Span<Item>::Slice(const Integer& start)
    {
        const int length = Length();
        const int count = length - start;
        Array<Item> result = Array<Item>(count);
        for (int i = start; i < length; ++i)
            result[i-start] = tab[i];
        result[count] = '\0';
        return result;
    }
#pragma endregion custom methods
#pragma region override
    template <typename Item>
    String Span<Item>::ToString() const
    {
        return tab.ToString();
    }

    template <typename Item>
    Integer Span<Item>::GetHashCode() const
    {
        return tab.GetHashCode();
    }

    template <typename Item>
    Span<Item>& Span<Item>::operator=(const Span<Item>& other)
    {
        this->tab = other.tab;
        return *this;
    }
#pragma endregion override
#pragma region operator
    template <typename Item>
    Item Span<Item>::operator[](const Integer& index) const
    {
        if (index < 0 || index > tab.Count())
            throw IndexOutOfRangeException("invalid index Span !");
        return tab[index];
    }

    template <typename Item>
    Item& Span<Item>::operator[](const Integer& index)
    {
        if (index < 0 || index > tab.Count())
            throw IndexOutOfRangeException("invalid index Span !");
        return tab[index];
    }
#pragma endregion operator
}
