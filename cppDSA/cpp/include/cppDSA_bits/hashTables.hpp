#ifndef HASHTABLES_H
#define HASHTABLES_H
#define TABLE_SIZE 7

#include <string>
#include <list>

class HashTableSC
{
    // SC stands for separate chaining.
private:
    std::list<std::pair<int, std::string>> tableList[TABLE_SIZE];
    int HashFunction(int key);

public:
    HashTableSC();
    ~HashTableSC();
    void Insert(int key, std::string value);
    void Remove(int key);
    std::string Search(int key);
    bool IsEmpty();
};

class HashElement
{
public:
    int Key;
    std::string Value;

    HashElement(int key, std::string value);
    ~HashElement();
};

class HashTableLP
{
    // LP stands for Linear Probing
private:
    int currentSize;
    HashElement **arr;
    HashElement *deletedElement;
    int HashFunction(int key);

public:
    HashTableLP();
    ~HashTableLP();

    void Insert(int key, std::string value);
    std::string Search(int key);
    void Remove(int key);
    bool IsEmpty();
    void PrintHashTable();
};

#endif