#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.hpp"

template <typename T>
class LinkedList
{

private:
    int count;

public:
    Node<T> *Head;
    Node<T> *Tail;

    LinkedList();
    ~LinkedList();
    Node<T> *Get(int index);
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    int Search(T val);

    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count();
    void PrintList();
};

template <typename T>
LinkedList<T>::LinkedList() : count(0), Head(nullptr), Tail(nullptr)
{
}

template <typename T>
Node<T> *LinkedList<T>::Get(int index)
{
    if (index < 0 || index > count)
        return nullptr;

    Node<T> *node = Head;
    for (int i = 0; i < index; i++)
        node = node->Next;

    return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    Node<T> *node = new Node<T>(val);
    node->Next = Head;
    Head = node;

    if (count == 0)
        Tail = Head;
    count++;
    return;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    if (count == 0)
    {
        InsertHead(val);
        return;
    }
    Node<T> *node = new Node<T>(val);
    Tail->Next = node;
    Tail = node;
    count++;
    return;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
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
    Node<T> *prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;
    Node<T> *nextNode = prevNode->Next;
    Node<T> *node = new Node<T>(val);
    node->Next = nextNode;
    prevNode->Next = node;
    count++;
    return;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
    if (count == 0)
        return -1;
    int index = 0;
    Node<T> *node = Head;
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
void LinkedList<T>::RemoveHead()
{
    if (count == 0)
        return;

    Node<T> *node = Head;
    Head = Head->Next;
    node->Next = nullptr;
    delete node;
    count--;
    return;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
    if (count == 0)
        return;

    if (count == 1)
    {
        RemoveHead();
        return;
    }
    Node<T> *prevNode = Head;
    Node<T> *node = Head->Next;

    while (node->Next != nullptr)
    {
        prevNode = prevNode->Next;
        node = node->Next;
    }
    prevNode->Next = nullptr;
    Tail = prevNode;
    delete node;
    count--;
    return;
}

template <typename T>
void LinkedList<T>::Remove(int index)
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

    Node<T> *prevNode = Head;
    for (int i = 0; i < index - 1; i++)
        prevNode = prevNode->Next;

    Node<T> *node = prevNode->Next;
    Node<T> *nextNode = node->Next;
    prevNode->Next = nextNode;
    node->Next = nullptr;
    delete node;
    count--;
    return;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    delete Head;
}

template <typename T>
int LinkedList<T>::Count()
{
    return count;
}

template <typename T>
void LinkedList<T>::PrintList()
{
    Node<T> *node = Head;
    while (node)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << std::endl;
    return;
}

#endif