#ifndef QUEUE_H
#define QUEUE_H
#include <memory>

template <class t_Data>
class Queue
{
    struct Node
    {
        t_Data data;
        std::unique_ptr<Node> nextNode;

        Node(const t_Data &data) : data(data)
        {
        }
    };

    std::unique_ptr<Node> firstNode;
    Node *lastNode = nullptr;

    int count = 0;

public:
    bool isEmpty() const
    {
        return firstNode == nullptr;
    }

    int size() const
    {
        return count;
    }

    void enqueue(const t_Data &newData)
    {
        ++count;

        Node *oldLastNode = lastNode;
        auto newLastNode = std::make_unique<Node>(newData);
        lastNode = newLastNode.get();

        if (isEmpty())
            firstNode = std::move(newLastNode);
        else
            oldLastNode->nextNode = std::move(newLastNode);
    }

    t_Data dequeue()
    {
        if (isEmpty())
            throw std::out_of_range("Queue is empty");
        --count;

        t_Data dataToDequeue = std::move(firstNode->data);
        std::unique_ptr<Node> temp = std::move(firstNode->nextNode);
        firstNode = std::move(temp);

        if (isEmpty())
            lastNode = nullptr;
        return dataToDequeue;
    }
};

#endif