#ifndef QUEUE_H
#define QUEUE_H
#include "node.hpp"

template <typename T>
class Queue
{
private:
    int count;
    Node<T> *front;
    Node<T> *back;

public:
    Queue();
    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
    int size();
    ~Queue();
};

template <typename T>
Queue<T>::Queue() : count(0), front(nullptr), back(nullptr)
{
}

template <typename T>
Queue<T>::~Queue()
{
    delete front;
    front = nullptr;
}

template <typename T>
T Queue<T>::Front()
{
    return front->Value;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
    return count <= 0;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
    Node<T> *node = new Node<T>(val);
    if (count == 0)
    {
        node->Next = nullptr;
        front = node;
        back = front;
    }

    else
    {
        back->Next = node;
        back = node;
    }

    count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
    if (IsEmpty())
        return;
    Node<T> *node = front;
    front = front->Next;
    node->Next = nullptr;
    delete node;
    count--;
}

template <typename T>
int Queue<T>::size()
{
    return count;
}

#endif