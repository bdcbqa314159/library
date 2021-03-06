#include "../include/cppTutorial2_bits/heap.hpp"
#include <iostream>
#include <algorithm>

Heap::Heap()
{
    heap.resize(CAPACITY);
}

void Heap::insert(int item)
{
    if (isHeapFull())
        throw std::overflow_error("Heap is full...");

    heap[heapSize] = item;
    ++heapSize;
    fixUp(heapSize - 1);
}

int Heap::getMax() const
{
    if (heapSize == 0)
        throw std::length_error("Heap is empty");
    return heap[0];
}

int Heap::poll()
{
    int max = getMax();
    std::swap(heap[0], heap[heapSize - 1]);
    --heapSize;
    fixDown(0);
    return max;
}

void Heap::heapsort()
{
    int size = heapSize;
    for (int i = 0; i < size; i++)
    {
        int max = poll();
        std::cout << max << ' ';
    }
    std::cout << std::endl;
}

void Heap::fixUp(int index)
{
    int parentIndex = (index - 1) / 2;

    if (index > 0 && heap[index] > heap[parentIndex])
    {
        std::swap(heap[index], heap[parentIndex]);
        fixUp(parentIndex);
    }
}

void Heap::fixDown(int index)
{
    int indexLeft = 2 * index + 1;
    int indexRight = 2 * index + 2;

    int indexLargest = index;

    if (indexLeft < heapSize && heap[indexLeft] > heap[index])
        indexLargest = indexLeft;
    if (indexRight < heapSize && heap[indexRight] > heap[indexLargest])
        indexLargest = indexRight;

    if (index != indexLargest)
    {
        std::swap(heap[index], heap[indexLargest]);
        fixDown(indexLargest);
    }
}

bool Heap::isHeapFull() const
{
    return CAPACITY == heapSize;
}
