#include "../include/cppTutorial3_bits/arrays.hpp"
using namespace std;

void showArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int linearSearch(int *arr, int n, int key)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int binarySearch(int *arr, int n, int key)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return -1;
}

void reverse(int *arr, int n)
{

    int s = 0, e = n - 1;
    while (s < e)
    {

        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void printingPairs(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

void printingSubarrays(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int maxSubarrayVersion1(int *arr, int n)
{
    int maxSub = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int k = i; k <= j; k++)
                currSum += arr[k];

            maxSub = max(currSum, maxSub);
        }
    }
    return maxSub;
}

int maxSubarrayVersion2(int *arr, int n)
{
    int curr = arr[0], total = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr = max(curr + arr[i], arr[i]);
        total = max(total, curr);
    }

    return total;
}

int maxSubarrayVersion3(int *arr, int n)
{
    int maxSub = INT_MIN;
    int *ps = new int[n];
    ps[0] = arr[0];
    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum;
            if (i > 0)
                currSum = ps[j] - ps[i - 1];
            else
                currSum = ps[j];

            maxSub = max(currSum, maxSub);
        }
    }
    delete[] ps;
    return maxSub;
}

int maxSubarrayVersion4(int *arr, int n)
{
    int curr = 0, total = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr < 0)
            curr = 0;

        total = max(total, curr);
    }

    return total;
}