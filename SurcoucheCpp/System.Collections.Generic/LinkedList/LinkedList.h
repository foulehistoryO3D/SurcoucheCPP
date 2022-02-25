#pragma once
#include "../../System/Exception/IndexOutOfRange/IndexOutOfRangeException.h"
#include "../../System/Utils/Template/TemplateMacro.h"
#include "../Interface/List/IList.h"
#include "LinkedListNode/LinkedListNode.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <typename Item>
            class LinkedList sealed : public Object, public ICollection<Item>, public IEnumerable<Item>,
                                      public IEnumerator<Item>
            {
                static_assert(!AreTypesEqual<Object, Item>::Value, "LinkedList Item must be an object");
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                LinkedListNode<Item>* tree = null;
                LinkedListNode<Item>* firstNode = null;
                LinkedListNode<Item>* lastNode = null;
                Item currentItem = Item();
                int count = 0;
                int currentIndex = -1;
            public:
                LinkedListNode<Item>* First() const { return this->firstNode; }
                LinkedListNode<Item>* Last() const { return this->lastNode; }

#pragma endregion f/p
#pragma region constructor
            public:
                LinkedList() = default;

                LinkedList(std::initializer_list<Item> items)
                {
                    for (const Item& item : items)
                        LinkedList::Add(item);
                }

                ~LinkedList() override = default;
#pragma endregion constructor
#pragma region custom methods
            public:
                void AddFirst(LinkedListNode<Item>* node)
                {
                    if (this->tree == null)
                    {
                        this->tree = node;
                        this->lastNode = node;
                    }
                    else
                    {
                        node->next = this->tree;
                        this->tree->previous = node;
                    }

                    this->firstNode = node;
                    count++;
                }

                void AddFirst(Item item)
                {
                    LinkedList::AddFirst(new LinkedListNode<Item>(this, item));
                }

                void AddAfter(LinkedListNode<Item>* node, Item value)
                {
                    LinkedListNode<Item>* currentTree = this->tree;
                    while (currentTree->next != null)
                    {
                        if (currentTree == node)
                            break;
                        currentTree = currentTree->next;
                    }
                    LinkedListNode<Item>* newNode = new LinkedListNode<Item>(this, value);

                    if (currentTree->next)
                        newNode->next = currentTree->next;
                    newNode->previous = currentTree;
                    currentTree->next = newNode;
                    if (newNode->next == null)
                        this->lastNode = newNode;
                    count++;
                }

                void Remove(LinkedListNode<Item>* node)
                {
                    LinkedList::Remove(node->value);
                }

                void RemoveFirst()
                {
                    LinkedList::Remove(First());
                }

                void RemoveLast()
                {
                    LinkedList::Remove(Last());
                }

                void CopyTo(Array<Item>& out, const Integer& index)
                {
                    LinkedListNode<Item>* currentTree = this->tree;
                    out = Array<Item>(this->count - index);
                    int currentIndex = 0;
                    for (int i = 0; i < index; ++i)
                        currentTree = currentTree->next;
                    for (int i = index; i < count; ++i)
                    {
                        if (currentTree == null) return;
                        out.InsertAt(currentIndex++, currentTree->value);
                        currentTree = currentTree->next;
                    }
                }
#pragma endregion custom methods
#pragma region override
            public:
                Item Current() override { return this->currentItem; }
                bool MoveNext() override { return false; }
                void Reset() override { this->currentIndex = -1; }
                IEnumerator<Item>* GetEnumerator() override { return this; }

                Integer Count() const override { return this->count; }

                void Add(Item _item) override
                {
                    if (this->tree == null)
                        LinkedList::AddFirst(_item);
                    else
                        LinkedList::AddAfter(this->lastNode, _item);
                }

                void Clear() override
                {
                    delete this->tree;
                    this->tree = null;
                    this->firstNode = null;
                    this->lastNode = null;
                }

                bool Contains(Item _item) override { return false; }

                void Remove(Item _item) override
                {
                    LinkedListNode<Item>* currentTree = this->tree;
                    LinkedListNode<Item>* previous = null;
                    if (currentTree && currentTree->value == _item)
                    {
                        this->tree = currentTree->next;
                        delete currentTree;
                        return;
                    }
                    while (currentTree != null && currentTree->value != _item)
                    {
                        previous = currentTree;
                        currentTree = currentTree->next;
                    }
                    if (currentTree == null) return;
                    previous->next = currentTree->next;
                    previous->previous = currentTree->previous;

                    delete currentTree;
                    count--;
                }

                String ToString() const override
                {
                    string result = string::Empty;
                    for (Item item : *this)
                    {
                        object* o = reinterpret_cast<object*>(&item);
                        if (!o)continue;
                        result += o->ToString() + " ";
                    }
                    return result;
                }

                Integer GetHashCode() const override
                {
                    return ToString().GetHashCode();
                }
#pragma endregion override
#pragma region operator
            public:
                Item& operator[](const Integer& index)
                {
                    if (index < 0 || index >= this->count)
                        throw IndexOutOfRangeException("Linkedlist invalid index !");

                    LinkedListNode<Item>* currentTree = this->tree;
                    for (int i = 0; i < index; ++i)
                        currentTree = currentTree->next;
                    if (currentTree == null)
                        throw OutOfRange("Index out of range");
                    return currentTree->value;
                }
#pragma endregion operator
                class LinkedListIterator sealed
                {
                    friend class LinkedList;
#pragma region f/p
                private:
                    LinkedListNode<Item>* nodePtr = null;
#pragma endregion f/p
#pragma region constructor
                public:
                    LinkedListIterator() = default;

                    LinkedListIterator(LinkedListNode<Item>* newPtr) : nodePtr(newPtr)
                    {
                    }
#pragma endregion constructor
#pragma region operator
                public:
                    bool operator!=(const LinkedListIterator& itr) const
                    {
                        return nodePtr != itr.nodePtr;
                    }

                    Item& operator*() const
                    {
                        return nodePtr->value;
                    }

                    LinkedListIterator operator++(int)
                    {
                        LinkedListIterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    LinkedListIterator& operator++()
                    {
                        nodePtr = nodePtr->next;
                        return *this;
                    }
#pragma endregion operator
                };

                LinkedListIterator begin() const { return LinkedListIterator(this->firstNode); }
                LinkedListIterator end() const { return LinkedListIterator(nullptr); }
            };
        }
    }
}
