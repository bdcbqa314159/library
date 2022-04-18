#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include "queue.hpp"

class Sorting
{

protected:
    std::vector<int> u;

public:
    Sorting(std::vector<int> u);
    void Show();
    virtual void Sort() = 0;
    virtual ~Sorting();
};

class BubbleSort : public Sorting
{
public:
    BubbleSort(std::vector<int> u);
    void Sort() override;
};

class SelectionSort : public Sorting
{
public:
    SelectionSort(std::vector<int> u);
    void Sort() override;
};

class InsertionSort : public Sorting
{
public:
    InsertionSort(std::vector<int> u);
    void Sort() override;
};

class MergeSort : public Sorting
{
public:
    MergeSort(std::vector<int> u);
    void Sort() override;
    void Merge(int startIndex, int middleIndex, int endIndex);
    void MergeSortHelper(int startIndex, int endIndex);
};

class QuickSort : public Sorting
{

public:
    QuickSort(std::vector<int> u);
    void Sort() override;
    int Partition(int startIndex, int endIndex);
    void QuickSortHelper(int startIndex, int endIndex);
};

class CountingSort : public Sorting
{
    // We assume a range between 0 to 9;
    std::vector<int> range = std::vector<int>(10, 0);

public:
    CountingSort(std::vector<int> u);
    void Sort() override;
};

class RadixSort : public Sorting
{

    std::vector<Queue<int>> buckets;

public:
    RadixSort(std::vector<int> u);
    void Sort() override;
};

#endif
