#ifndef STACK_H
#define STACK_H
#include "node.hpp"

template <typename T>
class Stack
{
private:
    int count;
    Node<T> *top;

public:
    Stack();
    bool IsEmpty();
    T Top();
    void Push(T val);
    void Pop();
    int size();
    ~Stack();
};

template <typename T>
Stack<T>::Stack() : count(0), top(nullptr)
{
}

template <typename T>
Stack<T>::~Stack()
{
    delete top;
}

template <typename T>
T Stack<T>::Top()
{
    return top->Value;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return count <= 0;
}

template <typename T>
void Stack<T>::Push(T val)
{

    Node<T> *node = new Node<T>(val);
    node->Next = top;
    top = node;
    count++;
}

template <typename T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        return;
    Node<T> *node = top;
    top = top->Next;
    node->Next = nullptr;
    delete node;
    count--;
}

template <typename T>
int Stack<T>::size()
{
    return count;
}

#endif