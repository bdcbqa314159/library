#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{

    std::vector<int> heap;
    int heapSize = 0;

    constexpr static int CAPACITY = 10;

public:
    Heap();

    void insert(int item);
    int getMax() const;
    int poll();
    void heapsort();

private:
    void fixUp(int index);
    void fixDown(int index);
    bool isHeapFull() const;
};

#endif