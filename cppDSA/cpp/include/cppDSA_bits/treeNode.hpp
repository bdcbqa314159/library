#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{

public:
    int Key;
    TreeNode *Left;
    TreeNode *Right;

    TreeNode(int Key);
    ~TreeNode();
};

class BSTNode
{

public:
    int Key;
    int Height;
    BSTNode *Left;
    BSTNode *Right;
    BSTNode *Parent;

    BSTNode();
    BSTNode(int Key);
    ~BSTNode();
};

#endif