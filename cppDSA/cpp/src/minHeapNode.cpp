#include "../include/cppDSA_bits/minHeapNode.hpp"

MinHeapNode::MinHeapNode(char data, unsigned freq) : LeftChild(nullptr), RightChild(nullptr), Frequency(freq), Data(data)
{
}

MinHeapNode::~MinHeapNode()
{
    delete LeftChild;
    delete RightChild;
}

bool compare::operator()(MinHeapNode *left, MinHeapNode *right)
{
    return (left->Frequency > right->Frequency);
}

void PrintCodes(MinHeapNode *root, std::string str)
{
    if (!root)
        return;
    if (root->Data != '$')
    {
        std::cout << root->Data << ": ";
        std::cout << str << std::endl;
    }

    PrintCodes(root->LeftChild, str + "0");
    PrintCodes(root->RightChild, str + "1");
}