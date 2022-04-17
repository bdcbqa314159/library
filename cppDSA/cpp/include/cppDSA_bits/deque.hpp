#ifndef DEQUE_H
#define DEQUE_H
#include "node.hpp"

template <typename T>
class Deque
{
private:
    int count;
    DoublyNode<T> *front;
    DoublyNode<T> *back;

public:
    Deque();
    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val);
    void EnqueueBack(T val);
    void DequeueFront();
    void DequeueBack();
    int size();
    ~Deque();
};

template <typename T>
Deque<T>::Deque() : count(0), front(nullptr), back(nullptr)
{
}

template <typename T>
Deque<T>::~Deque()
{
    delete front;
}

template <typename T>
int Deque<T>::size()
{
    return count;
}

template <typename T>
bool Deque<T>::IsEmpty()
{
    return count <= 0;
}

template <typename T>
T Deque<T>::Back()
{
    return back->Value;
}

template <typename T>
T Deque<T>::Front()
{
    return front->Value;
}

template <typename T>
void Deque<T>::EnqueueFront(T val)
{
    DoublyNode<T> *node = new DoublyNode<T>(val);

    node->Next = front;

    if (front)
        front->Previous = node;

    front = node;
    if (count == 0)
        back = front;
    count++;
}

template <typename T>
void Deque<T>::EnqueueBack(T val)
{
    if (count == 0)
    {
        EnqueueFront(val);
        return;
    }

    DoublyNode<T> *node = new DoublyNode<T>(val);
    back->Next = node;
    node->Previous = back;
    back = node;
    count++;
    return;
}

template <typename T>
void Deque<T>::DequeueFront()
{
    if (count == 0)
        return;
    DoublyNode<T> *node = front;
    front = front->Next;
    node->Next = nullptr;
    delete node;

    if (front)
        front->Previous = nullptr;
    count--;
    return;
}

template <typename T>
void Deque<T>::DequeueBack()
{
    if (count == 0)
        return;
    if (count == 1)
    {
        DequeueFront();
        return;
    }

    DoublyNode<T> *node = back;
    back = back->Previous;
    back->Next = nullptr;
    node->Next = nullptr;
    node->Previous = nullptr;
    delete node;

    count--;
    return;
}

#endif