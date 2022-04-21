#include "../include/cppDSA_bits/trees.hpp"
#include <iostream>
#include <algorithm>

BST::BST() : root(nullptr)
{
}

BST::~BST()
{
    delete root;
}

BSTNode *BST::Insert(BSTNode *node, int key)
{
    if (!node)
    {
        node = new BSTNode(key);
    }

    else if (node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }

    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    return node;
}

void BST::Insert(int key)
{
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode *node)
{
    if (!node)
        return;
    PrintTreeInOrder(node->Left);
    std::cout << node->Key << " ";
    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

BSTNode *BST::Search(BSTNode *node, int key)
{
    if (!node)
        return nullptr;
    else if (node->Key == key)
        return node;
    else if (node->Key < key)
        return Search(node->Right, key);
    else
        return Search(node->Left, key);
}

bool BST::Search(int key)
{
    BSTNode *result = Search(root, key);

    return result == nullptr ? false : true;
}

int BST::FindMin(BSTNode *node)
{
    if (!node)
        return -1;
    else if (node->Left == nullptr)
        return node->Key;
    else
        return FindMin(node->Left);
}

int BST::FindMax(BSTNode *node)
{
    if (!node)
        return -1;
    else if (node->Right == nullptr)
        return node->Key;
    else
        return FindMax(node->Right);
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Predecessor(BSTNode *node)
{
    if (node->Left)
        return FindMax(node->Left);
    else
    {
        BSTNode *parentNode = node->Parent;
        BSTNode *currentNode = node;

        while (parentNode && (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }
        return parentNode == nullptr ? -1 : parentNode->Key;
    }
}

int BST::Successor(BSTNode *node)
{
    if (node->Right)
        return FindMin(node->Right);
    else
    {
        BSTNode *parentNode = node->Parent;
        BSTNode *currentNode = node;

        while (parentNode && (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }
        return parentNode == nullptr ? -1 : parentNode->Key;
    }
}

int BST::Predecessor(int key)
{
    BSTNode *keyNode = Search(root, key);
    return keyNode == nullptr ? -1 : Predecessor(keyNode);
}

int BST::Successor(int key)
{
    BSTNode *keyNode = Search(root, key);
    return keyNode == nullptr ? -1 : Successor(keyNode);
}

BSTNode *BST::Remove(BSTNode *node, int key)
{
    if (!node)
        return nullptr;
    if (node->Key == key)
    {
        if (!node->Left && !node->Right)
            node = nullptr;
        else if (!node->Left && node->Right)
        {
            node->Right->Parent = node->Parent;
            node = node->Right;
        }
        else if (node->Left && !node->Right)
        {
            node->Left->Parent = node->Parent;
            node = node->Left;
        }
        else
        {
            int successorKey = Successor(key);
            node->Key = successorKey;
            node->Right = Remove(node->Right, successorKey);
        }
    }
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    else
        node->Left = Remove(node->Left, key);
    return node;
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}

AVL::AVL() : BST()
{
}

AVL::~AVL()
{
}

int AVL::GetHeight(BSTNode *node)
{
    return node == nullptr ? -1 : node->Height;
}

BSTNode *AVL::RotateLeft(BSTNode *node)
{

    BSTNode *balancedNode = node->Right;
    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Right = balancedNode->Left;

    if (balancedNode->Left)
        balancedNode->Left->Parent = node;
    balancedNode->Left = node;
    node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;

    balancedNode->Height = std::max(GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode *AVL::RotateRight(BSTNode *node)
{
    BSTNode *balancedNode = node->Left;
    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Left = balancedNode->Right;

    if (balancedNode->Right)
        balancedNode->Right->Parent = node;
    balancedNode->Right = node;
    node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
    balancedNode->Height = std::max(GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode *AVL::Insert(BSTNode *node, int key)
{
    if (!node)
    {
        node = new BSTNode(key);
    }

    else if (node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }

    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    int balance = GetHeight(node->Left) - GetHeight(node->Right);

    if (balance == 2)
    {
        int balance2 = GetHeight(node->Left->Left) - GetHeight(node->Left->Right);
        if (balance2 == 1)
            node = RotateRight(node);
        else
        {
            node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }
    }

    else if (balance == -2)
    {
        int balance2 = GetHeight(node->Right->Left) - GetHeight(node->Right->Right);
        if (balance2 == -1)
            node = RotateLeft(node);
        else
        {
            node->Right = RotateRight(node->Right);
            node = RotateLeft(node);
        }
    }

    node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;

    return node;
}

void AVL::Insert(int key)
{
    root = Insert(root, key);
}

BSTNode *AVL::Remove(BSTNode *node, int key)
{
    if (!node)
        return nullptr;
    if (node->Key == key)
    {
        if (!node->Left && !node->Right)
            node = nullptr;
        else if (!node->Left && node->Right)
        {
            node->Right->Parent = node->Parent;
            node = node->Right;
        }
        else if (node->Left && !node->Right)
        {
            node->Left->Parent = node->Parent;
            node = node->Left;
        }
        else
        {
            int successorKey = Successor(key);
            node->Key = successorKey;
            node->Right = Remove(node->Right, successorKey);
        }
    }
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    else
        node->Left = Remove(node->Left, key);

    if (node)
    {
        int balance = GetHeight(node->Left) - GetHeight(node->Right);
        if (balance == 2)
        {
            int balance2 = GetHeight(node->Left->Left) - GetHeight(node->Left->Right);
            if (balance2 == 1)
                node = RotateRight(node);
            else
                node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }

        else if (balance == -2)
        {
            int balance2 = GetHeight(node->Right->Left) - GetHeight(node->Right->Right);
            if (balance2 == -1)
                node = RotateLeft(node);
            else
                node->Right = RotateRight(node->Right);
            node = RotateLeft(node);
        }
        node->Height = std::max(GetHeight(node->Left), GetHeight(node->Right)) + 1;
    }

    return node;
}

void AVL::Remove(int key)
{
    root = Remove(root, key);
}

BinaryHeap::BinaryHeap() : v{-1}, heapSize(0)
{
}

BinaryHeap::~BinaryHeap()
{
}

void BinaryHeap::ShiftUp(int index)
{
    if (index > heapSize)
        return;

    if (index == 1)
        return;

    if (v[index] > v[p(index)])
    {
        std::swap(v[p(index)], v[index]);
    }
    ShiftUp(p(index));
    return;
}

void BinaryHeap::Insert(int key)
{
    if (heapSize + 1 >= v.size())
    {
        v.push_back(0);
    }

    v[++heapSize] = key;
    ShiftUp(heapSize);
    return;
}

void BinaryHeap::ShiftDown(int i)
{
    if (i > heapSize)
        return;

    int swapId = i;

    if (l(i) <= heapSize && v[i] < v[l(i)])
        swapId = l(i);

    if (r(i) <= heapSize && v[swapId] < v[r(i)])
        swapId = r(i);

    if (swapId != i)
    {
        std::swap(v[i], v[swapId]);
        ShiftDown(swapId);
    }
    return;
}

int BinaryHeap::ExtractMax()
{
    int maxVal = v[1];
    std::swap(v[1], v[heapSize--]);
    ShiftDown(1);
    return maxVal;
}