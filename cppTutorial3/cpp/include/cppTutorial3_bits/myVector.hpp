#ifndef MYVECTOR_H
#define MYVECTOR_H

class myVector
{
    int size;
    int capacity;
    int *data;

public:
    myVector(int maxSize = 1);
    ~myVector();

    bool isEmpty();
    void push_back(int element);
    void pop_back();

    int front();
    int back();
    int at(int i);
    int operator[](int i);
    int getCapacity();
    int getSize();

    void show();
};

#endif