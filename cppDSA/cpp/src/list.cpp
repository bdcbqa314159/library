#include "../include/cppDSA_bits/list.hpp"

List::List() : count(0)
{
    items = nullptr;
}

int List::Get(int index)
{
    if (index < 0 || index > count)
        return -1;
    return items[index];
}

void List::Insert(int index, int val)
{

    if (index < 0 || index > count)
        return;

    int *oldArray = items;
    count++;
    items = new int[count];

    for (int i = 0, j = 0; i < count; ++i)
    {
        if (index == i)
            items[i] = val;
        else
        {
            items[i] = oldArray[j];
            ++j;
        }
    }

    delete[] oldArray;
}

int List::Search(int val)
{
    for (int i = 0; i < count; ++i)
    {
        if (items[i] == val)
            return i;
    }
    return -1;
}

void List::Remove(int index)
{
    if (index < 0 || index > count)
        return;

    int *oldArray = items;
    count--;

    items = new int[count];

    for (int i = 0, j = 0; i < count; ++i, ++j)
    {

        if (index == j)
            ++j;

        items[i] = oldArray[j];
    }

    delete[] oldArray;
}

int List::Count()
{
    return count;
}

List::~List()
{

    delete[] items;
}