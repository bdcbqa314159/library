#ifndef NODES_H
#define NODES_H

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr)
    {
    }

    ~Node()
    {
        delete next;
    }
};

class NodeBin
{

public:
    int data;
    NodeBin *left, *right;

    NodeBin(int d) : data(d), left(nullptr), right(nullptr)
    {
    }

    ~NodeBin()
    {
        delete left;
        delete right;
    }
};

class NodeHash
{

public:
    string key;
    int value;
    NodeHash *next;

    NodeHash(string key, int value) : key(key), value(value), next(nullptr)
    {
    }

    ~NodeHash()
    {
        delete next;
    }
};

class NodeGraph
{
public:
    string name;
    list<string> nbrs;

    NodeGraph(string name) : name(name)
    {
    }

    ~NodeGraph()
    {
    }
};

class NodeT
{
public:
    char data;
    unordered_map<char, NodeT *> m;
    bool isTerminal;

    NodeT(char data) : data(data), isTerminal(false)
    {
    }

    ~NodeT()
    {
        unordered_map<char, NodeT *>::iterator it = m.begin();
        for (; it != m.end(); it++)
            delete it->second;
    }
};

#endif