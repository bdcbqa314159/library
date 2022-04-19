#include <cppDSA>
#include <iostream>
#include <vector>

using namespace std;

void Notify(int i, int searchedValue)
{
    if (i != -1)
    {
        cout << searchedValue << " is found in index ";
        cout << i << endl;
    }
    else
    {
        cout << "Could not find value " << searchedValue;
        cout << endl;
    }
    return;
}

void Show(vector<int> &u)
{
    for (auto &x : u)
        cout << x << " ";
    cout << endl;
    return;
}

int main()
{
    cout << "Linear Search" << endl;
    vector<int> arr = {43, 21, 26, 38, 17, 30, 25, 18};
    Show(arr);
    int N = arr.size();
    int searchedValue = 30;
    int i = LinearSearch(arr, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Binary Search" << endl;
    vector<int> arr1 = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
    Show(arr1);
    N = arr1.size();
    searchedValue = 16;
    i = BinarySearch(arr1, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Ternary Search" << endl;
    Show(arr1);
    searchedValue = 16;
    i = TernarySearch(arr1, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Interpolation Search" << endl;
    Show(arr1);
    searchedValue = 16;
    i = InterpolationSearch(arr1, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Jump Search" << endl;
    vector<int> arr2 = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
    Show(arr2);
    N = arr2.size();
    searchedValue = 39;
    i = JumpSearch(arr2, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Exponential Search" << endl;
    Show(arr2);
    searchedValue = 39;
    i = ExponentialSearch(arr2, 0, N - 1, searchedValue);
    Notify(i, searchedValue);

    cout << "========================" << endl;
    cout << "Sublist Search" << endl;

    LinkedList<int> *l1 = new LinkedList<int>();
    l1->InsertTail(23);
    l1->InsertTail(30);
    l1->InsertTail(41);

    l1->PrintList();

    LinkedList<int> *l2 = new LinkedList<int>();
    l2->InsertTail(10);
    l2->InsertTail(15);
    l2->InsertTail(23);
    l2->InsertTail(30);
    l2->InsertTail(41);
    l2->InsertTail(49);

    l2->PrintList();

    bool subListSearch = SubListSearch(l1->Head, l2->Head);
    if (subListSearch)
        cout << "found";
    else
        cout << "not found";
    cout << " in first list." << endl;

    return 0;
}