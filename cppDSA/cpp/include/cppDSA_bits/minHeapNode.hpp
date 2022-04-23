#ifndef MINHEAPNODE_H
#define MINHEAPNODE_H
#include <string>
#include <iostream>

class MinHeapNode
{
public:
    char Data;
    unsigned Frequency;
    MinHeapNode *LeftChild, *RightChild;
    MinHeapNode(char data, unsigned freq);
    ~MinHeapNode();
};

class compare
{
public:
    bool operator()(MinHeapNode *left, MinHeapNode *right);
};

void PrintCodes(MinHeapNode *root, std::string str);

#endif