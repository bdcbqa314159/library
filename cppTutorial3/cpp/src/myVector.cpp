#include "../include/cppTutorial3_bits/myVector.hpp"
#include <iostream>
using namespace std;

myVector::myVector(int maxSize) : size(0), capacity(maxSize)
{
    data = new int[maxSize];
}

myVector::~myVector()
{
    delete[] data;
}

void myVector::push_back(int element)
{
    if (size == capacity)
    {
        int *oldData = data;
        capacity *= 2;
        data = new int[capacity];
        for (int i = 0; i < size; i++)
            data[i] = oldData[i];
        delete[] oldData;
    }

    data[size] = element;
    size++;
}

bool myVector::isEmpty()
{
    return size == 0;
}

void myVector::pop_back()
{
    if (isEmpty())
        return;
    size--;
    return;
}

int myVector::front()
{
    if (isEmpty())
    {
        cout << "WARNING: container is empty" << endl;
        return INT_MAX;
    }
    return data[0];
}

int myVector::back()
{
    if (isEmpty())
    {
        cout << "WARNING: container is empty" << endl;
        return INT_MAX;
    }
    return data[size - 1];
}

int myVector::at(int i)
{
    if (isEmpty())
    {
        cout << "WARNING: container is empty" << endl;
        return INT_MAX;
    }
    if (i < 0 || i >= size)
    {
        cout << "WARNING: out of bounds" << endl;
        return INT_MAX;
    }
    return data[i];
}

int myVector::operator[](int i)
{
    if (isEmpty())
    {
        cout << "WARNING: container is empty" << endl;
        return INT_MAX;
    }
    if (i < 0 || i >= size)
    {
        cout << "WARNING: out of bounds" << endl;
        return INT_MAX;
    }
    return data[i];
}

int myVector::getSize()
{
    return size;
}

int myVector::getCapacity()
{
    return capacity;
}

void myVector::show()
{
    if (isEmpty())
    {
        cout << "WARNING: container is empty" << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        cout << data[i] << " ";

    cout << endl;
}
