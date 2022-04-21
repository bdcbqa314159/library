#include "../include/cppDSA_bits/hashTables.hpp"
#include <iostream>

HashTableSC::HashTableSC() : tableList()
{
}

HashTableSC::~HashTableSC()
{
}

int HashTableSC::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

void HashTableSC::Insert(int key, std::string value)
{
    bool isKeyFound = false;
    int hashKey = HashFunction(key);

    for (auto &keyValue : tableList[hashKey])
    {
        if (keyValue.first == key)
        {
            isKeyFound = true;
            keyValue.second = value;
        }
    }

    if (!isKeyFound)
    {
        tableList[hashKey].emplace_back(key, value);
    }
}

std::string HashTableSC::Search(int key)
{
    int hashKey = HashFunction(key);

    for (auto &keyValue : tableList[hashKey])
    {
        if (keyValue.first == key)
            return keyValue.second;
    }
    return "";
}

void HashTableSC::Remove(int key)
{
    int hashKey = HashFunction(key);
    auto &cell = tableList[hashKey];

    for (auto it = cell.begin(); it != cell.end(); it++)
    {
        if (it->first == key)
        {
            cell.erase(it);
            break;
        }
    }
}

bool HashTableSC::IsEmpty()
{
    int totalElement = 0;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        totalElement += (int)tableList[i].size();
        if (totalElement > 0)
            return false;
    }

    return true;
}

HashElement::HashElement(int key, std::string value) : Key(key), Value(value)
{
}

HashElement::~HashElement()
{
}

int HashTableLP::HashFunction(int key)
{
    return key % TABLE_SIZE;
}

HashTableLP::HashTableLP()
{
    currentSize = 0;
    arr = new HashElement *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i)
        arr[i] = nullptr;

    deletedElement = new HashElement(-1, "");
}

HashTableLP::~HashTableLP()
{
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] && arr[i]->Key != -1)
            delete arr[i];
    }

    delete[] arr;
    if (deletedElement && deletedElement->Key == -1)
        delete deletedElement;
}

void HashTableLP::Insert(int key, std::string value)
{
    if (currentSize >= TABLE_SIZE)
        return;

    HashElement *temp = new HashElement(key, value);
    int hashIndex = HashFunction(key);

    while (arr[hashIndex] && (arr[hashIndex]->Key != key) && (arr[hashIndex]->Key != -1))
    {
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    if (!arr[hashIndex] || (arr[hashIndex]->Key == -1))
    {
        ++currentSize;
        arr[hashIndex] = temp;
    }
    temp = nullptr;
    delete temp;
    return;
}

std::string HashTableLP::Search(int key)
{
    int hashIndex = HashFunction(key);

    while (arr[hashIndex] != nullptr && (arr[hashIndex]->Key != deletedElement->Key))
    {
        if (arr[hashIndex]->Key == key)
            return arr[hashIndex]->Value;
        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }

    return "";
}

void HashTableLP::Remove(int key)
{

    int hashIndex = HashFunction(key);

    while (arr[hashIndex] && arr[hashIndex]->Key != deletedElement->Key)
    {
        if (arr[hashIndex]->Key == key)
        {
            arr[hashIndex] = deletedElement;
            --currentSize;
            return;
        }

        ++hashIndex;
        hashIndex %= TABLE_SIZE;
    }
    return;
}

bool HashTableLP::IsEmpty()
{
    return currentSize == 0;
}

void HashTableLP::PrintHashTable()
{
    for (int i = 0; i < currentSize; ++i)
    {
        if (arr[i] && arr[i]->Key != -1)
        {
            std::cout << "Cell: " << i;
            std::cout << " Key: " << arr[i]->Key;
            std::cout << " Value: " << arr[i]->Value;
            std::cout << std::endl;
        }
    }
}