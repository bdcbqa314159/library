#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H
#include <memory>

template <class t_Data>
class StackLinkedList
{
    struct Node
    {
        t_Data data;
        std::unique_ptr<Node> nextNode;

        Node(const t_Data &data) : data(data)
        {
        }
    };

    std::unique_ptr<Node> head;
    int count = 0;

public:
    void push(const t_Data &item)
    {
        if (!head)
        {
            head = std::make_unique<Node>(item);
        }
        else
        {
            std::unique_ptr<Node> oldhead = std::move(head);
            head = std::make_unique<Node>(item);
            head->nextNode = std::move(oldhead);
        }

        ++count;
    }

    t_Data pop()
    {
        if (isEmpty())
            throw std::out_of_range("Stack is empty");

        t_Data itemToPop = head->data;
        std::unique_ptr<Node> temp = std::move(head->nextNode);
        head = std::move(temp);
        --count;

        return itemToPop;
    }

    bool isEmpty() const
    {
        return !head;
    }

    int size() const
    {
        return count;
    }
};

#endif