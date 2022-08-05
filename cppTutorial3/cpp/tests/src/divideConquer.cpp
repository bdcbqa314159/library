#include <cppTutorial3>
#include <iostream>

using namespace std;

void testingMergeSort()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0, e = arr.size() - 1;
    mergeSort(arr, s, e);

    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

void testingQuickSort()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0, e = arr.size();
    quickSort(arr, s, e - 1);

    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

void testingRotatedArray()
{
    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    int s = 0, e = arr.size() - 1;
    cout << "key? >>";
    int key;
    cin >> key;
    cout << rotatedSearch(arr, key) << endl;
}

int main()
{

    cout << "Hey bit divide & conquer" << endl;
    cout << "Sorting with merge sort" << endl;
    testingMergeSort();
    cout << "Sorting with quick sort" << endl;
    testingQuickSort();
    cout << "Rotated array search" << endl;
    testingRotatedArray();
    return 0;
}