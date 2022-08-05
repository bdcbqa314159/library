#ifndef HASH_H
#define HASH_H

#include <string>
#include "nodes.hpp"

using namespace std;

class HashTable
{

public:
    NodeHash **table;
    int cs, ts;

    HashTable(int ts = 7) : cs(0), ts(ts)
    {
        table = new NodeHash *[ts];

        for (int i = 0; i < ts; i++)
            table[i] = nullptr;
    }

    int hash(string &key)
    {
        int idx = 0;
        int power = 1;
        for (auto ch : key)
        {
            idx = (idx + ch * power) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }

    void rehash()
    {
        NodeHash **oldTable = table;
        int oldTs = ts;
        cs = 0;
        ts = 2 * ts + 1;
        table = new NodeHash *[ts];
        for (int i = 0; i < ts; i++)
            table[i] = nullptr;

        for (int i = 0; i < oldTs; i++)
        {
            NodeHash *temp = oldTable[i];
            while (temp)
            {
                string key = temp->key;
                int value = temp->value;

                insert(key, value);
                temp = temp->next;
            }
        }

        for (int i = 0; i < oldTs; i++)
        {
            delete oldTable[i];
        }

        delete[] oldTable;
    }

    void insert(string key, int val)
    {
        int idx = hash(key);
        NodeHash *n = new NodeHash(key, val);

        n->next = table[idx];
        table[idx] = n;
        cs++;
        float load_factor = cs / float(ts);
        if (load_factor > 0.7)
            rehash();
    }

    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << "->";
            NodeHash *temp = table[i];

            while (temp)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    int *search(string key)
    {
        int idx = hash(key);
        NodeHash *temp = table[idx];
        while (temp)
        {
            if (temp->key == key)
                return &temp->value;
            temp = temp->next;
        }
        return nullptr;
    }

    int &operator[](string key)
    {
        int *valueFound = search(key);
        if (!valueFound)
        {
            int object;
            insert(key, object);
            valueFound = search(key);
        }

        return *valueFound;
    }
};

#endif