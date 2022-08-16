#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

template <class T>
class TestTemplate
{
private:
    T obj;

public:
    TestTemplate() : obj(0)
    {
    }

    TestTemplate(T obj) : obj(obj)
    {
    }

    void print()
    {
        std::cout << obj << std::endl;
    }
};

template <typename T>
void myPrintTemplate(T x)
{
    std::cout << x << std::endl;
}

void myPrintTemplate(int value)
{
    std::cout << "Without template" << std::endl;
    std::cout << value << std::endl;
}

/*
Might crush:
show<>()
*/

template <class T>
void show()
{
    std::cout << T() << std::endl;
}

template <class T>
class ring
{

    int pos;
    int size_;
    T *values;

public:
    // Bad practice:
    // class iterator;
    // {
    // public:
    //     void print()
    //     {
    //         std::cout << "Hello from ring iterator" << std::endl;
    //     }
    // };
    // Better:
    class iterator;

public:
    ring(int size) : pos(0), size_(size), values(nullptr)
    {
        values = new T[size_];
    }

    ~ring()
    {
        delete[] values;
    }
    int size() const
    {
        return size_;
    }

    void add(T value)
    {
        values[pos++] = value;

        if (pos == size_)
        {
            pos = 0;
        }
        return;
    }

    T &get(int pos)
    {
        return values[pos];
    }

    iterator begin()
    {
        return iterator(0, *this);
    }

    iterator end()
    {
        return iterator(size_, *this);
    }
};

template <class T>
class ring<T>::iterator
{
    int pos;
    ring &r;

public:
    iterator(int pos, ring &r) : pos(pos), r(r)
    {
    }

    // prefix
    iterator &operator++()
    {
        pos++;
        return *this;
    }

    // postfix
    iterator &operator++(int)
    {
        pos++;
        return *this;
    }

    T &operator*()
    {
        return r.get(pos);
    }

    bool operator!=(const iterator &other) const
    {
        return pos != other.pos;
    }

    bool operator==(const iterator &other) const
    {
        return !(operator!=(other));
    }
};

#endif