#ifndef QUEUES_H
#define QUEUES_H

class Queue
{

public:
    int *arr;
    int cs, ms, front, rear;

    Queue(int size = 5) : ms(size)
    {

        arr = new int[ms];
        cs = 0;
        front = 0;
        rear = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }

    void push(int data)
    {
        if (full())
            return;

        rear = (rear + 1) % ms;
        arr[rear] = data;
        cs++;
    }

    bool empty()
    {
        return cs == 0;
    }

    void pop()
    {
        if (empty())
            return;
        front = (front + 1) % ms;
        cs--;
    }

    int getFront()
    {
        return arr[front];
    }
};

#endif