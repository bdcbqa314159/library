#include <cppTutorial2>
#include <iostream>

using namespace std;

int main()
{
    HashTable hashTable{};
    hashTable.put(1, 1);
    hashTable.put(11, 10);
    hashTable.put(21, 100);

    cout << hashTable.get(1) << endl;
    cout << hashTable.get(11) << endl;
    cout << hashTable.get(21) << endl;

    return 0;
}