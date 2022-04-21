#include <cppDSA>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkInOrder(TreeNode *root)
{
    if (!root)
        return;
    checkInOrder(root->Left);
    cout << root->Key << " ";
    checkInOrder(root->Right);
    return;
}

void singleTree()
{

    TreeNode *node = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);

    node->Left = left;
    node->Right = right;

    left->Left = new TreeNode(4);
    left->Right = new TreeNode(5);

    right->Left = new TreeNode(6);
    right->Right = new TreeNode(7);

    checkInOrder(node);

    return;
}

void WorkingWithBST()
{

    BST *tree = new BST();
    vector<int> keys = {23, 12, 31, 3, 15, 7, 29, 88, 53};
    for (const int &key : keys)
        tree->Insert(key);

    cout << "Tree keys: " << endl;
    tree->PrintTreeInOrder();

    cout << "Search key 31: ";
    bool b = tree->Search(31);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    cout << "Search key 18: ";
    b = tree->Search(18);
    if (b)
        cout << "found";
    else
        cout << "NOT found";
    cout << endl;

    cout << "Min. key : " << tree->FindMin();
    cout << endl;
    cout << "Max. key : " << tree->FindMax();
    cout << endl;

    cout << "Successor(31) = ";
    cout << tree->Successor(31) << endl;
    cout << "Successor(18) = ";
    cout << tree->Successor(18) << endl;
    cout << "Successor(15) = ";
    cout << tree->Successor(88) << endl;
    cout << "Predecessor(12) = ";
    cout << tree->Predecessor(12) << endl;
    cout << "Predecessor(29) = ";
    cout << tree->Predecessor(29) << endl;
    cout << "Predecessor(3) = ";
    cout << tree->Predecessor(3) << endl;

    cout << "Removing key 15" << endl;
    tree->Remove(15);

    cout << "Removing key 53" << endl;
    tree->Remove(53);

    cout << "Tree keys: " << endl;
    tree->PrintTreeInOrder();

    delete tree;
}

void WorkingWithAVL()
{
    AVL *tree1 = new AVL();
    vector<int> keys = {69, 62, 46, 32, 24};
    for (const int &key : keys)
        tree1->Insert(key);

    cout << "Tree keys: " << endl;
    tree1->PrintTreeInOrder();

    delete tree1;
}

void WorkingWithBinaryHeap()
{
    BinaryHeap *priorityQueue = new BinaryHeap();
    cout << "Is the queue empty?" << endl;
    bool b = priorityQueue->IsEmpty();
    if (b)
        cout << "True";
    else
        cout << "False";
    cout << endl;

    // priorityQueue->Insert(14);
    // priorityQueue->Insert(53);
    // priorityQueue->Insert(8);
    // priorityQueue->Insert(32);
    priorityQueue->Insert(10);
    priorityQueue->Insert(120);
    priorityQueue->Insert(34);
    priorityQueue->Insert(41);
    priorityQueue->Insert(5);

    cout << "GetMax() = ";
    cout << priorityQueue->GetMax();
    cout << endl;

    cout << "ExtractMax() = ";
    cout << priorityQueue->ExtractMax();
    cout << endl;

    cout << "GetMax() = ";
    cout << priorityQueue->GetMax();
    cout << endl;
    delete priorityQueue;
}

int main()
{
    WorkingWithBinaryHeap();

    return 0;
}
