#ifndef NODE_H
#define NODE_H
#include <iostream>

// class Node
// {
// public:
//     int Value;
//     Node *Next;
// };
// void PrintNode(Node *node);

template <typename T>
class Node
{
public:
    T Value;
    Node<T> *Next;

    Node(T value) : Value(value) {}

    ~Node()
    {
        // std::cout << Value << std::endl;
        delete Next;
    }
};

template <typename T>
class DoublyNode
{
public:
    T Value;
    DoublyNode<T> *Previous;
    DoublyNode<T> *Next;

    DoublyNode(T value) : Value(value) {}

    ~DoublyNode()
    {
        // std::cout << Value << std::endl;
        delete Next;
    }
};

template <typename T>
void PrintNode(Node<T> *node)
{
    while (node)
    {
        std::cout << node->Value << " -> ";
        node = node->Next;
    }
    std::cout << "NULL" << std::endl;
}

#endif