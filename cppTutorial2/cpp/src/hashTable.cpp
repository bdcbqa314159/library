#include "../include/cppTutorial2_bits/hashTable.hpp"
#include <iostream>

HashTable::HashTable()
{
    hashTable.resize(TABLE_SIZE);
}

int HashTable::get(int key)
{
    int generatedArrayIndex = hash(key);
    std::list<HashItem> &items = hashTable[generatedArrayIndex];
    if (hashTable[generatedArrayIndex].empty())
        return -1;

    for (HashItem const &item : items)
    {
        if (item.key == key)
            return item.value;
    }

    std::cout << "Sorry the search failed :(" << std::endl;

    return -1;
}

void HashTable::put(int key, int value)
{
    int hashArrayIndex = hash(key);

    std::list<HashItem> &items = hashTable[hashArrayIndex];

    if (items.empty())
    {
        std::cout << "No colision simple insertion.." << std::endl;
    }
    else
    {
        std::cout << "Collision when inserting with key " << key << std::endl;
    }

    for (HashItem const &item : items)
    {
        if (item.key == key)
        {
            std::cout << "item is already inserted..." << std::endl;
            return;
        }
    }

    items.push_back(HashItem{key, value});
    std::cout << "Size of the list is " << items.size() << std::endl;
}

int HashTable::hash(int key)
{
    return key % TABLE_SIZE;
}