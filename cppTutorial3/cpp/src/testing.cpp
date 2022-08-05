#include "../include/cppTutorial3_bits/testing.hpp"

using namespace std;

void intFindInterface(int index, int value)
{
    if (index == -1)
        cout << "\nSorry the value " << value << " is NOT found " << endl;
    else
        cout
            << "\nGREAT! the value " << value << " is in the index " << index << endl;
}

void testingLinearSearch()
{

    int arr[] = {2, 54, 9, -1, 3, 90, 100};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    int counter = 4;

    while (true)
    {
        if (counter == 0)
            break;

        cout << "\nGive a key for testing linear search >> ";
        cin >> key;

        int index = linearSearch(arr, n, key);
        intFindInterface(index, key);

        counter--;
    }

    cout << "\nAll good, goodbye." << endl;
}

void testingBinarySearch()
{

    int arr[] = {12, 34, 59, 100, 789, 1234, 4523};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    int counter = 4;

    while (true)
    {
        if (counter == 0)
            break;

        cout << "\nGive a key for testing binary search >> ";
        cin >> key;

        int index = binarySearch(arr, n, key);
        intFindInterface(index, key);

        counter--;
    }

    cout << "\nAll good, goodbye." << endl;
}

void testingReverse()
{

    int arr[] = {-1, 23, 42, 104, 7, 34, 52};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    cout << "Reversing the array:" << endl;

    reverse(arr, n);

    cout << "Showing the array after the reversing: " << endl;
    showArray(arr, n);

    cout << "\nAll good, goodbye." << endl;
}

void testingPrintingPairs()
{

    int arr[] = {-1, 23, 42, 104, 7, 34, 52};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    printingPairs(arr, n);

    cout << "\nAll good, goodbye." << endl;
}

void testingPrintingSubarrays()
{

    int arr[] = {-1, 23, 42, 104, 7, 34, 52};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    printingSubarrays(arr, n);

    cout << "\nAll good, goodbye." << endl;
}

void testingMaxSubarrays()
{
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 2, 3};
    int n = sizeof(arr) / sizeof(int), key = 0;

    cout << "Showing the array first: " << endl;
    showArray(arr, n);

    cout << "testing with brute force approach -> O(n^3):" << endl;
    cout << "Answer: " << maxSubarrayVersion1(arr, n) << endl;

    cout << "testing with the approach I learnt from leetcode -> O(n):" << endl;
    cout << "Answer: " << maxSubarrayVersion2(arr, n) << endl;

    cout << "testing with the approach of prefix sum -> O(n^2):" << endl;
    cout << "Answer: " << maxSubarrayVersion3(arr, n) << endl;

    cout << "testing with the approach of Kadane's Algorithm -> O(n):" << endl;
    cout << "Answer: " << maxSubarrayVersion4(arr, n) << endl;

    cout << "\nAll good, goodbye." << endl;
}

void testingBubbleSort()
{
    vector<int> a{-2, 3, 4, -1, 5, -12, 6, 2, 3};

    cout << "Showing the vector first: " << endl;
    showVector(a);

    cout << "Now Sorting.." << endl;
    bubbleSort(a);

    cout << "Showing the vector sorted via bubble sort: " << endl;
    showVector(a);

    cout << "\nAll good, goodbye." << endl;

    vector<int> b{-2, 3, 12, -1, 5, -12, 6, 90, 3};

    cout << "Showing the vector first: " << endl;
    showVector(b);

    int n = b.size();
    cout << "Now Sorting.." << endl;
    bubbleSortRecursive(b, n, 0);

    cout << "Showing the vector sorted via bubble sort recursive: " << endl;
    showVector(b);

    cout << "\nAll good, goodbye." << endl;
}

void testingInsertionSort()
{
    vector<int> a{-2, 3, 4, -1, 5, -12, 6, 2, 3};

    cout << "Showing the vector first: " << endl;
    showVector(a);

    cout << "Now Sorting.." << endl;
    insertionSort(a);

    cout << "Showing the vector sorted via insertion sort: " << endl;
    showVector(a);

    cout << "\nAll good, goodbye." << endl;
}

void testingSelectionSort()
{
    vector<int> a{-2, 3, 4, -1, 5, -12, 6, 2, 3};

    cout << "Showing the vector first: " << endl;
    showVector(a);

    cout << "Now Sorting.." << endl;
    selectionSort(a);

    cout << "Showing the vector sorted via selection sort: " << endl;
    showVector(a);

    cout << "\nAll good, goodbye." << endl;
}

void testingCountingSort()
{

    cout << "In counting sort we work with arange of integers to sort." << endl;

    vector<int> a{0, 90, 23, 140, 2, 4, 6, 0, 3, 3, 2, 9};

    cout << "Showing the vector first: " << endl;
    showVector(a);

    cout << "Now Sorting.." << endl;
    countingSort(a);

    cout << "Showing the vector sorted via counting sort: " << endl;
    showVector(a);

    cout << "\nAll good, goodbye." << endl;
}
/*
Very important!

if int arr[n];
sort(arr, arr+n)

if vector<int> arr(n);
sort(arr.begin(),arr.end())

and

bool compare(int a, int b){
    return a<b;
}

sort(arr, arr+n, compare);

reverse(arr, arr+n);

AND:
sort(arr, arr+n, greater<int>())  //reverse -> min heaps!

*/