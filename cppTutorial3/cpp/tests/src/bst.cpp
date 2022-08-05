#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
void testingBST()
{
    NodeBin *node = nullptr;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int x : arr)
        node = insert(node, x);

    printInorder(node);
    cout << endl;
    cout << "Is 10 in the bst:" << endl;
    cout << boolalpha;
    cout << search(node, 10) << endl;
    cout << "Removing nodes" << endl;
    int key;
    cout << "Key>> ";
    cin >> key;
    node = remove(node, key);
    printInorder(node);
    cout << endl;
    cout << "Printing in range: " << endl;
    printRange(node, 10, 12);
    cout << endl;
    cout << "Tree?" << endl;
    vector<int> path;
    NodeBin *node1 = buildTree();
    printInorder(node1);
    cout << endl;
    printRoot2LeafPaths(node1, path);
    cout << endl;

    return;
}

int main()
{
    testingBST();
    return 0;
}