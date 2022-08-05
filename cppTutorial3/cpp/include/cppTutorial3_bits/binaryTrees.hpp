#ifndef BINARYTREES_H
#define BINARYTREES_H

#include "nodes.hpp"
#include <iostream>
#include <queue>

using namespace std;

NodeBin *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
        return nullptr;

    NodeBin *n = new NodeBin(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}
// Input 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Input2 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
void printPreorder(NodeBin *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(NodeBin *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPostorder(NodeBin *root)
{
    if (!root)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void levelOrderPrint(NodeBin *root)
{
    queue<NodeBin *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        NodeBin *temp = q.front();

        if (temp == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return;
}

NodeBin *levelOrderBuild()
{
    int d;
    cin >> d;

    NodeBin *root = new NodeBin(d);
    queue<NodeBin *> q;
    q.push(root);

    while (!q.empty())
    {
        NodeBin *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            current->left = new NodeBin(c1);
            q.push(current->left);
        }

        if (c2 != -1)
        {
            current->right = new NodeBin(c2);
            q.push(current->right);
        }
    }

    cout << "Here" << endl;
    return root;
}

int height(NodeBin *root)
{
    if (!root)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}

// O(n^2) -> bad version
int diameter(NodeBin *root)
{
    if (!root)
        return 0;
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

class HDPair
{
public:
    int height, diameter;
    HDPair(int h, int d) : height(h), diameter(d)
    {
    }
    ~HDPair()
    {
    }
};

HDPair diameterOptimised(NodeBin *root)
{
    HDPair p(0, 0);
    if (!root)
    {
        p.height = p.diameter = 0;
        return p;
    }

    HDPair l = diameterOptimised(root->left);
    HDPair r = diameterOptimised(root->right);

    p.height = max(l.height, r.height) + 1;
    int d1 = l.height + r.height;
    int d2 = l.diameter;
    int d3 = l.diameter;

    p.diameter = max(d1, max(d2, d3));
    return p;
}

#endif