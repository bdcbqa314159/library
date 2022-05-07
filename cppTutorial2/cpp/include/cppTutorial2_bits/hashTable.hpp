#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

class HashTable
{
    static constexpr int TABLE_SIZE = 10;

    struct HashItem
    {
        int key = 0;
        int value = 0;
    };

    std::vector<std::list<HashItem>> hashTable;

public:
    HashTable();
    int get(int key);
    void put(int key, int value);

private:
    static int hash(int key);
};

#endif