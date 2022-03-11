#pragma once
#include "../../../System/Object/Object.h"
#include "../../../System/PrimaryType/String/String.h"
#include "../../../System/PrimaryType/Integer/Integer.h"
#include "../../../System/Utils/Template/AreTypesEqual.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template<typename Item>
            class LinkedList;
            
            template<typename Item>
            class LinkedListNode sealed : public Object
            {
                static_assert(!AreTypesEqual<Object, Item>::Value, "LinkedListNode value must be an object");
                DECLARE_CLASS_INFO(Object)
                REGISTER_ATTRIBUTE(Sealed)
#pragma region f/p
            private:
                LinkedList<Item>* list = null;
            public:
                
                LinkedListNode<Item>* next = null;
                LinkedListNode<Item>* previous = null;
                Item value = Item();
                LinkedList<Item*> List()const { return this->list; }
#pragma endregion f/p
#pragma region constructor
            public:
                LinkedListNode() = default;
                LinkedListNode(LinkedList<Item>* list, Item value)
                {
                    this->list = list;
                    this->value = value;
                    this->next = null;
                    this->previous = null;
                }
                LinkedListNode(const LinkedListNode& copy)  : Object(copy)
                {
                    this->list = copy.list;
                    this->value = copy.value;
                    this->next = copy.next;
                    this->previous = copy.previous;
                }
                ~LinkedListNode() override = default;
#pragma endregion constructor
#pragma region override
            public:
                String ToString() const override
                {
                    Item item = value;
                    const object* o = reinterpret_cast<object*>(&item);
                    return o->ToString();
                }
                Integer GetHashCode() const override
                {
                    Item item = value;
                    const object* o = reinterpret_cast<object*>(&item);
                    return o->GetHashCode();
                }
#pragma endregion override
#pragma region operator
            public:
                Boolean operator==(const LinkedListNode& other)
                {
                    return this->value == other.value;
                }
                Boolean operator!=(const LinkedListNode& other)
                {
                    return !this->operator==(other);
                }
#pragma endregion operator
            };
        }
    }
}
