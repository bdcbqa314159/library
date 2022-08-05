#include <cppTutorial3>
#include <iostream>
#include <stack>
#include <string>
#include <queue>

void testingBinaryTrees()
{
    NodeBin *root = buildTree();
    cout << "\npreorder traversal:" << endl;
    printPreorder(root);
    cout << "\ninorder traversal:" << endl;
    printInorder(root);
    cout << "\npostorder traversal:" << endl;
    printPostorder(root);
    cout << endl;
    cout << "level order traversal:" << endl;
    levelOrderPrint(root);

    cout << "\nCreating a tree by level order:" << endl;
    NodeBin *root1 = levelOrderBuild();
    levelOrderPrint(root1);

    HDPair p = diameterOptimised(root1);
    cout << "height: " << p.height << " - diameter: " << p.diameter << endl;
}

int main()
{
    testingBinaryTrees();
    return 0;
}