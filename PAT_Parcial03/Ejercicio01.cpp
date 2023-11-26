#include "Ejercicio01.h"
#include <iostream>
#include <unordered_map>
#include <map>

Node<int>* mergeSortedLists(Node<int>* l1, Node<int>* l2)
{
    Node<int> header{ 0 };
    Node<int>* current = &header;

    while (l1 != nullptr && l2 != nullptr) 
    {
        if (l1->value > l2->value) 
        {
            current->next = l1;
            l1 = l1->next;
        }
        else 
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != nullptr) 
    {
        current->next = l1;
    }
    else
    {
        current->next = l2;
    }

    return header.next;  
}

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    if (lists == nullptr) {
        return nullptr;
    }

    while (lists->next != nullptr) {
        lists->value = mergeSortedLists(lists->value, lists->next->value);
        lists->next = lists->next->next;
    }

    return lists->value;
}
