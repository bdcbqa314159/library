#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void PrintedLinkedList(const list<int> &llist)
{
    for (auto l : llist)
        cout << l << " -> ";
    cout << "NULL" << endl;
}

list<int>::iterator GetIterator(list<int>::iterator it, int x)
{
    for (int i = 0; i < x; ++i, ++it)
        ;
    return it;
}

void vectorSTL()
{
    cout << endl;
    cout << "Vectors -> include <vector>" << endl;
    cout << "Check the code in tests/src/stl.cpp" << endl;
    vector<int> vectorList;
    vectorList.push_back(35);
    vectorList.push_back(41);
    vectorList.push_back(94);

    cout << "Using .at and []:" << endl;
    int i = vectorList.at(1);
    int j = vectorList[0];

    cout << "Showing all current elements:" << endl;
    for (int i = 0; i < vectorList.size(); i++)
        cout << vectorList.at(i) << " ";
    cout << endl;

    cout << "Iterators & vectors" << endl;
    vector<int>::iterator it;

    it = vectorList.begin();
    vectorList.insert(it, 58);

    it = vectorList.end();
    vectorList.insert(it, 37);

    cout << "Showing all current elements:" << endl;
    for (int i = 0; i < vectorList.size(); i++)
        cout << vectorList.at(i) << " ";
    cout << endl;

    it = vectorList.begin();
    vectorList.insert(it + 3, 67);

    cout << "Showing all current elements:" << endl;
    for (int i = 0; i < vectorList.size(); i++)
        cout << vectorList.at(i) << " ";
    cout << endl;

    it = find(vectorList.begin(), vectorList.end(), 41);
    if (it != vectorList.end())
        cout << "Element found in vectorList: " << *it;
    else
        cout << "Element not found in vectorList" << endl;
    cout << endl;

    it = vectorList.begin();
    vectorList.erase(it + 1);

    cout << "Showing all current elements:" << endl;
    for (int i = 0; i < vectorList.size(); i++)
        cout << vectorList.at(i) << " ";
    cout << endl;
}

void linkedListsSTL()
{

    cout << endl;
    cout << "Lists -> include <list>" << endl;
    cout << "Check the code in tests/src/stl.cpp" << endl;

    list<int> linkedList;
    linkedList.push_front(43);
    linkedList.push_front(76);
    linkedList.push_back(15);
    linkedList.push_back(44);

    cout << "First Printed:" << endl;
    PrintedLinkedList(linkedList);
    cout << endl;

    list<int>::iterator it = GetIterator(linkedList.begin(), 4);
    linkedList.insert(it, 100);

    it = GetIterator(linkedList.begin(), 3);
    linkedList.insert(it, 48);

    linkedList.insert(linkedList.begin(), 22);

    cout << "Second Printed:" << endl;
    PrintedLinkedList(linkedList);
    cout << endl;

    cout << "Get value of the second index:" << endl;
    it = GetIterator(linkedList.begin(), 2);
    if (it != linkedList.end())
        cout << *it;
    else
        cout << "not found.";
    cout << endl
         << endl;

    it = find(linkedList.begin(), linkedList.end(), 15);
    if (it != linkedList.end())
        cout << "Element found in linkedList: " << *it;
    else
        cout << "Element not found in linkedList";
    cout << endl
         << endl;

    cout << "Remove the fifth element: " << endl;
    it = GetIterator(linkedList.begin(), 4);
    linkedList.erase(it);

    PrintedLinkedList(linkedList);
    cout << endl;
}

int main()
{
    vectorSTL();
    linkedListsSTL();
    return 0;
}