#include "../include/cppDSA_bits/sorting.hpp"
#include <iostream>

Sorting::Sorting(std::vector<int> u) : u(u)
{
}

Sorting::~Sorting()
{
}

void Sorting::Show()
{
    for (int i = 0; i < u.size(); i++)
        std::cout << u.at(i) << " ";
    std::cout << std::endl;
}

BubbleSort::BubbleSort(std::vector<int> u) : Sorting(u)
{
}

void BubbleSort::Sort()
{
    bool isSwapped;

    int unsortedElements = u.size();
    do
    {
        isSwapped = false;
        for (int i = 0; i < unsortedElements - 1; i++)
        {
            if (u[i] > u[i + 1])
            {
                std::swap(u[i], u[i + 1]);
                isSwapped = true;
            }
        }
        unsortedElements--;
    } while (isSwapped);
}

SelectionSort::SelectionSort(std::vector<int> u) : Sorting(u)
{
}

void SelectionSort::Sort()
{
    int minIndex;
    for (int i = 0; i < u.size() - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < u.size(); j++)
        {
            if (u.at(j) < u.at(minIndex))
                minIndex = j;
        }
        std::swap(u.at(i), u.at(minIndex));
    }
}

InsertionSort::InsertionSort(std::vector<int> u) : Sorting(u)
{
}

void InsertionSort::Sort()
{

    for (int i = 0; i < u.size(); ++i)
    {
        int refValue = u.at(i);
        int j;

        for (j = i - 1; j >= 0; --j)
        {
            if (u.at(j) > refValue)
                u.at(j + 1) = u.at(j);
            else
                break;
        }
        u.at(j + 1) = refValue;
    }
}

MergeSort::MergeSort(std::vector<int> u) : Sorting(u)
{
}

void MergeSort::Merge(int startIndex, int middleIndex, int endIndex)
{
    int totalElements = endIndex - startIndex + 1;
    std::vector<int> *temp = new std::vector<int>(totalElements, 0);
    int leftIndex = startIndex, rightIndex = middleIndex + 1;
    int mergedIndex = 0;

    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if (u.at(leftIndex) <= u.at(rightIndex))
        {
            temp->at(mergedIndex) = u.at(leftIndex);
            leftIndex++;
        }
        else
        {
            temp->at(mergedIndex) = u.at(rightIndex);
            ++rightIndex;
        }
        ++mergedIndex;
    }
    while (leftIndex <= middleIndex)
    {
        temp->at(mergedIndex) = u.at(leftIndex);
        ++leftIndex;
        ++mergedIndex;
    }

    while (rightIndex <= endIndex)
    {
        temp->at(mergedIndex) = u.at(rightIndex);
        ++rightIndex;
        ++mergedIndex;
    }

    for (int i = 0; i < totalElements; ++i)
        u.at(startIndex + i) = temp->at(i);

    delete temp;
    return;
}

void MergeSort::MergeSortHelper(int startIndex, int endIndex)
{

    if (startIndex < endIndex)
    {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;
        MergeSortHelper(startIndex, middleIndex);
        MergeSortHelper(middleIndex + 1, endIndex);
        Merge(startIndex, middleIndex, endIndex);
    }
    return;
}

void MergeSort::Sort()
{
    MergeSortHelper(0, u.size() - 1);
    return;
}

QuickSort::QuickSort(std::vector<int> u) : Sorting(u)
{
}

int QuickSort::Partition(int startIndex, int endIndex)
{
    int pivot = u.at(startIndex);
    int middleIndex = startIndex;

    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (u.at(i) < pivot)
        {
            ++middleIndex;
            std::swap(u.at(i), u.at(middleIndex));
        }
    }
    std::swap(u.at(startIndex), u.at(middleIndex));
    return middleIndex;
}

void QuickSort::QuickSortHelper(int startIndex, int endIndex)
{
    if (startIndex < endIndex)
    {
        int pivotIndex = Partition(startIndex, endIndex);
        QuickSortHelper(startIndex, pivotIndex - 1);
        QuickSortHelper(pivotIndex + 1, endIndex);
    }
    return;
}

void QuickSort::Sort()
{
    QuickSortHelper(0, u.size() - 1);
    return;
}

CountingSort::CountingSort(std::vector<int> u) : Sorting(u)
{
}

void CountingSort::Sort()
{

    int counterSize = range.size();

    for (int i = 0; i < u.size(); i++)
        range.at(u.at(i))++;

    int arrCounter = 0;

    for (int i = 0; i < counterSize; i++)
    {
        while (range.at(i) > 0)
        {
            u.at(arrCounter++) = i;
            --range.at(i);
        }
    }
    return;
}

RadixSort::RadixSort(std::vector<int> u) : Sorting(u)
{
    buckets = std::vector<Queue<int>>(10);
}

void RadixSort::Sort()
{

    int largestElement = u.at(0);
    for (int i = 0; i < u.size(); ++i)
    {
        if (largestElement < u.at(i))
            largestElement = u.at(i);
    }

    for (int exp = 1; largestElement / exp > 0; exp *= 10)
    {
        for (int i = 0; i < u.size(); ++i)
        {
            buckets[(u.at(i) / exp) % 10].Enqueue(u.at(i));
        }

        int arrCounter = 0;
        for (int i = 0; i < 10; ++i)
        {
            while (!buckets.at(i).IsEmpty())
            {
                u.at(arrCounter++) = buckets.at(i).Front();
                buckets.at(i).Dequeue();
            }
            buckets.at(i) = Queue<int>(); // to be able to call the destructor on for the Nodes.
        }
    }
    return;
}
