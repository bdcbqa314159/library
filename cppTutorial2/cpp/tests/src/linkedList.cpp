#include <cppTutorial2>
#include <iostream>
#include <memory>

using namespace std;

int main()
{

    cout << "Working with linked lists." << endl;

    unique_ptr<List<int>> myLinkedList = make_unique<LinkedList<int>>();

    myLinkedList->insert(1);
    myLinkedList->insert(2);
    myLinkedList->insert(3);
    myLinkedList->insert(4);
    myLinkedList->traverseList();

    myLinkedList->remove(1);
    myLinkedList->traverseList();

    return 0;
}