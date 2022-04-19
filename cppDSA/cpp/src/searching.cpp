#include "../include/cppDSA_bits/searching.hpp"

int LinearSearch(std::vector<int> &u, int startIndex, int endIndex, int val)
{

    for (int i = startIndex; i < endIndex; i++)
    {
        if (u.at(i) == val)
            return i;
    }

    return -1;
}

int BinarySearch(std::vector<int> &u, int startIndex, int endIndex, int val)
{

    if (startIndex <= endIndex)
    {
        int middleIndex = startIndex + (endIndex - startIndex) / 2;
        if (u[middleIndex] == val)
            return middleIndex;
        else if (u[middleIndex] < val)
            return BinarySearch(u, middleIndex + 1, endIndex, val);
        else
            return BinarySearch(u, startIndex, middleIndex - 1, val);
    }
    return -1;
}

int TernarySearch(std::vector<int> &u, int startIndex, int endIndex, int val)
{

    if (startIndex <= endIndex)
    {
        int middleLeftIndex = startIndex + (endIndex - startIndex) / 3;
        int middleRightIndex = middleLeftIndex + (endIndex - startIndex) / 3;

        if (u.at(middleLeftIndex) == val)
            return middleLeftIndex;
        else if (u.at(middleRightIndex) == val)
            return middleRightIndex;
        else if (u.at(middleLeftIndex) > val)
            return TernarySearch(u, startIndex, middleLeftIndex - 1, val);
        else if (u.at(middleRightIndex) < val)
            return TernarySearch(u, middleRightIndex + 1, endIndex, val);
        else
            return TernarySearch(u, middleLeftIndex + 1, middleRightIndex - 1, val);
    }

    return -1;
}

int InterpolationSearch(std::vector<int> &u, int lowIndex, int highIndex, int val)
{

    if (lowIndex <= highIndex)
    {
        int middleIndex = lowIndex + (val - u[lowIndex]) * (highIndex - lowIndex) / (u[highIndex] - u[lowIndex]);
        if (u[middleIndex] == val)
            return middleIndex;
        else if (u[middleIndex] < val)
            return InterpolationSearch(u, middleIndex + 1, highIndex, val);
        else
            return InterpolationSearch(u, lowIndex, middleIndex - 1, val);
    }
    return -1;
}

int JumpSearch(std::vector<int> &u, int lowIndex, int highIndex, int val)
{

    int N = u.size();
    if (N <= 0)
        return -1;

    int step = std::sqrt(N);
    int blockIndex = 0;

    while (blockIndex < N && u[blockIndex] < val)
    {
        blockIndex += step;
    }

    return LinearSearch(u, blockIndex - step, std::min(blockIndex, N), val);
}

int ExponentialSearch(std::vector<int> &u, int lowIndex, int highIndex, int val)
{

    int N = u.size();
    if (N <= 0)
        return -1;

    int blockIndex = 1;
    while (blockIndex < N && u[blockIndex] < val)
        blockIndex *= 2;

    return BinarySearch(u, blockIndex / 2, std::min(blockIndex, N), val);
}

bool CompareAllMatchedElements(Node<int> *ptr1, Node<int> *ptr2)
{
    if (ptr1 && !ptr2)
        return false;
    if (!ptr1)
        return true;

    if (ptr1->Value == ptr2->Value)
        return CompareAllMatchedElements(ptr1->Next, ptr2->Next);
    else
        return false;
}

bool SubListSearch(Node<int> *firstList, Node<int> *secondList)
{
    if (firstList == nullptr && secondList == nullptr)
        return true;

    if ((firstList != nullptr && secondList == nullptr) || (firstList == nullptr && secondList != nullptr))
        return false;

    if (firstList->Value == secondList->Value)
    {
        if (CompareAllMatchedElements(firstList, secondList))
            return true;
    }

    return SubListSearch(firstList, secondList->Next);
}