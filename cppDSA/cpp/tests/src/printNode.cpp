#include <cppDSA>
#include <iostream>

using namespace std;

int main()
{
    // Node *node1 = new Node;
    // node1->Value = 7;

    // Node *node2 = new Node;
    // node2->Value = 12;

    // Node *node3 = new Node;
    // node3->Value = 21;

    // node1->Next = node2;
    // node2->Next = node3;

    // PrintNode(node1);
    cout << "Nodes with int: " << endl;
    Node<int> *node1 = new Node<int>(7);
    Node<int> *node2 = new Node<int>(12);
    Node<int> *node3 = new Node<int>(21);
    node1->Next = node2;
    node2->Next = node3;

    PrintNode(node1);

    cout << "Nodes with float: " << endl;
    Node<float> *node4 = new Node<float>(4.98);
    Node<float> *node5 = new Node<float>(1.567);
    Node<float> *node6 = new Node<float>(98.23);
    node4->Next = node5;
    node5->Next = node6;

    PrintNode(node4);

    return 0;
}