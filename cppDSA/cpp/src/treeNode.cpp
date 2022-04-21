#include "../include/cppDSA_bits/treeNode.hpp"
#include <iostream>

TreeNode::TreeNode(int Key) : Key(Key), Left(nullptr), Right(nullptr)
{
}

TreeNode::~TreeNode()
{
    delete Left;
    delete Right;
}

BSTNode::BSTNode() : Key(0), Left(nullptr), Right(nullptr), Parent(nullptr), Height(0)
{
}

BSTNode::BSTNode(int Key) : Key(Key), Left(nullptr), Right(nullptr), Parent(nullptr)
{
}

BSTNode::~BSTNode()
{
    // std::cout << Key << " ";
    delete Left;
    delete Right;
}