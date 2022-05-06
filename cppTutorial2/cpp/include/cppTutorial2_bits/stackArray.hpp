#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <memory>

template <class t_Data>
class StackArray
{
    t_Data *stack = nullptr;
    int numberOfItems = 0;
    int capacity = 0;

public:
    StackArray()
    {
        stack = new t_Data[1];
        capacity = 1;
    }

    ~StackArray()
    {
        delete[] stack;
    }

    void push(const t_Data &item)
    {
        if (numberOfItems == capacity)
            resize(2 * capacity);

        stack[numberOfItems++] = item;
    }

    t_Data pop()
    {
        if (isEmpty())
            throw std::out_of_range("Stack is empty");

        t_Data itemToPop = stack[--numberOfItems];
        if (numberOfItems > 0 && numberOfItems == capacity / 4)
            resize(capacity / 2);

        return itemToPop;
    }

    bool isEmpty() const
    {
        return numberOfItems == 0;
    }

    int size() const
    {
        return numberOfItems;
    }

    void resize(int capacity)
    {
        t_Data *stackCopy = new t_Data[capacity];

        for (int i = 0; i < numberOfItems; i++)
            stackCopy[i] = stack[i];

        delete[] stack;
        stack = stackCopy;
        this->capacity = capacity;
    }
};

#endif