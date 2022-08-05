#ifndef BST_H
#define BST_H
#include <vector>

#include "nodes.hpp"
using namespace std;

NodeBin *insert(NodeBin *node, int data)
{
    if (!node)
        return new NodeBin(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

bool search(NodeBin *node, int data)
{
    if (!node)
        return false;
    if (node->data == data)
        return true;
    if (node->data < data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

NodeBin *findMin(NodeBin *node)
{
    while (node->left)
    {
        node = node->left;
    }
    return node;
}

NodeBin *remove(NodeBin *node, int key)
{
    if (!node)
        return nullptr;

    else if (key < node->data)
        node->left = remove(node->left, key);
    else if (key > node->data)
        node->right = remove(node->right, key);

    else
    {
        if (!node->left && !node->right)
        {
            delete node;
            node = nullptr;
        }

        else if (!node->left)
        {
            NodeBin *temp = node;
            node = node->right;
            temp->right = nullptr;
            delete temp;
        }

        else if (!node->right)
        {
            NodeBin *temp = node;
            node = node->left;
            temp->left = nullptr;
            delete temp;
        }

        else
        {
            NodeBin *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    return node;
}

void printRange(NodeBin *root, int k1, int k2)
{
    if (!root)
        return;

    printRange(root->left, k1, k2);
    if (root->data <= k2 && root->data >= k1)
        cout << root->data << " ";
    printRange(root->right, k1, k2);
}

void printRoot2LeafPaths(NodeBin *node, vector<int> &path)
{
    if (!node)
        return;

    if (!node->left && !node->right)
    {
        for (int node : path)
            cout << node << "->";

        cout << node->data << "->";
        cout << endl;
        return;
    }

    path.push_back(node->data);
    printRoot2LeafPaths(node->left, path);
    printRoot2LeafPaths(node->right, path);
    path.pop_back();
    return;
}

#endif