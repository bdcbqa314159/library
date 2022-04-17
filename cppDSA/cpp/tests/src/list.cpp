#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    List list = List();
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);

    for (int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";

    cout << endl;

    list.Insert(2, 25);
    list.Insert(2, 71);

    cout << "New List elements:" << endl;
    for (int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";

    cout << endl
         << endl;

    cout << "Search element 71" << endl;
    int result = list.Search(71);
    if (result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;

    cout << endl
         << endl;

    cout << "Remove element at index 2" << endl;
    list.Remove(2);
    cout << endl;

    cout << "New List elements:" << endl;
    for (int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";

    cout << endl
         << endl;

    cout << "Search element 71 again..." << endl;
    result = list.Search(71);
    if (result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;

    cout << endl
         << endl;

    return 0;
}