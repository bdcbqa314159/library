#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "node.hpp"

template <typename T>
class DoublyLinkedList
{

private:
    int count;

public:
    DoublyNode<T> *Head;
    DoublyNode<T> *Tail;

    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyNode<T> *Get(int index);
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    int Search(T val);

    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count();
    void PrintList();
    void PrintListBackward();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : count(0), Head(nullptr), Tail(nullptr)
{
}

template <typename T>
DoublyNode<T> *DoublyLinkedList<T>::Get(int index)
{
    if (index < 0 || index > count)
        return nullptr;

    DoublyNode<T> *node = Head;
    for (int i = 0; i < index; i++)
        node = node->Next;

    return node;
}

template <typename T>
void DoublyLinkedList<T>::InsertHead(T val)
{
    DoublyNode<T> *node = new DoublyNode<T>(val);
    node->Next = Head;
    if (Head)
        Head->Previous = node;
    Head = node;

    if (count == 0)
        Tail = Head;
    count++;
    return;
}

template <typename T>
void DoublyLinkedList<T>::InsertTail(T val)
{
    if (count == 0)
    {
        InsertHead(val);
        return;
    }
    DoublyNode<T> *node = new DoublyNode<T>(val);
    Tail->Next = node;
    node->Previous = Tail;
    Tail = node;
    count++;
    return;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val)
{
    if (index < 0 || index > count)
        return;
    if (index == 0)
    {
        InsertHead(val);
        return;
    }
    else if (index == count)
    {
        InsertTail(val);
        return;
    }
    DoublyNode<T> *prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;
    DoublyNode<T> *nextNode = prevNode->Next;
    DoublyNode<T> *node = new DoublyNode<T>(val);
    node->Next = nextNode;
    node->Previous = prevNode;
    prevNode->Next = node;
    nextNode->Previous = node;
    count++;
    return;
}

template <typename T>
int DoublyLinkedList<T>::Search(T val)
{
    if (count == 0)
        return -1;
    int index = 0;
    DoublyNode<T> *node = Head;
    while (node->Value != val)
    {
        index++;
        node = node->Next;

        if (node == nullptr)
            return -1;
    }
    return index;
}

template <typename T>
void DoublyLinkedList<T>::RemoveHead()
{
    if (count == 0)
        return;

    DoublyNode<T> *node = Head;
    Head = Head->Next;
    node->Next = nullptr;
    node->Previous = nullptr;
    delete node;

    if (Head)
        Head->Previous = nullptr;

    count--;
    return;
}

template <typename T>
void DoublyLinkedList<T>::RemoveTail()
{
    if (count == 0)
        return;

    if (count == 1)
    {
        RemoveHead();
        return;
    }

    DoublyNode<T> *node = Tail;
    Tail = Tail->Previous;
    Tail->Next = nullptr;
    node->Next = nullptr;
    node->Previous = nullptr;
    delete node;

    count--;
    return;
}

template <typename T>
void DoublyLinkedList<T>::Remove(int index)
{
    if (count == 0)
        return;
    if (index < 0 || index >= count)
        return;
    if (index == 0)
    {
        RemoveHead();
        return;
    }
    else if (index == count - 1)
    {
        RemoveTail();
        return;
    }

    DoublyNode<T> *prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;

    DoublyNode<T> *node = prevNode->Next;
    DoublyNode<T> *nextNode = node->Next;
    prevNode->Next = nextNode;
    nextNode->Previous = prevNode;
    node->Next = nullptr;
    node->Previous = nullptr;
    delete node;
    count--;
    return;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    delete Head;
}

template <typename T>
int DoublyLinkedList<T>::Count()
{
    return count;
}

template <typename T>
void DoublyLinkedList<T>::PrintList()
{
    DoublyNode<T> *node = Head;
    while (node)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << std::endl;
    return;
}

template <typename T>
void DoublyLinkedList<T>::PrintListBackward()
{
    DoublyNode<T> *node = Tail;
    while (node)
    {
        std::cout << node->Value << " -> ";
        node = node->Previous;
    }
    std::cout << "NULL" << std::endl;
    return;
}

#endif