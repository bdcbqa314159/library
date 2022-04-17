#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();
    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);

    cout << "First Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);

    cout << "Second Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    cout << "Second Printed Backwards:" << endl;
    linkedList.PrintListBackward();
    cout << endl;

    cout << "Get value of the second index: " << endl;
    DoublyNode<int> *get = linkedList.Get(2);
    if (get)
        cout << get->Value;
    else
        cout << "not found";

    cout << endl
         << endl;

    cout << "The position of value 15: " << endl;
    int srch = linkedList.Search(15);

    if (srch == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index : " << srch << endl;

    cout << "Remove the first element: " << endl;
    linkedList.Remove(0);
    linkedList.PrintList();
    cout << endl;

    cout << "Remove the fifth element: " << endl;
    linkedList.Remove(4);
    linkedList.PrintList();
    cout << endl;

    cout << "Remove the tenth element: (nothing happen)" << endl;
    linkedList.Remove(9);
    linkedList.PrintList();
    cout << endl;

    return 0;
}