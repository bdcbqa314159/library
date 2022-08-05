#ifndef TRIES_H
#define TRIES_H

#include <string>
#include "nodes.hpp"

using namespace std;

class Trie
{
public:
    NodeT *root;

    Trie()
    {
        root = new NodeT('\0');
    }

    void insert(string word)
    {
        NodeT *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                NodeT *n = new NodeT(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        NodeT *temp = root;
        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    ~Trie()
    {
        delete root;
    }
};

#endif