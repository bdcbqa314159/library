#include <cppDSA>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {43, 21, 26, 38, 17, 30};
    vector<int> arr1 = {7, 1, 5, 9, 3, 6, 8, 2};

    cout << "Original vector:" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    cout << "====================" << endl;
    cout << "Bubble Sort" << endl;
    cout << "====================" << endl;
    BubbleSort bubble(arr);
    bubble.Show();
    bubble.Sort();
    bubble.Show();

    cout << "====================" << endl;
    cout << "Original vector:" << endl;
    cout << "====================" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    cout << "====================" << endl;
    cout << "Selection Sort" << endl;
    cout << "====================" << endl;
    SelectionSort selection(arr);
    selection.Show();
    selection.Sort();
    selection.Show();

    cout << "====================" << endl;
    cout << "Original vector:" << endl;
    cout << "====================" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    cout << "====================" << endl;
    cout << "Insertion Sort" << endl;
    cout << "====================" << endl;
    InsertionSort insertion(arr);
    insertion.Show();
    insertion.Sort();
    insertion.Show();

    cout << "====================" << endl;
    cout << "Original vector:" << endl;
    cout << "====================" << endl;
    for (auto &x : arr1)
        cout << x << " ";
    cout << endl;

    cout << "====================" << endl;
    cout << "Merge Sort" << endl;
    cout << "====================" << endl;
    MergeSort mergeSort(arr1);
    mergeSort.Show();
    mergeSort.Sort();
    mergeSort.Show();

    cout << "====================" << endl;
    cout << "Quick Sort" << endl;
    cout << "====================" << endl;
    QuickSort quickSort(arr1);
    quickSort.Show();
    quickSort.Sort();
    quickSort.Show();

    cout << "====================" << endl;
    cout << "Counting Sort" << endl;
    cout << "====================" << endl;
    vector<int> arr2 = {9, 6, 5, 6, 1, 7, 2, 4, 3, 5, 7, 7, 9, 6};
    CountingSort countingSort(arr2);
    countingSort.Show();
    countingSort.Sort();
    countingSort.Show();

    cout << "====================" << endl;
    cout << "Radix Sort" << endl;
    cout << "====================" << endl;
    vector<int> arr3 = {429, 3309, 65, 7439, 12, 9954, 30, 4567, 8, 882};
    RadixSort radixSort(arr3);
    radixSort.Show();
    radixSort.Sort();
    radixSort.Show();

    return 0;
}