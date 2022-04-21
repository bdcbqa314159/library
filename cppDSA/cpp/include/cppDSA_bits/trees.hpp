#ifndef TREES_H
#define TREES_H
#include <vector>
#include "treeNode.hpp"

class BST
{
protected:
    BSTNode *root;
    BSTNode *Insert(BSTNode *node, int key);
    void PrintTreeInOrder(BSTNode *node);
    BSTNode *Search(BSTNode *node, int key);
    int FindMin(BSTNode *node);
    int FindMax(BSTNode *node);
    int Successor(BSTNode *node);
    int Predecessor(BSTNode *node);
    BSTNode *Remove(BSTNode *node, int key);

public:
    BST();
    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(BST *node);
    int Successor(int key);
    int Predecessor(BST *node);
    int Predecessor(int key);
    void Remove(int key);
    ~BST();
};

class AVL : public BST
{

public:
    int GetHeight(BSTNode *node);
    BSTNode *RotateLeft(BSTNode *node);
    BSTNode *RotateRight(BSTNode *node);
    BSTNode *Insert(BSTNode *node, int key);
    BSTNode *Remove(BSTNode *node, int key);

public:
    AVL();
    ~AVL();

    void Insert(int v);
    void Remove(int v);
};

class BinaryHeap
{
private:
    std::vector<int> v;
    int heapSize;
    int p(int i) { return i >> 1; };
    int l(int i) { return i << 1; };
    int r(int i) { return (i << 1) + 1; };

public:
    BinaryHeap();
    ~BinaryHeap();
    bool IsEmpty() { return heapSize == 0; };
    void Insert(int key);
    void ShiftUp(int index);
    void ShiftDown(int i);
    int ExtractMax();
    int GetMax() { return v[1]; };
};

#endif