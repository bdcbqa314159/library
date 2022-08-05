#include "../include/cppTutorial3_bits/sorting.hpp"

void showVector(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int cur = a[i], prev = i - 1;
        while (prev >= 0 && a[prev] > cur)
        {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = cur;
    }
}

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
                pos = j;
        }
        if (i != pos)
            swap(a[pos], a[i]);
    }
}

void countingSort(vector<int> &a)
{
    int M = -1, n = a.size();

    for (int i = 0; i < n; i++)
        M = max(M, a[i]);

    vector<int> buckets(M + 1, 0);

    for (int i = 0; i < n; i++)
        buckets[a[i]]++;

    int j = 0;
    for (int i = 0; i < M + 1; i++)
    {
        while (buckets[i] > 0)
        {
            a[j] = i;
            buckets[i]--;
            j++;
        }
    }
}

void bubbleSortRecursive(vector<int> &a, int n, int j)
{
    if (n == 1)
        return;

    if (j == n - 1)
    {
        return bubbleSortRecursive(a, n - 1, 0);
    }

    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);

    return bubbleSortRecursive(a, n, j + 1);
}