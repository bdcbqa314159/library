#include <cppDSA>
#include <iostream>

using namespace std;

void WorkingWithHashTableSeparateChaining()
{

    cout << "HashTable with separate chaining technique." << endl;
    HashTableSC *hashTable = new HashTableSC();

    bool b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Has table is not empty";

    cout << endl;

    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";

    cout << endl;

    hashTable->Insert(391, "Dominic");
    hashTable->Insert(806, "Adam");
    hashTable->Insert(117, "Lindsey");
    hashTable->Insert(548, "Cameron");
    hashTable->Insert(669, "Terry");
    hashTable->Insert(722, "Brynn");
    hashTable->Insert(276, "Jody");
    hashTable->Insert(953, "Frankie");
    hashTable->Insert(895, "Vanessa");

    int key = 669;
    cout << "Search value for key ";
    cout << key << endl;

    string name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }

    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }

    cout << endl;

    cout << "Remove node of key ";
    cout << key << endl;

    hashTable->Remove(key);
    name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }

    cout << endl;
    delete hashTable;

    return;
}

void WorkingWithHashTableLinearProbing()
{

    cout << "HashTable with open addressing - linear probing technique." << endl;
    HashTableLP *hashTable = new HashTableLP();

    bool b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Has table is not empty";

    cout << endl;

    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if (b)
        cout << "Hash table is empty";
    else
        cout << "Has table is not empty";

    cout << endl;

    hashTable->Insert(391, "Dominic");
    hashTable->Insert(806, "Adam");
    hashTable->Insert(117, "Lindsey");
    hashTable->Insert(548, "Cameron");
    hashTable->Insert(669, "Terry");
    hashTable->Insert(722, "Brynn");
    hashTable->Insert(276, "Jody");
    hashTable->Insert(953, "Frankie");
    hashTable->Insert(895, "Vanessa");

    int key = 669;
    cout << "Search value for key ";
    cout << key << endl;

    string name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }

    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }

    cout << endl;

    cout << "Remove node of key ";
    cout << key << endl;

    hashTable->Remove(key);
    name = hashTable->Search(key);
    if (name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }

    cout << endl;
    hashTable->PrintHashTable();
    delete hashTable;

    return;
}

int main()
{
    WorkingWithHashTableSeparateChaining();
    cout << "=================" << endl;
    cout << endl;
    cout << "=================" << endl;
    WorkingWithHashTableLinearProbing();
    return 0;
}