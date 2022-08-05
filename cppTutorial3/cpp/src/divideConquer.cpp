#include "../include/cppTutorial3_bits/divideConquer.hpp"
#include <vector>

void merge(vector<int> &a, int s, int e)
{
    int i = s, m = s + (e - s) / 2, j = m + 1;
    vector<int> temp;

    while (i <= m and j <= e)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(a[i++]);
    }
    while (j <= e)
    {
        temp.push_back(a[j++]);
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        a[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &a, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    return merge(a, s, e);
}

int partition(vector<int> &a, int s, int e)
{
    int pivot = a[e], i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(vector<int> &a, int s, int e)
{

    if (s >= e)
        return;

    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int rotatedSearch(vector<int> &a, int k)
{

    int n = a.size(), s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] == k)
            return mid;
        if (a[s] <= a[mid])
        {
            if (k >= a[s] and k <= a[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (k >= a[mid] and k <= a[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}